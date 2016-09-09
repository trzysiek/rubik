#include "cube.h"
#include "util.h"

std::vector<std::vector<std::pair<int, int>>> Cube::cubixons_to_2d = {
    {{0, 0}, {2, 0}, {4, 2}},
    {{0, 1}, {4, 1}},
    {{0, 2}, {3, 2}, {4, 0}},
    {{0, 3}, {2, 1}},
    {{0, 4}},
    {{0, 5}, {3, 1}},
    {{0, 6}, {1, 0}, {2, 2}},
    {{0, 7}, {1, 1}},
    {{0, 8}, {1, 2}, {3, 1}},

    {{2, 4}, {4, 5}},
    {{4, 4}},
    {{3, 5}, {4, 3}},
    {{2, 4}},
    {},
    {{3, 4}},
    {{1, 3}, {2, 5}},
    {{1, 4}},
    {{1, 5}, {3, 3}},

    {{2, 6}, {4, 8}, {5, 6}},
    {{4, 7}, {5, 7}},
    {{3, 8}, {4, 6}, {5, 8}},
    {{2, 7}, {5, 3}},
    {{5, 4}},
    {{3, 7}, {5, 5}},
    {{1, 6}, {2, 8}, {5, 0}},
    {{1, 7}, {5, 1}},
    {{1, 8}, {3, 6}, {5, 2}}
};

Cube Cube::get_default_cube() {
    const std::string f1 = "yyyyyyyyy";
    const std::string f2 = "rrrwrbrwo";
    const std::string f3 = "bbbwbrwrw";
    const std::string f4 = "gggwgbbgb";
    const std::string f5 = "oooroorbo";
    const std::string f6 = "ggwgwogow";
    Cube c({Face_2d(f1), Face_2d(f2), Face_2d(f3), Face_2d(f4), Face_2d(f5), Face_2d(f6)});
    cubixons_3d = cubixons;
}

Cubixon Cube::get_cubixon(std::vector<Face_2d> faces, int nr) {
    Cubixon c;
    for (const auto& cub : cubixons_to_2d[nr - 1]) {
        int f = cub.first; // face
        int p = cub.second; // pole
        char cc = faces[f].colors[p];
        c.colors.push_back(faces[f].colors[p]);
    }
    return c;
}

void Cube::print(std::ostream& os) const {
    os << "Wypisuje kostke:\n";
    for (int i = 0; i < faces_2d.size(); ++i)
        os << faces_2d[i].to_string(i+1);
}

void Cube::cubixons_to_faces() {
    printf("Zamieniam cubixy na mape 2d. Cubixow: %u.\n", cubixons_3d.size());
    for (int i = 0; i < cubixons_3d.size(); ++i) {
        Cubixon& cub = cubixons_3d[i];
        for (int j = 0; j < cub.colors.size(); ++j) {
            char c = color_to_char(cub[j]);
            int f_nor = cubixons_to_2d[i][j].first;
            int p_nor = cubixons_to_2d[i][j].second;
            faces_2d[f_nor].colors[p_nor] = cub[j];
        }
    }
}
