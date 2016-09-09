#include "cube.h"
#include "util.h"
#include "turn.h"

#include <queue>
#include <map>

const unsigned int Cube::TURN_CUBIXONS_NUM = 8;

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

    {{2, 3}, {4, 5}},
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

void Cube::move_cubixon(unsigned int a, unsigned int b) {
    unsigned int size = cubixons_3d[a].colors.size();
    cubixons_3d[b].colors.resize(size);
    auto which = Turn::move_table.table.at({a, b});
    for (unsigned int i = 0; i < size; ++i) {
        cubixons_3d[b][which[i]] = cubixons_3d[a][i];
    }
}

Cube Cube::move(Cube c, int turn_nr) {
    std::vector<int> turn;
    if (turn_nr == 1)
        turn = Turn::turn1;
    else if (turn_nr == 2);
    else
        throw new std::exception();

    Cube cube(c);
    //std::cerr << "Obrocik nr " << turn_nr << "." << std::endl;

    int last_i = Cube::TURN_CUBIXONS_NUM - 1;
    Cubixon a = cube.cubixons_3d[turn[last_i]];
    Cubixon b = cube.cubixons_3d[turn[last_i - 1]];

    // move all but last 2 cubixons
    for (int i = last_i - 2; i >= 0; i--)
        cube.move_cubixon(turn[i], turn[i + 2]);
    Cubixon a2 = cube.cubixons_3d[turn[last_i]];
    Cubixon b2 = cube.cubixons_3d[turn[last_i - 1]];
    cube.cubixons_3d[turn[last_i]]     = a;
    cube.cubixons_3d[turn[last_i - 1]] = b;
    
    // move last 2 cubixons
    cube.move_cubixon(turn[last_i],   turn[1]);
    cube.move_cubixon(turn[last_i-1], turn[0]);

    cube.cubixons_3d[turn[last_i]]     = a2;
    cube.cubixons_3d[turn[last_i - 1]] = b2;
    cube.cubixons_to_faces();
    return cube;
}

int Cube::bfs(std::vector<Face_2d> restr) {
    std::map<int, int> dist;
    std::queue<Cube> q;

    q.push(*this);
    dist[hash()] = 0;
    while (!q.empty()) {
        Cube c = q.front(); q.pop();
        std::cerr << c.hash() << ", " << dist[c.hash()] << std::endl;
        c.print_cubixons();
        for (unsigned int i = 1; i <= 1; ++i) {
            Cube c_t = Cube::move(c, i);
            int h = c_t.hash();
            if (dist.count(h) == 0) {
                dist[h] = dist[c.hash()] + 1;
                q.push(c_t);
            }
            else
                std::cerr << "cant: " << h << std::endl;
        }
    }
    return 101;
}

int Cube::bfs() {
    return bfs({});
}

int Cube::hash() {
    static const int P = 97;

    int res = 0;
    for (const auto& f : faces_2d) {
        for (const auto& p : f.colors) {
            res = (res * P) + p;
        }
    }
    return res;
}

Cube Cube::get_default_cube() {
    const std::string f1 = "yyyyyyyyy";
    const std::string f2 = "rrrwrbrwo";
    const std::string f3 = "bbbwbrwrw";
    const std::string f4 = "gggwgbbgb";
    const std::string f5 = "oooroorbo";
    const std::string f6 = "ggwgwogow";
    return Cube({Face_2d(f1), Face_2d(f2), Face_2d(f3), Face_2d(f4), Face_2d(f5), Face_2d(f6)});
}

Cubixon Cube::get_cubixon(std::vector<Face_2d> faces, int nr) {
    Cubixon c;
    for (const auto& cub : cubixons_to_2d[nr - 1]) {
        int f = cub.first; // face
        int p = cub.second; // pole
        c.colors.push_back(faces[f].colors[p]);
    }
    return c;
}

void Cube::cubixons_to_faces() {
    //printf("Zamieniam cubixy na mape 2d. Cubixow: %d.\n\n", (int)cubixons_3d.size());
    for (unsigned int i = 0; i < cubixons_3d.size(); ++i) {
        Cubixon& cub = cubixons_3d[i];
        for (unsigned int j = 0; j < cub.colors.size(); ++j) {
            int f_nor = cubixons_to_2d[i][j].first;
            int p_nor = cubixons_to_2d[i][j].second;
            faces_2d[f_nor].colors[p_nor] = cub[j];
        }
    }
}

void Cube::print(std::ostream& os) const {
    os << "Wypisuje kostke:\n";
    for (unsigned int i = 0; i < faces_2d.size(); ++i)
        os << faces_2d[i].to_string(i+1);
}

void Cube::print_cubixons() const {
    for (int i = 0; i < 27; ++i) {
        printf("%d ", i);
        cubixons_3d[i].println((i <= 9) ? true : false);
        if (i == 8 || i == 17 || i == 26)
            printf("\n");
    }
    printf("\n");
}
