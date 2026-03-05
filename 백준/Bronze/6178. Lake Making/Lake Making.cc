#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C, E, N;
    cin>>R>>C>>E>>N;
    vector<vector<int>> maps(R, vector<int>(C));
    for(int i=0; i<R; ++i) {
        for(int j=0; j<C; ++j) {
            cin>>maps[i][j];
        }
    }
    for(int i=0; i<N; ++i) {
        int R_s, C_s, D_s;
        cin>>R_s>>C_s>>D_s;
        R_s--; C_s--;
        int highest = 0;
        for(int i=R_s; i<R_s+3; ++i) {
            for(int j=C_s; j<C_s+3; ++j) {
                if(maps[i][j]>highest) {
                    highest = maps[i][j];
                }
            }
        }
        highest-=D_s;
        for(int i=R_s; i<R_s+3; ++i) {
            for(int j=C_s; j<C_s+3; ++j) {
                if(maps[i][j]>highest) {
                    maps[i][j]=highest;
                }
            }
        }
    }

    int sum = 0;
    for(int i=0; i<R; ++i) {
        for(int j=0; j<C; ++j) {
            int deep = E-maps[i][j];
            if(deep>=0) {
                sum+=deep;
            }
        }
    }
    int vol = sum*72*72;
    cout<<vol<<"\n";
    return 0;
}