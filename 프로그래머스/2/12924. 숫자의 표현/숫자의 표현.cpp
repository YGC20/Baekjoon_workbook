#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int start, end;
    start=end=1;
    while(start<=n){
        int sum = 0;
        for(int i=start;i<=end;++i) sum+=i;
        if(sum<n) end++;
        else if(sum>n) start++;
        else answer++, end++;
    }
    return answer;
}