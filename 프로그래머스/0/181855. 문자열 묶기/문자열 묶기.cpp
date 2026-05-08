#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<string> strArr)
{
    vector<int> strGroup(31,0);
    
    for(string sa : strArr) {
        int len = sa.size();
        strGroup[len]++;
    }
    sort(strGroup.begin(), strGroup.end());
    return strGroup.back();
}