#include "face_2d.h"

#include <stdexcept>

Face_2d::Face_2d(std::vector<char> v) {
    if (v.size() != FACE_2D_FIELDS_NUM)
        throw new std::runtime_error("Invalid 2d face");

    for (int i = 0; i < FACE_2D_FIELDS_NUM; ++i)
        colors[i] = Color(v[i]);
}
