#ifndef BLUETOOTH_CONNECTOR_H
#define BLUETOOTH_CONNECTOR_H

#include <exception>

typedef int Identifier;
#define NO_DEVICE_ID -1

class BluetoothConnector {
public:
    bool isBluetoothConnected;
    Identifier connectedDeviceId;
    Identifier connectionRequestId;

    BluetoothConnector();
    void connectDevice();
    void disconnectDevice();
    bool connectionRequestActive();
};

#endif /* BLUETOOTH_CONNECTOR_H */
