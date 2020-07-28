#include <string>
#include <vector>
#include <list>

using namespace std;

const int hashSize = 100002;

string solution(vector<string> participant, vector<string> completion) {
    std::hash<std::string> hashStr;
    std::vector<std::string> data1;
    std::vector<int> idx;
    std::string rst;


    data1.resize(hashSize);
    idx.resize(hashSize);

    // index initialize
    for (size_t i = 0; i < idx.size(); i++)
    {
        idx[i] = 0;
    }

    // pool initialize
    for (size_t i = 0; i < participant.size(); i++)
    {
        auto pos = hashStr(participant[i]) % data1.size();
        if (idx[i] == 0) {
            data1[pos] = participant[i];
        }
        idx[pos]++;
    }

    // erase data from pool
    for (size_t i = 0; i < completion.size(); i++)
    {
        auto pos = hashStr(completion[i]) % data1.size();
        idx[pos]--;
    }

    // extract result
    for (size_t i = 0; i < idx.size(); i++)
    {
        if (idx[i] != 0)
        {
            rst = data1[i];
        }
    }




    return rst;
}
// success with several execution