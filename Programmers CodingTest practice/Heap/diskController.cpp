#include<iostream>
#include<queue>
#include<algorithm>



struct queueOrder{
    bool operator()(std::pair<int, int> x1, std::pair<int, int> x2){
    return x1.second > x2.second;
    }
};

int solution_memoryExceed(std::vector<std::vector<int>> jobs) {
    int answer = 0;
    int currentTime;
    std::vector<std::pair<int, int>> time;
    std::priority_queue<std::pair<int ,int>, std::vector<std::pair<int ,int>>, std::greater<std::pair<int,int>>> works;
    for( int j=0; j<jobs.size(); j++)
        works.push({jobs[j][0], jobs[j][1]});

   
    
    std::priority_queue<std::pair<int ,int>, std::vector<std::pair<int ,int>>, queueOrder> pq;
    time.push_back({works.top().first + works.top().second, works.top().second});
    works.pop();

    currentTime = time.front().first;

    while (!works.empty() || !pq.empty())
    {
        if (works.top().first > currentTime)
        {
            time.push_back({works.top().first + works.top().second, works.top().second});
            works.pop();
            continue;
        }
        while (!works.empty() && works.top().first <= currentTime )
        {
            pq.push(works.top());
            works.pop();
        }
        time.push_back({time.back().first + pq.top().second, time.back().first - pq.top().first + pq.top().second});
        pq.pop();
    }
    
    while (!time.empty())
    {
        answer += time.back().second;
        time.pop_back();
    }
    

    return answer / jobs.size();
}


int solution(std::vector<std::vector<int>> jobs) {
    int answer = 0;
    int currentTime;
    
    std::vector<std::pair<int, int>> time;
    std::sort(jobs.rbegin(), jobs.rend());   
    
    std::priority_queue<std::pair<int ,int>, std::vector<std::pair<int ,int>>, queueOrder> pq;
    time.push_back({jobs.back()[0] + jobs.back()[1], jobs.back()[1]});
    jobs.pop_back();
    currentTime = time.back().first;
    

    while (!jobs.empty() || !pq.empty())
    {
        if ( pq.empty() && jobs.back()[0] > currentTime)
        {
            time.push_back({jobs.back()[0] + jobs.back()[1], jobs.back()[1]});
            jobs.pop_back();
            continue;
        }
        while (!jobs.empty() && jobs.back()[0] <= currentTime )
        {
            pq.push({jobs.back()[0], jobs.back()[1]});
            jobs.pop_back();
        }
        time.push_back({time.back().first + pq.top().second, time.back().first - pq.top().first + pq.top().second});
        currentTime = time.back().first;
        pq.pop();
    }
    
    for(auto it = time.begin(); it != time.end(); it ++)
    {
        answer += it->second;
    }

    return answer / time.size();
}
