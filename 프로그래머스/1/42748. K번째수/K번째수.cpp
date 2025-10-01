#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(vector<int> c:commands){
        vector<int> temp;
        for(int i=0;i<array.size();++i){
            if(i>=(c[0]-1)&&i<c[1]) temp.push_back(array[i]);
        }
        sort(temp.begin(),temp.end());
        answer.push_back(temp[c[2]-1]);
    }
    return answer;
}