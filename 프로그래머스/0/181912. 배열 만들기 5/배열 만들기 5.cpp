#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l)
{
    vector<int> result;
    for(auto iss : intStrs) {
        int tmp = stoi(iss.substr(s,l));
        if(tmp>k)
            result.push_back(tmp);
    }
    return result;
}