#include "face_2d.h"
#include "util.h"

#include <stdexcept>
#include <iostream>

Face_2d::Face_2d() {
    Face_2d(std::vector<char> {});
}

Face_2d::Face_2d(std::vector<char> v) {
    if (v.size() != FACE_2D_FIELDS_NUM)
        throw new std::runtime_error("Invalid 2d face");

    for (unsigned int i = 0; i < FACE_2D_FIELDS_NUM; ++i)
        colors[i] = char_to_color(v[i]);
}

Face_2d::Face_2d(std::string s) {
    std::vector<char> v;
    for (auto c : s)
        v.push_back(c);
    *this = Face_2d(v);
}


std::string Face_2d::to_string(int nr) const {
    // TODO sciana nr zamiast nr-1
    return "Sciana nr " + std::to_string(nr-1) + ": " + colors_to_string() + '\n';
}

std::string Face_2d::colors_to_string() const {
    std::string s;
    for (unsigned int i = 0; i < RUBIK_SIZE; ++i) {
        for (unsigned int j = 0; j < RUBIK_SIZE; ++j)
            s += color_to_char(colors[i*RUBIK_SIZE+j]);
        s += ' ';
    }
    return s;
}
