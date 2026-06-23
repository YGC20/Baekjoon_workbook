#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
typedef long long ll;

ll solution(int price, int money, int count)
{
    ll answer = -1;
    ll mid = 0;
    if(count%2!=0) mid = (count/2+1)*price;
    ll pm = price + price*count;
    answer = pm*(count/2) + mid;
    return ((answer-money)>0)?(answer-money):0;
}