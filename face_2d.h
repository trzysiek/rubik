#ifndef __face_2d_h__
#define __face_2d_h__

#include <vector>

const unsigned int RUBIK_SIZE = 3;
const unsigned int FACE_2D_FIELDS_NUM = RUBIK_SIZE * RUBIK_SIZE;

enum Color {White, Yellow, Orange, Brown, Green, Blue};

class Face_2d {
  private:
    Color colors[FACE_2D_FIELDS_NUM];
  public:
    Face_2d(std::vector<char> v);
};

#endif // __face_2d._h__
