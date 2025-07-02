#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void cardSort(void){
    int N, min;
    cin>>N;
    vector<int> decks(N);
    for(int i=0; i<N; i++) cin>>decks[i];
    make_heap(decks.begin(), decks.end(), greater<int>());
    int result=0;
    while(decks.size()>1){
        pop_heap(decks.begin(), decks.end(), greater<int>());
        int a = decks.back();
        decks.pop_back();
        pop_heap(decks.begin(), decks.end(), greater<int>());
        int b = decks.back();
        decks.pop_back();
        int sum = a+b;
        result+=sum;
        decks.push_back(sum);
        push_heap(decks.begin(), decks.end(), greater<int>());
    }
    cout<<result<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cardSort();
    return 0;
}