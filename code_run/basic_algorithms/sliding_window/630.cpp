#include <vector>
#include <algorithm>

int solution(int n, std::vector<int>& a) {

    sort(a.begin(),a.end());
    
    int max_keep = 0;
    int r = 0;

    for (int l=0; l<n; l++){
        
        if (r<l) r == l;

        while (r<n && a[r]-a[l] < n){
            r+=1;
        }

        max_keep = std::max(max_keep, r - l);
    }

    return n - max_keep;
}
