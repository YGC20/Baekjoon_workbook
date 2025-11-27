#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main(int argc, char** argv) {
    int n; cin>>n;
    vector<int> div;
    for(int i=1;i<=sqrt(n);++i) {
        if(n%i==0) {
            div.push_back(i);
            if(n!=i*i) div.push_back(n/i);
        }
    }
    sort(div.begin(),div.end());
    for(int d:div)
        cout<<d<<" ";
    cout<<"\n";
	return 0;
}