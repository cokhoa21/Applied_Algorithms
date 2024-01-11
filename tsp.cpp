#include<bits/stdc++.h>

using namespace std;
#define MAX 100
int n;
int c[MAX][MAX];
bool visited[MAX];
int f;
int x[MAX];
int c_min = 1e9;
int f_min = 1e9;

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if(i != j && c_min > c[i][j]) {
                c_min = c[i][j];
            } 
        }
    }
}

bool check(int v, int k) {
    return visited[v] == false;
}

void solution() {
    if (f + c[x[n]][x[1]] < f_min) f_min = f + c[x[n]][x[1]];
}

void Try(int k) {
    for(int v = 1;v <= n;v++) {
        if(check(v, k)) {
            x[k] = v;
            f += c[x[k-1]][x[k]];
            visited[v] = true;
            if(k == n) solution();
            else {
                if(f + c_min*(n - k + 1) < f_min) Try(k+1);
            }
            f -= c[x[k-1]][x[k]];
            visited[v] = false;
        }
    }
}

int main() {
    input();
    f = 0;
    Try(1);
    cout << f_min << endl;
    return 0;
}

