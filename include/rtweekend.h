//
// Created by macbook on 2021/6/3.
//

#ifndef RAY_TRACING_IN_ONE_WEEKEND_RTWEEKEND_H
#define RAY_TRACING_IN_ONE_WEEKEND_RTWEEKEND_H

#include <cmath>
#include <limits>
#include <memory>

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

//common headers
#include "ray.h"
#include "vec3.h"

#endif //RAY_TRACING_IN_ONE_WEEKEND_RTWEEKEND_H
