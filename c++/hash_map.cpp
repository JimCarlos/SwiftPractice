#include <iostream>
#include <algorithm>
#include <vector>

using uint = unsigned int;

class hash_map {
private:
    std::vector<int> data;

public:
    hash_map(size_t n) {
        data = std::vector<int>(n, -1);
    }

    bool find(uint value){
        uint n = data.size();

        return data[value % n] == value;
    }

    void insert(uint value) {
        uint n = data.size();

        data[value % n] = value;
        std::cout << value << " has been inserted " << std::endl;
    }

    void erase(uint value) {
        uint n = data.size();

        if (find(value))
        {
            data[value % n] == -1;
            std::cout << value << "has been erased\n";
        }
    }

    void print() {
        uint n = data.size();
        for (size_t i = 0; i < n; i++)
        {
            std::cout << i << " : " << data[i] << ",  ";
        }
        std::cout << std::endl;
    }

};
