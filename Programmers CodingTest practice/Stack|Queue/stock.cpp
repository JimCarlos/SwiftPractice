#include<vector>
#include<stack>

std::vector<int> solution_bad(std::vector<int> prices) {
    std::vector<int> answer;
    for(int i=0; i<prices.size(); i++){
        answer.push_back(0);
    }
    for(int i=0; i<prices.size(); i++){
        for(int j=i+1; j<prices.size(); j++){
            answer[i]++;
            if (prices[j] < prices[i])
            {
                break;
            }
            
        }
    }
    return answer;
}

std::vector<int> solution(std::vector<int> prices){
    std::vector<int> answer(prices.size());
    std::stack<int> pool;

    for(int i=0; i<prices.size(); i++){
        while (!pool.empty() && prices[pool.top()] > prices[i])
        {
            answer[pool.top()] = i - pool.top();
            pool.pop();
        }
        pool.push(i);
    }

    while(!pool.empty()){
        answer[pool.top()] = prices.size() - pool.top() - 1;
        pool.pop();
    }

    return answer;
}