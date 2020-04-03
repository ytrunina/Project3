#include "stdafx.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "Ghost.h"


using namespace std;

Ghost::Ghost()
{
	strGhostName = "";
	nNumLifePoints = 100;

	/* initialize random seed: */
	srand(time(NULL));
}


Ghost::~Ghost()
{
}



//sets Ghost current room
void Ghost::SetCurrentRoom(Room * r)
{
	CurrentRoom = r;
}

//get the Ghost current room
Room Ghost::getCurrentRoom()
{
	return *CurrentRoom;
}


//sets Ghost name
void Ghost::setGhostName(string strName)
{
	strGhostName = strName;
}


//returns the num life points
int Ghost::getNumLifePoints()
{
	return nNumLifePoints;
}


//ghost moves
void Ghost::GhostMove(User * u)
{
	// Is the GHost in the same room as user u?
	if (u->getCurrentRoom().getRoomName() == CurrentRoom->getRoomName())
	{
		// If so then the ghost can attack the user
		GhostAttack(u);

	}
}


//ghost attacks user
void Ghost::GhostAttack(User * u)
{
	cout << strGhostName << " is attacking " << u->getUserName() << "\n";
	
	int iHitUser;

	/* generate random number between 1 and 100: */
	iHitUser = rand() % 100 + 1;
	if (iHitUser <= 30) // the ghost has a 30 % chance of hitting the user
	{
		cout << strGhostName << " hits " << u->getUserName() << "\n";
		int iAmtDamage;

		/* generate random number between 1 and 10: */
		iAmtDamage = rand() % 10 + 1;

		// the ghost can do 1 to 10 life points damage to the user.
		cout << strGhostName << " does " << iAmtDamage<<" life points damage to "<< u->getUserName() << "\n";
		u->ReduceLifePoints(iAmtDamage);
		getCurrentRoom();
	}
	else
	{
		cout << strGhostName << " misses hitting " << u->getUserName() << "\n";
		getCurrentRoom();
	}
	
}



