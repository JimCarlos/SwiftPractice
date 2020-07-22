//
//  Towers.swift
//  
//
//  Created by JohnnyAngels on 2020/07/22.
//

import Foundation

func solution(_ heights:[Int]) -> [Int] {
    var answer = Array<Int>(repeating: 0, count: heights.count)
    
    for i in answer.indices{
        for j in 0..<i{
            if heights[i-j-1] > heights[i] {
                answer[i] = i-j
                break;
            }
        }
    }
    
    return answer
}


print(solution([3,9,9,3,5,7,2]))
