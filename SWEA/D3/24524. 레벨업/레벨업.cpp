#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
    for(test_case = 1; test_case <= T; ++test_case)	{
		int N; cin>>N;
        vector<int> node(N);
        for(int i=0;i<N;++i) {
            cin>>node[i];
        }
        int total_dist = 0;
        for(int i=0;i<N-1;++i) {
            total_dist+=abs(node[i+1]-node[i]);
        }
        int min_dist = total_dist;
        for(int i=1;i<N-1;++i) {
            int skip_route = abs(node[i]-node[i-1])+abs(node[i+1]-node[i]);
            int new_route = abs(node[i+1]-node[i-1]);
            int current_route = total_dist - skip_route + new_route;
            if(current_route<min_dist) {
            	min_dist = current_route;
            }
        }
        cout<<min_dist<<"\n";
	}
	return 0;
}