#include <string>
#include <vector>
using namespace std;

int solution(vector<string> babbling)
{
    int cnt = 0;
    vector<string> canSp = {"aya","ye","woo","ma"};
    
    for(auto& bl : babbling) {
        bool cc = false;
        for(const auto& cs : canSp) {
            if(bl.find(cs+cs)!=string::npos) {
                cc = true;
                break;
            }
        }
        if(cc) continue;
        
        for(const auto& cs : canSp) {
            int idx = 0;
            while((idx=bl.find(cs))!=string::npos) {
                bl.replace(idx, cs.length(), " ");
            }
        }
        
        bool cv = true;
        for(auto ch : bl) {
            if(ch!=' ') {
                cv = false;
                break;
            }
        }
        if(cv) cnt++;
    }
    return cnt;
}