#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	int T, N; cin>>T;
    int value[8] = {50000,10000,5000,1000,500,100,50,10};
    int money[8] = {0};
	for(int tc=1; tc<=T; ++tc) {
		cin>>N;
        for(int i=0; i<8; ++i) {
            money[i] += N / value[i];
            N %= value[i];
        } /* for i */
        
        cout << "#" << tc << "\n";
        for(int i=0; i<8; ++i) {
            cout << money[i] << " ";
            money[i] = 0;
        } /* for i */
        cout << "\n";
	} /* for tc */
	return 0;
}