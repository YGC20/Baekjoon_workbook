#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    int len = queries.size();
    for(int i=0; i<len; i++) {
        int x = queries[i][0];
        int y = queries[i][1];
        int tmp = arr[x];
        arr[x] = arr[y];
        arr[y] = tmp;
    }
    return arr;
}