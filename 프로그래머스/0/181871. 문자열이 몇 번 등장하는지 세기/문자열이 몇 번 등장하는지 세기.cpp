#include <string>
#include <vector>
using namespace std;

int solution(string myString, string pat)
{
    int cnt = 0;
    for(int i=0; i<myString.size(); i++) {
        if((i+pat.size()-1)<myString.size() && myString[i]==pat[0]) {
            bool check = true;
            for(int j=0; j<pat.size(); j++) {
                if(pat[j]!=myString[i+j]) check = false;
            }
            if(check) cnt++;
        }
    }
    return cnt;
}