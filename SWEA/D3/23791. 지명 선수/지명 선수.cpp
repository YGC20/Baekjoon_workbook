#include<iostream>
#include<vector>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
		int N; cin>>N;
        vector<int> A(N),B(N);
        vector<char> m(N,'0');
        for(int i=0;i<N;++i) {
            cin>>A[i];
        }
        for(int i=0;i<N;++i) {
            cin>>B[i];
        }
        int ai = 0,bi = 0;
        for(int i=0;i<N;++i) {
            if(i%2==0) {
                while(m[A[ai]-1]!='0') {
                    ai++;
                }
                m[A[ai]-1] = 'A';
                ai++;
            }
            else {
                while(m[B[bi]-1]!='0') {
                    bi++;
                }
                m[B[bi]-1] = 'B';
                bi++;
            }
        }
        for(char ab:m) {
            cout<<ab;
        } cout<<"\n";
	}
	return 0;
}