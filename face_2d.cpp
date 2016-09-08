#include "face_2d.h"

#include <stdexcept>
#include <iostream>

Color make_new_color(char c) {
    if (c == 'g') return Color::Green;
    if (c == 'r') return Color::Red;
    if (c == 'w') return Color::White;
    if (c == 'o') return Color::Orange;
    if (c == 'y') return Color::Yellow;
    if (c == 'b') return Color::Blue;
    throw new std::runtime_error("make_new_color");
}

char color_to_char(Color c) {
    if (c == Color::Green) return 'g';
    if (c == Color::Red) return 'r';
    if (c == Color::White) return 'w';
    if (c == Color::Orange) return 'o';
    if (c == Color::Yellow) return 'y';
    if (c == Color::Blue) return 'b';
    throw new std::runtime_error("color_to_char");
}

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
        colors[i] = make_new_color(v[i]);
}
