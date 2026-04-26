#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<int> num_list, int n)
{
    vector<vector<int>> result;
    for(int i=0; i<num_list.size(); i+=n) {
        vector<int> tmp;
        for(int j=i; j<(n+i); j++) {
            tmp.push_back(num_list[j]);
        }
        result.push_back(tmp);
    }
    return result;
}