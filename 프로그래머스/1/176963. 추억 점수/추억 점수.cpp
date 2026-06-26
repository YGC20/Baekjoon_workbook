#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    int nlen = name.size(), plen = photo.size();
    vector<int> result;
    unordered_map<string, int> npum;
    for(int i=0; i<nlen; ++i) {
        npum[name[i]] = yearning[i];
    }
    
    for(const auto& pl : photo) {
        int sum = 0;
        for(const auto& n : pl) {
            sum += npum[n];
        }
        result.push_back(sum);
    }
    return result;
}