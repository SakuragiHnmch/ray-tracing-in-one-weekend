#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
public:
    vec3() : ele{0, 0, 0} {}
    vec3(double e0, double e1, double e2) : ele{e0, e1, e2} {}

    double x() const {return ele[0];}
    double y() const {return ele[1];}
    double z() const {return ele[2];}

    vec3 operator-() const {return vec3(-ele[0], -ele[1], -ele[2]);}
    double operator[](int i) const {return ele[i];}
    double& operator[](int i) {return ele[i];}

    vec3& operator+=(const vec3 &v) {
        ele[0] += v.ele[0];
        ele[1] += v.ele[1];
        ele[2] += v.ele[2];
        return *this;
    }

    vec3& operator*=(const double t) {
        ele[0] *= t;
        ele[1] *= t;
        ele[2] *= t;
        return *this;
    }

    vec3 operator /= (const double t) {
        return *this *= 1 / t;
    }

    double length_squared() const {
        return ele[0] * ele[0] + ele[1] * ele[1] + ele[2] * ele[2];
    }

    double length() const {
        return sqrt(length_squared());
    }
public:
    double ele[3];


};

using point3 = vec3;
using color = vec3;

inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.ele[0] << ' ' << v.ele[1] << ' '  << v.ele[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.ele[0] + v.ele[0], u.ele[1] + v.ele[1], u.ele[2] + v.ele[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.ele[0] - v.ele[0], u.ele[1] - v.ele[1], u.ele[2] - v.ele[2]);
}

inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t * v.ele[0], t * v.ele[1], t * v.ele[2]);
}

inline vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

inline vec3 operator/(vec3 v, double t) {
    return (1 / t) * v;
}

inline double dot (const vec3 &u, const vec3 &v) {
    return u.ele[0] * v.ele[0] +
           u.ele[1] * v.ele[1] +
           u.ele[2] * v.ele[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(
            u.ele[1] * v.ele[2] - u.ele[2] * v.ele[1],
            u.ele[2] * v.ele[0] - u.ele[0] * v.ele[2],
            u.ele[0] * v.ele[1] - u.ele[1] * v.ele[0]
            );
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}

#endif