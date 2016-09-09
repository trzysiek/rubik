#include "face_2d.h"
#include "util.h"

#include <stdexcept>
#include <iostream>

std::string Face_2d::colors_to_string() const {
    std::string s;
    for (int i = 0; i < FACE_2D_FIELDS_NUM; ++i)
        s += color_to_char(colors[i]);
    return s;
}


Face_2d::Face_2d(std::vector<char> v) {
    if (v.size() != FACE_2D_FIELDS_NUM)
        throw new std::runtime_error("Invalid 2d face");

    for (int i = 0; i < FACE_2D_FIELDS_NUM; ++i)
        colors[i] = char_to_color(v[i]);
}

Face_2d::Face_2d(std::string s) {
    std::vector<char> v;
    for (auto c : s)
        v.push_back(c);
    *this = Face_2d(v);
}
