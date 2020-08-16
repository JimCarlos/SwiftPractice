#include<vector>
#include<algorithm>

int solution(std::vector<int> citations) {
    for(int i = citations.size(); i > 0; i--){
        int tmp = 0;
        for(int j=0; j<citations.size(); j++){
            if (citations[j] >= i)
            {
                tmp++;
            }
            if (tmp >= i)
            {
                return i;
            }
        }
    }
}

int solution2(std::vector<int> citations) {

    std::sort(citations.begin(), citations.end());
    for(int i = citations.size(); i > 0; i--){
        int tmp = 0;
        for(int j=citations.size() - 1; j >= 0; j--){
            if (citations[j] >= i)
            {
                tmp++;
            }else{
                break;
            }
            if (tmp >= i)
            {
                return i;
            }
        }
    }
}

int solution_best(std::vector<int> citations){

    std::sort(citations.begin(), citations.end(), std::greater<int>());

    for(int i=0; i<citations.size(); i++){
        if (citations[i] < i + 1)
        {
            return i;
        }
    }

    return citations.size();
}