//
// Created by macbook on 2021/6/3.
//

#ifndef RAY_TRACING_IN_ONE_WEEKEND_RTWEEKEND_H
#define RAY_TRACING_IN_ONE_WEEKEND_RTWEEKEND_H

#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>

//using
using std::shared_ptr;
using std::make_shared;
using  std::sqrt;

//constant
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

//utility functions
inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

inline double random_double() {
    //return a random real in [0, 1).
    return rand() / (RAND_MAX + 1.0);
}

inline double random_double(double min, double max) {
    //return a random real in [min, max).
    return min + (max - min) * random_double();
}

inline double clamp(double x, double min, double max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}


//common headers
#include "ray.h"
#include "vec3.h"

#endif //RAY_TRACING_IN_ONE_WEEKEND_RTWEEKEND_H
