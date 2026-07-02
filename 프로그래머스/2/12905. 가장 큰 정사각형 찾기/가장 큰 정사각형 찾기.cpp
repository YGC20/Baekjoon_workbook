#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int r, c;
    int row = board.size();
    int col = board[0].size();
    
    int maxVal = 1;
    if(row>=2 && col >=2) {
        maxVal = 0;
    }
    for(r=1; r<row; ++r) {
        for(c=1; c<col; ++c) {
            if(board[r][c]==0) {
                continue;
            }
            board[r][c] = min({board[r][c-1], board[r-1][c], board[r-1][c-1]}) + 1;
            if(maxVal<board[r][c]) {
                maxVal = board[r][c];
            }
        }
    }
    maxVal *= maxVal;
    return maxVal;
}