#ifndef VOLUMECONTROL_H
#define VOLUMECONTROL_H

class VolumeControl {
public:
    float usrVolReq; // Variable to store the user requested volume
    float sysVolReq; // Variable to store the system volume
    bool tooLoud; // Flag to indicate if the volume is too loud

    // Constructor to initialize variables
    VolumeControl();

    // Function to set the system volume based on user request
    void setVolume(float usrVolReq);

    // Function to warn the user if the volume is too loud
    void warnUserIfTooLoud();
};

#endif // VOLUMECONTROL_H
