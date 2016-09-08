#ifndef __face_2d_h__
#define __face_2d_h__

#include <vector>
#include <iostream>

const unsigned int RUBIK_SIZE = 3;
const unsigned int FACE_2D_FIELDS_NUM = RUBIK_SIZE * RUBIK_SIZE;

enum Color {White, Yellow, Orange, Red, Green, Blue};

class Face_2d {
  private:
    Color colors[FACE_2D_FIELDS_NUM];
  public:
    Face_2d(std::vector<char> v);
    Face_2d() { Face_2d(std::vector<char> {}); }
    std::string to_string(int nr) const {
        return "Sciana nr " + std::to_string(nr) + ": " + colors_to_string() + '\n';
    }
    std::string colors_to_string() const;
};

#endif // __face_2d._h__
