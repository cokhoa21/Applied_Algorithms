#include<bits/stdc++.h>

using namespace std;
#define MAX 100
int n, k;
int q;
bool visited[MAX];
int c[MAX][MAX];
int x[MAX];
int minDis;
int distanceCur = 0;
int distanceMin = 1e9;
int minDist = 1e9;

void input() {
    cin >> n >> k;
    for (int i = 1; i <= 2*n + 1; i++)
    {
        for (int j = 1; j <= 2*n + 1; j++)
        {
            cin >> c[i][j];
            if(i != j) minDist = min(minDist, c[i][j]);
        }
    }
}

bool check(int v, int a) {
    if(q == k)
        if(v <= n+1) return false;
    if(c[x[a]][v] == 0) return false;
    if(v > n+1)
        if(!visited[v-n]) return false;
    if(!visited[v]) return true;
    return false;
}

void solution() {
    if(distanceCur + c[x[2*n + 1]][1] < distanceMin) distanceMin = distanceCur + c[x[2*n + 1]][1];
}

void Try(int a) {
    for (int v = 2;v<= 2*n+1;v++)
    {
        if(check(v, a)) {
            x[a+1] = v;
            visited[v] = true;
            distanceCur += c[x[a]][v];
            if(v<=n+1) q++;
            else q--;
            if(a == 2*n) solution();
            else
                if(distanceCur + (2*n - a) * minDist < distanceMin) Try(a+1); 
            if(v<=n+1) q--;
            else q++;
            visited[v] = false;
            distanceCur -= c[x[a]][v];
        }
    }
}

int main() {
    input();
    x[1] = 1;
    Try(1);
    cout << distanceMin;
    return 0;
}