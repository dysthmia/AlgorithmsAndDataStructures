#include <iostream>
#include <vector>

using namespace std;

/*
    Идея: сотрудник j влияет на премию сотрудника i, если
                j<i      и      j+Aj >i
    то есть:
                i => [j+1; j + Aj - 1]
        все сотрудники которые лежат внутри этого отрезка их премия увеличивается благодаря сотрдунитку j

    Значит, можно для каждого j добавить +1 на отрезке будущих i, а потом просто идти слева направо и поддерживать текущее количество таких j.

*/

int main(){

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<int> diff(n + 2, 0);

    for (int j = 1; j <= n; ++j) {
        if (a[j] == 0) continue;

        int L = j + 1;
        int R = j + a[j];

        if (L <= n) diff[L]++;
        if (R <= n) diff[R]--;
    }

    int64_t ans = 0;
    int cur = 0;

    for (int i=1; i<=n; i++){
        cur += diff[i];
        ans += 1LL * a[i] * cur;
    }

    cout << ans << "\n";
    return 0;
}