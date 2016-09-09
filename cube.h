#ifndef __cube_h__
#define __cube_h__

#include "face_2d.h"
#include "util.h"
#include "turn.h"

#include <vector>
#include <iostream>

// small 1x1x1 cube
struct Cubixon {
    std::vector<Color> colors;
    Color& operator[](int nr) {
        return colors[nr];
    }
    void println(bool space) const {
        const int spaces_nr = 10;

        if (space) printf(" ");
        int spaces = spaces_nr;
        for (int i = 0; i < (int)colors.size(); ++i) {
            printf("%c ", color_to_char(colors[i]));
            spaces -= 2;
        }
        while (spaces --)
            printf(" ");
    }
};


class Cube {
  public:
    std::vector<Face_2d> faces_2d; // list of faces (human-like represantation of cube)
    std::vector<Cubixon> cubixons_3d; // list of 27 (most likely) 1x1x1 cubixons
    std::vector<Face_2d> restr; // restrictions

    Cube() {};
    Cube(std::vector<Face_2d> faces) : faces_2d(faces) {
        for (int i = 1; i <= 27; ++i)
            cubixons_3d.push_back(get_cubixon(faces, i));
    };
    Cube(const Cube& c) : faces_2d(c.faces_2d) {
        for (int i = 1; i <= 27; ++i)
            cubixons_3d.push_back(get_cubixon(c.faces_2d, i));
    }
    Cube& operator=(Cube c) {
        faces_2d = c.faces_2d;
        cubixons_3d = c.cubixons_3d;
        restr = c.restr;
        return *this;
    }

    // perform one single turn
    static Cube move(Cube c, int turn_nr);
    int bfs(std::vector<Face_2d> restr);
    int bfs();

    void print(std::ostream& os) const;
    void print_cubixons() const;

    void cubixons_to_faces();
    void move_cubixon(unsigned int a, unsigned int b);

    Cube get_default_cube();

  private:
    int hash();

    static const unsigned int TURN_CUBIXONS_NUM;
    static Cubixon get_cubixon(std::vector<Face_2d> faces, int nr);

    const Cubixon cubixon01 = {{Color::Y, Color::B, Color::O}};
    const Cubixon cubixon02 = {{Color::Y, Color::O}};
    const Cubixon cubixon03 = {{Color::Y, Color::G, Color::O}};
    const Cubixon cubixon04 = {{Color::Y, Color::B}};
    const Cubixon cubixon05 = {{Color::Y}};
    const Cubixon cubixon06 = {{Color::Y, Color::G}};
    const Cubixon cubixon07 = {{Color::Y, Color::R, Color::B}};
    const Cubixon cubixon08 = {{Color::Y, Color::R}};
    const Cubixon cubixon09 = {{Color::Y, Color::R, Color::G}};

    const Cubixon cubixon10 = {{Color::W, Color::O}};
    const Cubixon cubixon11 = {{Color::O}};
    const Cubixon cubixon12 = {{Color::B, Color::R}};
    const Cubixon cubixon13 = {{Color::B}};
    const Cubixon cubixon14 = {{}};
    const Cubixon cubixon15 = {{Color::G}};
    const Cubixon cubixon16 = {{Color::W, Color::R}};
    const Cubixon cubixon17 = {{Color::R}};
    const Cubixon cubixon18 = {{Color::B, Color::W}};

    const Cubixon cubixon19 = {{Color::B, Color::O, Color::W}};
    const Cubixon cubixon20 = {{Color::W, Color::G}};
    const Cubixon cubixon21 = {{Color::W, Color::R, Color::G}};
    const Cubixon cubixon22 = {{Color::G, Color::O}};
    const Cubixon cubixon23 = {{Color::W}};
    const Cubixon cubixon24 = {{Color::R, Color::G}};
    const Cubixon cubixon25 = {{Color::R, Color::B, Color::W}};
    const Cubixon cubixon26 = {{Color::B, Color::O}};
    const Cubixon cubixon27 = {{Color::O, Color::W, Color::G}};

    const std::vector<Cubixon> cubixons = {
        cubixon01, cubixon02, cubixon03, cubixon04, cubixon05, cubixon06,
        cubixon07, cubixon08, cubixon09, cubixon10, cubixon11, cubixon12,
        cubixon13, cubixon14, cubixon15, cubixon16, cubixon17, cubixon18,
        cubixon18, cubixon20, cubixon21, cubixon22, cubixon23, cubixon24,
        cubixon25, cubixon26, cubixon27
    };

    static std::vector<std::vector<std::pair<int, int>>> cubixons_to_2d;
};

#endif // __cube_h__
