#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    int odd = 0;
    int even = 0;
    for(int nl : num_list) {
        if(nl%2==0)
            even++;
        else
            odd++;
    }
    return { even, odd };
}