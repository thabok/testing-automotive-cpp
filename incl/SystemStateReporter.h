#ifndef SYSTEM_STATE_REPORTER_H
#define SYSTEM_STATE_REPORTER_H

extern unsigned char systemStateBitfield;

typedef enum {
    NAVIGATION_OFF,
    NAVIGATION_ON,
    BLUETOOTH_OFF,
    BLUETOOTH_ON
} SystemState;

void updateSystemState(SystemState state);

#endif /* SYSTEM_STATE_REPORTER_H */
