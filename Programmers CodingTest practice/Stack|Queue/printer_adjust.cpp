#include<vector>
#include<queue>


int solution_vector(std::vector<int> priorities, int location) {
    int answer = 0;
    std::vector<int> idx;
    bool flag = true;
    
    idx.reserve(priorities.size() * 1.5);
    for(int i=0; i<priorities.size(); i++){
        idx.push_back(i);
    }
    
    while(1){
        std::vector<int>::iterator max_idx = idx.begin();

        for(auto it = idx.begin() + 1; it != idx.end(); it++)
        {
            if (priorities[*it] > priorities[*max_idx])
            {
                max_idx = it;
            }
        }
        if (*idx.begin() == *max_idx)
        {
            answer++;
            if (*idx.begin() == location)
            {
                return answer;
            }
            
            idx.erase(idx.begin());
        }
        else{            
            for(auto i=idx.begin(); i != max_idx; i++)
            {
                idx.push_back(idx.front());
                idx.erase(idx.begin());
            }
        }
    }
    return answer;
}

int solution_best(std::vector<int> priorities, int location) {
    int answer = 0;
    std::queue<std::pair<int, int>> q;

    for(int i=0; i<priorities.size(); i++){
        q.push({priorities[i], i});
    }

    while (1)
    {
        auto max = std::max_element(priorities.begin(), priorities.end());
        if (q.front().first == *max)
        {
            answer++;
            if (q.front().second == location)
            {
                return answer;
            }
            q.pop();
            priorities.erase(max);
        }
        else{
            q.push(q.front());
            q.pop();
        }

    }
}