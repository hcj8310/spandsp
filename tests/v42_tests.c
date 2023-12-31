/*
 * SpanDSP - a series of DSP components for telephony
 *
 * v42_tests.c
 *
 * Written by Steve Underwood <steveu@coppice.org>
 *
 * Copyright (C) 2004, 2011 Steve Underwood
 *
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2, as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/* THIS IS A WORK IN PROGRESS. IT IS NOT FINISHED. */

/*! \page v42_tests_page V.42 tests
\section v42_tests_page_sec_1 What does it do?
These tests connect two instances of V.42 back to back. V.42 frames are
then exchanged between them.
*/

#if defined(HAVE_CONFIG_H)
#include "config.h"
#endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define SPANDSP_EXPOSE_INTERNAL_STRUCTURES

#include "spandsp.h"

v42_state_t callerx;
v42_state_t answererx;
v42_state_t *caller;
v42_state_t *answerer;
int variable_length;

int rx_next[3] = {0};
int tx_next[3] = {0};

static void v42_status(void *user_data, int status)
{
    v42_state_t *s;

    s = (v42_state_t *) user_data;
    if (status < 0)
        printf("%p: Status is '%s' (%d)\n", s, signal_status_to_str(status), status);
    else
        printf("%p: Status is '%s' (%d)\n", s, lapm_status_to_str(status), status);
    /*endif*/
}
/*- End of function --------------------------------------------------------*/

static int v42_get_frames(void *user_data, uint8_t msg[], int len)
{
    int i;
    int j;
    int k;
    int x;
    v42_state_t *s;

    if (len < 0)
    {
        v42_status(user_data, len);
        return 0;
    }
    /*endif*/
    s = (v42_state_t *) user_data;
    x = (s == caller)  ?  1  :  2;
    if (variable_length)
    {
        j = make_mask32(len);
        do
            k = j & rand();
        while (k > len);
    }
    else
    {
        k = len;
    }
    /*endif*/
    for (i = 0;  i < k;  i++)
        msg[i] = tx_next[x]++;
    /*endfor*/
    return k;
}
/*- End of function --------------------------------------------------------*/

static void v42_put_frames(void *user_data, const uint8_t msg[], int len)
{
    int i;
    v42_state_t *s;
    int x;
    static int count = 0;
    static int xxx = 0;

    if (len < 0)
    {
        v42_status(user_data, len);
        return;
    }
    /*endif*/
    s = (v42_state_t *) user_data;
    x = (s == caller)  ?  1  :  2;
    for (i = 0;  i < len;  i++)
    {
        if (msg[i] != (rx_next[x] & 0xFF))
        {
            printf("%p: Mismatch 0x%02X 0x%02X\n", user_data, msg[i], rx_next[x] & 0xFF);
            exit(2);
        }
        /*endif*/
        rx_next[x]++;
    }
    /*endfor*/
    printf("%p: Got frame len %d\n", user_data, len);
    printf("%p: %d Far end busy status %d\n", user_data, count, v42_get_far_busy_status(s));
    if (s == caller)
    {
        if (++count == 5)
        {
            v42_set_local_busy_status(s, true);
            xxx = 1;
        }
        /*endif*/
    }
    else
    {
        if (xxx  &&  ++count == 45)
            v42_set_local_busy_status(caller, false);
        /*endif*/
    }
    /*endif*/
}
/*- End of function --------------------------------------------------------*/

int main(int argc, char *argv[])
{
    int i;
    int bit;
    bool insert_caller_bit_errors;
    bool insert_answerer_bit_errors;
    int opt;

    insert_caller_bit_errors = false;
    insert_answerer_bit_errors = false;
    variable_length = false;
    while ((opt = getopt(argc, argv, "bv")) != -1)
    {
        switch (opt)
        {
        case 'b':
            insert_caller_bit_errors = 11000;
            insert_answerer_bit_errors = 10000;
            break;
        case 'v':
            variable_length = true;
            break;
        default:
            //usage();
            exit(2);
            break;
        }
        /*endswitch*/
    }
    /*endwhile*/

    caller = v42_init(&callerx, true, true, v42_get_frames, v42_put_frames, (void *) &callerx);
    answerer = v42_init(&answererx, false, true, v42_get_frames, v42_put_frames, (void *) &answererx);
    v42_set_status_callback(caller, v42_status, (void *) caller);
    v42_set_status_callback(answerer, v42_status, (void *) answerer);
    v42_restart(caller);
    v42_restart(answerer);

    span_log_set_level(v42_get_logging_state(caller), SPAN_LOG_SHOW_SEVERITY | SPAN_LOG_SHOW_PROTOCOL | SPAN_LOG_SHOW_TAG | SPAN_LOG_DEBUG);
    span_log_set_tag(v42_get_logging_state(caller), "caller");
    span_log_set_level(v42_get_logging_state(answerer), SPAN_LOG_SHOW_SEVERITY | SPAN_LOG_SHOW_PROTOCOL | SPAN_LOG_SHOW_TAG | SPAN_LOG_DEBUG);
    span_log_set_tag(v42_get_logging_state(answerer), "answerer");

    for (i = 0;  i < 1000000;  i++)
    {
        bit = v42_tx_bit(caller);
        if (insert_caller_bit_errors  &&  i%insert_caller_bit_errors == 0)
            bit ^= 1;
        /*endif*/
        v42_rx_bit(answerer, bit);
        bit = v42_tx_bit(answerer);
        if (insert_answerer_bit_errors  &&  i%insert_answerer_bit_errors == 0)
            bit ^= 1;
        /*endif*/
        v42_rx_bit(caller, bit);
    }
    /*endfor*/
    return 0;
}
/*- End of function --------------------------------------------------------*/
/*- End of file ------------------------------------------------------------*/
