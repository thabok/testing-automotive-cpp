#ifndef BLUETOOTH_CONNECTOR_H
#define BLUETOOTH_CONNECTOR_H

#define NO_DEVICE_ID -1

class BluetoothConnector {
public:
    bool isBluetoothConnected;
    int connectedDeviceId;
    int connectionRequestId;

    BluetoothConnector();
    void connectDevice();
    void disconnectDevice();
    bool connectionRequestActive();
};

#endif /* BLUETOOTH_CONNECTOR_H */
