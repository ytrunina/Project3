#include "stdafx.h"
#include <iostream>
#include <string>
#include "User.h"


using namespace std;

User::User()
{
	strUserName = "";
	nNumLifePoints = 100;
}


User::~User()
{
}


//current room
//sets users current room
void User::SetCurrentRoom(Room * r)
{
	CurrentRoom = r;
}
//get the users current room
Room User::getCurrentRoom()
{
	return *CurrentRoom;
}

//gets user name
string User::getUserName()
{
	return strUserName;
}

//sets user name
void User::setUserName(string strName)
{
	strUserName = strName;
}


//returns the num life points
int User::getNumLifePoints()
{
	return nNumLifePoints;
}

// reduces the life points by nAmt
void User::ReduceLifePoints(int nAmt)
{
	nNumLifePoints -= nAmt;
}

// Add life points
void User::AddLifePoints(int nAmt)
{
	nNumLifePoints += nAmt;
}


//get User Quit
bool User::getUserQuit()
{
	return bUserQuit;
}


//user moves
void User::UserMove()
{
	string strMove;
	cout << "\n\nIf you need help enter ?";
	cout << "\nIf you want to check your health enter h\n";
	cout << "*Special* For extra life points enter X. (For more details go to help --- enter ?)\n";
	cout << "\nIt is your turn what would you like to do?";
	cout << "\nYour choice: ";
	cin >> strMove;

	//validate move
	if ((strMove == "N") || (strMove == "n")) // move north
		UserChangeRoom(North);
	else if ((strMove == "S") || (strMove == "s")) // move south
		UserChangeRoom(South);
	else if ((strMove == "E") || (strMove == "e")) // move east
		UserChangeRoom(East);
	else if ((strMove == "W") || (strMove == "w")) // move west
		UserChangeRoom(West);
	else if ((strMove == "Q") || (strMove == "q")) // user quit
		bUserQuit = true;
	else if (strMove == "?") //ask for help
	{
		cout << "\n---------------------------------\n";
		cout << "---------------HELP--------------\n";
		cout << "Commands:\n";
		cout << "N or n : Moves the user to the room that is north of the current room (if such a room exists).\n";
		cout << "S or s : Moves the user to the room that is south of the current room (if such a room exists).\n";
		cout << "W or w : Moves the user to the room that is west of the current room (if such a room exists).\n";
		cout << "E or e : Moves the user to the room that is east of the current room (if such a room exists).\n\n";
		cout << "Q or q : Quit game\n";
		cout << "H or h : Check your health.\n\n\n";
		cout << "-----------SPECIAL--------------\n";
		cout << "X or x : If you enter X and your health is less than 80 you will get EXTRA 10 life points!!\n\n\n";
	}
	else if ((strMove == "h") || (strMove == "H")) //check health
	{
		string descr;

		cout << "\nLifepoints: " << nNumLifePoints << checkHealth(nNumLifePoints, descr)<< endl;
		cout << "--------------------------------\n";
	}
	else if ((strMove == "x") || (strMove == "X")) //extra points by entering X
	{
		if (nNumLifePoints < 80)
		{
			nNumLifePoints += 5;
			cout << "\n---------------------------------\n";
			cout << "You got extra 5 point to your health!\n\n";
			cout << "\n---------------------------------\n";

		}
		if (nNumLifePoints >= 80)
		{
			cout << "\n---------------------------------\n";
			cout << "\nYou health is " << nNumLifePoints << ". Use that option when you will have less that 80 life points!\n\n";
			cout << "\n---------------------------------\n";
		}
	}
	else
		cout << "Invalid command \n Please try again.";
	
}

// user change room
void User::UserChangeRoom(direction d)
{
	Room * r;	
	r = CurrentRoom->MoveRoom(d);
	if (r == NULL)
		cout << " You can not move that way!!!\n There is no door there.\n";
	else
		CurrentRoom = r;
}

//Function to display health results
string User::checkHealth(int health, string strHealth)
{
	if (nNumLifePoints > 90)
		strHealth= " ---- You are in the good health\n";
	else if ((nNumLifePoints > 70) && (nNumLifePoints < 90))
		strHealth = " ---- Your health could be better...\n";
	else if ((nNumLifePoints > 40) && (nNumLifePoints < 70))
		strHealth = " ---- You are not in the best health\n";
	else if ((nNumLifePoints > 1) && (nNumLifePoints < 40))
		strHealth = " ---- You are about to die...\n";
	return strHealth;
}