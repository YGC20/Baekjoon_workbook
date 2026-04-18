#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> array) {
    int mid = array.size()/2;
    sort(array.begin(), array.end());
    return array[mid];
}