#include "cube.h"

#include <map>
#include <queue>

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
