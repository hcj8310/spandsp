/*
 * SpanDSP - a series of DSP components for telephony
 *
 * fax_tester.h
 *
 * Written by Steve Underwood <steveu@coppice.org>
 *
 * Copyright (C) 2008 Steve Underwood
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

/*! \file */

#if !defined(_SPANDSP_FAX_TESTER_H_)
#define _SPANDSP_FAX_TESTER_H_

/*! \page fax_tester_page FAX over analogue modem handling

\section fax_tester_page_sec_1 What does it do?

\section fax_tester_page_sec_2 How does it work?
*/

typedef struct faxtester_state_s faxtester_state_t;

typedef void (*faxtester_flush_handler_t)(faxtester_state_t *s, void *user_data, int which);

/*!
    FAX tester descriptor.
*/
struct faxtester_state_s
{
    /*! \brief The far end FAX context */
    fax_state_t *far_fax;
    t38_terminal_state_t *far_t38;
    
    int far_tag;

    /*! \brief The far end T.38 terminal context */
    t38_terminal_state_t *far_t38_fax;
    
    t30_state_t *far_t30;

    t30_exchanged_info_t expected_rx_info;

    bool use_receiver_not_ready;
    bool test_local_interrupt;

    /*! \brief Path for the FAX image test files. */
    char image_path[1024];

    /*! \brief Pointer to the XML document. */
    xmlDocPtr doc;
    /*! \brief Pointer to our current step in the test. */
    xmlNodePtr cur;
    
    int repeat_min;
    int repeat_max;
    int repeat_count;
    xmlNodePtr repeat_start;
    xmlNodePtr repeat_parent;

    faxtester_flush_handler_t flush_handler;
    void *flush_user_data;

    const uint8_t *image_buffer;
    int image_len;
    int image_ptr;
    int image_bit_ptr;

    uint8_t image[1000000];

    int ecm_frame_size;
    int corrupt_crc;

    int final_delayed;

    fax_modems_state_t modems;

    /*! \brief CED or CNG detector */
    modem_connect_tones_rx_state_t connect_rx;

    /*! If true, transmission is in progress */
    bool transmit;

    /*! \brief True if the short training sequence should be used. */
    bool short_train;

    /*! \brief The currently select receiver type */
    int current_rx_type;
    /*! \brief The currently select transmitter type */
    int current_tx_type;

    int wait_for_silence;

    int tone_state;
    int64_t tone_on_time;

    int64_t timer;
    int64_t timeout;

    bool test_for_call_clear;
    int call_clear_timer;

    bool far_end_cleared_call;

    int timein_x;
    int timeout_x;

    uint8_t awaited[1000];
    int awaited_len;

    char next_tx_file[1024];

    /*! \brief Error and flow logging control */
    logging_state_t logging;
};

#if defined(__cplusplus)
extern "C"
{
#endif

/*! Apply T.30 receive processing to a block of audio samples.
    \brief Apply T.30 receive processing to a block of audio samples.
    \param s The FAX tester context.
    \param amp The audio sample buffer.
    \param len The number of samples in the buffer.
    \return The number of samples unprocessed. This should only be non-zero if
            the software has reached the end of the FAX call.
*/
int faxtester_rx(faxtester_state_t *s, int16_t *amp, int len);

/*! Apply T.30 transmit processing to generate a block of audio samples.
    \brief Apply T.30 transmit processing to generate a block of audio samples.
    \param s The FAX tester context.
    \param amp The audio sample buffer.
    \param max_len The number of samples to be generated.
    \return The number of samples actually generated. This will be zero when
            there is nothing to send.
*/
int faxtester_tx(faxtester_state_t *s, int16_t *amp, int max_len);

void faxtester_set_tx_type(void *user_data, int type, int bit_rate, int short_train, int use_hdlc);

void faxtester_set_rx_type(void *user_data, int type, int bit_rate, int short_train, int use_hdlc);

void faxtest_set_rx_silence(faxtester_state_t *s);

void faxtester_send_hdlc_flags(faxtester_state_t *s, int flags);

void faxtester_send_hdlc_msg(faxtester_state_t *s, const uint8_t *msg, int len, int crc_ok);

void faxtester_set_flush_handler(faxtester_state_t *s, faxtester_flush_handler_t handler, void *user_data);

/*! Select whether silent audio will be sent when FAX transmit is idle.
    \brief Select whether silent audio will be sent when FAX transmit is idle.
    \param s The FAX tester context.
    \param transmit_on_idle True if silent audio should be output when the FAX transmitter is
           idle. False to transmit zero length audio when the FAX transmitter is idle. The default
           behaviour is false.
*/
void faxtester_set_transmit_on_idle(faxtester_state_t *s, int transmit_on_idle);

/*! Select whether talker echo protection tone will be sent for the image modems.
    \brief Select whether TEP will be sent for the image modems.
    \param s The FAX tester context.
    \param use_tep true if TEP should be sent.
*/
void faxtester_set_tep_mode(faxtester_state_t *s, int use_tep);

void faxtester_set_timeout(faxtester_state_t *s, int timeout);

SPAN_DECLARE(int) faxtester_next_step(faxtester_state_t *s);

/*! Get the logging context associated with a FAX tester context.
    \brief Get the logging context associated with a FAX tester context.
    \param s The FAX tester context.
    \return A pointer to the logging context */
SPAN_DECLARE(logging_state_t *) faxtester_get_logging_state(faxtester_state_t *s);

/*! Initialise a FAX tester context.
    \brief Initialise a FAX tester context.
    \param s The FAX tester context.
    \param test_file The name of the file of XML test scripts.
    \param test The name of the XML script test.
    \return A pointer to the FAX context, or NULL if there was a problem.
*/
faxtester_state_t *faxtester_init(faxtester_state_t *s, const char *test_file, const char *test);

/*! Release a FAX context.
    \brief Release a FAX context.
    \param s The FAX tester context.
    \return 0 for OK, else -1. */
int faxtester_release(faxtester_state_t *s);

/*! Free a FAX context.
    \brief Free a FAX context.
    \param s The FAX tester context.
    \return 0 for OK, else -1. */
int faxtester_free(faxtester_state_t *s);

#if defined(__cplusplus)
}
#endif

#endif
/*- End of file ------------------------------------------------------------*/
