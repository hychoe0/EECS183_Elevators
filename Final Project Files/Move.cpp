/*
 * Copyright 2022 University of Michigan EECS183
 *
 * Move.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Juana, Gerrard, Priya, Meera
 * juani, hychoe, priyasha, mmanek
 *
 * Final Project - Elevators
 */
 
#include <cmath>
#include <sstream>
#include <stdio.h>      
#include <stdlib.h>
#include "Move.h"

using namespace std;

Move::Move(string commandString) : Move() {
    char junk;
    if (commandString.size() > 0){
        stringstream ins;
        ins << commandString;
        if (ins >> junk){
            if (tolower(junk) == 'e'){
                ins >> elevatorId >> junk;
                if (tolower(junk) == 'f'){
                    ins >> targetFloor;
                }
                else if (tolower(junk) == 'p'){
                    isPickup = true;
                }
            }
            else if (tolower(junk) == 'q'){
                isQuit = true;
            }
            else if (tolower(junk) == 's'){
                isSave = true;
            }
        }
    }
    else{
        isPass = true;
    }
}
/*If a move is a Pass Move, a Quit Move, or a Save Move it is valid
*           For both Pickup Moves and Servicing Moves:
*               0 <= elevatorId < NUM_ELEVATORS
*               The corresponding Elevator is currently not
*                  servicing a request.
*           For Servicing Moves only:
*               0 <= targetFloor < NUM_FLOORS
*               targetFloor is different from the corresponding
*                  Elevator's currentFloor
 */
bool Move::isValidMove(Elevator elevators[NUM_ELEVATORS]) const {
    Elevator temporary = elevators[elevatorId];
    
    if (isPass == true) {
        return true;
    }
    else if (isQuit == true) {
        return true;
    }
    else if (isSave == true) {
        return true;
    }
    else {
        if (0 <= elevatorId && elevatorId < NUM_ELEVATORS &&
            temporary.isServicing() == false) {
            if (isPickup == true) {
                return true;
            }
            else {
                if (0 <= targetFloor && targetFloor < NUM_FLOORS &&
                    temporary.getCurrentFloor() != targetFloor)
                    return true;
            }
        }
    }
       
    return false;
        
}
        

void Move::setPeopleToPickup(const string& pickupList, const int currentFloor, const Floor& pickupFloor) {
    
    numPeopleToPickup = 0;
    totalSatisfaction = 0;
    int diffMax = 0;
    int extremeTargetFloor = 0;
        
    for (int i = 0; i < pickupList.size(); i++) {
        // ASCII hack, '0' = 48
        peopleToPickup[i] = pickupList[i] - '0';
        numPeopleToPickup++;
            
        Person A = pickupFloor.getPersonByIndex(peopleToPickup[i]);
            
        totalSatisfaction += (MAX_ANGER - A.getAngerLevel());
        
        int currTarDiff = abs(A.getCurrentFloor() - A.getTargetFloor());
        
        if (currTarDiff > diffMax) {
        
            diffMax = currTarDiff;
            extremeTargetFloor = A.getTargetFloor();
            }
        }

    targetFloor = extremeTargetFloor;

}

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Move::Move() {
    elevatorId = -1;
    targetFloor = -1;
    numPeopleToPickup = 0;
    totalSatisfaction = 0;
	isPass = false;
    isPickup = false;
    isSave = false;
    isQuit = false;
}

bool Move::isPickupMove() const {
    return isPickup;
}

bool Move::isPassMove() const {
	return isPass;
}

bool Move::isSaveMove() const {
	return isSave;
}

bool Move::isQuitMove() const {
	return isQuit;
}

int Move::getElevatorId() const {
    return elevatorId;
}

int Move::getTargetFloor() const {
    return targetFloor;
}

int Move::getNumPeopleToPickup() const {
    return numPeopleToPickup;
}

int Move::getTotalSatisfaction() const {
    return totalSatisfaction;
}

void Move::setTargetFloor(int inTargetFloor) {
    targetFloor = inTargetFloor;
}

void Move::copyListOfPeopleToPickup(int newList[MAX_PEOPLE_PER_FLOOR]) const {
    for (int i = 0; i < numPeopleToPickup; ++i) {
        newList[i] = peopleToPickup[i];
    }
}
