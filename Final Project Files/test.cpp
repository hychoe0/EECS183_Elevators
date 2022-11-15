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
void floor_tests();
void move_tests();

void start_tests() {
    file_check();
    person_tests();
    elevator_tests();
    floor_tests();
    move_tests();
    
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
    
    p2.tick(TICKS_PER_ANGER_INCREASE - 1);
    cout << "Expected: 4 10" << endl;
    cout << "  Actual: " << p2.getTargetFloor() << " " << p2.getAngerLevel()<< endl;
    
}

void elevator_tests() {
    cout << "Testing Elevator()" << endl;
    
    // TC 1
    Elevator e1;
}

void floor_tests(){
    
    cout << "TESTING FLOOR CLASS" << endl;
    
//    Person person1("10f4t8a9");
//    Person person2("10f4t8a8");
//    Person person3("10f4t8a9");
//    Floor floor1;
//    
//    // testing addPerson()
//    floor1.addPerson(person1, 5);
//    floor1.addPerson(person2, 5);
//    floor1.addPerson(person3, 5);
//    
//    floor1.printFloorPickupMenu(cout);
//    cout << endl;
//    
//    // testing tick()
//    // setting anger level of person1 to 10
//    //person1.tick(TICKS_PER_ANGER_INCREASE);
//    cout << person1.getAngerLevel() << " Expected 9" << endl;
//
//    // person1 and person3 should explode
//    cout << floor1.tick(TICKS_PER_ANGER_INCREASE) << " Expected 2!" << endl;
//    
//    floor1.printFloorPickupMenu(cout);
//    cout << endl;
//    
//    // setting anger level of person2 to 10
//    person2.tick(TICKS_PER_ANGER_INCREASE);
//    person2.tick(TICKS_PER_ANGER_INCREASE);
//    cout << person2.getAngerLevel() << " Expected 10" << endl;
//    
//    cout << floor1.tick(TICKS_PER_ANGER_INCREASE) << " Expected 3!" << endl;
//    
//    floor1.printFloorPickupMenu(cout);
//    cout << endl;
//    
    // testing removePeople()
    Floor floor2;
    Person person4("7f3t1a3");
    Person person5("7f3t1a1");
    Person person6("7f3t1a5");
    
    floor2.addPerson(person4, -1);
    floor2.addPerson(person5, -1);
    floor2.addPerson(person6, -1);
    
//    cout << floor2.getHasDownRequest() << " Expected 1" << endl;
//    cout << floor2.getHasUpRequest() << " Expected 0" << endl;
//
//    cout << person4.getAngerLevel() << " Expected 9" << endl;
//
//    floor2.printFloorPickupMenu(cout);
//    cout << endl;
//
//    floor2.tick(TICKS_PER_ANGER_INCREASE);
    
    // NOT WORKING
    cout << "not working" << endl;
    cout << floor2.getNumPeople() << " Expected 3" << endl;
    int indicesRemoved[] = {0, 1};
    const int peopleRemoved = 2;

    floor2.removePeople(indicesRemoved, peopleRemoved);

    cout << floor2.getNumPeople() << endl;

//
//
//    floor2.printFloorPickupMenu(cout);
    cout << endl;
    
    cout << endl;
}

void move_tests() {
    cout << "TESTING MOVE" << endl;
    
    cout << "Expected: " << endl;
    Move("e1f4");
}
