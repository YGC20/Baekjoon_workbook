#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s) {
    string ans = "";
    sort(s.begin(), s.end());
    
    for(int i=0; i<s.length(); i++) {
        bool unique = true;
        if(i>0 && s[i]==s[i-1]) unique = false;
        if(i<s.length()-1 && s[i]==s[i+1]) unique = false;
        
        if(unique) ans += s[i];
    }
    return ans;
}