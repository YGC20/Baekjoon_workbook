#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board)
{
    int boardX = board[0]/2, boardY = board[1]/2;
    int x = 0, y = 0;
    for(auto cmd : keyinput) {
        if(cmd == "up" && y+1<=boardY) y++;
        else if(cmd == "left" && x-1>=-boardX) x--;
        else if(cmd == "right" && x+1<=boardX) x++;
        else if(cmd == "down" && y-1>=-boardY) y--;
    }
    return { x, y };
}