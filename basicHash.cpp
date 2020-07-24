//
//  main.cpp
//  practiceCpp
//
//  Created by JohnnyAngels on 2020/07/23.
//  Copyright © 2020 JohnnyAngels. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


using uint = unsigned int;

class hash_map{
private:
    vector<int> data;
    
public:
    hash_map(size_t n){
        data = vector<int>(n, -1);
    }
    
    void insert(uint value){
        unsigned long n = data.size();
        
        if (find(value)) {
            cout << value << "already exist" << endl;
        }else {
            data[ value % n ] = value;
            cout << value << " has been inserted" << endl;
        }
    }
    
    bool find(uint value){
        unsigned long n = data.size();
        return (data[value % n] == value);
    }
    
    void erase(uint value){
        unsigned long n = data.size();
        if( find(value) ){
            data[ value % n ] = -1;
            cout << value << " has been removed" << endl;
        } else{
            cout << "no such value" << endl;
        }
    }
  
    vector<int> content(){
        return data;
    }
    
};

template <typename T>
void printEveryVector(vector<T> input){
    for (int i=0; i<input.size(); i++) {
        cout << i << "st : " << input[i] << endl;
    }
}

int main(int argc, const char * argv[]) {
    
    hash_map map(7);
    
    map.insert(5);
    map.insert(7);
    map.insert(7);
    map.erase(3);
    map.erase(5);
    
    printEveryVector(map.content());
    
    return 0;
}
