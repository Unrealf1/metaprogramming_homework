#pragma once

#include "LifetimeTracker.hpp"

static void AtExitFn() {
    assert(elements > 0 && pTrackerArray != 0);
    --elements;
    LifetimeTracker* pTop = pTrackerArray[elements];
    //pTrackerArray = static_cast<TrackerArray>(std::realloc(pTrackerArray, sizeof(LifeTimeTracker*) * elements));
    delete pTop;
}

template <typename T>
void SetLongevity(T* ptr, unsigned int longevity) {
    TrackerArray pNewArray = static_cast<TrackerArray>(
        std::realloc(pTrackerArray, sizeof(T) * (elements + 1))
    );
    if (!pNewArray) {
        throw std::bad_alloc();
    }
    pTrackerArray = pNewArray;
    LifetimeTracker* tracker = new ConcreteLifetimeTracker<T>(ptr, longevity);
    TrackerArray insert_pos = std::upper_bound(
        pTrackerArray, pTrackerArray + elements, longevity, LifetimeTracker::Compare
    );
    std::copy_backward(insert_pos, pTrackerArray + elements, pTrackerArray + elements + 1);
    *insert_pos = tracker;
    ++elements;
    std::atexit(AtExitFn);
}
