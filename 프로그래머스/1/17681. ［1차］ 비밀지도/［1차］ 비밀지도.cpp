#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string binaryPadding(int x, int n){
    string binary = "";
    if(x==0) binary = "0";
    while(x>0){
        binary += ((x&1) ? '1':'0');
        x>>=1;
    }
    reverse(binary.begin(),binary.end());
    if((int)binary.size()<n)
        binary = string(n-binary.size(),'0')+binary;
    return binary;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> binArr1, binArr2;
    string binary = "";
    for(int a:arr1){
        binArr1.push_back(binaryPadding(a,n));
    }
    for(int a:arr2){
        binArr2.push_back(binaryPadding(a,n));
    }
    vector<string> answer(n);
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(binArr1[i][j]=='0' && binArr2[i][j]=='0')
                answer[i].push_back(' ');
            else
                answer[i].push_back('#');
        }
    }
    return answer;
}