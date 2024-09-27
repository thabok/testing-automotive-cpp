#ifndef EMERGENCY_CALL_SYSTEM_H
#define EMERGENCY_CALL_SYSTEM_H

class EmergencyCallSystem {
public:
    bool accidentDetected;
    bool emergencyCallFlag;

    EmergencyCallSystem();

    void detectAccident(bool collisionAlert);
    void callEmergencyServices();
};

#endif /* EMERGENCY_CALL_SYSTEM_H */
