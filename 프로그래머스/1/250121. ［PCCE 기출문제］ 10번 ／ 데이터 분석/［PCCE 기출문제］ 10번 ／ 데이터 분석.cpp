#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int getIndex(string s)
{
    if(s=="code") return 0;
    if(s=="date") return 1;
    if(s=="maximum") return 2;
    if(s=="remain") return 3;
    return -1;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by)
{
    int iext = getIndex(ext);
    int isort_by = getIndex(sort_by);
    
    vector<vector<int>> answer;
    for(int i=0; i<data.size(); ++i) {
        if(data[i][iext]<val_ext) {
            answer.push_back(data[i]);
        }
    }
    sort(answer.begin(), answer.end(), [isort_by](const vector<int>& a, const vector<int>& b){ return a[isort_by]<b[isort_by]; });
    return answer;
}