#include <string>
#include <vector>
using namespace std;

int solution(vector<string> babbling)
{
    int cnt = 0;
    vector<string> talk = { "aya", "ye", "woo", "ma" };
    
    for(string bl : babbling) {
        int i=0;
        bool speak = true;
        
        while(i<bl.length()) {
            bool matched = false;
            for(string t : talk) {
                if(bl.substr(i, t.length()) == t) {
                    i += t.length();
                    matched = true;
                    break;
                }
            }
            if(!matched) {
                speak = false;
                break;
            }
        }
        
        if(speak) cnt++;
    }
    
    return cnt;
}