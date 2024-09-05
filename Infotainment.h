#ifndef INFOTAINMENT_H
#define INFOTAINMENT_H

#include "VolumeControl.h"
#include "NavigationSystem.h"
#include "Bluetooth.h"

class Infotainment : public VolumeControl, public NavigationSystem, public Bluetooth {
public:
    // Constructor to initialize variables
    Infotainment();

    // Step function to call relevant functions
    void step();
};

#endif // INFOTAINMENT_H
