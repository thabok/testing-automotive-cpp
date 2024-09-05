#include "VolumeControl.h"

// Constructor to initialize variables
VolumeControl::VolumeControl() : usrVolReq(0), sysVolReq(0), tooLoud(false) {}

// Function to set the system volume based on user request
void VolumeControl::setVolume(float usrVolReq) {
    if (usrVolReq >= 0 && usrVolReq <= 100) {
        sysVolReq = usrVolReq;
    }
}

// Function to warn the user if the volume is too loud
void VolumeControl::warnUserIfTooLoud() {
    tooLoud = (sysVolReq > 50);
}
