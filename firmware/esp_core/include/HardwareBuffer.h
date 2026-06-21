//
// Created by srira on 6/19/2026.
//

#ifndef ESP_CORE_HARDWARESTRUCTS_H
#define ESP_CORE_HARDWARESTRUCTS_H
#include <array>
#include <functional>
#include <string>
#include <unordered_map>

// Contains all the hardware structs / buffers to be edited then updated to the physical
// components at once

// ALL enum vars (what each hardware component is set to show)
// 8 digit displays
enum class KSP_Display_Outputs {APO, ALT, PER, SP_DV};
enum class FSX_Display_Outputs {};
// 4 digit display is burn time for KSP, ___ for FSX
// annunciator panel led
enum class KSP_Annunciator_Outputs {IMPACT_COURSE, WEAK_SIG, BAT_LOW, ESCAPE_V, CHECK_BURN_DV, MONO_LOW, GFORCE, TMP_HIGH};
enum class FSX_Annunciator_Outputs {};
// buttons
enum class KSP_Buttons {
    PROGRADE, RETROGRADE, TARGET, BURN, NORMAL, // SAS lock buttons
    MAX_THRUST, KILL_THRUST,                    // thrust buttons
    STAGE,

};

// each component has a pin
struct Component {
    uint8_t pin{};
    bool handledByOtherESP;

    // setting pin to 0 marks it as a component that is handled by the other esp
    void setPin(const uint8_t espPin) {
        if (espPin == 0) handledByOtherESP = true;
        else pin = espPin;
    }

    Component(const uint8_t pin) : pin(pin), handledByOtherESP(false) {}
    virtual ~Component() = default;
};

// 8 digit display
struct Display8 : Component {
    std::array<int, 8> value{};

    Display8() : Component(255) {}
};


// 4 digit display
struct Display4 : Component {
    std::array<int, 4> value{};

    Display4() : Component(255) {}
};

// led (SINGLE LEDs)
struct Led : Component {
    bool on;

    Led(const uint8_t ledPin) : Component(ledPin), on(false) {}
    Led() : Component(255), on(false) {}
};

// Button WITH Led
struct Button : Component {
    uint8_t ledPin;
    bool ledOn;

    std::function<void()> onClick;

    void setPin(const uint8_t buttonPin, const uint8_t LedPin) {
        pin = buttonPin; ledPin = LedPin;
    }

    Button(uint8_t buttonPin, uint8_t ledPin, const std::function<void()> &onClick) :
        Component(buttonPin), ledPin(ledPin), ledOn(false), onClick(onClick) {}
    Button() : Component(255), ledPin(255), ledOn(false) {}
};

// switch
struct Switch : Component {
    bool state;

    std::function<void()> onChange;

    Switch(uint8_t buttonPin, const std::function<void()> &onChange) :
        Component(buttonPin), state(false), onChange(onChange) {}
};


class HardwareBuffer {

    // --------------- OUTPUTS ---------------

    // All 8 digit displays where,
    std::unordered_map<int, Display8> telemDisplayPanel;

    Display4 throttlePanelDisplay;

    // 2x4 Annunciator panel where,
    std::unordered_map<int, Led> annunciatorPanel;

    // led in staging
    Led stagingLed;

    // ALL buttons (with leds)
    std::unordered_map<int, Button> Buttons;


    void clear();

    // initialize all hardware devices for KSP (kerbal space program) settings
    void initKSP();

};


#endif //ESP_CORE_HARDWARESTRUCTS_H