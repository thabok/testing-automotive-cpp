#include "BluetoothConnector.h"

BluetoothConnector::BluetoothConnector() : isBluetoothConnected(false), connectionRequestId(0), connectedDeviceId(-1) {}

/**
 * @brief Accepts the active connection request
 * @throws Exception if there is already another device connected
 */
void BluetoothConnector::connectDevice() {
    if (connectionRequestActive()) {
        // don't allow a new connection request to replace the existing active connection
        if (isBluetoothConnected && connectedDeviceId != connectionRequestId) {
            throw std::exception();
        }
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