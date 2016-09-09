#ifndef __turn_h__
#define __turn_h__

#include "cube.h"
// ogarnac kolejnosc include
#include <vector>
#include <map>

struct Move_Table {
    typedef std::vector<int> Move_Conf;
    std::map<std::pair<int, int>, Move_Conf> table {
        {{2, 8}, {1, 2, 0}},
        {{8, 26}, {0, 2, 1}},
        {{26, 20}, {2, 0, 1}},
        {{20, 2}, {1, 0, 2}},
        {{5, 17}, {0, 1}},
        {{17, 23}, {1, 0}},
        {{23, 11}, {0, 1}},
        {{11, 5}, {1, 0}},
    };
};

// class defining turn arounds a man can do to a cube
class Turn {
  public:
    static const Move_Table move_table;
    static const std::vector<int> turn1;
    static const unsigned int turns_nr;
};

#endif // turn.h
