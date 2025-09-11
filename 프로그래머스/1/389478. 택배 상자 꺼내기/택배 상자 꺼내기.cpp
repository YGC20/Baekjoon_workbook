#include <string>
#include <vector>

using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    int R = (n+w-1)/w;
    int r = (num-1)/w;
    int p = (num-1)%w;
    int c = (r%2==0)?p:(w-1-p);
    
    int len_last = n-(R-1)*w;
    if(len_last<=0) len_last=w;
    
    int top_to_r=(R-1)-r;
    bool last_has_c;
    if((R-1)%2==0)
        last_has_c=(c<len_last);
    else
        last_has_c=(c>=w-len_last);
    answer=top_to_r+(last_has_c?1:0);
    return answer;
}