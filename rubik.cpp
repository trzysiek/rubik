#include "face_2d.h"
#include "cube.h"

#include <fstream>
#include <iostream>
#include <stdexcept>

const std::string default_path_to_cube = "cube.in";

Cube load_cube_from_file() {
    std::ifstream file(default_path_to_cube);
    if (!file.is_open())
        throw new std::exception();

    std::string face;
    const unsigned int face_nr = 6;
    std::vector<Face_2d> faces;
    for (int i = 0; i < face_nr; ++i) {
        file >> face;
        std::vector<char> v;
        if (face.size() != FACE_2D_FIELDS_NUM)
            throw new std::exception();

        for (int j = 0; j < face.size(); ++j)
            v.push_back(face[j]);
        faces.push_back(Face_2d(v));
    }
    return Cube(faces);
}

Cube load_cube_from_input() {
    // TODO: implement
    return Cube();
}

Cube load_cube_from_file_or_input() {
    try {
        return load_cube_from_file();
    }
    catch (...) {
        return load_cube_from_input();
    }
}

template<class T>
auto operator<<(std::ostream& os, const T& t) -> decltype(t.print(os), os) {
    t.print(os);
    return os;
}

int main() {
    try {
        Cube c = load_cube_from_file_or_input();
        std::cout << c;
        c.cubixons_to_faces();
        std::cout << c;
    }
    catch (...) {
        std::cerr << "Error in loading cube." << std::endl;
    }
}
