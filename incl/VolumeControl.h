#ifndef VOLUME_CONTROL_H
#define VOLUME_CONTROL_H

class VolumeControl {
public:
    float userVolumeRequest;
    float effectiveVolume;
    float volumeThreshold;
    bool tooLoud;

    VolumeControl();
    void setVolume();
    void saturateVolume();
};

#endif /* VOLUME_CONTROL_H */
