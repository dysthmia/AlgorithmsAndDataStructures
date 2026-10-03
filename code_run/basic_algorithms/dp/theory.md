# Поиск подстроки и подпоследовательности

Подстрока всегда состоит из символов, идущих строго подряд, а подпоследовательность может содержать символы с пропусками, главное — сохранять их исходный порядок.

``` text
Например: слово "молоко"
подстроками будут «мол», «оло», «локо», но не «млк»
"млк" в нашем же случае будет подпоследовательностью
```

## Поиск самой длинной общей подстроки

Расмотрим на примере: fish и hish

``` text

                f   i   s   h
            h   0   0   0   0 
            i   0   1   0   0 
            s   0   0   2   0 
            h   1   0   0   3 
```

Пример реализации в коде:
``` c++
    string l, w; cin >> l >> w;

    int n = l.size(); int m = w.size();
    vector<vector<int>> dp (n+1, vector<int>(m+1));

    int max_len = 0;
    int end_i = 0, end_j = 0;

    for (int i=1; i<n+1; i++){
        for (int j=1; j<m+1; j++){
            if (l[i-1] == w[j-1]){
                dp[i][j] += dp[i-1][j-1]+1;
                if (max_len < dp[i][j]){
                    max_len = dp[i][j];
                    end_i = i; end_j = j;
                }
            }
        }
    }
    
    string s = l.substr(end_i - max_len, max_len);

    cout << max_len << '\n';
    cout << s << '\n';
```

## Поиск самой длинной общей подпоследовательности

Расмотрим на примере: fish и hish

``` text
            f   i   s   h 
        f   1   1   1   1 
        o   1   1   1   1 
        s   1   1   2   2 
        h   1   1   2   3 
```

Пример реализации в коде:

``` c++
string l, w; cin >> l >> w;

int n = l.size(); int m = w.size();
vector<vector<int>> dp (n+1, vector<int>(m+1));

for (int i=1; i<n+1; i++){
    for (int j=1; j<m+1; j++){
        if (l[i-1] == w[j-1]){
            dp[i][j] += dp[i-1][j-1] + 1;
        } else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
}

string s;
int row = n, col = m;

while (row > 0 && col > 0){
    if (l[row-1] == w[col-1]){
        s += l[row-1];
        row--;
        col--;
    } else if (dp[row-1][col] >= dp[row][col-1]){
        row--;
    } else col--;
}

reverse(s.begin(),s.end());

cout << dp[n][m] << '\n';
cout << s << '\n';
```

