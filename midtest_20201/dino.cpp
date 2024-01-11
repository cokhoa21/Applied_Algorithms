#include<bits/stdc++.h>
#include<queue>
#include<stack>
#include<string>

using namespace std;
#define MAX 100005
stack<int> chuong;
queue<int> hanhlang;
int p[MAX];
int n;
string cmd;

void dino() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    for (int i = n; i >= 1; i--)
    {
        chuong.push(p[i]);
    }
    cin >> cmd;

    for(int i = 0; i < cmd.length(); i++) {
        if(cmd[i] == 'C') {
            if(!chuong.empty()) {
                int i = chuong.top();
                hanhlang.push(i);
                chuong.pop();
            }
        }else if(cmd[i] == 'H') {
            if(!hanhlang.empty()) {
                int i = hanhlang.front();
                chuong.push(i);
                hanhlang.pop();
            }
        }
    }

    while(!chuong.empty()) {
        cout << chuong.top() << " ";
        chuong.pop();
    }
    
}

int main() {
    dino();
    return 0;
}