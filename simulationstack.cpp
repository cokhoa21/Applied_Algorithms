#include<bits/stdc++.h>
#include<string>
#include<stack>

using namespace std;
stack<int> database;


void solution() {
    string cmd;
    int key;
    while (true)
    {
        cin >> cmd;
        if(cmd == "#") {
            break;
        }

        if(cmd == "PUSH") {
            cin >> key;
            database.push(key);
        }else if(cmd == "POP") {
            if(database.empty()) {
                cout << "NULL" << endl;
            }
            else {
                cout << database.top() << endl;
                database.pop();
            }
        }
    }
}

int main() {
    solution();
    return 0;
}