#include <iostream>
using namespace std;
int N, nums[11], operators[4];
int numMin=1000000001, numMax=-1000000001;
void getanswer(int result, int idx){
    if(idx==N){
        if(result>numMax)
            numMax=result;
        if(result<numMin)
            numMin=result;
        return;
    }
    for(int i=0;i<4;i++){
        if(operators[i]>0){
            operators[i]--;
            if(i==0)
                getanswer(result+nums[idx],idx+1);
            else if(i==1)
                getanswer(result-nums[idx],idx+1);
            else if(i==2)
                getanswer(result*nums[idx],idx+1);
            else if(i==3)
                getanswer(result/nums[idx],idx+1);
            operators[i]++;
        }
    }
    return;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>nums[i];
    for(int i=0;i<4;i++)
        cin>>operators[i];
    getanswer(nums[0],1);
    cout<<numMax<<"\n";
    cout<<numMin;
    return 0;
}