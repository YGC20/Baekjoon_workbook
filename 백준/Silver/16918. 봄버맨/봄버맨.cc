#include <iostream>
#include <vector>
using namespace std;
int R,C,N;
vector<string> initial_grid;
void print_grid(const vector<string>& grid){
    for(int i=0;i<R;++i)
        cout<<grid[i]<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>R>>C>>N;
    initial_grid.resize(R);
    for(int i=0;i<R;++i)
        cin>>initial_grid[i];
    
    if(N<=1){
        print_grid(initial_grid);
        return 0;
    }
    if(N%2==0){
        vector<string> full_grid(R,string(C,'O'));
        print_grid(full_grid);
        return 0;
    }
    vector<string> grid1(R,string(C,'O'));
    int dx[]={0,0,1,-1,0}, dy[]={1,-1,0,0,0};
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            if(initial_grid[i][j]=='O'){
                for(int k=0;k<5;++k){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni>=0&&ni<R&&nj>=0&&nj<C){
                        grid1[ni][nj]='.';
                    }
                }
            }
        }
    }
    if(N%4==3){
        print_grid(grid1);
        return 0;
    }
    vector<string> grid2(R,string(C,'O'));
    for(int i=0;i<R;++i){
        for(int j=0;j<C;++j){
            if(grid1[i][j]=='O'){
                for(int k=0;k<5;++k){
                    int ni=i+dx[k];
                    int nj=j+dy[k];
                    if(ni>=0&&ni<R&&nj>=0&&nj<C){
                        grid2[ni][nj]='.';
                    }
                }
            }
        }
    }
    if(N%4==1){
        print_grid(grid2);
        return 0;
    }
    return 0;
}