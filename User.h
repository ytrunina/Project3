#pragma once
#include "string"
#include "Room.h"

using namespace std;

class User
{
private:
	string strUserName;
	int nNumLifePoints;
	Room *CurrentRoom;
	bool bUserQuit = false;

public:
	User();
	~User();

	//gets user name
	string getUserName();
	//sets user name
	void setUserName(string strName);

	//sets the users current room
	void SetCurrentRoom(Room * r);
	//get the users current room
	Room getCurrentRoom();

	//returns the num life points
	int getNumLifePoints();

	//Reduce Life points
	void ReduceLifePoints(int nAmt);

	//Add life points
	void AddLifePoints(int nAmt);

	//user moves
	void UserMove();

	// user change room
	void UserChangeRoom(direction d);

	//check health
	string checkHealth(int health, string healthDescr);

	//get User Quit
	bool getUserQuit();

};

