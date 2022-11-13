/*
 * Copyright 2022 University of Michigan EECS183
 *
 * Elevator.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Juana, Gerrard, Priya, Meera
 * juani, hychoe, priyasha, mmanek
 *
 * Final Project - Elevators
 */

#include "Elevator.h"
#include <iostream>

using namespace std;

void Elevator::tick(int currentTime) {
    // checking if currentTime is divisible by ticks per elevator move
    if (currentTime % TICKS_PER_ELEVATOR_MOVE == 0
        && servicing){
        //checking if elevator is going up. if so add 1 to currentFloor
        if (targetFloor > currentFloor){
            currentFloor++;
        }
        //checking if elevator is going down. if so substract 1 to currentFloor
        if (currentFloor > targetFloor) {
            currentFloor--;
        }
        // set servicing to false if the new current floor is the target floor
        if (currentFloor == targetFloor){
            servicing = false;
        }
    }
}

void Elevator::serviceRequest(int floorNum) {
    // setting target floor equal to the floorNum entered in the Building class
    targetFloor = floorNum;
    servicing = true;
}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

void Elevator::print(ostream &outs) {
    outs << currentFloor;
    if (!servicing){
        outs << "w";
    } else {
        outs << "s" << targetFloor;
    }
}

Elevator::Elevator() {
    currentFloor = 0;
    servicing = false;
	targetFloor = 0;
}

void Elevator::setCurrentFloor(int currentFloorIn) {
    currentFloor = currentFloorIn;
}

bool Elevator::isServicing() const {
	return servicing;
}

int Elevator::getCurrentFloor() const {
    return currentFloor;
}

int Elevator::getTargetFloor() const {
    return targetFloor;
}
