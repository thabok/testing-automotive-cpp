#include "InfotainmentSystem.h"

InfotainmentSystem::InfotainmentSystem() : VolumeControl(), NavigationSystem(), BluetoothConnector() {}

void InfotainmentSystem::stepFunction() {
    // Adjust volume
    VolumeControl::setVolume();

    // Activate Navigation
    NavigationSystem::startNavigation();

    // Driver panic mode: if music is too loud -> stop navigation
    if (VolumeControl::tooLoud || NavigationSystem::stopRequested) {
        NavigationSystem::stopNavigation();
    }

    // Bluetooth connection
    if (BluetoothConnector::connectionRequestActive()) {
        // connect bluetooth device if connection is pending
        try {
            BluetoothConnector::connectDevice();
        } catch (const std::exception& e) {
            InfotainmentSystem::errorFlag = true;
        }

        if (VolumeControl::tooLoud) {
            VolumeControl::saturateVolume();
        }
    } else if (BluetoothConnector::isBluetoothConnected) {
        // disconnect bluetooth device if no connection is pending and a connection is active
        BluetoothConnector::disconnectDevice();
    }

    // adapt system status
    SystemState btState = BluetoothConnector::isBluetoothConnected ? BLUETOOTH_ON : BLUETOOTH_OFF;
    SystemState navState = NavigationSystem::isNavigationActive ? NAVIGATION_ON : NAVIGATION_OFF;
    updateSystemState(btState);
    updateSystemState(navState);
}
