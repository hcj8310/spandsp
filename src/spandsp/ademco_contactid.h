/*
 * SpanDSP - a series of DSP components for telephony
 *
 * ademco_contactid.h  Ademco ContactID alarm protocol
 *
 * Written by Steve Underwood <steveu@coppice.org>
 *
 * Copyright (C) 2012 Steve Underwood
 *
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License version 2.1,
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

/*! \file */

#if !defined(_SPANDSP_ADEMCO_CONTACTID_H_)
#define _SPANDSP_ADEMCO_CONTACTID_H_

enum
{
    ADEMCO_CONTACTID_MESSAGE_TYPE_18 = 0x18,
    ADEMCO_CONTACTID_MESSAGE_TYPE_98 = 0x98
};

enum
{
    ADEMCO_CONTACTID_QUALIFIER_NEW_EVENT = 1,
    ADEMCO_CONTACTID_QUALIFIER_NEW_RESTORE = 3,
    ADEMCO_CONTACTID_QUALIFIER_STATUS_REPORT = 6
};

enum
{
    ADEMCO_CONTACTID_DATA_IS_ZONE = 0,
    ADEMCO_CONTACTID_DATA_IS_USER = 1
};

enum
{
    ADEMCO_CONTACTID_MEDICAL = 0x100,
    ADEMCO_CONTACTID_PERSONAL_EMERGENCY = 0x101,
    ADEMCO_CONTACTID_FAIL_TO_REPORT_IN = 0x102,
    ADEMCO_CONTACTID_FIRE = 0x110,
    ADEMCO_CONTACTID_SMOKE = 0x111,
    ADEMCO_CONTACTID_COMBUSTION = 0x112,
    ADEMCO_CONTACTID_WATER_FLOW = 0x113,
    ADEMCO_CONTACTID_HEAT = 0x114,
    ADEMCO_CONTACTID_PULL_STATION = 0x115,
    ADEMCO_CONTACTID_DUCT = 0x116,
    ADEMCO_CONTACTID_FLAME = 0x117,
    ADEMCO_CONTACTID_NEAR_ALARM_A = 0x118,
    ADEMCO_CONTACTID_PANIC = 0x120,
    ADEMCO_CONTACTID_DURESS = 0x121,
    ADEMCO_CONTACTID_SILENT = 0x122,
    ADEMCO_CONTACTID_AUDIBLE = 0x123,
    ADEMCO_CONTACTID_DURESS_ACCESS_GRANTED = 0x124,
    ADEMCO_CONTACTID_DURESS_EGRESS_GRANTED = 0x125,
    ADEMCO_CONTACTID_BURGLARY = 0x130,
    ADEMCO_CONTACTID_PERIMETER = 0x131,
    ADEMCO_CONTACTID_INTERIOR = 0x132,
    ADEMCO_CONTACTID_24_HOUR_SAFE = 0x133,
    ADEMCO_CONTACTID_ENTRY_EXIT = 0x134,
    ADEMCO_CONTACTID_DAY_NIGHT = 0x135,
    ADEMCO_CONTACTID_OUTDOOR = 0x136,
    ADEMCO_CONTACTID_TAMPER = 0x137,
    ADEMCO_CONTACTID_NEAR_ALARM_B = 0x138,
    ADEMCO_CONTACTID_INTRUSION_VERIFIER = 0x139,
    ADEMCO_CONTACTID_GENERAL_ALARM = 0x140,
    ADEMCO_CONTACTID_POLLING_LOOP_OPEN_A = 0x141,
    ADEMCO_CONTACTID_POLLING_LOOP_SHORT_A = 0x142,
    ADEMCO_CONTACTID_EXPANSION_MODULE_FAILURE_A = 0x143,
    ADEMCO_CONTACTID_SENSOR_TAMPER_A = 0x144,
    ADEMCO_CONTACTID_EXPANSION_MODULE_TAMPER = 0x145,
    ADEMCO_CONTACTID_SILENT_BURGLARY = 0x146,
    ADEMCO_CONTACTID_SENSOR_SUPERVISION_FAILURE = 0x147,
    ADEMCO_CONTACTID_24_HOUR_NONBURGLARY = 0x150,
    ADEMCO_CONTACTID_GAS_DETECTED = 0x151,
    ADEMCO_CONTACTID_REFRIGERATION = 0x152,
    ADEMCO_CONTACTID_LOSS_OF_HEAT = 0x153,
    ADEMCO_CONTACTID_WATER_LEAKAGE = 0x154,
    ADEMCO_CONTACTID_FOIL_BREAK = 0x155,
    ADEMCO_CONTACTID_DAY_TROUBLE = 0x156,
    ADEMCO_CONTACTID_LOW_BOTTLED_GAS_LEVEL = 0x157,
    ADEMCO_CONTACTID_HIGH_TEMP = 0x158,
    ADEMCO_CONTACTID_LOW_TEMP = 0x159,
    ADEMCO_CONTACTID_LOSS_OF_AIR_FLOW = 0x161,
    ADEMCO_CONTACTID_CARBON_MONOXIDE_DETECTED = 0x162,
    ADEMCO_CONTACTID_TANK_LEVEL = 0x163,
    ADEMCO_CONTACTID_FIRE_SUPERVISORY = 0x200,
    ADEMCO_CONTACTID_LOW_WATER_PRESSURE = 0x201,
    ADEMCO_CONTACTID_LOW_CO2 = 0x202,
    ADEMCO_CONTACTID_GATE_VALVE_SENSOR = 0x203,
    ADEMCO_CONTACTID_LOW_WATER_LEVEL = 0x204,
    ADEMCO_CONTACTID_PUMP_ACTIVATED = 0x205,
    ADEMCO_CONTACTID_PUMP_FAILURE = 0x206,
    ADEMCO_CONTACTID_SYSTEM_TROUBLE = 0x300,
    ADEMCO_CONTACTID_AC_LOSS = 0x301,
    ADEMCO_CONTACTID_LOW_SYSTEM_BATTERY = 0x302,
    ADEMCO_CONTACTID_RAM_CHECKSUM_BAD = 0x303,
    ADEMCO_CONTACTID_ROM_CHECKSUM_BAD = 0x304,
    ADEMCO_CONTACTID_SYSTEM_RESET = 0x305,
    ADEMCO_CONTACTID_PANEL_PROGRAMMING_CHANGED = 0x306,
    ADEMCO_CONTACTID_SELFTEST_FAILURE = 0x307,
    ADEMCO_CONTACTID_SYSTEM_SHUTDOWN = 0x308,
    ADEMCO_CONTACTID_BATTERY_TEST_FAILURE = 0x309,
    ADEMCO_CONTACTID_GROUND_FAULT = 0x310,
    ADEMCO_CONTACTID_BATTERY_MISSING_DEAD = 0x311,
    ADEMCO_CONTACTID_POWER_SUPPLY_OVERCURRENT = 0x312,
    ADEMCO_CONTACTID_ENGINEER_RESET = 0x313,
    ADEMCO_CONTACTID_SOUNDER_RELAY = 0x320,
    ADEMCO_CONTACTID_BELL_1 = 0x321,
    ADEMCO_CONTACTID_BELL_2 = 0x322,
    ADEMCO_CONTACTID_ALARM_RELAY = 0x323,
    ADEMCO_CONTACTID_TROUBLE_RELAY = 0x324,
    ADEMCO_CONTACTID_REVERSING_RELAY = 0x325,
    ADEMCO_CONTACTID_NOTIFICATION_APPLIANCE_CKT_3 = 0x326,
    ADEMCO_CONTACTID_NOTIFICATION_APPLIANCE_CKT_4 = 0x327,
    ADEMCO_CONTACTID_SYSTEM_PERIPHERAL_TROUBLE = 0x330,
    ADEMCO_CONTACTID_POLLING_LOOP_OPEN_B = 0x331,
    ADEMCO_CONTACTID_POLLING_LOOP_SHORT_B = 0x332,
    ADEMCO_CONTACTID_EXPANSION_MODULE_FAILURE_B = 0x333,
    ADEMCO_CONTACTID_REPEATER_FAILURE = 0x334,
    ADEMCO_CONTACTID_LOCAL_PRINTER_OUT_OF_PAPER = 0x335,
    ADEMCO_CONTACTID_LOCAL_PRINTER_FAILURE = 0x336,
    ADEMCO_CONTACTID_EXP_MODULE_DC_LOSS = 0x337,
    ADEMCO_CONTACTID_EXP_MODULE_LOW_BATTERY = 0x338,
    ADEMCO_CONTACTID_EXP_MODULE_RESET = 0x339,
    ADEMCO_CONTACTID_EXP_MODULE_TAMPER = 0x341,
    ADEMCO_CONTACTID_EXP_MODULE_AC_LOSS = 0x342,
    ADEMCO_CONTACTID_EXP_MODULE_SELFTEST_FAIL = 0x343,
    ADEMCO_CONTACTID_RF_RECEIVER_JAM_DETECT = 0x344,
    ADEMCO_CONTACTID_COMMUNICATION_TROUBLE = 0x350,
    ADEMCO_CONTACTID_TELCO_1_FAULT = 0x351,
    ADEMCO_CONTACTID_TELCO_2_FAULT = 0x352,
    ADEMCO_CONTACTID_LONG_RANGE_RADIO_TRANSMITTER_FAULT = 0x353,
    ADEMCO_CONTACTID_FAILURE_TO_COMMUNICATE_EVENT = 0x354,
    ADEMCO_CONTACTID_LOSS_OF_RADIO_SUPERVISION = 0x355,
    ADEMCO_CONTACTID_LOSS_OF_CENTRAL_POLLING = 0x356,
    ADEMCO_CONTACTID_LONG_RANGE_RADIO_VSWR_PROBLEM = 0x357,
    ADEMCO_CONTACTID_PROTECTION_LOOP = 0x370,
    ADEMCO_CONTACTID_PROTECTION_LOOP_OPEN = 0x371,
    ADEMCO_CONTACTID_PROTECTION_LOOP_SHORT = 0x372,
    ADEMCO_CONTACTID_FIRE_TROUBLE = 0x373,
    ADEMCO_CONTACTID_EXIT_ERROR_ALARM_ZONE = 0x374,
    ADEMCO_CONTACTID_PANIC_ZONE_TROUBLE = 0x375,
    ADEMCO_CONTACTID_HOLDUP_ZONE_TROUBLE = 0x376,
    ADEMCO_CONTACTID_SWINGER_TROUBLE = 0x377,
    ADEMCO_CONTACTID_CROSSZONE_TROUBLE = 0x378,
    ADEMCO_CONTACTID_SENSOR_TROUBLE = 0x380,
    ADEMCO_CONTACTID_LOSS_OF_SUPERVISION__RF = 0x381,
    ADEMCO_CONTACTID_LOSS_OF_SUPERVISION__RPM = 0x382,
    ADEMCO_CONTACTID_SENSOR_TAMPER_B = 0x383,
    ADEMCO_CONTACTID_RF_LOW_BATTERY = 0x384,
    ADEMCO_CONTACTID_SMOKE_DETECTOR_HIGH_SENSITIVITY = 0x385,
    ADEMCO_CONTACTID_SMOKE_DETECTOR_LOW_SENSITIVITY = 0x386,
    ADEMCO_CONTACTID_INTRUSION_DETECTOR_HIGH_SENSITIVITY = 0x387,
    ADEMCO_CONTACTID_INTRUSION_DETECTOR_LOW_SENSITIVITY = 0x388,
    ADEMCO_CONTACTID_SENSOR_SELFTEST_FAILURE = 0x389,
    ADEMCO_CONTACTID_SENSOR_WATCH_TROUBLE = 0x391,
    ADEMCO_CONTACTID_DRIFT_COMPENSATION_ERROR = 0x392,
    ADEMCO_CONTACTID_MAINTENANCE_ALERT = 0x393,
    ADEMCO_CONTACTID_OPEN_CLOSE = 0x400,
    ADEMCO_CONTACTID_OC_BY_USER = 0x401,
    ADEMCO_CONTACTID_GROUP_OC = 0x402,
    ADEMCO_CONTACTID_AUTOMATIC_OC = 0x403,
    ADEMCO_CONTACTID_LATE_TO_OC = 0x404,
    ADEMCO_CONTACTID_DEFERRED_OC = 0x405,
    ADEMCO_CONTACTID_CANCEL = 0x406,
    ADEMCO_CONTACTID_REMOTE_ARM_DISARM = 0x407,
    ADEMCO_CONTACTID_QUICK_ARM = 0x408,
    ADEMCO_CONTACTID_KEYSWITCH_OC = 0x409,
    ADEMCO_CONTACTID_ARMED_STAY = 0x441,
    ADEMCO_CONTACTID_KEYSWITCH_ARMED_STAY = 0x442,
    ADEMCO_CONTACTID_EXCEPTION_OC = 0x450,
    ADEMCO_CONTACTID_EARLY_OC = 0x451,
    ADEMCO_CONTACTID_LATE_OC = 0x452,
    ADEMCO_CONTACTID_FAILED_TO_OPEN = 0x453,
    ADEMCO_CONTACTID_FAILED_TO_CLOSE = 0x454,
    ADEMCO_CONTACTID_AUTOARM_FAILED = 0x455,
    ADEMCO_CONTACTID_PARTIAL_ARM = 0x456,
    ADEMCO_CONTACTID_EXIT_ERROR_USER = 0x457,
    ADEMCO_CONTACTID_USER_ON_PREMISES = 0x458,
    ADEMCO_CONTACTID_RECENT_CLOSE = 0x459,
    ADEMCO_CONTACTID_WRONG_CODE_ENTRY = 0x461,
    ADEMCO_CONTACTID_LEGAL_CODE_ENTRY = 0x462,
    ADEMCO_CONTACTID_REARM_AFTER_ALARM = 0x463,
    ADEMCO_CONTACTID_AUTOARM_TIME_EXTENDED = 0x464,
    ADEMCO_CONTACTID_PANIC_ALARM_RESET = 0x465,
    ADEMCO_CONTACTID_SERVICE_ON_OFF_PREMISES = 0x466,
    ADEMCO_CONTACTID_CALLBACK_REQUEST_MADE = 0x411,
    ADEMCO_CONTACTID_SUCCESSFUL_DOWNLOAD_ACCESS = 0x412,
    ADEMCO_CONTACTID_UNSUCCESSFUL_ACCESS = 0x413,
    ADEMCO_CONTACTID_SYSTEM_SHUTDOWN_COMMAND_RECEIVED = 0x414,
    ADEMCO_CONTACTID_DIALER_SHUTDOWN_COMMAND_RECEIVED = 0x415,
    ADEMCO_CONTACTID_SUCCESSFUL_UPLOAD = 0x416,
    ADEMCO_CONTACTID_ACCESS_DENIED = 0x421,
    ADEMCO_CONTACTID_ACCESS_REPORT_BY_USER = 0x422,
    ADEMCO_CONTACTID_FORCED_ACCESS = 0x423,
    ADEMCO_CONTACTID_EGRESS_DENIED = 0x424,
    ADEMCO_CONTACTID_EGRESS_GRANTED = 0x425,
    ADEMCO_CONTACTID_ACCESS_DOOR_PROPPED_OPEN = 0x426,
    ADEMCO_CONTACTID_ACCESS_POINT_DOOR_STATUS_MONITOR_TROUBLE = 0x427,
    ADEMCO_CONTACTID_ACCESS_POINT_REQUEST_TO_EXIT_TROUBLE = 0x428,
    ADEMCO_CONTACTID_ACCESS_PROGRAM_MODE_ENTRY = 0x429,
    ADEMCO_CONTACTID_ACCESS_PROGRAM_MODE_EXIT = 0x430,
    ADEMCO_CONTACTID_ACCESS_THREAT_LEVEL_CHANGE = 0x431,
    ADEMCO_CONTACTID_ACCESS_RELAY_TRIGGER_FAIL = 0x432,
    ADEMCO_CONTACTID_ACCESS_RTE_SHUNT = 0x433,
    ADEMCO_CONTACTID_ACCESS_DSM_SHUNT = 0x434,
    ADEMCO_CONTACTID_ACCESS_READER_DISABLE = 0x501,
    ADEMCO_CONTACTID_SOUNDER_RELAY_DISABLE = 0x520,
    ADEMCO_CONTACTID_BELL_1_DISABLE = 0x521,
    ADEMCO_CONTACTID_BELL_2_DISABLE = 0x522,
    ADEMCO_CONTACTID_ALARM_RELAY_DISABLE = 0x523,
    ADEMCO_CONTACTID_TROUBLE_RELAY_DISABLE = 0x524,
    ADEMCO_CONTACTID_REVERSING_RELAY_DISABLE = 0x525,
    ADEMCO_CONTACTID_NOTIFICATION_APPLIANCE_CKT_3_DISABLE = 0x526,
    ADEMCO_CONTACTID_NOTIFICATION_APPLIANCE_CKT_4_DISABLE = 0x527,
    ADEMCO_CONTACTID_MODULE_ADDED = 0x531,
    ADEMCO_CONTACTID_MODULE_REMOVED = 0x532,
    ADEMCO_CONTACTID_DIALER_DISABLED = 0x551,
    ADEMCO_CONTACTID_RADIO_TRANSMITTER_DISABLED = 0x552,
    ADEMCO_CONTACTID_REMOTE_UPLOAD_DOWNLOAD_DISABLED = 0x553,
    ADEMCO_CONTACTID_ZONE_SENSOR_BYPASS = 0x570,
    ADEMCO_CONTACTID_FIRE_BYPASS = 0x571,
    ADEMCO_CONTACTID_24_HOUR_ZONE_BYPASS = 0x572,
    ADEMCO_CONTACTID_BURG_BYPASS = 0x573,
    ADEMCO_CONTACTID_GROUP_BYPASS = 0x574,
    ADEMCO_CONTACTID_SWINGER_BYPASS = 0x575,
    ADEMCO_CONTACTID_ACCESS_ZONE_SHUNT = 0x576,
    ADEMCO_CONTACTID_ACCESS_POINT_BYPASS = 0x577,
    ADEMCO_CONTACTID_MANUAL_TRIGGER_TEST_REPORT = 0x601,
    ADEMCO_CONTACTID_PERIODIC_TEST_REPORT = 0x602,
    ADEMCO_CONTACTID_PERIODIC_RF_TRANSMISSION = 0x603,
    ADEMCO_CONTACTID_FIRE_TEST = 0x604,
    ADEMCO_CONTACTID_STATUS_REPORT_TO_FOLLOW = 0x605,
    ADEMCO_CONTACTID_LISTENIN_TO_FOLLOW = 0x606,
    ADEMCO_CONTACTID_WALK_TEST_MODE = 0x607,
    ADEMCO_CONTACTID_PERIODIC_TEST__SYSTEM_TROUBLE_PRESENT = 0x608,
    ADEMCO_CONTACTID_VIDEO_TRANSMITTER_ACTIVE = 0x609,
    ADEMCO_CONTACTID_POINT_TESTED_OK = 0x611,
    ADEMCO_CONTACTID_POINT_NOT_TESTED = 0x612,
    ADEMCO_CONTACTID_INTRUSION_ZONE_WALK_TESTED = 0x613,
    ADEMCO_CONTACTID_FIRE_ZONE_WALK_TESTED = 0x614,
    ADEMCO_CONTACTID_PANIC_ZONE_WALK_TESTED = 0x615,
    ADEMCO_CONTACTID_SERVICE_REQUEST = 0x616,
    ADEMCO_CONTACTID_EVENT_LOG_RESET = 0x621,
    ADEMCO_CONTACTID_EVENT_LOG_50PC_FULL = 0x622,
    ADEMCO_CONTACTID_EVENT_LOG_90PC_FULL = 0x623,
    ADEMCO_CONTACTID_EVENT_LOG_OVERFLOW = 0x624,
    ADEMCO_CONTACTID_TIME_DATE_RESET = 0x625,
    ADEMCO_CONTACTID_TIME_DATE_INACCURATE = 0x626,
    ADEMCO_CONTACTID_PROGRAM_MODE_ENTRY = 0x627,
    ADEMCO_CONTACTID_PROGRAM_MODE_EXIT = 0x628,
    ADEMCO_CONTACTID_32_HOUR_EVENT_LOG_MARKER = 0x629,
    ADEMCO_CONTACTID_SCHEDULE_CHANGE = 0x630,
    ADEMCO_CONTACTID_EXCEPTION_SCHEDULE_CHANGE = 0x631,
    ADEMCO_CONTACTID_ACCESS_SCHEDULE_CHANGE = 0x632,
    ADEMCO_CONTACTID_SENIOR_WATCH_TROUBLE = 0x641,
    ADEMCO_CONTACTID_LATCHKEY_SUPERVISION = 0x642,
    ADEMCO_CONTACTID_RESERVED_FOR_ADEMCO_USE_1 = 0x651,
    ADEMCO_CONTACTID_RESERVED_FOR_ADEMCO_USE_2 = 0x652,
    ADEMCO_CONTACTID_RESERVED_FOR_ADEMCO_USE_3 = 0x653,
    ADEMCO_CONTACTID_SYSTEM_INACTIVITY = 0x654,
    ADEMCO_CONTACTID_DOWNLOAD_ABORT = 0x900,
    ADEMCO_CONTACTID_DOWNLOAD_START_END = 0x901,
    ADEMCO_CONTACTID_DOWNLOAD_INTERRUPTED = 0x902,
    ADEMCO_CONTACTID_AUTOCLOSE_WITH_BYPASS = 0x910,
    ADEMCO_CONTACTID_BYPASS_CLOSING = 0x911,
    ADEMCO_CONTACTID_32_HOUR_NO_READ_OF_EVENT_LOG = 0x999
};

