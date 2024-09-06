#ifndef INFOTAINMENT_SYSTEM_H
#define INFOTAINMENT_SYSTEM_H

#include "VolumeControl.h"
#include "NavigationSystem.h"
#include "BluetoothConnector.h"
#include "SystemStateReporter.h"  // C header


class InfotainmentSystem : public VolumeControl, public NavigationSystem, public BluetoothConnector {
public:
    InfotainmentSystem();
    void stepFunction();
};

#endif /* INFOTAINMENT_SYSTEM_H */
