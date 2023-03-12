#include "edges.h"

const uint8_t NUMBER_OF_COUNTRIES = 49;

int minimal_ecs(vector<set<int>>& adjacency_list, int v) {
    queue<int> graphs;
    graphs.push(v);
    vector<int> dist(NUMBER_OF_COUNTRIES + 1, -1);
    dist[v] = 0;
    while (!graphs.empty()) {
        int k = graphs.front();
        graphs.pop();
        for (auto m : adjacency_list[k]) {
            if (dist[m] == -1) {
                dist[m] = dist[k] + 1;
                graphs.push(m);
            }
        }
    }
    int minimum = 0;
    for (int i = 1; i <= NUMBER_OF_COUNTRIES; ++i) {
        if (i == 20 || i == 21 || i == 48 || i == 28 || i == 10) {
            continue;
        }
        minimum = max(minimum, dist[i]);
    }
    return minimum;
}


int main() { // 20 - Iceland, 21 - Ireland, 48 - UK, 28 - Malta, 10 Cyprus.
    vector<set<int>> adjacency_list(NUMBER_OF_COUNTRIES + 1);
    for (int i = 0; i < edges.size(); ++i) {
        int a = edges[i].first;
        int b = edges[i].second;
        adjacency_list[a].insert(b);
        adjacency_list[b].insert(a);
    }
    int radius = 100;
    for (int v = 1; v <= NUMBER_OF_COUNTRIES; ++v) {
        if (v == 20 || v == 21 || v == 48 || v == 28 || v == 10) {
            continue;
        }
        radius = min(minimal_ecs(adjacency_list, v), radius);
    }
    cout << radius;
    return 0;
}
