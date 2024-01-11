#include<bits/stdc++.h>

using namespace std;
#define MAX 1000000

int n, M, a[MAX];
int x[MAX];
int cnt = 0;

void input() {
    cin >> n >> M;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

bool check(int v, int k) {
    if(a[k] != a[v] && a[v] + a[k] == M) return true;
    else return false;
}


void Try(int k) {
    for(int v = 1;v <= n; v++) {
        if(check(v, k)) {
            x[k] = a[v];
            cnt ++;
            if(k != n) Try(k+1);
            cnt --;
        }
    }
}

int main() {
    input();
    Try(1);
    return 0;
}