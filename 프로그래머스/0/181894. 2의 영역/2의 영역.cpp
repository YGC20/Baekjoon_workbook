#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{
    int start = arr.size(), last = 0;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i]==2) {
            if(i<start) start = i;
            if(i>last) last = i;
        }
    }
    if(start>last) return { -1 };
    vector<int> result;
    for(int i=start; i<=last; i++) {
        result.push_back(arr[i]);
    }
    return result;
}