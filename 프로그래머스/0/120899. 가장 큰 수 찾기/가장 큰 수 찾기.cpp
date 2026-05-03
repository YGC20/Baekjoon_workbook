#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array)
{
    vector<int> pos = array;
    
    sort(array.begin(), array.end());
    int large = array.back();
    
    for(int i=0; i<pos.size(); i++) {
        if(pos[i]==large) return {large, i};
    }
}