//Yelena Trunina
//Dec 7, 2019
//Project 2

#include "stdafx.h"
#include <iostream>
#include "User.h"
#include "Room.h"
#include "Ghost.h"
#include "GoodGuy.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>  

using namespace std;

//User
User Player1 = User();

//rooms
const int numRooms = 8;
Room Rooms[numRooms] = { Room(), Room(), Room(), Room(), Room(), Room(), Room(), Room() };

//Ghosts
const int numGhosts = 5;
Ghost Ghosts[numGhosts] = { Ghost(), Ghost(), Ghost(), Ghost(), Ghost() };

//Good Guys
const int numGoodGuy = 2;
GoodGuy Guys[numGoodGuy] = { GoodGuy(), GoodGuy()};

//Prototype
void setUpRooms();
void setUpUser();
void setUpGhost();
int getRandomNum(int random);
void runProject();
void setUpGoodGuy();
void welcome();


int main()
{

	runProject();

}

void runProject()
{
	//welcome user
	welcome();

	//set up rooms
	setUpRooms();

	//set up user
	setUpUser();

	// keep playing until user decides to quit 
	// or user dies 
	while (!Player1.getUserQuit() && Player1.getNumLifePoints() > 0)
	{
		//display info current room
		Player1.getCurrentRoom().DisplayRoomInfo();

		//set up ghosts 

		setUpGhost();
		
		//Player 1 move
		Player1.UserMove();
		
		//allow ghosts to move
		for each (Ghost g in Ghosts)
		{
			//is the ghost still alive?
			if (g.getNumLifePoints() > 0)
			{
				//yes.. still alive
				g.GhostMove(&Player1);

			}
		}
		
		//Set up good guys
		setUpGoodGuy();

		//allow guys to move
		for each (GoodGuy gg in Guys)
		{
			if (gg.getNumLifePoints()>0)
			{
				gg.GoodGuyMove(&Player1);

			}
		}

		cout << "\nPress any key to continue game.\n";
		cout << "Enter here: ";
		
		string strWait;
		cin >> strWait;
		setUpGhost();
		system("CLS");
	}

	// closure
	if (Player1.getNumLifePoints() <= 0)
	{
		cout << "I am sorry but you have died. \n";
	}
	cout << "Thank you for playing... Please come again";
	string strWait;
	cin >> strWait;
}

//function that initializes user
void setUpUser()
{
	//prompt player for name
	string strName;
	cout << "What is your name?";
	cout << "\nEnter here: ";
	
	cin >> strName;
	cout << "------------------------------------------------------\n";

	Player1.setUserName(strName);

	// user starts in the hallway
	Player1.SetCurrentRoom(&Rooms[0]);
}

