#include<bits/stdc++.h>

using namespace std;
#define MAX 1000000
unsigned long long n, a[MAX];
unsigned long long sc[MAX];
unsigned long long sl[MAX];
unsigned long long exist_chan[MAX];
unsigned long long exist_le[MAX];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        exist_chan[i] = exist_le[i] = 1;
        sc[i] = sl[i] = 0;
    }
}

unsigned long long MaxEvenSubSeq() {
    unsigned long long res = 0;
    if(a[1] % 2 == 1){
        exist_chan[1] = -1;
        sl[1] = a[1];
    }else {
        exist_le[1] = -1;
        sc[1] = a[1];
    }
    for(int i = 2;i <= n; i++) {
        if(a[i] % 2 == 0) {
            if(exist_chan[i-1] == 1 && sc[i-1] > 0) sc[i] = sc[i-1] + a[i];
            else sc[i] == a[i];
            if(exist_le[i-1] == 1 && sl[i-1] > 0) sl[i] = sl[i-1] + a[i];
            else exist_le[i] = -1;
        }else{
            if(exist_le[i-1] == 1 && sl[i-1] > 0) sl[i] = sl[i-1] + a[i];
            else sl[i] == a[i];
            if(exist_chan[i-1] == 1 && sc[i-1] > 0) sc[i] = sc[i-1] + a[i];
            else exist_chan[i] = -1;
        }
        if(sc[i] > res && sc[i] == 1) res = sc[i]; 
    }
    return res;
}

int main() {
    input();
    cout << MaxEvenSubSeq();
    return 0;
}