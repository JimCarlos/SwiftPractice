#include<vector>
#include<algorithm>


std::vector<int> solution(std::vector<int> answers) {
    std::vector<int> answer;

    std::vector<std::vector<int>> humans(3);
    humans[0] = {1,2,3,4,5};
    humans[1] = {2, 1, 2, 3, 2, 4, 2, 5};
    humans[2] = {3,3,1,1,2,2,4,4,5,5};
    std::vector<int> correct(3, 0);

    for(int i=0; i<answers.size(); i++){
        for(int j=0; j<humans.size(); j++){    
            if (answers[i] == humans[j][i%humans[j].size()])
            {
                correct[j]++;
            }
        }
    }

    auto max = std::max_element(correct.begin(), correct.end());
    for(int i=0; i<correct.size(); i++){
        if (correct[i] == *max)
        {
            answer.push_back(i+1);
        }
        
    }

    return answer;
}