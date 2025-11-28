#include<iostream>
#include<vector>
using namespace std;
int checkSudoku(const vector<vector<int>>& sudoku) {
    for(int i=0;i<9;++i) {
        vector<bool> visited(10,false);
        for(int j=0;j<9;++j) {
            int num = sudoku[i][j];
            if(visited[num]) return 0;
            visited[num] = true;
        } }
	
    for(int i=0;i<9;++i) {
        vector<bool> visited(10,false);
        for(int j=0;j<9;++j) {
            int num = sudoku[j][i];
            if(visited[num]) return 0;
            visited[num] = true;
        } }
    
    for(int i=0;i<9;i+=3) {
        for(int j=0;j<9;j+=3) {
            vector<bool> visited(10,false);
            for(int x=0;x<3;++x) {
                for(int y=0;y<3;++y) {
                    int num = sudoku[i+x][j+y];
                    if(visited[num]) return 0;
                    visited[num] = true;
                } } } }
    return 1;
}
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
    	vector<vector<int>> sudoku(9,vector<int>(9,0));
        for(int i=0;i<9;++i)
            for(int j=0;j<9;++j)
                cin>>sudoku[i][j];
        int answer = checkSudoku(sudoku);
        cout<<"#"<<test_case<<" "<<answer<<"\n";
    }
	return 0;
}