//
//  ContentView.swift
//  practice
//
//  Created by JohnnyAngels on 2020/07/19.
//  Copyright © 2020 JohnnyAngels. All rights reserved.
//

import SwiftUI

struct ContentView: View {
    
    @State var xPos: CGFloat = 0
    @State var yPos: CGFloat = 0
    
    var body: some View {
        VStack {
            
            GeometryReader { geometry in
                ZStack {
                    Rectangle()
                        .fill(Color.white)
                        .frame(width: geometry.size.width, height: geometry.size.height)
                    Text("Coordinate: \(self.xPos)\n\(self.yPos)")
                        .frame(width: geometry.size.width, height: geometry.size.height)
                }
            }.gesture(DragGesture(minimumDistance: 0, coordinateSpace: .global).onEnded { dragGesture in
                self.xPos = dragGesture.location.x
                self.yPos = dragGesture.location.y
            })
        }
    }
}


