#include<string>
#include<vector>
#include<unordered_map>

using namespace std;


string solution(vector<string> participant, vector<string> completion){

    std::unordered_map<std::string, int> pool;

    for(auto item : participant){
        if (pool.find(item) == pool.end())
        {
            pool.insert({item,1});
        }else{
            pool[item]++;
        }
    }

    for(auto item : completion){
        auto pt = pool.find(item);
        if (pt != pool.end())
        {
            pool[item]--;
        }
    }
    
    auto item = pool.begin();
    while (item != pool.end())
    {
        if (item->second == 1)
        {
            return item->first;
        }
        item++;
    }
}