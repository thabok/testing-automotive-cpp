#ifndef NAVIGATION_SYSTEM_H
#define NAVIGATION_SYSTEM_H

typedef float DistanceKM;

class NavigationSystem {
public:
    bool isNavigationActive;
    bool stopRequested;
    DistanceKM currentRouteLength;
    DistanceKM requestedRouteLength;

    NavigationSystem();

    void startNavigation();
    void stopNavigation();
};

#endif /* NAVIGATION_SYSTEM_H */
