//
// Created by srira on 6/20/2026.
//

#ifndef ESP_CORE_HANDLEINPUTKSP_H
#define ESP_CORE_HANDLEINPUTKSP_H

#include "HardwareBuffer.h"

namespace HandleInputKSP {

    // callback for SAS lock buttons
    void cb_ProgradeLock();
    void cb_RetrogradeLock();
    void cb_TargetLock();
    void cb_BurnLock();
    void cb_NormalLock();

    void cb_MaxThrust();
    void cb_KillThrust();
    void cb_Stage();

};


#endif //ESP_CORE_HANDLEINPUTKSP_H