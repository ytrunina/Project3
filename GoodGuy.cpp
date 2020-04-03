#include "stdafx.h"
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include "GoodGuy.h"

using namespace std;

GoodGuy::GoodGuy()
{
	strGoodGuyName = "";
	nNumLifePoints = 100;

	/* initialize random seed: */
	srand(time(NULL));
}


GoodGuy::~GoodGuy()
{
}


//sets Guys current room
void GoodGuy::SetCurrentRoom(Room* r)
{
	CurrentRoom = r;
}

//get the guy current room
Room GoodGuy::getCurrentRoom()
{
	return *CurrentRoom;
}



//sets guys name
void GoodGuy::setGoodGuyName(string strName)
{
	strGoodGuyName = strName;
}


//returns the num life points
int GoodGuy::getNumLifePoints()
{
	
	return nNumLifePoints;

}


//guy moves
void GoodGuy::GoodGuyMove(User* u)
{
	// Is the good guy in the same room as user u?
	if ((u->getCurrentRoom().getRoomName() == CurrentRoom->getRoomName()) && (nNumLifePoints==100))
	{
		// If so then the good guy can add life points
		GoodGuyDefence(u);
		
	}
	nNumLifePoints = 0;
	
}


//guy adds points to the user
void GoodGuy::GoodGuyDefence(User* u)
{	
	if (nNumLifePoints == 100)
	{

		cout << strGoodGuyName << " is adding lifepoints to " << u->getUserName() << "\n";


		int iAmtDefence;


		iAmtDefence = rand() % 5 + 1;

		// the guy can add 1 to 5 life points to the user.
		cout << strGoodGuyName << " added " << iAmtDefence << " life points to " << u->getUserName() << "\n";
		u->AddLifePoints(iAmtDefence);

		getCurrentRoom();

	}
}
