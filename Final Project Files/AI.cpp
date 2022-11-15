/*
 * Copyright 2022 University of Michigan EECS183
 *
 * AI.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Juana, Gerrard, Priya, Meera
 * juani, hychoe, priyasha, mmanek
 *
 * Final Project - Elevators
 */

#include "AI.h"
#include <cassert>

// This file is used only in the Reach, not the Core.
// You do not need to make any changes to this file for the Core

int sumEveryonesAnger(const BuildingState& buildingState, int floorNumber){
    int sum = 0;
    for (int i = 0; i < buildingState.floors[floorNumber].numPeople; i++){
        sum += buildingState.floors[floorNumber].people[i].angerLevel;
    }
    return sum;
}

int serviceFreeID(const BuildingState& buildingState) {
    int freeElevatorID = 0;
    
    for (int i = 0; i < 3; i++) {
        if (buildingState.elevators[i].isServicing == false) {
            freeElevatorID = i;
        }
    }
    return freeElevatorID;
}

int urgentFloor(const BuildingState& buildingState) {
    
    int largestNumPeople = buildingState.floors[0].numPeople;
    
    // finding the largest number of people on the floors
    for (int i = 0; i < 9; i++) {
        if (buildingState.floors[i].numPeople < buildingState.floors[i + 1].numPeople) {
            largestNumPeople = buildingState.floors[i + 1].numPeople;
        }
    }
    
    int count = 0;
    int urgentFloors[MAX_PEOPLE_PER_FLOOR] = {};
    
    
    for (int j = 0; j < 10; j++) {
        if (buildingState.floors[j].numPeople == largestNumPeople) {
            urgentFloors[count] = j;
            count++;
        }
    }
    int urgentFloor = urgentFloors[0];
    if (count > 1) {
        for (int k = 1; k < count; k++) {
            if (sumEveryonesAnger(buildingState, urgentFloors[k]) > sumEveryonesAnger(buildingState, urgentFloor)) {
                urgentFloor = urgentFloors[k];
            }
        }
    }
    return urgentFloor;
}

string getAIMoveString(const BuildingState& buildingState) {
    
//    if (buildingState.elevators[0].isServicing == true &&
//        buildingState.elevators[1].isServicing == true &&
//        buildingState.elevators[2].isServicing == true) {
//        return "";
//    }
        
    return "";
}

string getAIPickupList(const Move& move, const BuildingState& buildingState, 
                       const Floor& floorToPickup) {
    return "";
}
