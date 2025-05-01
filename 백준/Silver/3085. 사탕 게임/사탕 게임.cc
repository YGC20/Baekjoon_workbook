#include <iostream>
#include <algorithm>
using namespace std;
int boardSize=3, maxCandy=0;
char board[51][51];
void check();
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>boardSize;
    for(int i=0;i<boardSize;i++)
        for(int j=0;j<boardSize;j++)
            cin>>board[i][j];
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize-1;j++){
            swap(board[i][j],board[i][j+1]);
            check();
            swap(board[i][j],board[i][j+1]);
        }
    }
    for(int j=0;j<boardSize;j++){
        for(int i=0;i<boardSize-1;i++){
            swap(board[i][j],board[i+1][j]);
            check();
            swap(board[i][j],board[i+1][j]);
        }
    }
    cout<<maxCandy;
    return 0;
}
void check(){
    char candyColor;
    for(int i=0;i<boardSize;i++){
        int count=1;
        candyColor=board[i][0];
        for(int j=1;j<boardSize;j++){
            if(board[i][j]==candyColor)
                count+=1;
            else
                count=1;
            candyColor=board[i][j];
            if(count>maxCandy)
                maxCandy=count;
        }
    }
    for(int j=0;j<boardSize;j++){
        int count=1;
        candyColor=board[0][j];
        for(int i=1;i<boardSize;i++){
            if(board[i][j]==candyColor)
                count+=1;
            else
                count=1;
            candyColor=board[i][j];
            if(count>maxCandy)
                maxCandy=count;
        }
    }
}