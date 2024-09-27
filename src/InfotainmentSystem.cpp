#include "InfotainmentSystem.h"

InfotainmentSystem::InfotainmentSystem() : VolumeControl(), NavigationSystem(), BluetoothConnector(), DriverAssistance(), EmergencyCallSystem() {}

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
        try {
            BluetoothConnector::connectDevice();
        } catch (const std::exception& e) {
            InfotainmentSystem::errorFlag = true;
        }

        if (VolumeControl::tooLoud) {
            VolumeControl::saturateVolume();
        }
    } else if (BluetoothConnector::isBluetoothConnected) {
        BluetoothConnector::disconnectDevice();
    }

    // Driver assistance checks
    float currentSpeed = /* get current speed */;
    float distanceToObstacle = /* get distance to obstacle */;
    float carPosition = /* get car position */;
    float leftLaneBoundary = /* get left lane boundary */;
    float rightLaneBoundary = /* get right lane boundary */;
    
    DriverAssistance::checkLaneDeparture(carPosition, leftLaneBoundary, rightLaneBoundary);
    DriverAssistance::checkCollision(currentSpeed, distanceToObstacle);
    DriverAssistance::checkSpeedLimit(currentSpeed);

    // Emergency call system
    EmergencyCallSystem::detectAccident(DriverAssistance::collisionAlert);
    EmergencyCallSystem::callEmergencyServices();

    // Adapt system status
    SystemState btState = BluetoothConnector::isBluetoothConnected ? BLUETOOTH_ON : BLUETOOTH_OFF;
    SystemState navState = NavigationSystem::isNavigationActive ? NAVIGATION_ON : NAVIGATION_OFF;
    updateSystemState(btState);
    updateSystemState(navState);
}
