#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

long long solution(int n, int q, std::vector<long long>& a, std::vector<std::pair<int, int>>& queries) {
    
    std::vector<int> diff(n+2);

    for (int i=0; i<q; i++){
        const auto& [l,r] = queries[i];
        diff[l]++;
        diff[r+1]--;
    }

    std::vector<int> cnt (n+1,0);

    for (int i=1; i<n+1; i++){
        cnt[i] = cnt[i-1]+diff[i];
    }

    sort(a.begin(),a.end());
    sort(cnt.begin(),cnt.end());

    long long sum = 0;
    for (int i=1; i<n+1; i++){
        sum+=cnt[i]*a[i-1];
    }

    return sum;
}

int main(){
    int n, q;
    std::cin >> n >> q;

    std::vector<long long> a(n);
    for (int i=0; i<n; i++){
        std::cin >> a[i];
    }

    std::vector<std::pair<int, int>> queries;
    queries.reserve(q);
    
    for (int i=0; i<q; i++){
        int l, r;
        std::cin >> l >> r;
        queries.push_back({l,r});
    }

    long long ans = solution(n,q,a,queries);
    std::cout << ans << "\n";

    return 0;
}