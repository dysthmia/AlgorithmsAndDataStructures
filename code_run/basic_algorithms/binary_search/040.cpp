#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n;
    cin >> n;

    vector<Point> towers(n);

    for (int i = 0; i < n; i++) {
        cin >> towers[i].x >> towers[i].y;
    }

    // Проверяем, можно ли использовать мощность R
    auto can = [&](double R) {
        vector<int> color(n, -1);

        for (int start = 0; start < n; start++) {
            if (color[start] != -1)
                continue;

            color[start] = 0;
            queue<int> q;
            q.push(start);

            while (!q.empty()) {
                int v = q.front();
                q.pop();

                for (int u = 0; u < n; u++) {
                    if (u == v)
                        continue;

                    long long dx = towers[v].x - towers[u].x;
                    long long dy = towers[v].y - towers[u].y;

                    long long dist2 = dx * dx + dy * dy;

                    // Круги имеют пересечение ненулевой площади
                    if (dist2 < 4 * R * R) {

                        if (color[u] == -1) {
                            color[u] = color[v] ^ 1;
                            q.push(u);
                        }
                        else if (color[u] == color[v]) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    };

    // Найдём максимальное возможное расстояние между вышками.
    double hi = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = towers[i].x - towers[j].x;
            double dy = towers[i].y - towers[j].y;

            hi = max(hi, sqrt(dx * dx + dy * dy) / 2.0);
        }
    }

    double lo = 0;

    // Бинарный поиск
    for (int it = 0; it < 100; it++) {
        double mid = (lo + hi) / 2;

        if (can(mid))
            lo = mid;
        else
            hi = mid;
    }

    cout << fixed << setprecision(15) << lo << '\n';

    return 0;
}