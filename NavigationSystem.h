#ifndef NAVIGATIONSYSTEM_H
#define NAVIGATIONSYSTEM_H

#include <cstdint>

class NavigationSystem {
public:
    // Enum class to represent directions
    enum Direction {
        Unknown = 0,
        North = 1,
        East = 2,
        West = 3,
        South = 4
    };

    uint8_t directionInput; // Variable to store the direction input
    Direction direction; // Variable to store the current direction

    // Constructor to initialize variables
    NavigationSystem();

    // Function to set the direction input and update the direction
    void setDirectionInput(uint8_t input);

    // Function to update the direction based on directionInput
    void displayDirection();
};

#endif // NAVIGATIONSYSTEM_H
