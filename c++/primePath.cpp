#include<vector>
#include<string>
#include<queue>
#include<vector>


// Sieve of Eratosthenes
std::vector<int> listPrime(int n){
    std::vector<int> answer;
    answer.push_back(2);

    for(int i=3; i<n; i++){
        bool flag = true;
        for(int j=0; j<answer.size(); j++){
            if ( i % answer[j] == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            answer.push_back(i);
        }
    }
    return answer;
}



bool isPrime(int n){
    if (n <= 1)
    {
        return false;
    }
    int x = 2;
    while (x < n/2)
    {
        if (n%(x++) == 0)
        {
            return false;
        }
    }
    return true;
}

bool oneDigit(int x1, int x2){
    std::string num1 = std::to_string(x1), num2 = std::to_string(x2);
    int digit = 0;

    if (num1.size() != num2.size())
    {
        return false;
    }
    for(int i=0; i<num1.size(); i++){
        if (num1[i] != num2[i])
        {
            digit++;
        }
        if (digit > 1)
        {
            return false;
        }
    }
    return true;
}

std::vector<int> listPrime(int from, int to){
    std::vector<int> answer;

    for(int i = from + 1; i <= to; i++){
        if (isPrime(i))
        {
            answer.push_back(i);
        }
    }

    return answer;
}

std::vector<int> listOneDigit(int target, std::vector<int> from){
    std::vector<int> answer;

    for(int i=0; i<from.size(); i++){
        if (oneDigit(target, from[i]))
        {
            answer.push_back(from[i]);
        }
    }
    return answer;
}

int PrimePath(int from, int to){

    std::queue<std::pair<std::vector<int>, int>> q;
    q.push({{from}, 0});
    std::vector<int> primes = listPrime(1000, 9999);
    
    while (q.front().first[q.front().first.size()-1] != to)
    {
        std::vector<int> currentPath = q.front().first;
        std::vector<int> candidate = listOneDigit(currentPath[currentPath.size()-1], primes);
        
        for(int i=0; i<candidate.size(); i++){
            bool flag = true;
            for(int j=0; j < currentPath.size(); j++){

                if (candidate[i] == currentPath[j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                std::vector<int> tmp(currentPath);
                tmp.push_back(candidate[i]);
                q.push({tmp, q.front().second + 1});
            }
        }

        q.pop();
    }
    return q.front().second;
}
