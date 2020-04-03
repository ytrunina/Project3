#pragma once
#include "string"
#include "Room.h"
#include "User.h"

class GoodGuy
{
private:
	string strGoodGuyName;
	int nNumLifePoints;
	Room* CurrentRoom;


public:
	GoodGuy();
	~GoodGuy();

	//set name 
	void setGoodGuyName(string strName);

	//set Current Room
	void SetCurrentRoom(Room* r);

	//get the current room
	Room getCurrentRoom();

	//returns the num life points
	int getNumLifePoints();

	//goodguy moves
	void GoodGuyMove(User* u);

	//defend user
	void GoodGuyDefence(User* u);






};

