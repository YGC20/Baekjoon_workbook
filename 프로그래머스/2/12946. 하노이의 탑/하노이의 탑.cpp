#include <string>
#include <vector>
using namespace std;
vector<vector<int>> tower;
void hanoi(int n, int from, int tmp, int to){
    if(n==1)    tower.push_back({from,to});
    else{
        hanoi(n-1,from,to,tmp);
        tower.push_back({from,to});
        hanoi(n-1,tmp,from,to);
    }
}
vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 2, 3);
    for(vector<int> t:tower){
        answer.push_back(t);
    }
    return answer;
}