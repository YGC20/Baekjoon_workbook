#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAX_N (16+2)

int N, result;
int sX, sY, eX, eY;
int mazeMap[MAX_N][MAX_N] = {0};

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

typedef struct _node {
    int x, y;
} Node;

void inputData(void)
{
    cin>>N;
    char temp[MAX_N] = {0};
    for(int i=1; i<=16; ++i) {
        cin>>temp+1;
        for(int j=1; j<=16; ++j) {
            mazeMap[i][j] = temp[j]-'0';
            if(temp[j]=='2') sX=i, sY=j;
            else if(temp[j]=='3') eX=i, eY=j;
        }
    }
}

int mazeBFS(void)
{
    queue<Node> que;
    que.push({sX,sY});
    
    int cX, cY, nX, nY;
    while(!que.empty()) {
        Node curr = que.front(); que.pop();
        cX = curr.x; cY = curr.y;
        for(int i=0; i<4; ++i) {
            nX = cX+dx[i]; nY = cY+dy[i];
            if(nX<=0 || nX>16 || nY<=0 || nY>16) continue;
            if(mazeMap[nX][nY]!=0 && mazeMap[nX][nY]!=3) continue;
            
            mazeMap[nX][nY] = mazeMap[cX][cY]+1;
            que.push({nX,nY});
        }
    }
    
    int ans = 1;
    if(mazeMap[eX][eY]==3) ans = 0;
    return ans;
}

int main(int argc, char** argv)
{
    int testCase;
	for(testCase = 1; testCase <= 10; ++testCase) {
        inputData();
        result=0;
        result = mazeBFS();
        cout<<"#"<<N<<" "<<result<<"\n";
	}
	return 0;
}