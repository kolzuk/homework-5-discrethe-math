#include "edges.h"
#include "vertices.h"

const uint8_t NUMBER_OF_COUNTRIES = 49;

int main() { // 20 - Iceland, 21 - Ireland, 48 - UK, 28 - Malta, 10 Cyprus.
    vector<set<int>> adjacency_list(NUMBER_OF_COUNTRIES + 1);
    for (int i = 0; i < edges.size(); ++i) {
        int a = edges[i].first;
        int b = edges[i].second;
        adjacency_list[a].insert(b);
        adjacency_list[b].insert(a);
    }
    for (int v1 = 1; v1 <= NUMBER_OF_COUNTRIES; ++v1) {
        for (int v2 = 1; v2 <= NUMBER_OF_COUNTRIES; ++v2) {
            for (int v3 = 1; v3 <= NUMBER_OF_COUNTRIES; ++v3) {
                for (int v4 = 1; v4 <= NUMBER_OF_COUNTRIES; ++v4) {
                    for (int v5 = 1; v5 <= NUMBER_OF_COUNTRIES; ++v5) {
                        if (v1 == v2 || v1 == v3 || v1 == v4 || v1 == v5 || v2 == v3 || v2 == v4 || v2 == v5
                        || v3 == v4 || v3 == v5 || v4 == v5) {
                            continue;
                        }
                        if (find(adjacency_list[v1].begin(), adjacency_list[v1].end(), v2) == adjacency_list[v1].end()) {
                            continue;
                        }
                        if (find(adjacency_list[v1].begin(), adjacency_list[v1].end(), v3) == adjacency_list[v1].end()) {
                            continue;
                        }
                        if (find(adjacency_list[v1].begin(), adjacency_list[v1].end(), v4) == adjacency_list[v1].end()) {
                            continue;
                        }
                        if (find(adjacency_list[v1].begin(), adjacency_list[v1].end(), v5) == adjacency_list[v1].end()) {
                            continue;
                        }
                        if (find(adjacency_list[v2].begin(), adjacency_list[v2].end(), v3) == adjacency_list[v2].end()) {
                            continue;
                        }
                        if (find(adjacency_list[v2].begin(), adjacency_list[v2].end(), v4) == adjacency_list[v2].end()) {
                            continue;
                        }
                        if (find(adjacency_list[v2].begin(), adjacency_list[v2].end(), v5) == adjacency_list[v2].end()) {
                            continue;
                        }
                        if (find(adjacency_list[v3].begin(), adjacency_list[v3].end(), v4) == adjacency_list[v3].end()) {
                            continue;
                        }
                        if (find(adjacency_list[v3].begin(), adjacency_list[v3].end(), v5) == adjacency_list[v3].end()) {
                            continue;
                        }
                        if (find(adjacency_list[v4].begin(), adjacency_list[v4].end(), v5) == adjacency_list[v4].end()) {
                            continue;
                        }
                        cout << "YES" << '\n';
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NO" << '\n';
    return 0;
}
