#include<bits/stdc++.h>

using namespace std;

#define MAX 100
int N, M;
int A[MAX][MAX];
int load[MAX];
int c[MAX];
int x[MAX];
int max_load = 0;
int min_all = 1e9;

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; i++)
    {
        cin >> c[i];
    }
    for(int i = 1;i <= N;i++) {
        for(int j = 1;j <= N;j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 1; i <= M; i++)
    {
        load[i] = 0;
    }
}

bool check(int v, int k) {
    for(int i = 1; i <= k;i++) {
        if(A[i][k] == 1) {
            if(x[i] >= v) return false;
            else return true;
        }else if(A[k][i] == 1) {
            if(v >= x[i]) return false;
            else return true;
        }
    }
}

void solution() {
    min_all = min(min_all, max_load);
}

void Try(int k) {
    for(int v = 1;v <= M;v++) {
        if(check(v, k)) {
            x[k] = v;
            load[v] += c[k];
            int pre = max_load;
            max_load = max(max_load, load[v]);
            if(k == N) solution();
            else
                if(max_load < min_all) Try(k+1);
            max_load = pre;
            load[v] -= c[k];
        }
    }
}

int main() {
    input();
    Try(1);
    cout << min_all;
    return 0;
}
