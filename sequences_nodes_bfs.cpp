#include<bits/stdc++.h>
#include<queue>

using namespace std;

#define MAX 1e5
int n, m;
vector<vector<int>> a(MAX);
vector<int> result;
vector<bool> visited(MAX, false);
queue<int> q;

void input() {
    cin >> n >> m;
    int cmd1, cmd2;
    for (int i = 0; i < m; i++)
    {
        cin >> cmd1 >> cmd2;
        a[cmd1].push_back(cmd2);
        a[cmd2].push_back(cmd1);
    }
}

void bfs(int u) {
    q.push(u);
    visited[u] = true;
    while (!q.empty())
    {
        int v = q.front();
        result.push_back(v);
        q.pop();
        sort(a[v].begin(), a[v].end());
        for(int x : a[v]) {
            if(!visited[x]) {
                q.push(x);
                visited[x] = true;
            }
        }
    }    
}

int main() {
    input();
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) bfs(i);
    }
    for(int node : result) {
        cout << node << " ";
    }
    return 0;
}