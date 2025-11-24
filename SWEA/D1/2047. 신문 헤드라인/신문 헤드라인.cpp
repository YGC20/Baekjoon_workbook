#include<iostream>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
    string headline; cin>>headline;
    for(int i=0;i<headline.size();++i) {
        if('a'<=headline[i] && headline[i]<='z') {
            headline[i]-=('a'-'A');
        }
    }
    cout<<headline<<"\n";
	return 0;
}