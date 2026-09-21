#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() 
{
	int n, m;
    cin >> n >> m;

    vector<int> xs(n), ys(n);

    long long sum = 0; // общая сумма

    for (int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        xs[i] = x;
        ys[i] = y;
        sum += abs(x) + abs(y); // добавляем растояние от (0,0) до каждой точки 
    }

    string s;
    cin >> s;

    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());

    int x0 = 0,y0 = 0;

    for (char c : s){
        if (c=='N'){
            long long k = upper_bound(ys.begin(),ys.end(),y0) - ys.begin();
            sum += 2*k - n;
            y0++;
        } else if (c == 'S'){
            long long k = lower_bound(ys.begin(),ys.end(),y0) - ys.begin();
            sum += n - 2*k;
            y0--;
        } else if (c == 'E'){
            long long k = upper_bound(xs.begin(), xs.end(), x0) - xs.begin();
            sum += 2 * k - n;
            x0++;
        } else {
            long long k = lower_bound(xs.begin(), xs.end(), x0) - xs.begin();
            sum += n - 2 * k;
            x0--;
        }

        cout << sum << "\n";

    }

	return 0;
}


/*

    N:  y+1 => все точки которые > y0 расстояние до них уменьшится
        все точки (k) которые <= y0 расстояние до них увеличится 
        k - (n - k) = 2k - n



    S:  y-1 => точки >= y0 растояние увеличивается k
               точки < y0 растояние уменьшается
        (n - k) - k = n - 2k

    W: x-1 => все точки >= x0 растояние увеличиваетя lb
                точки < x0 растояние уменьшается
        
*/
