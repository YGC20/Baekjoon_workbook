#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int T;
    cin>>T;
    while(T--){
        string S;
        cin>>S;
        stack<char> password;
        stack<char> temp;
        for(char c:S){
            if(c=='<'){
                if(!password.empty()){
                    temp.push(password.top());
                    password.pop();
                }
            }
            else if(c=='>'){
                if(!temp.empty()){
                    password.push(temp.top());
                    temp.pop();
                }
            }
            else if(c=='-'){
                if(!password.empty())   password.pop();
            }
            else{
                password.push(c);
            }
        }
        while(!temp.empty()){
            password.push(temp.top());
            temp.pop();
        }
        string result;
        while(!password.empty()){
            result.push_back(password.top());
            password.pop();
        }
        reverse(result.begin(), result.end());
        cout<<result<<"\n";
    }
    return 0;
}