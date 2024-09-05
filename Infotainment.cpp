#include "Infotainment.h"

// Constructor to initialize variables
Infotainment::Infotainment() : VolumeControl(), NavigationSystem(), Bluetooth() {}

// Step function to call relevant functions
void Infotainment::step() {
    setVolume(usrVolReq); // Set the system volume based on user request
    warnUserIfTooLoud(); // Check if the volume is too loud and warn the user
    setDirectionInput(directionInput); // Set the direction input and update the direction
    updateBluetoothStatus(); // Update the Bluetooth connection status
}
