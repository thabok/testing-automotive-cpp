#ifndef INFOTAINMENT_SYSTEM_H
#define INFOTAINMENT_SYSTEM_H

#include <exception>

#include "VolumeControl.h"
#include "NavigationSystem.h"
#include "BluetoothConnector.h"
#include "SystemStateReporter.h"  // C header

/**
 * @brief This class uses VolumeControl, NavigationSystem and BluetoothConnector
 * to provide feature via its "stepFunction()" that leverages these components.
 */
class InfotainmentSystem : public VolumeControl, public NavigationSystem, public BluetoothConnector {
public:
    /** Indicates that an error has happened (e.g. invalid bt connection attempt) */
    bool errorFlag;

    InfotainmentSystem();

    /**
     * @brief Leverages the components VolumeControl, NavigationSystem and BluetoothConnector
     * to provide a cross functional feature.
     */
    void stepFunction();
};

#endif /* INFOTAINMENT_SYSTEM_H */
