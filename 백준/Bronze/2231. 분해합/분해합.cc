#include <iostream>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int N;
    bool check=false;
    cin>>N;
    int i=1;
    while(i<N){
        int digit=0;
        digit += i/1000000;
        digit += (i%1000000)/100000;
        digit += (i%100000)/10000;
        digit += (i%10000)/1000;
        digit += (i%1000)/100;
        digit += (i%100)/10;
        digit += i%10;
        if((i+digit)==N){
            cout<<i<<"\n";
            check=true;
            break;
        }
        i++;
    }
    if(check==false)
        cout<<"0\n";
    return 0;
}