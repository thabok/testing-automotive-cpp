#ifndef DRIVER_ASSISTANCE_H
#define DRIVER_ASSISTANCE_H

class DriverAssistance {
public:
    bool laneDepartureWarning;
    bool collisionAlert;
    bool speedLimitNotification;

    float collisionThreshold; // Threshold for detecting potential collision
    float speedLimit;         // Speed limit threshold

    DriverAssistance();

    void checkLaneDeparture(float carPosition, float leftLaneBoundary, float rightLaneBoundary);
    void checkCollision(float currentSpeed, float distanceToObstacle);
    void checkSpeedLimit(float currentSpeed);
};

#endif /* DRIVER_ASSISTANCE_H */
