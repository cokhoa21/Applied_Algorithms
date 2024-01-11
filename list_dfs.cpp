#include<bits/stdc++.h>
#include<vector>
#include<stack>

using namespace std;
#define MAX 1e5
int n, m;
vector<vector<int>> a(MAX);
vector<int> result;
vector<bool> bvisited(MAX, false);           // đánh dấu những phần tử cho vào hàng đợi chưa duyệt  
vector<bool> bMarked(MAX, false);            // đánh dấu những phần tử đã duyệt xong

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

void dfs(int start) {
    if(bMarked[start]) return;
    result.push_back(start);
    bvisited[start] = true;
    bMarked[start] = true;
    for (int i : a[start])
    {
        bvisited[i] = true;
        dfs(i);
    }
}

int main() {
    input();
    dfs(1);
    for(int node : result) {
        cout << node << " ";
    }
    return 0;
}