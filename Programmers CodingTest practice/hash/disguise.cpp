#include<iostream>
#include<vector>
#include<unordered_map>

int solution(std::vector<std::vector<std::string>> clothes) {
    int answer = 1;
    std::unordered_map<std::string, int> pool;

    for( std::vector<std::string> it : clothes ){
        // if (pool.find(it[1]) == pool.end())
        // {
        //     pool.insert({it[1], 1});
        // }else{
        //     pool[it[1]]++;
        // }

        pool[it[1]]++;
    }

    if (pool.size() == 1)
    {
        for(auto item : pool){
            answer = item.second;
        }
        return answer;
    }else{
        for(auto item : pool){
            answer *= (item.second + 1);
        }
        answer -= 1;
    }
    

    return answer;
}
