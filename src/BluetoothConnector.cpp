#include "BluetoothConnector.h"

BluetoothConnector::BluetoothConnector() : isBluetoothConnected(false), connectionRequestId(0), connectedDeviceId(-1) {}

void BluetoothConnector::connectDevice() {
    if (connectionRequestActive()) {
        isBluetoothConnected = true;
        connectedDeviceId = connectionRequestId;
    }
}

void BluetoothConnector::disconnectDevice() {
    isBluetoothConnected = false;
    connectedDeviceId = -1;
}

bool BluetoothConnector::connectionRequestActive() {
    return connectionRequestId > 0;
}