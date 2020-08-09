#include <vector>
#include <queue>

int solution_hotter(std::vector<int> scoville, int K) {
    int answer = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pool;
    for(int i=0; i<scoville.size(); i++){
        pool.push(scoville[i]);
    }
    while (pool.top() < K)
    {
        answer++;
        if (pool.size() < 2)
        {
            return -1;
        }
        
        int x1 = pool.top();
        pool.pop();
        int x2 = pool.top();
        pool.pop();
        pool.push(x1 + (2*x2));
    }
    return answer;
}
