#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
	int testCase;
	int T = 10;
	for(testCase=1; testCase<=T; ++testCase)
	{
        int N; cin >> N;
        deque<int> numbers;
        
        int num = 0;
        for(int i=0; i<8; ++i) {
            cin >> num;
            numbers.push_back(num);
        }
        
        int idx = 1;
        do {
            num = numbers.front(); numbers.pop_front();
            num -= idx;
            idx++;
            if(idx > 5) { idx = 1; }
            if(num <= 0) { num = 0; }
            numbers.push_back(num);
        } while(num > 0);
        
        cout << "#" << N << " ";
        for(auto& n : numbers) {
            cout << n << " ";
        }
        cout << "\n";
	}
	return 0;
}