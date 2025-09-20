#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown+yellow;
    for(int y=3;y<=total;++y){
        if(total%y==0){
            int x=total/y;
            if(x>=y&&((x-2)*(y-2)==yellow)){
                answer.push_back(x);
                answer.push_back(y);
            }
        }
    }
    return answer;
}