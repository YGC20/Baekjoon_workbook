#include <iostream>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void dfs(int** martix, int** visited, int x, int y, int M, int N){
    visited[x][y] = 1;
    for(int i=0; i<4; i++){
        int next_x = x + dx[i];
        int next_y = y + dy[i];
        if(next_x>=0 && next_x<M && next_y>=0 && next_y<N && visited[next_x][next_y]==0 && martix[next_x][next_y]==1){
            dfs(martix, visited, next_x, next_y, M, N);
        }
    }
}

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while(T--){
		int M, N, K, result = 0;
		cin >> M >> N >> K;

		int** matrix = new int*[M];
		for(int i=0; i<M; i++){ matrix[i] = new int[N](); }
        int** visited = new int*[M];
        for(int i=0; i<M; i++){ visited[i] = new int[N](); }

		for(int i=0; i<K; i++){
			int X, Y;
			cin >> X >> Y;
			matrix[X][Y] = 1;
		}

		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				if(matrix[i][j]==1 && visited[i][j]==0){
					dfs(matrix, visited, i, j, M, N);
                    result++;
				}
			}
		}

        cout << result << "\n";

		for(int i=0; i<M; i++){
            delete[] matrix[i];
            delete[] visited[i];
        }
		delete[] matrix;
        delete[] visited;
	}
	return 0;
}