#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int cnt = 0;
    vector<int> bag;
    for(int m:moves){
        int moveDoll = 0;
        for(int i=0;i<board.size();++i){
            if(board[i][m-1]!=0){
                moveDoll = board[i][m-1];
                board[i][m-1] = 0;
                break;
            }
        }
        if(moveDoll!=0){
            if(!bag.empty()&&bag.back()==moveDoll){
                bag.pop_back();
                cnt+=2;
            }
            else
                bag.push_back(moveDoll);
        }
    }
    return cnt;
}