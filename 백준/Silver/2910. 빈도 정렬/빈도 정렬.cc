#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct Element{
    int num;
    int freq;
    int order;
};
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N, C, i;
    cin>>N>>C;
    map<int, int> freq;
    map<int, int> order;
    vector<int> input(N);
    for(i=0; i<N; i++){
        cin>>input[i];
        freq[input[i]]++;
        if(order.find(input[i])==order.end())
            order[input[i]]=i;
    }
    vector<Element> elems;
    for(auto& e:freq)
        elems.push_back({e.first, e.second, order[e.first]});
    sort(elems.begin(), elems.end(), [](Element a, Element b){
        if(a.freq!=b.freq) return a.freq>b.freq;
        return a.order<b.order;
    });
    for(auto& e:elems)
        for(i=0; i<e.freq; i++)
            cout<<e.num<<" ";
    return 0;
}