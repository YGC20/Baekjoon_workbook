#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
    int i, j;
    int len = s.length();
    for(i=0; i<len; ++i) {
        if(s[i]!=' ') {
            for(j=1; j<=n; ++j) {
                s[i]+=1;
                if(s[i]>'z') s[i] = 'a';
                if(s[i]>'Z' && s[i]<'a') s[i] = 'A';
            }
        }
    }
    return s;
}