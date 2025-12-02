#include<iostream>
#include<set>
using namespace std;
int main(int argc, char** argv) {
	int test_case;
	int T;	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)	{
    	int an,bn; cin>>an>>bn;
        set<int> A, B;
        for(int i=0;i<an;++i) {
            int tmp; cin>>tmp;
            A.insert(tmp);
        }
        for(int i=0;i<bn;++i) {
            int tmp; cin>>tmp;
            B.insert(tmp);
        }
                
        bool checkSet = true;
        if(an>=bn) {
            set<int>::iterator iter;
            for(iter=B.begin();iter!=B.end();iter++) {
                if(A.find(*iter)==A.end()) {
                    checkSet = false;
                }
            }
        }
        else {
            set<int>::iterator iter;
            for(iter=A.begin();iter!=A.end();iter++) {
                if(B.find(*iter)==B.end()) {
                    checkSet = false;
                }
            }
        }
        if(checkSet) {
            if(an>bn) {
                cout<<">\n";
            }
            else if(an<bn) {
                cout<<"<\n";
            }
            else {
                cout<<"=\n";
            }
        }
        else {
            cout<<"?\n";
        }
    }
	return 0;
}