#include<iostream>
using namespace std;
int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int A,B; cin>>A>>B;
    switch(A) {
        case 1:
            if(B==2) cout<<"B\n";
            else if(B==3) cout<<"A\n";
        case 2:
            if(B==1) cout<<"A\n";
            else if(B==3) cout<<"B\n";
        case 3:
            if(B==1) cout<<"B\n";
            else if(B==2) cout<<"A\n";
    }
    return 0;
}