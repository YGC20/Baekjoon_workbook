#include <iostream>
#include <stack>
using namespace std;

int setPriority(char op)
{
    if(op == '*') { return 2; }
    if(op == '+') { return 1; }
    return 0;
}

int main(int argc, char** argv)
{
    int T = 10;
    for(int tc=1; tc<=T; ++tc) {
        int N; cin >> N;
        string exper; cin >> exper;

        stack<int> num;
        stack<char> op;

        for(auto& e : exper) {
            if(isdigit(e)) { num.push(e - '0'); }
            else if(e == '(') { op.push(e); }
            else if(e == ')') {
                while(!op.empty() && op.top() != '(') {
                    char curr = op.top(); op.pop();
                    int n2 = num.top(); num.pop();
                    int n1 = num.top(); num.pop();

                    if(curr == '+') { num.push(n1 + n2); }
                    else if(curr == '*') { num.push(n1 * n2); }
                }
                if(!op.empty()) { op.pop(); }
            }
            else {
                while(!op.empty() && setPriority(op.top()) >= setPriority(e)) {
                    char curr = op.top(); op.pop();
                    int n2 = num.top(); num.pop();
                    int n1 = num.top(); num.pop();

                    if(curr == '+') { num.push(n1 + n2); }
                    else if(curr == '*') { num.push(n1 * n2); }
                }
                op.push(e);
            }
        }

        while(!op.empty()) {
            char curr = op.top(); op.pop();
            int n2 = num.top(); num.pop();
            int n1 = num.top(); num.pop();

            if(curr == '+') { num.push(n1 + n2); }
            else if(curr == '*') { num.push(n1 * n2); }
        }

        cout << "#" << tc << " " << num.top() << endl;
    } /* for tc T */
    return 0;
}