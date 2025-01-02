#include <iostream>
using namespace std;

int T;
int main(void){
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	for(int i=0; i<T; i++){
		int a, b;
		cin >> a >> b;
		a %= 10;
		if(a==0){
			cout << 10 << "\n";
			continue;
		}
		int result = 1;
		for(int i=0; i<b; i++) result = (result * a) % 10;
		cout << result << "\n";
	}
	return 0;
}