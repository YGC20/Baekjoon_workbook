#include <iostream>
#include <vector>

struct item {
    int v;
    int c;
};

void solution(int test_case)
{
    int n, k;
    std::cin>>n>>k;

    std::vector<item> goods(n);
    for(int i=0; i<n; ++i) {
        std::cin>>goods[i].v>>goods[i].c;
    }

    std::vector<int> dp(k+1, 0);
    for(int i=0; i<n; ++i) {
        int weight = goods[i].v;
        int value = goods[i].c;

        for(int j=k; j>=weight; --j) {
            if(dp[j]<dp[j-weight]+value) {
                dp[j] = dp[j-weight]+value;
            }
        }
    }

    std::cout<<"#"<<test_case<<" "<<dp[k]<<"\n";
}

int main(int argc, char** argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int test_case;
    if(std::cin>>test_case) {
        for(int i=1; i<=test_case; ++i) {
            solution(i);
        }
    }
    return 0;
}