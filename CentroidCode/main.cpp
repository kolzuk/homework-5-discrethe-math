#include "edges.h"
#include "vertices.h"
#include "edges_with_distance.h"

const uint8_t NUMBER_OF_COUNTRIES = 49;

void dfs(vector<pair<int, pair<int, int>>>& ans, vector<bool>& was, int v, int& sum) {
    was[v] = true;
    for (int i = 0; i < ans.size(); ++i) {
        int v1 = ans[i].second.first;
        int v2 = ans[i].second.second;
        if (v == v2 && !was[v1]) {
            sum += ans[i].first;
            dfs(ans, was, v1, sum);
        }
        if (v == v1 && !was[v2]) {
            sum += ans[i].first;
            dfs(ans, was, v2, sum);
        }
    }
}

int centroid_num(vector<pair<int, pair<int, int>>>& ans, vector<bool>& was, int v) {
    int maximum = 0;
    was[v] = true;
    vector<int> branches;
    for (int i = 0; i < ans.size(); ++i) {
        int v1 = ans[i].second.first;
        int v2 = ans[i].second.second;
        if (v1 == v) {
            int sum = ans[i].first;
            dfs(ans, was, v2, sum);
            maximum = max(sum, maximum);
        }
        if (v2 == v) {
            int sum = ans[i].first;
            dfs(ans, was, v1, sum);
            maximum = max(sum, maximum);
        }
    }
    return maximum;
}

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
    vector<pair<int, pair<int, int>>> ans;
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
            ans.push_back({__edges[i].first, {v1, v2}});
        }
    }

    vector<int> centroid(NUMBER_OF_COUNTRIES + 1);
    for (int v = 1; v <= NUMBER_OF_COUNTRIES; ++v) {
        vector<bool> was(NUMBER_OF_COUNTRIES + 1, false);
        cout << vertices.at(v) << ' ' << centroid_num(ans, was, v) << '\n';
    }
    return 0;
}