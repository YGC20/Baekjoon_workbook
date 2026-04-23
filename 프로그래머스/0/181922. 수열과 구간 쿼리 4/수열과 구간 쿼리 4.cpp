#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries)
{
    for(auto q : queries) {
        int first = q[0];
        int last = q[1];
        int num = q[2];
        
        for(int i=first; i<=last; i++) {
            if(i%num==0) {
                arr[i]++;
            }
        }
    }
    return arr;
}