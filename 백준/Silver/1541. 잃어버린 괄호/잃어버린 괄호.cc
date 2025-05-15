#include <iostream>
#include <vector>
using namespace std;
void lostBracket(void){
    string expre, temp = "";
    vector<int> nums;
    vector<char> operators;
    cin>>expre;
    for(int i=0;i<expre.size();i++){
        if(expre[i]=='+'||expre[i]=='-'){
            nums.push_back(stoi(temp));
            operators.push_back(expre[i]);
            temp="";
        }
        else temp+=expre[i];
    }
    nums.push_back(stoi(temp));

    int result = nums[0];
    bool minus = false;
    for(int i=0;i<operators.size();i++){
        if(operators[i]=='-') minus = true;
        if(minus) result-=nums[i+1];
        else result+=nums[i+1];
    }
    cout<<result<<"\n";
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    lostBracket();
    return 0;
}