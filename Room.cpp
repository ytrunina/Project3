#include "stdafx.h"
#include <iostream>
#include "Room.h"
using namespace std;


Room::Room()
{
	strRoomName = "";
	strRoomDesc = "";
	movementRoom[North] = NULL; 
	movementRoom[South] = NULL;
	movementRoom[East] = NULL;
	movementRoom[West] = NULL;
}


Room::~Room()
{
}

//get room name
string Room::getRoomName()
{
	return strRoomName;
}

//Get room description
string Room::getRoomDesc()
{
	return strRoomDesc;
}

//Set room name
void Room::setRoomName(string strName)
{
	strRoomName = strName;
}

//Set room description
void Room::setRoomDesc(string roomDesc)
{
	strRoomDesc = roomDesc;
}

//Display room info
void Room::DisplayRoomInfo()
{
	cout << "\nYou are in the " << strRoomName << "\n\n";
	cout << strRoomDesc;
}

//Links rooms so that user can move through them
//Set room North
void Room::SetRoomNorth(Room * r)
{
	movementRoom[North] = r;
}
//Set room South
void Room::SetRoomSouth(Room * r)
{
	movementRoom[South] = r;
}

//Set room East
void Room::SetRoomEast(Room * r)
{
	movementRoom[East] = r;
}

//Set room West
void Room::SetRoomWest(Room * r)
{
	movementRoom[West] = r;
}

// this will either return null if this is an invalid movement
// or a pointer to the new room
Room * Room::MoveRoom(direction d)
{
	return movementRoom[d];
}