#include <iostream>
#include <vector>
using namespace std;

void solution(int start);

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int start;
    if(cin>>start) {
        solution(start);
    }
    return 0;
}

bool check_tigtagto(vector<vector<int>>& ttt, int user){
    for(int i=0; i<3; ++i) {
        if(ttt[i][0]==user && ttt[i][1]==user && ttt[i][2]==user) {
            return true;
        }
        if(ttt[0][i]==user && ttt[1][i]==user && ttt[2][i]==user) {
            return true;
        }
    }

    if(ttt[0][0]==user && ttt[1][1]==user && ttt[2][2]==user) {
        return true;
    }
    if(ttt[0][2]==user && ttt[1][1]==user && ttt[2][0]==user) {
        return true;
    }

    return false;
}

void solution(int start)
{
    int user = start;
    int winner = 0;
    bool ttt = false;
    vector<vector<int>> tigTagTo(3,vector<int>(3,0));
    for(int i=0; i<9; ++i) {
        int x, y;
        cin>>x>>y;
        x--; y--;
        tigTagTo[x][y]=user;
        if(winner==0 && check_tigtagto(tigTagTo,user)) {
            winner=user;
        }
        user=(user==1)?2:1;
    }
    cout<<winner<<"\n";
}