#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool solution(int time, const vector<int>& flashes, int num_computer);

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_computer, num_flash;
    cin>>num_computer;
    cin>>num_flash;

    int min_time = 1000;
    vector<int> flashes(num_flash);
    for(int i=0; i<num_flash; ++i) {
        cin>>flashes[i];
        if(flashes[i]<min_time) {
            min_time = flashes[i];
        }
    }

    int low = 1;
    int high = min_time*num_computer;
    int result = high;

    while(low<=high) {
        int mid = low + (high-low)/2;
        if(solution(mid, flashes, num_computer)) {
            result = mid;
            high = mid-1;
        }
        else {
            low = mid+1;
        }
    }
    cout<<result<<"\n";
    return 0;
}

bool solution(int time, const vector<int>& flashes, int num_computer)
{
    int result = 0;
    for(int t : flashes) {
        result += (time/t);
        if(result>=num_computer) {
            return true;
        }
    }
    return result>=num_computer;
}