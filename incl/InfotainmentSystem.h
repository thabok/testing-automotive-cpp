#ifndef INFOTAINMENT_SYSTEM_H
#define INFOTAINMENT_SYSTEM_H

#include <exception>

#include "VolumeControl.h"
#include "NavigationSystem.h"
#include "BluetoothConnector.h"
#include "DriverAssistance.h"
#include "EmergencyCallSystem.h"
#include "SystemStateReporter.h"  // C header

/**
 * @brief This class uses VolumeControl, NavigationSystem, BluetoothConnector,
 * DriverAssistance, and EmergencyCallSystem to provide features via its "stepFunction()"
 * that leverages these components.
 */
class InfotainmentSystem : public VolumeControl, public NavigationSystem, public BluetoothConnector, public DriverAssistance, public EmergencyCallSystem {
public:
    /** Indicates that an error has happened (e.g. invalid bt connection attempt) */
    bool errorFlag;

    InfotainmentSystem();

    /**
     * @brief Leverages the components VolumeControl, NavigationSystem, BluetoothConnector,
     * DriverAssistance, and EmergencyCallSystem to provide a cross-functional feature.
     */
    void stepFunction();
};

#endif /* INFOTAINMENT_SYSTEM_H */

