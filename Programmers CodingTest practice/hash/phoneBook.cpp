#include<iostream>
#include<vector>
#include<algorithm>

bool hasPrefix(std::string from, std::string which){
    auto it1 = from.begin(), it2 = which.begin();

    while (it2 != which.end())
    {
        if (*(it2++) != *(it1++))
        {
            return false;
        }
    }
    return true;
}

bool solution(std::vector<std::string> phone_book) {
    
    bool answer;
    std::vector<std::string> pool(phone_book);
    std::sort(pool.begin(), pool.end());

    auto it = pool.begin();
    while (it != pool.end())
    {
        auto it2 = it + 1;
        while (it2 != pool.end())
        {
            if (hasPrefix(*it2, *it))
            {
                return false;
            }
            it2++;
        }
        it++;
    }
    

    return true;
}

bool better_solution(std::vector<std::string> phone_book){
    std::vector<std::string> pool(phone_book);
    std::sort(pool.begin(), pool.end());

    auto it = pool.begin();
    while ((it+1) != pool.end())
    {
        if (*it == (it+1)->substr(0,it->size()))
        {
            return false;
        }
        it++;
    }
    return true;
}


int main(int argc, char* argv[]){

    // std::vector<std::string> input = {"12", "123", "1235", "567", "88"};
    std::vector<std::string> input = {"123", "456", "789"};

    std::cout << solution(input) << std::endl;
    std::cout << better_solution(input) << std::endl;

    return 0;
}