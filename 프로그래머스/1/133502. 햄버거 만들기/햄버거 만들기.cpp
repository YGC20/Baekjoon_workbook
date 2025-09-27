#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0, idx = 0;
    vector<int> bugger(ingredient.size(),0);
    for(auto i=0;i<ingredient.size();++i){
        bugger[idx]=ingredient[i];
        if(i>2 && bugger[idx]==1 && bugger[idx-1]==3 && bugger[idx-2]==2 && bugger[idx-3]==1){
            idx-=3;
            answer++;
        }
        else idx++;
    }
    return answer;
}