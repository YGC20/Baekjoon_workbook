#include <string>
#include <vector>
using namespace std;

vector<string> solution(string myStr)
{
    vector<string> result;
    string tmp = "";
    for(auto ms : myStr) {
        if(ms=='a' || ms=='b' || ms=='c') {
            if(!tmp.empty()) {
                result.push_back(tmp);
                tmp.clear();
            }
        }
        else {
            tmp+=ms;
        }
    }
    if(!tmp.empty())
        result.push_back(tmp);
    
    if(result.empty()) return { "EMPTY" };
    else return result;
}