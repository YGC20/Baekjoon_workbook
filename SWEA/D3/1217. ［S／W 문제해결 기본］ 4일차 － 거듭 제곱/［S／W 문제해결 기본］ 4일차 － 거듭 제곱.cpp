#include<iostream>
using namespace std;
int square(int num, int cnt)
{
    if(cnt==1) return num;
    return square(num,--cnt)*num;
}
int main(int argc, char** argv)
{
	for(int i=0;i<10;++i)
    {
        int test_case; cin>>test_case;
        int num, cnt; cin>>num>>cnt;
        cout<<"#"<<test_case<<" "<<square(num,cnt)<<"\n";
    }
	return 0;
}