#include "NavigationSystem.h"

NavigationSystem::NavigationSystem() : isNavigationActive(false), requestedRouteLength(0), currentRouteLength(0) {}

void NavigationSystem::startNavigation() {
    if (requestedRouteLength > 0) {
        isNavigationActive = true;
        currentRouteLength = requestedRouteLength;
    }
}

void NavigationSystem::stopNavigation() {
    isNavigationActive = false;
    currentRouteLength = 0;
}
