#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdint>

using namespace std;

struct Decoration {
    int64_t w;
    int64_t h;
};

int main() {
    int64_t n, k;
    cin >> n >> k;

    if (n < 1 || n > 1'000'000) {
        cout << -2 << '\n';
        return 0;
    }

    vector<Decoration> a(n);

    for (int64_t i = 0; i < n; ++i) {
        cin >> a[i].w >> a[i].h;
    }


    sort(a.begin(), a.end(), [](const Decoration& x, const Decoration& y) {
        return x.h < y.h;
    });

    priority_queue<int64_t> pq;

    int64_t sumWidth = 0;
    int64_t answer = INT64_MAX;

    for (const auto& decoration : a) {
        pq.push(decoration.w);
        sumWidth += decoration.w;

        if (static_cast<int64_t>(pq.size()) > k) {
            sumWidth -= pq.top();
            pq.pop();
        }

        if (static_cast<int64_t>(pq.size()) == k) {
            int64_t area = sumWidth * decoration.h;
            answer = min(answer, area);
        }
    }

    cout << answer << '\n';
    return 0;
}