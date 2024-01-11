#include<bits/stdc++.h>
#include<set>
#include<string>

using namespace std;
set<string> database;

void input() {
    string k;
    while(true) {
        cin >> k;
        if(k == "*") {
            break;
        }
        database.insert(k);
    }
}

void solution() {
    string key, cmd;
    while(true) {
        cin >> cmd;
        if(cmd == "***") {
            break;
        }
        cin >> key;

        if(cmd == "find") {
            cout << (database.find(key) != database.end() ? 1 : 0) << endl;
        }else if(cmd == "insert") {
            if(database.find(key) != database.end()) {
                cout << 0 << endl;
            }else {
                database.insert(key);
                cout << 1 << endl;
            }
        }
    }
}

int main() {
    input();
    solution();

    return 0;
}