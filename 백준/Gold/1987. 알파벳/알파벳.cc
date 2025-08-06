#include <iostream>
using namespace std;
int R,C,maxCount=0;
char maps[21][21];
bool visited_alpha[26];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
void backtrack(int x, int y, int count){
    if(count > maxCount) maxCount = count;

    for(int i=0; i<4; i++){
        int mx = x + dx[i];
        int my = y + dy[i];
        
        if(mx >= 0 && mx < R && my >= 0 && my < C && !visited_alpha[maps[mx][my]-'A']){
            visited_alpha[maps[mx][my]-'A'] = true;
            backtrack(mx, my, count + 1);
            visited_alpha[maps[mx][my]-'A'] = false;
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>R>>C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>maps[i][j];
        }
    }
    visited_alpha[maps[0][0]-'A']=true;
    backtrack(0,0,1);
    cout<<maxCount<<"\n";
    return 0;
}