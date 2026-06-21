#ifndef AEROLAP_PINS_H
#define AEROLAP_PINS_H

#include <cstdint>

// Specifies the pin values for components
namespace Pin {
    // constexpr tells the compiler to swap these at compile-time.
    // saves memory

    // onboard led
    constexpr uint8_t ONBOARD_LED = 2;

    constexpr uint8_t ANN_PANEL = 1;
    constexpr uint8_t STAGING_LED = 1;

    // buttons sas lock
    constexpr uint8_t SAS_LOCK_1_BTN = 1;
    constexpr uint8_t SAS_LOCK_2_BTN = 1;
    constexpr uint8_t SAS_LOCK_3_BTN = 1;
    constexpr uint8_t SAS_LOCK_4_BTN = 1;
    constexpr uint8_t SAS_LOCK_5_BTN = 1;
    constexpr uint8_t SAS_LOCK_1_BTN_LED = 1;
    constexpr uint8_t SAS_LOCK_2_BTN_LED = 1;
    constexpr uint8_t SAS_LOCK_3_BTN_LED = 1;
    constexpr uint8_t SAS_LOCK_4_BTN_LED = 1;
    constexpr uint8_t SAS_LOCK_5_BTN_LED = 1;

    constexpr uint8_t MAX_THRUST_BTN = 1;
    constexpr uint8_t MAX_THRUST_BTN_LED = 1;
    constexpr uint8_t KILL_THRUST_BTN = 1;
    constexpr uint8_t KILL_THRUST_BTN_LED = 1;

    constexpr uint8_t STAGE_BTN = 1;
    constexpr uint8_t STAGE_BTN_LED = 1;

    //
    // // LED Bars
    // constexpr uint8_t TOP_BAR    = 13;
    // constexpr uint8_t BOTTOM_BAR = 12;
    //
    // // 7-Segment Displays (Shift Register)
    // constexpr uint8_t SCLK       = 14;
    // constexpr uint8_t RCLK       = 27;
    // constexpr uint8_t LEFT_DIO   = 26;
    // constexpr uint8_t CENTER_DIO = 25;
    // constexpr uint8_t RIGHT_DIO  = 33;
    //
    // // rotary encoder
    // constexpr uint8_t ENCODER_CLK = 32; // TODO: find the actual pins
    // constexpr uint8_t ENCODER_DT  = 15; // TODO: find the actual pins
    //
    // // button for individual uses within each dashboard mode
    // constexpr uint8_t BUTTON_1 = 4; // TODO: find the actual pins
}

#endif