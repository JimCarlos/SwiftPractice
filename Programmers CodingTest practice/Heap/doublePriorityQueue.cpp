#include<vector>
#include<algorithm>
#include<sstream>
#include<set>


std::vector<int> solution(std::vector<std::string> operations) {
    std::vector<int> answer;
    std::set<int, std::greater<int>> set;


    for(int i=0; i<operations.size(); i++){
        std::stringstream toInt(operations[i].substr(1));
            int x=0;
            toInt >> x;
        if (operations[i][0] == 'I')
        {
            set.insert(x);
        }else if(operations[i] == "D 1"){
            if (set.size() == 0)
            {
                continue;
            }
            set.erase(set.begin());
        }else if(operations[i] == "D -1"){
            if (set.size() == 0)
            {
                continue;
            }
            auto it = set.end();
            it--;
            set.erase(it);
        }
    }

    answer.resize(2);
    answer[0] = 0;
    answer[1] = 0;
    if (set.size() != 0)
    {
        answer[0] = *set.begin();
        auto it = set.end();
        it--;
        answer[1] = *it;
    }
    

    return answer;
}
