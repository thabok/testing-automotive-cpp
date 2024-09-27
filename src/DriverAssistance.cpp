#include "DriverAssistance.h"

DriverAssistance::DriverAssistance() : laneDepartureWarning(false), collisionAlert(false), speedLimitNotification(false), collisionThreshold(5.0), speedLimit(100.0) {}

void DriverAssistance::checkLaneDeparture(float carPosition, float leftLaneBoundary, float rightLaneBoundary) {
    // Simple logic to simulate lane departure warning
    if (carPosition < leftLaneBoundary || carPosition > rightLaneBoundary) {
        laneDepartureWarning = true;
        // Additional logic to handle lane departure warning
    } else {
        laneDepartureWarning = false;
    }
}

void DriverAssistance::checkCollision(float currentSpeed, float distanceToObstacle) {
    // Simple logic to simulate collision alert
    if (distanceToObstacle < collisionThreshold) {
        collisionAlert = true;
        // Additional logic to handle collision alert
    } else {
        collisionAlert = false;
    }
}

void DriverAssistance::checkSpeedLimit(float currentSpeed) {
    // Simple logic to simulate speed limit notification
    if (currentSpeed > speedLimit) {
        speedLimitNotification = true;
        // Additional logic to handle speed limit notification
    } else {
        speedLimitNotification = false;
    }
}
