#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(string s) {
    int zero_count = 0, cnt = 0;
    while(s!="1"){
        int ones=count(s.begin(),s.end(),'1');
        zero_count+=(int)s.size()-ones;
        cnt++;
        
        s.clear();
        for(int x=ones;x;x>>=1) s.push_back(char('0'+(x&1)));
        reverse(s.begin(),s.end());
    }
    vector<int> answer;
    answer.push_back(cnt);
    answer.push_back(zero_count);
    return answer;
}