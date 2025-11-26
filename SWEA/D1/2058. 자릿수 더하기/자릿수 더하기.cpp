#include<iostream>
using namespace std;
int main(int argc, char** argv) {
	string N; cin>>N;
    int sum = 0;
    for(int i=0;i<N.size();++i)
        if('0'<=N[i] && N[i]<='9') sum+=(N[i]-'0');
    cout<<sum<<"\n";
	return 0;
}