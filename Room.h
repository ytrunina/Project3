#pragma once
#include "string"
using namespace std;

// these are the valid directions
enum direction
{
	North,
	South,
	East,
	West
};

// this class is the Room object
class Room
{
private:
	string strRoomName;
	string strRoomDesc;
	Room *movementRoom[4];
	

public:
	Room();
	~Room();
	
	//get room name
	string getRoomName();
	string getRoomDesc();
	//set room name
	void setRoomName(string strName);
	void setRoomDesc(string roomDesc);

	//Displays information about a room
	void DisplayRoomInfo();

	//Set room North
	void SetRoomNorth(Room * r);
	//Set room South
	void SetRoomSouth(Room * r);
	//Set room East
	void SetRoomEast(Room * r);
	//Set room West
	void SetRoomWest(Room * r);


	// this will either return null if this is an invalid movement
	// or a pointer to the new room
	Room * MoveRoom(direction d);
};

