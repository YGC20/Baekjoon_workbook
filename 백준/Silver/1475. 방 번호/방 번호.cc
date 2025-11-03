#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    ios::sync_with_stdio(false);
    cout.tie(NULL); cin.tie(NULL);
    int n;
    cin>>n;
    string num = to_string(n);
    vector<int> numBox(10,0);
    for(char x:num)
        numBox[x-'0']++;
    numBox[6] = numBox[9] = (numBox[6]+numBox[9]+1)/2;
    int max = *max_element(numBox.begin(),numBox.end());
    cout<<max<<"\n";
    return 0;
}