#include <string>
#include <vector>
using namespace std;

vector<string> solution(vector<string> strArr)
{
    vector<string> result;
    for(const string& sa : strArr) {
        if(sa.find("ad")==string::npos) result.push_back(sa);
    }
    return result;
}