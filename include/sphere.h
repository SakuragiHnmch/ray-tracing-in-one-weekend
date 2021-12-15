#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"


class sphere : public hittable {
public:
    sphere() {}
    sphere(point3 cen, double radius) : center(cen), radius(radius) {}

    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const override;

public:
    point3 center;
    double radius;
};

bool sphere::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {
    vec3 oc = r.origin() - center;
    double a = r.direction().length_squared();
    double half_b = dot(oc, r.direction());
    double c = oc.length_squared() - radius * radius;

    auto discrimination = half_b * half_b - a * c;
    if (discrimination < 0) return false;

    auto sqr = sqrt(discrimination);

    // find the nearest root that lies in the acceptable range
    auto root = (-half_b - sqr) / a; // 先取二元函数的较小解，即比较靠近光线的点
    if (root < t_min || root > t_max) {
        root = (-half_b + sqr) / a;
        if (root < t_min || root > t_max) return false;
    }

    rec.t = root;
    rec.p = r.at(root);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);

    return true;
}

#endif