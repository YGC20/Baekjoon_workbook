#include<iostream>
#include<string>
using namespace std;
int main(int argc, char** argv) {
	string arr; cin>>arr;
	for(char a:arr) {
		cout<<a-'A'+1<<" ";
	} cout<<"\n";
	return 0;
}