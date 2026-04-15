// 1998년생인 내가 태국에서는 2541년생?!
#include <iostream>
using namespace std;

int slov(int year)
{
	return year - 543;
}

int main(int argc, char* argv)
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int year; cin >> year;
	cout << slov(year) << "\n";

	return 0;
}