#pragma once

#include <algorithm>
#include <cassert>


class LifetimeTracker {
public:
    LifetimeTracker(unsigned int x): _longevity(x) {}
    virtual ~LifetimeTracker() = default;
    static bool Compare(unsigned int longevity, const LifetimeTracker* p) {
        return p->_longevity < longevity; 
    }
private:
    unsigned int _longevity;
};

using TrackerArray = LifetimeTracker**;

static TrackerArray pTrackerArray;
static unsigned int elements;

// inheritance is needed for unified storage
template <typename T>
class ConcreteLifetimeTracker: public LifetimeTracker {
public:
    ConcreteLifetimeTracker(T* ptr, unsigned int longevity)
    : LifetimeTracker(longevity), _tracked(ptr) {}
    ~ConcreteLifetimeTracker() {
        delete _tracked;
    }
private:
    T* _tracked;
};
