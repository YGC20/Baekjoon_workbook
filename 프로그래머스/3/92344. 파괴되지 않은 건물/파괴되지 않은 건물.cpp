#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skills)
{
    int rows = board.size();
    int cols = board[0].size();
    
    vector<vector<int>> stk(rows+1, vector<int>(cols+1, 0));
    for(auto& skill : skills) {
        int atype = skill[0], damage = skill[5];
        int r0 = skill[1], c0 = skill[2], r1 = skill[3], c1 = skill[4];
        if(atype == 1) { damage = -damage; }
        stk[r0][c0] += damage;
        stk[r0][c1+1] -= damage;
        stk[r1+1][c0] -= damage;
        stk[r1+1][c1+1] += damage;
    }
    
    for(int i=0; i<rows; ++i) {
        for(int j=1; j<cols; ++j) {
            stk[i][j] += stk[i][j-1];
        }
    }
    
    for(int j=0; j<cols; ++j) {
        for(int i=1; i<rows; ++i) {
            stk[i][j] += stk[i-1][j];
        }
    }
    
    int result = 0;
    for(int i=0; i<rows; ++i) {
        for(int j=0; j<cols; ++j) {
            board[i][j] += stk[i][j];
            if(board[i][j] > 0) { ++result; }
        }
    }
    return result;
}