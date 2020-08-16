#include<vector>
#include<string>
#include<algorithm>



std::vector<int> eratos(int n){

    if ( n <= 1)
    {
        return {};
    }
    
    bool* PrimeArray = new bool[n+1];
    for(int i=2; i <= n; i++){
        PrimeArray[i] = true;
    }

    for(int i=2; i*i <=n; i++){
        if (PrimeArray[i])
        {
            for(int j=i*i; j<=n; j += i)
                PrimeArray[j] = false;
        }
    }

    std::vector<int> answer;

    for(int i=2; i<= n; i++){
        if (PrimeArray[i])
        {
            answer.push_back(i);
        }
    }
    return answer;
}


int solution(std::string numbers) {
    int answer = 0;

    std::sort(numbers.begin(), numbers.end(), std::greater<char>());

    std::vector<int> candidates = eratos(std::stoi(numbers));
    std::vector<char> str(numbers.size());
    for(int i=0; i<numbers.size(); i++){
        str[i] = numbers[i];
    }

    for(int i=0; i<candidates.size(); i++){
        std::vector<char> chars(str);
        int num = candidates[i];
        bool flag = true;
        while ( num != 0)
        {
            auto it = std::find(chars.begin(), chars.end(), (char)('0' + (num%10)));
            if ( it == chars.end())
            {
                flag = false;
                break;
            }else{
                chars.erase(it);
                num /= 10;
            }
        }
        if (flag)
        {
            answer++;
        }
    }


    return answer;
}


