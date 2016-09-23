#include "cube.h"

#include <iostream>

bool test_creating_cubixons3d_from_faces2d() {
    return true;
}

bool test_printing_cube_faces() {
    return true;
}

bool test_operator_equality() {
    Cube c = Cube::get_default_cube();
    Cube d = Cube::move(c, 1);
    return (c == c && !(c == d));
}

bool test_move_nr_1() {
    Cube c = Cube::get_default_cube();
    Cube d = Cube::move(c, 1);
    std::cout << c.to_string() << std::endl << d.to_string();
    std::cout << std::endl << Cube::default_cubixon_to_string << std::endl;
    return true;
}

bool test_move_nr_1_test_order() {
    const unsigned int element_order = 4;
    Cube c = Cube::get_default_cube();

    for (unsigned int i = 0; i < element_order; ++i)
        Cube::move(c, 1);

    std::cerr << c << std::endl << Cube::get_default_cube();
    return c == Cube::get_default_cube();
}

void test(int nr, auto f, std::string msg) {
    std::cerr << "Test nr " << nr << ": "
              << ((f) ? "Passed." : "FAILED!") << " (" << msg << ")\n";
}

int main() {
    test(1, test_creating_cubixons3d_from_faces2d(), "Creating 3d cubixons from 2d faces");
    test(2, test_printing_cube_faces(), "Printing cube faces");
    test(3, test_operator_equality(), "Test cube's == operator");
    test(4, test_move_nr_1(), "Move nr 1");
    test(5, test_move_nr_1_test_order(), "Move nr 1 - element order is 4");
}