typedef struct ademco_contactid_sender_state_s ademco_contactid_sender_state_t;

typedef struct ademco_contactid_receiver_state_s ademco_contactid_receiver_state_t;

typedef struct
{
    int acct;
    int mt;
    int q;
    int xyz;
    int gg;
    int ccc;
} ademco_contactid_report_t;

typedef void (*ademco_contactid_report_func_t)(void *user_data, const ademco_contactid_report_t *report);

#if defined(__cplusplus)
extern "C"
{
#endif

SPAN_DECLARE(const char *) ademco_contactid_msg_qualifier_to_str(int q);

SPAN_DECLARE(const char *) ademco_contactid_event_to_str(int xyz);

SPAN_DECLARE(int) encode_msg(char buf[], const ademco_contactid_report_t *report);

SPAN_DECLARE(int) decode_msg(ademco_contactid_report_t *report, const char buf[]);

SPAN_DECLARE(int) ademco_contactid_receiver_log_msg(ademco_contactid_receiver_state_t *s, const ademco_contactid_report_t *report);

SPAN_DECLARE(int) ademco_contactid_receiver_tx(ademco_contactid_receiver_state_t *s, int16_t amp[], int max_samples);

SPAN_DECLARE(int) ademco_contactid_receiver_rx(ademco_contactid_receiver_state_t *s, const int16_t amp[], int samples);

SPAN_DECLARE(int) ademco_contactid_receiver_fillin(ademco_contactid_receiver_state_t *s, int samples);

SPAN_DECLARE(logging_state_t *) ademco_contactid_receiver_get_logging_state(ademco_contactid_receiver_state_t *s);

SPAN_DECLARE(void) ademco_contactid_receiver_set_realtime_callback(ademco_contactid_receiver_state_t *s,
                                                                   ademco_contactid_report_func_t callback,
                                                                   void *user_data);

SPAN_DECLARE(ademco_contactid_receiver_state_t *) ademco_contactid_receiver_init(ademco_contactid_receiver_state_t *s,
                                                                                 ademco_contactid_report_func_t callback,
                                                                                 void *user_data);

SPAN_DECLARE(int) ademco_contactid_receiver_release(ademco_contactid_receiver_state_t *s);

SPAN_DECLARE(int) ademco_contactid_receiver_free(ademco_contactid_receiver_state_t *s);



SPAN_DECLARE(int) ademco_contactid_sender_tx(ademco_contactid_sender_state_t *s, int16_t amp[], int max_samples);

SPAN_DECLARE(int) ademco_contactid_sender_rx(ademco_contactid_sender_state_t *s, const int16_t amp[], int samples);

SPAN_DECLARE(int) ademco_contactid_sender_fillin(ademco_contactid_sender_state_t *s, int samples);

SPAN_DECLARE(int) ademco_contactid_sender_put(ademco_contactid_sender_state_t *s, const ademco_contactid_report_t *report);

SPAN_DECLARE(logging_state_t *) ademco_contactid_sender_get_logging_state(ademco_contactid_sender_state_t *s);

SPAN_DECLARE(void) ademco_contactid_sender_set_realtime_callback(ademco_contactid_sender_state_t *s,
                                                                 span_tone_report_func_t callback,
                                                                 void *user_data);

SPAN_DECLARE(ademco_contactid_sender_state_t *) ademco_contactid_sender_init(ademco_contactid_sender_state_t *s,
                                                                             span_tone_report_func_t callback,
                                                                             void *user_data);

SPAN_DECLARE(int) ademco_contactid_sender_release(ademco_contactid_sender_state_t *s);

SPAN_DECLARE(int) ademco_contactid_sender_free(ademco_contactid_sender_state_t *s);

#if defined(__cplusplus)
}
#endif

#endif
/*- End of file ------------------------------------------------------------*/
