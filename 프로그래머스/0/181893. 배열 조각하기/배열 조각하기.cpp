#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> query) {
    vector<int> answer;
    int first=0, last=arr.size()-1;
    for(int i=0; i<query.size(); ++i) {
        if(i%2==0) {
            last = first+query[i];
        }
        else {
            first += query[i];
        }
    }
    
    for(int i=first; i<=last; ++i) {
        answer.push_back(arr[i]);
    }
    return answer;
}