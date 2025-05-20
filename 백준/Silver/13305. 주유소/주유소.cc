#include <iostream>
using namespace std;
void gasStation(void){
    int N;
    cin>>N;
    int gasPrice[N], gasLoad[N-1];
    for(int i=0;i<N-1;i++) cin>>gasLoad[i];
    for(int i=0;i<N;i++) cin>>gasPrice[i];
    long long totalCost=0;
    int minPrice = gasPrice[0];
    for(int i=0;i<N-1;i++){
        if(gasPrice[i]<minPrice) minPrice=gasPrice[i];
        totalCost+=(long long)minPrice*gasLoad[i];
    }
    cout<<totalCost<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    gasStation();
    return 0;
}