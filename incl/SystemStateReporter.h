#ifndef SYSTEM_STATE_REPORTER_H
#define SYSTEM_STATE_REPORTER_H

typedef unsigned char Bitfield;

typedef enum {
    NAVIGATION_OFF,
    NAVIGATION_ON,
    BLUETOOTH_OFF,
    BLUETOOTH_ON
} SystemState;

extern Bitfield systemStateBitfield;

void updateSystemState(SystemState state);

#endif /* SYSTEM_STATE_REPORTER_H */
