#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    
    int n;
    string order;
    queue<int> que;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> order;
        
        if (order == "push") {
            int orderNum;
            cin >> orderNum;
            que.push(orderNum);
        }
        else if (order == "pop") {
            if (que.empty()) {
                cout << "-1\n";
            }
            else {
                cout << que.front() << "\n";
                que.pop();
            }
        }
        else if (order == "size") {
            cout << que.size() << "\n";
        }
        else if (order == "empty") {
            cout << que.empty() << "\n";
        }
        else if (order == "front") {
            if (que.empty()) {
                cout << "-1\n";
            }
            else {
                cout << que.front() << "\n";
            }
        }
        else if (order == "back") {
            if (que.empty()) {
                cout << "-1\n";
            }
            else {
                cout << que.back() << "\n";
            }
        }
    }
    return 0;
}
