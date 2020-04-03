#pragma once
#include "string"
#include "Room.h"
#include "User.h"

class Ghost
{
private:
	string strGhostName;
	int nNumLifePoints;
	Room *CurrentRoom;


public:
	Ghost();
	~Ghost();

	//set name of Ghost
	void setGhostName(string strName);

	//set Ghost Current Room
	void SetCurrentRoom(Room * r);

	//get the Ghost current room
	Room getCurrentRoom();

	//returns the num life points
	int getNumLifePoints();

	//ghost moves
	void GhostMove(User *u);

	//ghost attacks player
	void GhostAttack(User * u);

	
};

