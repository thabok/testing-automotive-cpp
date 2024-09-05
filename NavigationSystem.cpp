#include "NavigationSystem.h"

// Constructor to initialize variables
NavigationSystem::NavigationSystem() : directionInput(0), direction() {}

// Function to set the direction input and update the direction
void NavigationSystem::setDirectionInput(uint8_t input) {
    directionInput = input;
    displayDirection();
}

// Function to update the direction based on directionInput
void NavigationSystem::displayDirection() {
    switch (directionInput) {
        case 1:
            direction = East;
            break;
        case 2:
            direction = West;
            break;
        case 3:
            direction = North;
            break;
        case 4:
            direction = South;
            break;
        default:
            direction = Unknown;
            break;
    }
}
