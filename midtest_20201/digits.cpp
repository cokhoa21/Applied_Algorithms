#include<bits/stdc++.h>

using namespace std;

int T, N;
bool visited[10];
int cnt;
int x[50];
void input() {
    cnt = 0;
    cin >> N;
}

bool check(int v, int k) {
    if(k==1 && v==0) return false;
    if(k==3 && v==0) return false;
    return visited[v] == false;
}

void solution() {
    int hust = x[1]*1000 + x[2]*100 + x[3]*10 + x[4];
    int soict = x[3]*10000 + x[5]*1000 + x[6]*100 + x[7]*10 + x[4];

    if(hust + soict == N) cnt ++;
}

void Try(int k) {
    for(int v = 0;v <= 9; v++) {
        if(check(v, k)) {
            x[k] = v;
            visited[v] = true;
            if(k == 7) solution();
            else Try(k+1);
            visited[v] = false;
        }
    }
}

int main() {
    cin >> T;
    while(T > 0) {
        input();    
        Try(1);
        T--;
        cout << cnt << endl; 
    }
    return 0;
}