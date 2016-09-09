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
    if (c == Color::G) return 'G';
    if (c == Color::R) return 'R';
    if (c == Color::W) return 'W';
    if (c == Color::O) return 'O';
    if (c == Color::Y) return 'Y';
    if (c == Color::B) return 'B';
    throw new std::runtime_error("color_to_char");
}
