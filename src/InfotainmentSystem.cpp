#include "InfotainmentSystem.h"

InfotainmentSystem::InfotainmentSystem() : VolumeControl(), NavigationSystem(), BluetoothConnector() {}

void InfotainmentSystem::stepFunction() {
    // Adjust volume
    VolumeControl::setVolume();

    // Activate Navigation
    NavigationSystem::startNavigation();

    // Driver pamic mode: if music is too loud -> stop navigation
    if (VolumeControl::tooLoud || NavigationSystem::stopRequested) {
        NavigationSystem::stopNavigation();
        updateSystemState(NAVIGATION_OFF); // adapt system status
    }

    if (BluetoothConnector::connectionRequestActive()) {
        // connect bluetooth device if connection is pending and no connection is active
        if (!BluetoothConnector::isBluetoothConnected) {
            BluetoothConnector::connectDevice();
        }
        if (VolumeControl::tooLoud) {
            VolumeControl::saturateVolume();
        }
    } else if (BluetoothConnector::isBluetoothConnected) {
        // disconnect bluetooth device if no connection is pending and a connection is active
        BluetoothConnector::disconnectDevice();
        updateSystemState(BLUETOOTH_OFF);
    }

    // adapt system status
    if (BluetoothConnector::isBluetoothConnected) {
        updateSystemState(BLUETOOTH_ON);
    }
    if (NavigationSystem::isNavigationActive) {
        updateSystemState(NAVIGATION_ON);
    }
}
