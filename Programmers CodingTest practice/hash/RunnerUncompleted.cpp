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

template <typename T>

int findInVector(vector<T> list, T item){
    int i;
    for (i=0; i<list.size(); i++) {
        if (list[i] == item) {
            return i;
        }
    }
    return -1;
}

string solution(vector<string> participant, vector<string> completion) {
    vector<string> part (participant), comp (completion);
    while (comp.size() != 0) {
        int i=findInVector(part, string(comp[0]));
        if (i != -1) {
            part.erase(part.begin() + i);
            comp.erase(comp.begin());
        }
    }
    
    return part[0];
}

int main(int argc, const char * argv[]) {
    vector<string> input1 ( {"leo", "kiki", "eden"});
    vector<string> input2 ({"eden", "kiki"});
    
    cout << solution(input1, input2) << endl ;
//    cout << findInVector(input1, string("kiki")) << endl;
    return 0;
}

// 결과물은 통과하였으나 효율성에서 탈락
