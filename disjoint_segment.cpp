#include<bits/stdc++.h>

using namespace std;
#define MAX 1000000
int n;
pair<int, int> x[MAX];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i].first;
        cin >> x[i].second;
    }
    
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int solve() {
    int res = 0;
    int last = -1;
    sort(x+1, x+n+1, cmp);
    for (int i = 1; i <= n; i++)
    {
        if(x[i].first > last) {
            res++;
            last = x[i].second;
        }
    }
    return res;
}
int main() {
    input();
    cout << solve();
    return 0;
}