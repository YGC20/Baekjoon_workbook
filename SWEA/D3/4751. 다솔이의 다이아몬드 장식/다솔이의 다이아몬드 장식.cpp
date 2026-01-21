#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        string set1="..#.";
        string set2=".#.#";
        string str = "";
        cin>>str;
        int strLen = str.size();
        
        for(int i=0;i<strLen;++i)
        {
            cout<<set1;
        }
        cout<<".\n";
        
        for(int i=0;i<strLen;++i)
        {
            cout<<set2;
        }
        cout<<".\n";
        
        for(char s:str)
        {
            cout<<"#."<<s<<".";
        }
        cout<<"#\n";
        
        for(int i=0;i<strLen;++i)
        {
            cout<<set2;
        }
        cout<<".\n";
        
        for(int i=0;i<strLen;++i)
        {
            cout<<set1;
        }
        cout<<".\n";
	}
	return 0;
}