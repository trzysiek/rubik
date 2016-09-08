#ifndef __cube_h__
#define __cube_h__

#include "face_2d.h"

#include <vector>
#include <iostream>

class Cube {
  public:
    std::vector<Face_2d> faces_2d;
    Cube(std::vector<Face_2d> faces) : faces_2d(faces) {};
    Cube() : faces_2d(std::vector<Face_2d> {}) {};
    void print(std::ostream& os) const {
        os << "Wypisuje kostke:\n";
        for (int i = 0; i < faces_2d.size(); ++i)
            os << faces_2d[i].to_string(i+1);
    }
};

#endif // __cube_h__
