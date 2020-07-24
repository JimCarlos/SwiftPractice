//
//  willset_subscript_array.swift
//  
//
//  Created by JohnnyAngels on 2020/07/10.
//

import Foundation



// MARK: - Dictionary Grouping example

let cars = ["Honda Accord", "Honda Civic", "Honda CR-V", "Toyota Corolla", "Toyota RAV4", "Toyota Camry", "Ford F-150",
"Ford Explorer", "Kia Telluride", "Subaru Outback", "Jeep Wrangler", "Nissan Altima"]

var carsByManufacturer:Dictionary<String,[String]> = Dictionary(grouping: cars){
//    String($0.split(separator: " ")[0])
    let idx = $0.firstIndex(of: " ") ?? $0.endIndex
    return String($0[..<idx])
}

 // MARK: - print example
//print(aex)



    // MARK: - example about willSet and didSet
struct myStruct<Type>{
    private var content:Type{
        willSet{
            print("before mystruct<\(type(of: self))> is set")
        }
        didSet{
            print("after mystruct<\(type(of: self))> is set")
        }
    }
    
    func getContent() -> Type {
        return self.content
    }
    
    mutating func setContent(_ input:Type) -> (){
        self.content = input
    }
    
    init(_ content:Type) {
        self.content = content
    }
}
    
    // MARK: - print example
//var exampleStruct = myStruct<String>("ABCDE")
//print("get content : \(exampleStruct.getContent())")
//exampleStruct.setContent("Second Content")
//print("get content : \(exampleStruct.getContent())")



    // MARK: - subscript example
struct exampleSubscript{
    private var content:String

    subscript(index:Int)->String{
        get{
            precondition( index >= 0 && index <= self.content.count)
            return "character at \(index) is \(self.content[content.index(content.startIndex, offsetBy: index)])"
        }
        set{
            precondition(newValue.count == 1)
            let idx = content.index(content.startIndex, offsetBy: index)
            content.remove(at: idx)
            content.insert(contentsOf:newValue, at: idx)
        }
    }
    
    init(content input:String) {
        self.content = input
    }
    
    func printContent() {
        print(self.content)
    }
}


// MARK: - print example

//var Value1 = exampleSubscript(content: "This is Content of Example Subscript")
//Value1.printContent()
//print(Value1[1])
////print(Value1[-1])
//Value1[1] = "Q"
//print(Value1[1])
//Value1.printContent()



//let carname = "Ford Explorer"
//let idx = carname.firstIndex(of: " ") ?? carname.endIndex
//print(carname[..<idx])

// MARK: - subtract strings
var str = "hello wanderer"
let idx = str.index(str.endIndex, offsetBy: -6) ..< str.endIndex
//str.removeSubrange(idx)
//print(str)

//print(str[idx])

//str.insert(contentsOf: "[inserted]", at: str.firstIndex(of: " ") ?? str.endIndex)
//print(str)


// MARK: - array practice

//var intArray:Array<Int> = Array<Int>([1,2,3,4,5])
//intArray.insert(contentsOf: [11,22,33], at: 0)
//print("count : \(intArray.count), capacity : \(intArray.capacity)")
//intArray.insert(55, at: 3)
//intArray.insert(contentsOf: [909,905,223], at: intArray.index(before: intArray.endIndex))
//print(intArray)
//print("count : \(intArray.count), capacity : \(intArray.capacity)")
//intArray.removeSubrange(1...3)
//print(intArray)
//intArray.removeAll(keepingCapacity: true)
//print(intArray)
//print("count : \(intArray.count), capacity : \(intArray.capacity)")

//print(carsByManufacturer, terminator : "\n\n\n")
//print( type(of: carsByManufacturer.enumerated()) )
//print( carsByManufacturer.enumerated() )

for (mfr, list) in carsByManufacturer {
    print("manufacturer : \(mfr), list of content : \(list)", terminator : "\nEnd\n")
}

for (mfr, list) in carsByManufacturer.enumerated() {
    print("manufacturer : \(mfr), list of content : \(list)", terminator : "\nEnd\n")
}
