#include <iostream>
#include <vector>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int k, num, sum=0;
    vector<int> money;
    cin>>k;
    for(int i=0; i<k; i++){
        cin>>num;
        if(num!=0){
            money.push_back(num);
        } else{
            money.pop_back();
        }
    }
    for(int num:money){
        sum+=num;
    }
    cout<<sum<<"\n";
    return 0;
}