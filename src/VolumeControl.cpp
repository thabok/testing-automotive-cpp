#include "VolumeControl.h"

VolumeControl::VolumeControl() : userVolumeRequest(0), effectiveVolume(0), volumeThreshold(75), tooLoud(false) {}

void VolumeControl::setVolume() {
    if (userVolumeRequest >= 0 && userVolumeRequest <= 100) {
        effectiveVolume = userVolumeRequest;
    }
    tooLoud = (effectiveVolume > volumeThreshold);
}

// void VolumeControl::saturateVolume() {
//     if (userVolumeRequest > volumeThreshold) {
//         userVolumeRequest = volumeThreshold;
//         setVolume();
//     }
// }
