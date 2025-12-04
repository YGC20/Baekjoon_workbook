#include<iostream>
#include<string>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
		string command; cin>>command;
        int Lpos = 0, Rpos = 0;
        int maxLpos = 0, maxRpos = 0;
        for(char c:command) {
            if(c=='L') {
                Lpos--; Rpos--;
            }
            else if(c=='R') {
                Lpos++; Rpos++;
            }
            else if(c=='?') {
                Lpos--; Rpos++;
            }
            int absLpos = (Lpos>0)?Lpos:-Lpos;
            int absRpos = (Rpos>0)?Rpos:-Rpos;
            maxLpos = (absLpos>maxLpos)?absLpos:maxLpos;
            maxRpos = (absRpos>maxRpos)?absRpos:maxRpos;
        }
        int answer = (maxLpos>maxRpos)?maxLpos:maxRpos;
        cout<<answer<<"\n";
	}
	return 0;
}