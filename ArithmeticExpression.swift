//
//  ArithmeticExpression.swift
//  
//
//  Created by JohnnyAngels on 2020/06/10.
//

import UIKit

indirect enum ArithmeticExpression{
    case number(Int)
    case sum(ArithmeticExpression, ArithmeticExpression)
    case multiplication(ArithmeticExpression,ArithmeticExpression)
}

let four = ArithmeticExpression.number(4)
let five = ArithmeticExpression.number(5)

let sum = ArithmeticExpression.sum(four, five)

func evaluateArithmetic(_ exp:ArithmeticExpression) -> Int{
    switch exp {
    case .number(let num):
        return num
    case .sum(let x, let y):
        return evaluateArithmetic(x) + evaluateArithmetic(y)
    case .multiplication(let x, let y):
        return evaluateArithmetic(x) * evaluateArithmetic(y)
    }
}

enum oper{
    case sum
    case mul
}

func calUsingArith(_ num1:Int=2, _ num2:Int=3, _ op:oper = .sum) -> Int{
    switch op {
    case .sum:
        return evaluateArithmetic(ArithmeticExpression.sum(ArithmeticExpression.number(num1), ArithmeticExpression.number(num2)))
    case .mul:
        return evaluateArithmetic(ArithmeticExpression.multiplication(ArithmeticExpression.number(num1), ArithmeticExpression.number(num2)))
    }
}


print(calUsingArith(25, 5, .mul))

