#include<bits/stdc++.h>

using namespace std;

#define MAX 10000
int n, m;
int x[MAX];
int y[MAX];
int s[MAX][MAX];

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        s[i][0] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> y[i];
        s[0][i] = 0;
    }
}

void LCS() {
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(x[i] == y[j]) s[i][j] = s[i-1][j-1] + 1;
            else{
                if(s[i-1][j] > s[i][j-1]) s[i][j] = s[i-1][j];
                else s[i][j] = s[i][j-1];
            }
        }
    }
    cout << s[n][m];
}

int main() {
    input();
    LCS();
    return 0;
}