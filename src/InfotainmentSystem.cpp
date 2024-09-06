#include "InfotainmentSystem.h"

InfotainmentSystem::InfotainmentSystem() : VolumeControl(), NavigationSystem(), BluetoothConnector() {}

void InfotainmentSystem::stepFunction() {
    // Adjust volume
    VolumeControl::setVolume();

    // Activate Navigation
    NavigationSystem::startNavigation();

    // Panicking driver mode: if music is too loud -> stop navigation
    if (VolumeControl::tooLoud) {
        NavigationSystem::stopNavigation();
        updateSystemState(NAVIGATION_OFF); // adapt system status
    }

    // connect bluetooth device if connection is pending
    if (BluetoothConnector::connectionRequestActive()) {
        // if (VolumeControl::tooLoud) {
        //     VolumeControl::saturateVolume();
        // }
        BluetoothConnector::connectDevice();
    }

    // adapt system status
    if (BluetoothConnector::isBluetoothConnected) {
        updateSystemState(BLUETOOTH_ON);
    }

    if (NavigationSystem::isNavigationActive) {
        updateSystemState(NAVIGATION_ON); // adapt system status
    }
}
