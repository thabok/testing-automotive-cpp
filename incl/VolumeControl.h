#ifndef VOLUME_CONTROL_H
#define VOLUME_CONTROL_H

typedef float Volume;

class VolumeControl {
public:
    Volume userVolumeRequest;
    Volume effectiveVolume;
    Volume volumeThreshold;
    bool tooLoud;

    VolumeControl();
    void setVolume();
    void saturateVolume();
};

#endif /* VOLUME_CONTROL_H */
