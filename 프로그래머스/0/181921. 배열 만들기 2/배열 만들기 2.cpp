#include <string>
#include <vector>

using namespace std;

vector<int> solution(int l, int r) {
    vector<int> result;
    
    for(int i=1; ; ++i) {
        long long five_binary = 0;
        long long pos = 1;
        int tmp = i;
        
        while(tmp>0) {
            if(tmp%2 == 1) {
                five_binary+=(5*pos);
            }
            pos*=10;
            tmp/=2;
        }
        
        if(five_binary>r) {
            break;
        }
        if(five_binary>=l) {
            result.push_back((int)five_binary);
        }
    }
    if(result.empty()) {
        result.push_back(-1);
    }
    return result;
}