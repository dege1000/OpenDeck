/*

OpenDECK library v1.3
File: SysEx.h
Last revision date: 2014-12-25
Author: Igor Petrovic

*/


#ifndef SYSEX_H_
#define SYSEX_H_

//sysex

//manufacturer ID bytes
#define SYS_EX_M_ID_0                           0x00
#define SYS_EX_M_ID_1                           0x53
#define SYS_EX_M_ID_2                           0x43

//message length
#define SYS_EX_ML_REQ_HANDSHAKE                 0x05
#define SYS_EX_ML_REQ_STANDARD                  0x09
#define SYS_EX_ML_RES_BASIC                     0x08

#define SYS_EX_ENABLE                           0x01
#define SYS_EX_DISABLE                          0x00

#define SYS_EX_ACK                              0x41
#define SYS_EX_NACK                             0x46

typedef enum {

    //message wish
    SYS_EX_WISH_START,
    SYS_EX_WISH_GET = SYS_EX_WISH_START,
    SYS_EX_WISH_SET,
    SYS_EX_WISH_RESTORE,
    SYS_EX_WISH_END

} sysExWish;

typedef enum {

    //wanted data amount
    SYS_EX_AMOUNT_START,
    SYS_EX_AMOUNT_SINGLE = SYS_EX_AMOUNT_START,
    SYS_EX_AMOUNT_ALL,
    SYS_EX_AMOUNT_END

} sysExAmount;

typedef enum {

    //message types
    SYS_EX_MT_START,
    SYS_EX_MT_MIDI_CHANNEL = SYS_EX_MT_START,
    SYS_EX_MT_FEATURES,
    SYS_EX_MT_BUTTONS,
    SYS_EX_MT_ANALOG,
    SYS_EX_MT_LEDS,
    SYS_EX_MT_ENCODERS,
    SYS_EX_MT_ALL,
    SYS_EX_MT_END

} sysExMessageType;

typedef enum {

    SYS_EX_MC_START,
    SYS_EX_MC_BUTTON_NOTE = SYS_EX_MC_START,
    SYS_EX_MC_PROGRAM_CHANGE,
    SYS_EX_MC_CC,
    SYS_EX_MC_PITCH_BEND,
    SYS_EX_MC_INPUT,
    SYS_EX_MC_END

} sysExMIDIchannels;

typedef enum {

    //features
    SYS_EX_MST_FEATURES_START,
    SYS_EX_MST_FEATURES_MIDI = SYS_EX_MST_FEATURES_START,
    SYS_EX_MST_FEATURES_BUTTONS,
    SYS_EX_MST_FEATURES_LEDS,
    SYS_EX_MST_FEATURES_ANALOG,
    SYS_EX_MST_FEATURES_ENCODERS,
    SYS_EX_MST_FEATURES_END

} sysExFeatures;

typedef enum {

    SYS_EX_FEATURES_MIDI_START,
    SYS_EX_FEATURES_MIDI_STANDARD_NOTE_OFF = SYS_EX_FEATURES_MIDI_START,
    SYS_EX_FEATURES_MIDI_END

} sysExMIDIfeatures;

typedef enum {

    SYS_EX_FEATURES_LEDS_START,
    SYS_EX_FEATURES_LEDS_END

} sysExLEDfeatures;

typedef enum {

    SYS_EX_FEATURES_ANALOG_START,
    SYS_EX_FEATURES_ANALOG_END

} sysExAnalogFeatures;

typedef enum {

    SYS_EX_FEATURES_ENCODERS_START,
    SYS_EX_FEATURES_ENCODERS_END

} sysExEncodersfeatures;

typedef enum {

    SYS_EX_MST_BUTTONS_START,
    SYS_EX_MST_BUTTONS_HW_P = SYS_EX_MST_BUTTONS_START,
    SYS_EX_MST_BUTTONS_TYPE,
    SYS_EX_MST_BUTTONS_PROGRAM_CHANGE_ENABLED,
    SYS_EX_MST_BUTTONS_NOTE,
    SYS_EX_MST_BUTTONS_END

} sysExMessageSubTypeButtons;

