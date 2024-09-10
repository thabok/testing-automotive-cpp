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

    /**
     * @brief Sets the volume based on the userVolumeRequest
     */
    void setVolume();

    /**
     * @brief Saturates the volume to not be higher as the configured volumeThreshold
     */
    void saturateVolume();
};

#endif /* VOLUME_CONTROL_H */
