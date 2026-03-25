#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes)
{
    int len = sizes.size();
    vector<int> w_sort(len);
    vector<int> h_sort(len);
    for(int i=0; i<len; ++i) {
        w_sort[i] = sizes[i][0]>sizes[i][1]?sizes[i][0]:sizes[i][1];
        h_sort[i] = sizes[i][0]<sizes[i][1]?sizes[i][0]:sizes[i][1];
    }
    sort(w_sort.rbegin(),w_sort.rend());
    sort(h_sort.rbegin(),h_sort.rend());

    return w_sort[0]*h_sort[0];
}