typedef enum {

    SYS_EX_MST_ANALOG_START,
    SYS_EX_MST_ANALOG_HW_P = SYS_EX_MST_ANALOG_START,
    SYS_EX_MST_ANALOG_ENABLED,
    SYS_EX_MST_ANALOG_TYPE,
    SYS_EX_MST_ANALOG_INVERTED,
    SYS_EX_MST_ANALOG_NUMBER,
    SYS_EX_MST_ANALOG_LOWER_LIMIT,
    SYS_EX_MST_ANALOG_UPPER_LIMIT,
    SYS_EX_MST_ANALOG_END

} sysExMessageSubTypeAnalog;

typedef enum {

    SYS_EX_MST_LEDS_START,
    SYS_EX_MST_LEDS_HW_P = SYS_EX_MST_LEDS_START,
    SYS_EX_MST_LEDS_ACT_NOTE,
    SYS_EX_MST_LEDS_START_UP_NUMBER,
    SYS_EX_MST_LEDS_STATE,
    SYS_EX_MST_LEDS_END

} sysExMessageSubTypeLED;

typedef enum {

    SYS_EX_LEDS_HW_P_START,
    SYS_EX_LEDS_HW_P_TOTAL_NUMBER = SYS_EX_LEDS_HW_P_START,
    SYS_EX_LEDS_HW_P_BLINK_TIME,
    SYS_EX_LEDS_HW_P_START_UP_SWITCH_TIME,
    SYS_EX_LEDS_HW_P_START_UP_ROUTINE,
    SYS_EX_LEDS_HW_P_FADE_TIME,
    SYS_EX_LEDS_HW_P_END

} sysEXLEDHwParameter;

typedef enum {

    SYS_EX_LEDS_STATE_START,
    SYS_EX_LEDS_STATE_C_OFF = SYS_EX_LEDS_STATE_START,
    SYS_EX_LEDS_STATE_C_ON,
    SYS_EX_LEDS_STATE_B_OFF,
    SYS_EX_LEDS_STATE_B_ON,
    SYS_EX_LEDS_STATE_END

} sysExLEDstates;

typedef enum {

    SYS_EX_MST_ENCODERS_START,
    SYS_EX_MST_ENCODERS_HW_P = SYS_EX_MST_ENCODERS_START,
    SYS_EX_MST_ENCODERS_ENABLED,
    SYS_EX_MST_ENCODERS_INVERTED,
    SYS_EX_MST_ENCODERS_ENCODING_MODE,
    SYS_EX_MST_ENCODERS_FAST_MODE,
    SYS_EX_MST_ENCODERS_PULSES_PER_STEP,
    SYS_EX_MST_ENCODERS_NUMBER,
    SYS_EX_MST_ENCODERS_END

} sysExEncoders;

typedef enum {

    SYS_EX_ENCODERS_HW_P_START,
    SYS_EX_ENCODERS_HW_P_END

} sysExEncodersHwParameters;

typedef enum {

    SYS_EX_ANALOG_HW_P_START,
    SYS_EX_ANALOG_HW_P_END

} sysExAnalogHwParameters;

typedef enum {

    SYS_EX_ERROR_HANDSHAKE,
    SYS_EX_ERROR_WISH,
    SYS_EX_ERROR_AMOUNT,
    SYS_EX_ERROR_MT,
    SYS_EX_ERROR_MST,
    SYS_EX_ERROR_PARAMETER,
    SYS_EX_ERROR_NEW_PARAMETER,
    SYS_EX_ERROR_MESSAGE_LENGTH,
    SYS_EX_ERROR_NOT_SUPPORTED,
    SYS_EX_ERROR_EEPROM,

} sysExError;

typedef enum {

    SYS_EX_MS_M_ID_0 = 1,
    SYS_EX_MS_M_ID_1 = 2,
    SYS_EX_MS_M_ID_2 = 3,
    SYS_EX_MS_WISH = 4,
    SYS_EX_MS_AMOUNT = 5,
    SYS_EX_MS_MT = 6,
    SYS_EX_MS_MST = 7,
    SYS_EX_MS_PARAMETER_ID = 8,
    SYS_EX_MS_NEW_PARAMETER_ID_SINGLE = 9,
    SYS_EX_MS_NEW_PARAMETER_ID_ALL = 8,

} sysExMessageByteOrder;

#endif