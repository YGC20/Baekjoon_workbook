#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> A = {1,2,3,4,5};
    vector<int> B = {2,1,2,3,2,4,2,5};
    vector<int> C = {3,3,1,1,2,2,4,4,5,5};
    
    int acnt = 0, bcnt = 0, ccnt = 0;
    for(int i=0;i<(int)answers.size();++i){
        if(answers[i]==A[i%A.size()]) ++acnt;
        if(answers[i]==B[i%B.size()]) ++bcnt;
        if(answers[i]==C[i%C.size()]) ++ccnt;
    }
    
    int mx = max({acnt,bcnt,ccnt});
    vector<int> ans;
    if(acnt==mx) ans.push_back(1);
    if(bcnt==mx) ans.push_back(2);
    if(ccnt==mx) ans.push_back(3);
    return ans;
}