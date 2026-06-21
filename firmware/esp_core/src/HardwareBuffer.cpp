//
// Created by srira on 6/19/2026.
//

#include "../include/HardwareBuffer.h"
#include "Pin.h"
#include "HandleInputKSP.h"
#include <functional>

void HardwareBuffer::clear() {
    telemDisplayPanel.clear();
    annunciatorPanel.clear();
    Buttons.clear();
}

void HardwareBuffer::initKSP() {
    clear();

    // init each display panel display. all displays handled by other esp
    // so pin=0 bc they don't have a pin on this esp
    telemDisplayPanel[static_cast<int>(KSP_Display_Outputs::APO)].setPin(0);
    telemDisplayPanel[static_cast<int>(KSP_Display_Outputs::ALT)].setPin(0);
    telemDisplayPanel[static_cast<int>(KSP_Display_Outputs::PER)].setPin(0);
    telemDisplayPanel[static_cast<int>(KSP_Display_Outputs::SP_DV)].setPin(0);

    // one display on the throttle panel to burn time
    throttlePanelDisplay.setPin(0);

    // each annunciator panel has same led (sent to a led strip handled in hal)
    annunciatorPanel[static_cast<int>(KSP_Annunciator_Outputs::IMPACT_COURSE)].setPin(Pin::ANN_PANEL);
    annunciatorPanel[static_cast<int>(KSP_Annunciator_Outputs::WEAK_SIG)].setPin(Pin::ANN_PANEL);
    annunciatorPanel[static_cast<int>(KSP_Annunciator_Outputs::BAT_LOW)].setPin(Pin::ANN_PANEL);
    annunciatorPanel[static_cast<int>(KSP_Annunciator_Outputs::ESCAPE_V)].setPin(Pin::ANN_PANEL);
    annunciatorPanel[static_cast<int>(KSP_Annunciator_Outputs::CHECK_BURN_DV)].setPin(Pin::ANN_PANEL);
    annunciatorPanel[static_cast<int>(KSP_Annunciator_Outputs::MONO_LOW)].setPin(Pin::ANN_PANEL);
    annunciatorPanel[static_cast<int>(KSP_Annunciator_Outputs::GFORCE)].setPin(Pin::ANN_PANEL);
    annunciatorPanel[static_cast<int>(KSP_Annunciator_Outputs::TMP_HIGH)].setPin(Pin::ANN_PANEL);

    // led in staging to be used to show staging mode
    stagingLed.setPin(Pin::STAGING_LED);

    // SAS lock buttons
    Buttons[static_cast<int>(KSP_Buttons::PROGRADE)] =
        Button(Pin::SAS_LOCK_1_BTN, Pin::SAS_LOCK_1_BTN_LED, HandleInputKSP::cb_ProgradeLock);
    Buttons[static_cast<int>(KSP_Buttons::RETROGRADE)] =
        Button(Pin::SAS_LOCK_2_BTN, Pin::SAS_LOCK_2_BTN_LED, HandleInputKSP::cb_RetrogradeLock);
    Buttons[static_cast<int>(KSP_Buttons::TARGET)] =
        Button(Pin::SAS_LOCK_3_BTN, Pin::SAS_LOCK_3_BTN_LED, HandleInputKSP::cb_TargetLock);
    Buttons[static_cast<int>(KSP_Buttons::BURN)] =
        Button(Pin::SAS_LOCK_4_BTN, Pin::SAS_LOCK_4_BTN_LED, HandleInputKSP::cb_BurnLock);
    Buttons[static_cast<int>(KSP_Buttons::NORMAL)] =
        Button(Pin::SAS_LOCK_5_BTN, Pin::SAS_LOCK_5_BTN_LED, HandleInputKSP::cb_NormalLock);

    // thrust buttons
    Buttons[static_cast<int>(KSP_Buttons::MAX_THRUST)] =
        Button(Pin::MAX_THRUST_BTN, Pin::MAX_THRUST_BTN_LED, HandleInputKSP::cb_MaxThrust);
    Buttons[static_cast<int>(KSP_Buttons::KILL_THRUST)] =
        Button(Pin::KILL_THRUST_BTN, Pin::KILL_THRUST_BTN_LED, HandleInputKSP::cb_KillThrust);

    // stage button
    Buttons[static_cast<int>(KSP_Buttons::STAGE)] =
        Button(Pin::STAGE_BTN, Pin::STAGE_BTN_LED, HandleInputKSP::cb_Stage);



}
