#include <iostream>
using namespace std;
void gasStation(void){
    int N;
    cin>>N;
    int gasPrice[N], gasLoad[N-1];
    for(int i=0;i<N-1;i++) cin>>gasLoad[i];
    for(int i=0;i<N;i++) cin>>gasPrice[i];
    int index=0, results=0, lastIndex=0, load=0;
    while(true){
        if(index==N) break;
        load+=gasLoad[index];
        if(gasPrice[index]>=gasPrice[index+1]){
            results+=gasPrice[lastIndex]*load;
            load=0;
            index++;
        }
        else {
            lastIndex=index;
            index++;
        }
    }
    cout<<results<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    gasStation();
    return 0;
}