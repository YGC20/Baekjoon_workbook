#include <iostream>
using namespace std;
void blackjack(){
    int N, M, maxCard=0;
    cin>>N>>M;
    int card[N];
    for(int i=0;i<N;i++)
        cin>>card[i];
    for(int i=0;i<N-2;i++) for(int j=i+1;j<N-1;j++)
        for(int k = j + 1; k < N; k++) {
            int sum = card[i] + card[j] + card[k];
            if(sum <= M && sum > maxCard)
                maxCard = sum;
        }
    cout<<maxCard<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    blackjack();
    return 0;
}