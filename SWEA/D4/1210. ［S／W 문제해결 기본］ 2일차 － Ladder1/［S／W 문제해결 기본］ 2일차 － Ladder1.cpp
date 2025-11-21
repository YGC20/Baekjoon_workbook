#include<iostream>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	for(test_case = 1; test_case <= 10; ++test_case) {
        int T; cin>>T;
        int maze[100][100];
        int start_y;
        for(int i=0;i<100;++i) for(int j=0;j<100;++j) {
            cin>>maze[i][j];
            if(i==99&&maze[i][j]==2) start_y=j; 
        }
        int cur_x = 99, cur_y = start_y;
        while(cur_x>0) {
            if(cur_y>0 && maze[cur_x][cur_y-1]==1) {
                while(cur_y>0 && maze[cur_x][cur_y-1]==1) cur_y--;
            }
            else if(cur_y<99 && maze[cur_x][cur_y+1]==1) {
                while(cur_y<99 && maze[cur_x][cur_y+1]==1) cur_y++;
            }
            cur_x--;
        }
        cout<<"#"<<T<<" "<<cur_y<<"\n";
	}
	return 0;
}