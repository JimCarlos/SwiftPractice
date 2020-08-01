#include <string>
#include <vector>

double solution(std::vector<int> arr) {
    double answer = 0;

    for(int item:arr){
        answer += item;
    }
    answer /= arr.size();

    return answer;
}