//function that initializes rooms
void setUpRooms()
{
	// initialize Rooms

	// Hallway
	Rooms[0].setRoomName("Hallway");
	// Kitchen
	Rooms[1].setRoomName("Kitchen");
	//LivingRoom
	Rooms[2].setRoomName("Living Room");
	//EastBedroom
	Rooms[3].setRoomName("East Bedroom");
	//West Bedroom
	Rooms[4].setRoomName("West Bedroom");
	//Master Bedroom
	Rooms[5].setRoomName("Master Bedroom");
	//Bathroom
	Rooms[6].setRoomName("Bathroom");
	//Garage
	Rooms[7].setRoomName("Garage");

	//Set room desctiption for each room.
	Rooms[0].setRoomDesc("If you want to go to the Kitchen enter W.\nIf you want to go to the East Bedroom enter E.\n");
	Rooms[1].setRoomDesc("If you want to go to Hallway enter E.\nIf you want to go to Living Room enter S\n");
	Rooms[2].setRoomDesc("If you want to go Kitchen enter N.\nIf you want to go to the GARAGE press E.\nIf you want to go the MASTER BEDROOM press S.\nIf you want to go to the WEST BEDROOM press W\n");
	Rooms[3].setRoomDesc("If you want to back to the HALLWAY enter W.\n");
	Rooms[4].setRoomDesc("If you want to go to the LIVING ROOM enter E.\nIf you want to go to the BATHROOM enter S.\n");
	Rooms[5].setRoomDesc("If you want to go to the LIVING ROOM enter N.\nIf you want to go to the BATHROOM enter W.\n");
	Rooms[6].setRoomDesc("If you want to go to the WEST BEDROOM enter N.\nIf you want to go to the MASTER BEDROOM enter E.\n");
	Rooms[7].setRoomDesc("If you want to go to the HALLWAY enter N.\nIf you want to go to the LIVING ROOM press W.\n");
	
	
	//Set up movement
	//MAP.JPG in the documents.
	// One Door
	Rooms[1].SetRoomEast(&Rooms[0]);
	Rooms[0].SetRoomWest(&Rooms[1]);
	// Second Door
	Rooms[1].SetRoomSouth(&Rooms[2]);
	Rooms[2].SetRoomNorth(&Rooms[1]);
	//Third Door
	Rooms[0].SetRoomEast(&Rooms[3]);
	Rooms[3].SetRoomWest(&Rooms[0]);
	//Forth Door
	Rooms[2].SetRoomSouth(&Rooms[5]);
	Rooms[5].SetRoomNorth(&Rooms[2]);
	//Fifth Door
	Rooms[0].SetRoomSouth(&Rooms[7]);
	Rooms[7].SetRoomNorth(&Rooms[0]);
	//Sixth Door
	Rooms[4].SetRoomSouth(&Rooms[6]);
	Rooms[6].SetRoomNorth(&Rooms[4]);
	//Seventh Door
	Rooms[2].SetRoomEast(&Rooms[7]);
	Rooms[7].SetRoomWest(&Rooms[2]);
	//8th Door
	Rooms[4].SetRoomEast(&Rooms[2]);
	Rooms[2].SetRoomWest(&Rooms[4]);
	//9th Door
	Rooms[6].SetRoomEast(&Rooms[5]);
	Rooms[5].SetRoomWest(&Rooms[6]);
}

//function that initializes ghost
void setUpGhost()
{
	int randomRoom=0;

	//Set up Tina the Ghost
	Ghosts[0].setGhostName("Tina");
	Ghosts[0].SetCurrentRoom(&Rooms[getRandomNum(randomRoom)]);
	//Set up Mike the Ghost
	Ghosts[1].setGhostName("Mike");
	Ghosts[1].SetCurrentRoom(&Rooms[getRandomNum(randomRoom)]);
	//Set up Emma the Ghost
	Ghosts[2].setGhostName("Emma");
	Ghosts[2].SetCurrentRoom(&Rooms[getRandomNum(randomRoom)]);
	//Set up Erik the Ghost
	Ghosts[3].setGhostName("Erik");
	Ghosts[3].SetCurrentRoom(&Rooms[getRandomNum(randomRoom)]);
	//Set up Henry the Ghost
	Ghosts[4].setGhostName("Henry");
	Ghosts[4].SetCurrentRoom(&Rooms[getRandomNum(randomRoom)]);

}

void setUpGoodGuy()
{
	int randomRoom = 0;

	//Set up good guys
	Guys[0].setGoodGuyName("Good guy Robert");
	Guys[0].SetCurrentRoom(&Rooms[getRandomNum(randomRoom)]);
	Guys[1].setGoodGuyName("Good guy Zach");
	Guys[1].SetCurrentRoom(&Rooms[getRandomNum(randomRoom)]);

}
//Function that will help to move ghosts and good guys to different rooms
int getRandomNum(int random)
{
	random = 0+rand() % 8;
	return random;
}

	

void welcome()
{
	// welcome 
	cout << "---------------WELCOME TO THIS WONDERFUL GAME!---------------\n\n";
	cout << "                      LET'S START!!!\n";
	cout << "-------------------------------------------------------------\n\n\n";
}