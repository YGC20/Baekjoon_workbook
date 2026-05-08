#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<int> arr)
{
    int len = arr.size();
    
    int tlen = 1;
    while(tlen<len) {
        tlen*=2;
    }
    
    int rlen = tlen-len;
    for(int i=0; i<rlen; i++) {
        arr.push_back(0);
    }
    return arr;
}