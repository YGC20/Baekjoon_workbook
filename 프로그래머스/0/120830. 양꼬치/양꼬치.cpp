using namespace std;

int solution(int n, int k)
{
    int answer = 0;
    k -= (n/10);
    if(k<=0) {
        answer = 12000*n;
    }
    else {
        answer = 12000*n + 2000*k;
    }
    return answer;
}