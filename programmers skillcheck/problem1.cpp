#include <string>
#include <vector>
#include <algorithm>

long long solution(long long n) {
    long long answer = 0;
    std::vector<int> pool;
    long long x = n;

    while (x != 0)
    {
        pool.push_back(x%10);
        x /= 10;
    }
    std::sort(pool.rbegin(), pool.rend());
    
    for(auto it = pool.begin(); it != pool.end(); it++){
        answer += *it;
        answer *= 10;
    }
    answer /= 10;

    return answer;
}
