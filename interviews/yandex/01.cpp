#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (auto& row : grid) {
        cin >> row;
    }

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    int students = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'D') {
                dist[i][j] = 0;
                q.push({i, j});
            } 
            else if (grid[i][j] == 'S') {
                ++students;
            }
        }
    }

    if (students == 0) {
        cout << 0 << '\n';
        return 0;
    }

    const int dx[] = {-1, 1, 0, 0};
    const int dy[] = {0, 0, -1, 1};

    int answer = 0;
    int invited = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; ++dir) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                continue;
            }

            if (grid[nx][ny] == '*') {
                continue;
            }

            if (dist[nx][ny] != -1) {
                continue;
            }

            dist[nx][ny] = dist[x][y] + 1;

            if (grid[nx][ny] == 'S') {
                ++invited;
                answer = max(answer, dist[nx][ny]);
            }

            q.push({nx, ny});
        }
    }

    if (invited != students) {
        cout << -1 << '\n';
    } else {
        cout << answer << '\n';
    }

    return 0;
}