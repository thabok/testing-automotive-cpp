#ifndef BLUETOOTH_CONNECTOR_H
#define BLUETOOTH_CONNECTOR_H

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
