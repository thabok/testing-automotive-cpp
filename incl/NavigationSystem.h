#ifndef NAVIGATION_SYSTEM_H
#define NAVIGATION_SYSTEM_H

class NavigationSystem {
public:
    bool isNavigationActive;
    float currentRouteLength;
    float requestedRouteLength;

    NavigationSystem();
    void startNavigation();
    void stopNavigation();
};

#endif /* NAVIGATION_SYSTEM_H */
