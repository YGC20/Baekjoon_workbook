#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> targets)
{
    sort(targets.begin(), targets.end(), 
         [](const vector<int>& a, const vector<int>& b)
         { return a[1] < b[1]; });
    
    int cnt = 1;
    int tar = targets[0][1];
    for(int i=0; i<targets.size(); ++i) {
        if(tar <= targets[i][0]) {
            tar = targets[i][1];
            cnt++;
        }
    }
    return cnt;
}