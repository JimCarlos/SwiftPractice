#include <vector>
#include <algorithm>

std::vector<int> solution(std::vector<int> array, std::vector<std::vector<int>> commands) {
    std::vector<int> answer;

    for(auto it : commands){
        std::vector<int> tmp(array.begin() + it[0] - 1, array.begin() + it[1]);
        std::sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[it[2]-1]);
    }
    return answer;
}
