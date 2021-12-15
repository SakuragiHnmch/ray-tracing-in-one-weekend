#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"

#include <memory>
#include <vector>

using std::make_shared;
using std::shared_ptr;

class hittable_list : public hittable {
public:
    hittable_list(){}
    hittable_list(shared_ptr<hittable> obj) {add(obj);}

    void clear() {objects.clear();}
    void add(shared_ptr<hittable> obj) {objects.push_back(obj);}

    virtual bool hit(const ray &r, double t_min, double t_max, hit_record &rec) const override;
public:
    std::vector<shared_ptr<hittable>> objects;
};

bool hittable_list::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {
    hit_record tem_rec;
    auto closest_so_far = t_max;
    bool hit_anything = false;

    for (const auto& object : objects) {
        if (object->hit(r, t_min, closest_so_far, tem_rec)) {
            hit_anything = true;
            closest_so_far = tem_rec.t;
            rec = tem_rec;
        }
    }

    return hit_anything;
}

#endif