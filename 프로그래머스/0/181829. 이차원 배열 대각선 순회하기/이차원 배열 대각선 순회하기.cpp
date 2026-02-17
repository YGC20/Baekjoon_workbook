#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, int k)
{
    int answer = 0;
    int x_index = board.size();
    int y_index = board[0].size();

    for(int i=0; i<x_index; ++i) {
        for(int j=0; j<y_index; ++j) {
            if((i+j)<=k) {
                answer += board[i][j];
            }
        }
    }

    return answer;
}