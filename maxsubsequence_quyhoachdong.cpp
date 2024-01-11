#include<bits/stdc++.h>

using namespace std;
#define MAX 1000000
long n, a[MAX];
long long s[MAX];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

long long MaxSubSeq() {
    s[1] = a[1]; long long res = s[1];
    for(int i = 2;i <= n; i++) {
        if(s[i-1] > 0) s[i] = s[i-1] + a[i];
        else s[i] = a[i];
        if(s[i] > res) res = s[i];
    }
    return res;
}

int main() {
    input();
    cout << MaxSubSeq();
    return 0;
}