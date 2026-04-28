#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<int> slicer, vector<int> num_list)
{
    int start, last, gap;
    switch(n) {
        case 1:
            start = 0;
            last = slicer[1];
            gap = 1;
            break;
        case 2:
            start = slicer[0];
            last = num_list.size()-1;
            gap = 1;
            break;
        case 3:
            start = slicer[0];
            last = slicer[1];
            gap = 1;
            break;
        case 4:
            start = slicer[0];
            last = slicer[1];
            gap = slicer[2];
            break;
    }
    vector<int> result;
    for(int i = start; i<=last; i+=gap) {
        result.push_back(num_list[i]);
    }
    return result;
}