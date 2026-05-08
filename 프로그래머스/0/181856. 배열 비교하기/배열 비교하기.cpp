#include <string>
#include <vector>
using namespace std;

int solution(vector<int> arr1, vector<int> arr2)
{
    int len1 = arr1.size(), len2 = arr2.size();
    if(len1==len2) {
        int sum1 = 0, sum2 = 0;
        for(int i=0; i<len1; i++) {
            sum1+=arr1[i];
            sum2+=arr2[i];
        }
        return sum1==sum2?0:sum1>sum2?1:-1;
    }
    else {
        return len1>len2?1:-1;
    }
}