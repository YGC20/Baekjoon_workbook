#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T; cin>>T;
	for(test_case = 1; test_case <= T; ++test_case) {
        int n, k; cin>>n>>k;
        int pulzze[n][n];
        for(int i=0;i<n;++i) for(int j=0;j<n;++j)
            cin>>pulzze[i][j];
        int answer = 0;
        int cnt = 0;
        for(int i=0;i<n;++i){
            cnt = 0;
            for(int j=0;j<n;++j){
                if(pulzze[i][j]==1) cnt++;
                else{
                    if(cnt==k) answer++;
                    cnt = 0;
                }
            }
            if(cnt==k) answer++;
        }
        
        
        for(int j=0;j<n;++j){
            cnt = 0;
            for(int i=0;i<n;++i){
                if(pulzze[i][j]==1) cnt++;
                else{
                    if(cnt==k) answer++;
                    cnt = 0;
                }
            }
            if(cnt==k) answer++;
        }
        
        cout<<"#"<<test_case<<" "<<answer<<"\n";
	}
	return 0;
}