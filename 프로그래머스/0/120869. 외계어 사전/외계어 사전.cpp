#include <string>
#include <vector>
using namespace std;

int solution(vector<string> spell, vector<string> dic)
{
    for(auto d : dic) {
        int checkCnt = 0;
        for(auto s : spell) {
            if(d.find(s)!=string::npos) checkCnt++;
        }
        if(checkCnt==spell.size()) return 1;
    }
    return 2;
}