#ifndef NAVIGATION_SYSTEM_H
#define NAVIGATION_SYSTEM_H

class NavigationSystem {
public:
    bool isNavigationActive;
    bool stopRequested;
    float currentRouteLength;
    float requestedRouteLength;

    NavigationSystem();
    void startNavigation();
    void stopNavigation();
};

#endif /* NAVIGATION_SYSTEM_H */
