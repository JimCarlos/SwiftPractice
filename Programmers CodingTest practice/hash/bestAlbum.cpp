#include<vector>
#include<queue>
#include<unordered_map>
#include<string>


struct queueOrder{
    bool operator()(std::pair<int, int> x1, std::pair<int, int> x2){
        return x1.second < x2.second || x1.second == x2.second && x1.first > x2.first;
    }
};

struct playOrder{
    bool operator()(std::pair<std::string, int> x1, std::pair<std::string, int> x2){
        return x1.second < x2.second;
    }
};



std::vector<int> solution(std::vector<std::string> genres, std::vector<int> plays) {
    std::vector<int> answer;
    std::unordered_map<std::string, std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, queueOrder>> pool;
    std::priority_queue<std::pair<std::string, int>, std::vector<std::pair<std::string, int>>, playOrder> playQueue;
    std::unordered_map<std::string, int> playPriority;

    for(int i=0; i<genres.size(); i++){
        pool[genres[i]].push({i, plays[i]});
        playPriority[genres[i]] += plays[i];
    }
    for(auto it = playPriority.begin(); it != playPriority.end(); it++){
        playQueue.push({it->first, it->second});
    }
    while(!playQueue.empty()){
        answer.push_back(pool[playQueue.top().first].top().first);
        if (pool[playQueue.top().first].size() != 1)
        {
            pool[playQueue.top().first].pop();
            answer.push_back(pool[playQueue.top().first].top().first);
        }
        playQueue.pop();
    }

    return answer;
}
