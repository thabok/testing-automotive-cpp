#ifndef BLUETOOTH_H
#define BLUETOOTH_H

class Bluetooth {
public:
    bool buttonOn; // Variable to simulate the Bluetooth button state
    bool Bluetooth_Connected; // Variable to store the Bluetooth connection status

    // Constructor to initialize variables
    Bluetooth();

    // Function to update Bluetooth status based on button state
    void updateBluetoothStatus();
};

#endif // BLUETOOTH_H
