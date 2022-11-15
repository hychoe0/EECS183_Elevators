/*
 * Copyright 2022 University of Michigan EECS183
 *
 * Building.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Juana, Gerrard, Priya, Meera
 * juani, hychoe, priyasha, mmanek
 *
 * Final Project - Elevators
 */

#include "Building.h"

using namespace std;


void Building::spawnPerson(Person newPerson){
    // adds a new person to a floor in a building
floors [newPerson.getCurrentFloor()] .addPerson (newPerson, newPerson.getTargetFloor() - newPerson.getCurrentFloor());
    
            
    }

//  Requires: move is a valid move
//* Modifies: The building member variables affected by the move
//* Effects: Applies the move to the building:
//*          * If the move is a Pass Move, nothing happens
//*          * If the move is a Pickup Move, copies the list of people to
//*            pickup into an array, and calls removePeople() on the
//*            appropriate floor
//*          * For both Pickup Moves and Service Moves, the appropriate
//*            elevator should be sent to service the targetFloor of the move
//*/
//void update(Move move);


void Building::update(Move move){
    int temp [MAX_PEOPLE_PER_FLOOR];
    if (move.isPassMove ()) {
        return;
    }
    if (!move.isPassMove() && !move.isQuitMove () && !move.isSaveMove ()) {
        if (move.isPickupMove())  {
            move.copyListOfPeopleToPickup(temp);
            floors[elevators [move.getElevatorId()].getCurrentFloor()].removePeople(temp ,move.getNumPeopleToPickup());
        elevators[move.getElevatorId()].serviceRequest(move.getTargetFloor());

        }
        
        else {
            elevators[move.getElevatorId()].serviceRequest(move.getTargetFloor());
        }
    }
    
}
int Building::tick(Move move){
    int numExploded = 0;
    time ++;
    update (move);
    for (int i = 0; i < NUM_ELEVATORS; i++) {
        elevators [i].tick(time);
    }
    for (int j = 0; j < NUM_FLOORS; j++) {
        numExploded += floors[j].tick(time);
    }
           return numExploded;
            
    }

//////////////////////////////////////////////////////
////// DO NOT MODIFY ANY CODE BENEATH THIS LINE //////
//////////////////////////////////////////////////////

Building::Building() {
    time = 0;
}

void Building::setElevator(string elevatorInfo, int elevatorId) {
    int i = 0;
    string currPosString = "";
    string destPosString = "";

    while(elevatorInfo[i] != 's' && elevatorInfo[i] != 'w'){
        currPosString += elevatorInfo[i];
        i++;
    }
    elevators[elevatorId] = Elevator();

    elevators[elevatorId].setCurrentFloor(stoi(currPosString));

    if (elevatorInfo[i] == 's') {
        i++;
        while (i < (int)elevatorInfo.size()) {
            destPosString += elevatorInfo[i];
            i++;
        }
        elevators[elevatorId].serviceRequest(stoi(destPosString));
    }
}

int Building::getTime() const {
    return time;
}

void Building::setTime(int timeIn) {
    time = timeIn;
}

void Building::prettyPrintBuilding(ostream& outs) const {
    //-------
    //| | | | 🔼 1 4 2
    //| | |E| 🔽 o o o
    //-------
    //| | | | 🔼   1
    //| |E| |      o
    //-------
    //| | | |
    //|E| | |
    for (int i = NUM_FLOORS - 1; i >= 0; --i) {
            outs << "   ";
            for (int j = 0; j < 2 * NUM_ELEVATORS + 1; ++j) {

                outs << '-';
            }

            outs << endl << "   ";

            for (int j = 0; j <  NUM_ELEVATORS; ++j) {
                char floorIndicatorIcon = ' ';

                if (elevators[j].getCurrentFloor() == i &&
                    elevators[j].isServicing()) {

                    char floorServiceIndicator = ('0' + elevators[j].getTargetFloor());
                    floorIndicatorIcon = floorServiceIndicator;
                }

                outs << "|" << floorIndicatorIcon;
            }
            outs << "|";

            floors[i].prettyPrintFloorLine1(outs);
            outs << i << "  ";
            for (int j = 0; j <  NUM_ELEVATORS; ++j) {

                outs << "|" << (elevators[j].getCurrentFloor() == i ? 'E' : ' ');
            }
            outs << "|";

            floors[i].prettyPrintFloorLine2(outs);
        }
        outs << "   ";
        for (int j = 0; j < 2 * NUM_ELEVATORS + 1; ++j) {
            outs << '-';
        }
        outs << endl << "   ";
        for (int j = 0; j < NUM_ELEVATORS; ++j) {
            outs << " " << j;
        }
        outs << endl;
}

Elevator Building::getElevatorById(int elevatorId) const {
    return elevators[elevatorId];
}

Floor Building::getFloorByFloorNum(int floorNum) const {
    return floors[floorNum];
}

BuildingState Building::getBuildingState() const {
    BuildingState buildingState;
    buildingState.turn = time;

    for (int i = 0; i < NUM_FLOORS; ++i) {
        buildingState.floors[i].floorNum = i;
        buildingState.floors[i].hasDownRequest = floors[i].getHasDownRequest();
        buildingState.floors[i].hasUpRequest = floors[i].getHasUpRequest();

        int & np = buildingState.floors[i].numPeople;

        for (int j = 0; j < floors[i].getNumPeople(); ++j) {

            Person p = floors[i].getPersonByIndex(j);
            buildingState.floors[i].people[np++].angerLevel = p.getAngerLevel();
        }
    }

    for (int i = 0; i < NUM_ELEVATORS; ++i) {
        Elevator e = elevators[i];

        buildingState.elevators[i].elevatorId = i;
        buildingState.elevators[i].targetFloor = e.getTargetFloor();
        buildingState.elevators[i].currentFloor = e.getCurrentFloor();
        buildingState.elevators[i].isServicing = e.isServicing();
    }

    return buildingState;
}
