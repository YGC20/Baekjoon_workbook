#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    int num;
    cin>>num;
    vector<int> numbers;
    for(int i=1;i<=num;++i)
        numbers.push_back(i);
    do{
        for(int n:numbers) cout<<n<<" ";
        cout<<"\n";
    } while(next_permutation(numbers.begin(),numbers.end()));
    return 0;
}