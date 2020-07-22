import Foundation


// MARK:- 내 풀이

import Foundation


extension Array where Element == Int{
    func total() -> Int{
        if self.isEmpty{
            return 0
        } else {
            var sum = 0
            for idx in 0..<self.count{
                sum += self[idx]
            }
            return sum
        }
    }
}


func solution(_ bridge_length:Int, _ weight:Int, _ truck_weights:[Int]) -> Int {
    
    var truckPassed = Array<Int>()
    var truckMoving = Array<Int>()
    var truckPending = Array<Int>(truck_weights)
    var truckTimeElapsed = Array<Int>()
    var totalTimeElasped:Int = 0
    
    while( !(truckPending.isEmpty && truckMoving.isEmpty) ){
        var check : Int = 0
        
        while !truckMoving.isEmpty, check != truckMoving.count {
            if truckTimeElapsed[check] == bridge_length {
                truckPassed.append(truckMoving.removeFirst())
                truckTimeElapsed.removeFirst()
            } else {
                check += 1
            }
        }
        
        if !truckPending.isEmpty, truckMoving.total() + truckPending.first! <= weight {
            truckMoving.append(truckPending.removeFirst())
            truckTimeElapsed.append(0)
        }
        
        for idx in truckTimeElapsed.indices{
            truckTimeElapsed[idx] += 1
        }
        
        totalTimeElasped += 1
    }
    
    return totalTimeElasped
}


//  썩 좋은 풀이는 아닌게 중간에 while문이 bridge에 있는 모든 차량의 시간을 확인하기 때문.
//  또한 메모리도 더 많이 잡아 먹는다.



// MARK:- 아주 좋은 풀이



func solution(_ bridge_length:Int, _ weight:Int, _ truck_weights:[Int]) -> Int {
    var trucks = truck_weights
    var bridge = Array(repeating: 0, count: bridge_length)
    var sec = 0
    var w = 0

    while bridge.isEmpty == false {
        // 1초마다 다리위의 트럭 또는 빈공간은 움직임
        w -= bridge.removeFirst()
        sec += 1

        // 다리에 빈 공간 있으면
        if bridge.count < bridge_length {
            // 다리에 진입 예정인 트럭을 포함한 무게와 다리가 견딜 수 있는 무게를 비교해서
            // 견딜 수 있으면 트럭 진입 시킨다.
            if let t = trucks.first {
                if t + w <= weight  {
                    w += trucks.removeFirst() // 트럭 진입
                    bridge.append(t) // 트럭 진입 완료
                } else {
                    // 견딜 수 업으면 트럭 대기하고 빈공간만 보낸다.
                    bridge.append(0)
                }
            }
        }
    }

    return sec
}
