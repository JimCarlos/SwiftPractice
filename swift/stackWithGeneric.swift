//
//  stackWithGeneric.swift
//  
//
//  Created by JohnnyAngels on 2020/06/13.
//

import Foundation
import UIKit

struct myStack<T>{
    var items = [T]()
    
    mutating func push(_ val:T){
        items.append(val)
    }
    
    mutating func pull(){
        items.removeLast()
    }
    
    func printAll(){
        var i = 1
        for item in items{
            print("index : \(i) = \(item)")
            i += 1
        }
    }
}


var x:myStack<String> = myStack<String>()

x.push("first Input")
x.push("second input")
x.printAll()
x.push("third input")
x.printAll()
x.pull()
x.pull()
x.printAll()


