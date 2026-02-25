#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr)
{
    vector<vector<int>> tmp = arr;
    int row = tmp.size();
    int col = tmp[0].size();
    
    if(row>col) {
        int rc = row-col;
        for(int i=0; i<row; ++i) {
            for(int j=0; j<rc; ++j) {
                tmp[i].push_back(0);
            }
        }
    }
    else if(col>row) {
        int cr = col-row;
        for(int i=0; i<cr; ++i) {
            tmp.push_back(vector<int>(col,0));
        }
    }
    return tmp;
}