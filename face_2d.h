#ifndef __face_2d_h__
#define __face_2d_h__

#include <vector>
#include <iostream>

const unsigned int RUBIK_SIZE = 3;
const unsigned int FACE_2D_FIELDS_NUM = RUBIK_SIZE * RUBIK_SIZE;

enum Color {W, Y, O, R, G, B};

class Face_2d {
  private:
    std::string colors_to_string() const;
  public:
    Color colors[FACE_2D_FIELDS_NUM];

    Face_2d();
    Face_2d(std::vector<char>);
    Face_2d(std::string);

    // prints entire face (face-printer)
    std::string to_string(int nr) const;
};

#endif // __face_2d._h__
