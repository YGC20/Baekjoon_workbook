#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums)
{
    int len = static_cast<int>(nums.size()) / 2;
    unordered_map<int, int> pokemons;
    for(auto& n : nums) { pokemons[n]++; }
    int plen = static_cast<int>(pokemons.size());
    
    int answer = 0;
    if(len > plen) { answer = plen; }
    else { answer = len; }
    return answer;
}