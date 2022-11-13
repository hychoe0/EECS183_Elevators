/*
 * Copyright 2022 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Final Project - Elevators
 */
 
////////////////////////////////////////////////
// You will submit test.cpp to the autograder //
// FOR LAB 8, but NOT the final project Core  //
////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include "AI.h"
#include "Building.h"
#include "BuildingState.h"
#include "Elevator.h"
#include "Floor.h"
#include "Game.h"
#include "Move.h"
#include "Person.h"
#include "SatisfactionIndex.h"
#include "Utility.h"

using namespace std;

void person_tests();
void file_check();
void elevator_tests();

void start_tests() {
    file_check();
    person_tests();
    elevator_tests();
    
    return;
}

void file_check() {
    // open one of the text files that are part of the starter code
    ifstream ins;
    ins.open("new.in");
    // if the file was not in the correct directory, the stream state is fail
    if (ins.fail()) {
        cout << "Could not open new.in" << endl;
    }
    else {
        cout << "Success! Text files are in the right directory." << endl;
    }
    return;
}

void person_tests() {
    cout << "Testing Person()" << endl;
    
    // TC 1
    // Testing default constructor
    Person p1;
    cout << "Expected: f0t0a0" << endl;
    cout << "  Actual: " << p1 << endl;
    
    // TC 2
    // Testing non-default constructor
    Person p2("4f2t4a9");
    cout << "Expected: f2t4a9" << endl;
    cout << "  Actual: " << p2 << endl;
    
    // TC 2-1
    // Testing member functions
    cout << "Expected: 4 2 4 9" << endl;
    cout << "  Actual: " << p2.getTurn() << " "
         << p2.getCurrentFloor() << " "
         << p2.getTargetFloor() << " "
         << p2.getAngerLevel() << endl;
    
    // TC 2-2
    // Testing tick()
    cout << "Expected: 1" << endl;
    cout << "  Actual: " << p2.tick(5) << endl; // angerLevel at 10
    
    cout << "Expected: 0" << endl;
    cout << "  Actual: " << p2.tick(2) << endl; // angerLevel at 9
    
}

void elevator_tests() {
    cout << "Testing Elevator()" << endl;
}
