#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    int X; cin >> X;

    int n = 1;
    while(X > n)
    { X -= n; n += 1; }

    if(n % 2 == 0)
    { cout << X << "/" << (n + 1 - X) << "\n"; }
    else
    { cout << (n + 1 - X) << "/" << X << "\n"; }
    return 0;
}