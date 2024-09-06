#include "SystemStateReporter.h"

Bitfield systemStateBitfield = 0b00; // binary: 00

void updateSystemState(SystemState state) {
    switch (state) {
        case NAVIGATION_OFF:
            // Clear the navigation bit (bit 0)
            systemStateBitfield &= ~(1 << 0);
            break;
        case NAVIGATION_ON:
            // Set the navigation bit (bit 0)
            systemStateBitfield |= (1 << 0);
            break;
        case BLUETOOTH_OFF:
            // Clear the Bluetooth bit (bit 1)
            systemStateBitfield &= ~(1 << 1);
            break;
        case BLUETOOTH_ON:
            // Set the Bluetooth bit (bit 1)
            systemStateBitfield |= (1 << 1);
            break;
    }
}
