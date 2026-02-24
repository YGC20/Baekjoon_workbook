#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string str;
    cin >> str;
    
    string change_str = "";
    for(char s : str) {
        char tmp;
        if('A'<=s && s<='Z') {
            tmp = (s-'A')+'a';
        }
        else if('a'<=s && s<='z') {
            tmp = (s-'a')+'A';
        }
        change_str+=tmp;
    }
    cout<<change_str<<"\n";
    return 0;
}