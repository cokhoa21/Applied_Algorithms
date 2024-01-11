#include<bits/stdc++.h>

using namespace std;

#define MAX 10000000
long long a[MAX], n;

void input() {
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

long long MaxLeft(int l, int r) {
    long long res = -1e9;
    long long sum = 0;
    for(long long i = r; i >= l; i--) {
        sum += a[i];
        res = max(res, sum);
    }
    return res;
}

long long MaxRight(int l, int r) {
    long long res = -1e9;
    long long sum = 0;
    for(long long i = l;i <= r;i++) {
        sum += a[i];
        res = max(res, sum);
    }
    return res;
}

long long MaxSubSeq(int l, int r) {
    if(l == r) return a[l];
    long long m = (l + r) / 2;
    long long ML = MaxSubSeq(l, m);
    long long MR = MaxSubSeq(m+1, r);
    long long MLR = MaxLeft(l,m) + MaxRight(m+1, r);
    long long temp = max(ML, MR);
    temp = max(MR, MLR);
    return temp;
}

int main() {
    input();
    cout << MaxSubSeq(1, n);
    return 0;
}