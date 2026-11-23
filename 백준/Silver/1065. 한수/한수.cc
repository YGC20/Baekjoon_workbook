#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int num = 0, result = 0; cin >> num;
    if(num < 100) {
        result = num;
    }
    else if(num == 1000) {
        result = 144;
    }
    else {
        int fNum = num / 100;
        result += (fNum - 1) * 5 + 99;

        int cnt = 0;
        int first = 0, second = 0, third = 0;
        for(int i=(fNum * 100); i<=num; ++i) {
            first = i / 100;
            second = (i % 100) / 10;
            third = i % 10;

            if((first - second) == (second - third)) { cnt++; }
        }
        result += cnt;
    }
    
    cout << result << "\n";
    return 0;
}