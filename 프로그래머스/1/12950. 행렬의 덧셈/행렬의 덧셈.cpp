#include <string>
#include <vector>
using namespace std;

vector<vector<int>> 
solution(vector<vector<int>> arr1, 
    vector<vector<int>> arr2)
{
    int i, j;
    int rows = static_cast<int>(arr1.size());
    int cols = static_cast<int>(arr1[0].size());
    vector<vector<int>> answer(rows, vector<int>(cols, 0));

    for(i=0; i<rows; ++i) {
        for(j=0; j<cols; ++j) {
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return answer;
}