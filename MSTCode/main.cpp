#include "edges.h"
#include "vertices.h"
#include "edges_with_distance.h"

const uint8_t NUMBER_OF_COUNTRIES = 49;

int main() { // 20 - Iceland, 21 - Ireland, 48 - UK, 28 - Malta, 10 Cyprus.
    vector<pair<int, pair<int, int>>> __edges;
    for (int i = 0; i < edges.size(); ++i) {
        int a = edges_with_distance[i][0];
        int b = edges_with_distance[i][1];
        int c = edges_with_distance[i][2];
        __edges.push_back({c, {a, b}});
    }
    vector<int> color(NUMBER_OF_COUNTRIES + 1);
    for (int i = 0; i <= color.size(); ++i) {
        color[i] = i;
    }
    int weight = 0;
    vector<pair<int, int>> ans;
    sort(__edges.begin(), __edges.end());
    for (int i = 0; i < __edges.size(); ++i) {
        int v1 = __edges[i].second.first;
        int v2 = __edges[i].second.second;
        if (color[v1] != color[v2]) {
            int color_number = color[v2];
            for (int j = 1; j <= color.size(); ++j) {
                if (color_number == color[j]) {
                    color[j] = color[v1];
                }
            }
            ans.emplace_back(v1, v2);
            weight += __edges[i].first;
        }
    }
    cout << weight << '\n';
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        cout << vertices[ans[i].first] << '-' << vertices[ans[i].second] << '\n';
    }
    return 0;
}