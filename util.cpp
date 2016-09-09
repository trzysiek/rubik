#include "util.h"

Color char_to_color(char c) {
    if (c == 'g') return Color::G;
    if (c == 'r') return Color::R;
    if (c == 'w') return Color::W;
    if (c == 'o') return Color::O;
    if (c == 'y') return Color::Y;
    if (c == 'b') return Color::B;
    throw new std::runtime_error("make_new_color");
}

char color_to_char(Color c) {
    if (c == Color::G) return 'g';
    if (c == Color::R) return 'r';
    if (c == Color::W) return 'w';
    if (c == Color::O) return 'o';
    if (c == Color::Y) return 'y';
    if (c == Color::B) return 'b';
    throw new std::runtime_error("color_to_char");
}
