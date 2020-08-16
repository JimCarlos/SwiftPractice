#include<string>
#include<vector>
#include<algorithm>


bool sortOrder(std::string x1, std::string x2){
    return x1 + x2 > x2 + x1;
}

std::string solution(std::vector<int> numbers) {
    std::string answer = "";
    std::vector<std::string> pool;

    int sum = 0;

    for(int i=0; i<numbers.size(); i++){
        pool.push_back(std::to_string(numbers[i]));
        sum += numbers[i];
    }

    if (sum == 0)
    {
        return std::to_string(0);
    }
    
    std::sort(pool.begin(), pool.end(), sortOrder);
    for(auto it = pool.begin(); it != pool.end(); it++){
        answer += *it;
    }

    return answer;
}

std::string solution_best(std::vector<int> numbers) {
    std::string answer = "";
    std::vector<std::string> pool;

    for(int i=0; i<numbers.size(); i++){
        pool.push_back(std::to_string(numbers[i]));
    }

    std::sort(pool.begin(), pool.end(), sortOrder);
    for(auto it = pool.begin(); it != pool.end(); it++){
        answer += *it;
    }

    if(answer[0] == '0')
        return "0";

    return answer;
}



// struct sortOrder{
//     bool operator()(std::string& x1, std::string& x2){

//         if (x2.size() > x1.size())
//         {
//             std::swap(x1, x2);
//         }
//         // length : x1 >= x2

//         auto it1 = x1.begin();
//         auto it2 = x2.begin();
//         while (it1 != x1.end())
//         {
//             if(*it1 == *it2){
//                 if (it2 + 1 == x2.end())
//                 {
//                     return *(it1 + 1) < *it2;
//                 }else{
//                     it1++;
//                     it2++;
//                 }
//             }else{
//                 return *it1 < *it2;
//             }
            
//         }
        
//         return false;
//     }
// };



// // below is for std::sort

// bool sortOrder(std::string& x1, std::string& x2){
//         if (x2.size() > x1.size())
//         {
//             std::swap(x1, x2);
//         }
//         // length : x1 >= x2
//         auto it1 = x1.begin();
//         auto it2 = x2.begin();
//         while (it1 != x1.end())
//         {
//             if(*it1 == *it2){
//                 if (it2 + 1 == x2.end())
//                 {
//                     return *(it1 + 1) > *it2;
//                 }else{
//                     it1++;
//                     it2++;
//                 }
//             }else{
//                 return *it1 > *it2;
//             }     
//         }     
//         return true;
//     }

