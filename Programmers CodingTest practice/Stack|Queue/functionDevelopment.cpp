#include<vector>
#include<queue>

std::vector<int> solution(std::vector<int> progresses, std::vector<int> speeds) {
    std::vector<int> answer;
    std::queue<int> pool;
    
    for(int i=0; i<progresses.size(); i++){
        int day=0;
        while (progresses[i] < 100)
        {
            progresses[i] += speeds[i];
            day++;
        }
        pool.push(day);
    }

    while (!pool.empty())
    {
        int front = pool.front();
        int works = 1;
        pool.pop();
        if (pool.empty())
        {
            answer.push_back(works);
            continue;
        }
        
        while (pool.front() <= front)
        {
            works++;
            pool.pop();
            if (pool.empty())
            {
                break;
            }
            
        }
        answer.push_back(works);        
    }
    
    return answer;
}
