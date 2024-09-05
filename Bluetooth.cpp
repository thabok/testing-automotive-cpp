#include "Bluetooth.h"

// Constructor to initialize variables
Bluetooth::Bluetooth() : buttonOn(false), Bluetooth_Connected(false) {}

// Function to update Bluetooth status based on button state
void Bluetooth::updateBluetoothStatus() {
    Bluetooth_Connected = buttonOn;
}
