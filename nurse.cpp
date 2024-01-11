#include<bits/stdc++.h>

#define f1(i, a) for(int i = 1; i <= a; i++)
#define f0(i, a) for(int i = 0; i < a; i++)
#define MAX 1002
const int MOD = 1e9 + 7;
using namespace std;

int N, K1, K2, f[MAX][2], res;

void input() {
    cin >> N >> K1 >> K2;
}

void solve() {
    f[0][1] = f[0][0] = 1;
    f1(i, N) {
        for (int j = K1; j <= K2; j++)
        {
            if(i-j < 0) break;
            f[i][1] += f[i-j][0];
            f[i][1] %= MOD;
        }
        f[i][0] = f[i-1][1];        
    }
    res = (f[N][0] + f[N][1]) % MOD;
    cout << res << "\n";
}

int main() {
    input();
    solve();
    return 0;
}