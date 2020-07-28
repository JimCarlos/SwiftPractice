#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using uint = unsigned int;

class hash_list {
private:
    std::vector<std::list<int>> data;


public:
    hash_list(size_t n) {
        data = std::vector<std::list<int>>(n);
    }

    bool find(uint value) {
        uint n = data.size();

        for (std::list<int>::iterator i = data[value%n].begin(); i != data[value%n].end(); i++)
        {
            if (value == *i)
            {
                return true;
            }
        }
        return false;
    }

    void insert(uint value) {
        uint n = data.size();
        data[value % n].push_back(value);
        std::cout << value << " has been inserted\n";
    }

    void erase(uint value) {
        uint n = data.size();
        data[value % n].remove(value);
        std::cout << value + " removed\n";
    }

};
