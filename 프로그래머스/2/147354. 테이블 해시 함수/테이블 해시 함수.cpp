#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int sol(vector<int> tup, int idx)
{
    int sum = 0;
    for(auto& t : tup) { sum += t % idx; }
    return sum;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end)
{
    sort(data.begin(), data.end(), 
         [col](const vector<int>& a, const vector<int>& b){ 
             if(a[col-1] == b[col-1]) { return a[0] > b[0]; }
             return a[col-1] < b[col-1]; 
         });
    
    int answer = sol(data[row_begin - 1], row_begin);
    for(int i=row_begin; i<row_end; ++i) {
        answer ^= sol(data[i], i+1);
    }
    
    return answer;
}