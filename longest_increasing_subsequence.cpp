#include<bits/stdc++.h>

using namespace std;

#define MAX 10000
int n, a[MAX];
int iMem[MAX];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

int Lis(int i) {
    if(iMem[i] != -1) return iMem[i];
    int res = 1;
    for (int j = 1; j < i; j++)
    {
        if(a[j] < a[i]) res = max(res, 1+Lis(j));
    }
    iMem[i] = res;
    return res;
}

void solution() {
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        iMem[i] = -1;
        ans = max(ans, Lis(i));
    }
    cout << ans;
}

int main() {
    input();
    solution();
    return 0;
}