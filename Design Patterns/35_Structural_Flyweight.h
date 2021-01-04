#pragma once

// FlyWeight Pattern with example of Counter Strike Game 
// TO BE COMPLETED - CONTROLLED 
// ----------------------------------------------------
// ----------------------------------------------------

#ifdef STRUCTURAL_FLIGHTWEIGHT_I

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<string> 
#include<map> 
#include<random> 
#include<iterator> 

// A common interface for all players 
class Player {
public:
	virtual void assignWeapon(std::string weapon) = 0;
	virtual void mission() = 0;
};

// Derived class (a player) must have weapon and mission 
class Terrorist : public Player {
public:
	Terrorist()	{
		TASK = "PLANT A BOMB";
	}
	void assignWeapon(std::string weapon) override
	{
		// Assign a weapon 
		this->weapon = weapon;
	}
	void mission() override
	{
		//Work on the Mission 
		std::cout << "Terrorist with weapon " <<  weapon + "|" << " Task is " <<  TASK <<"\n";
	}
private:
	// Intrinsic Attribute 
	std::string TASK;

	// Extrinsic Attribute 
	std::string weapon;
};

// Derived class (another player) must have weapon and mission 
class CounterTerrorist : public Player {
public: 
	CounterTerrorist()	{
		TASK = "DIFFUSE BOMB";
	}
	void assignWeapon(std::string weapon) override{
		this->weapon = weapon;
	}
	void mission() override	{
		std::cout << "Counter Terrorist with weapon " << weapon + "|" << " Task is " << TASK << "\n";
	}
private:
	// Intrinsic Attribute 
	std::string TASK;

	// Extrinsic Attribute 
	std::string weapon;
};

// Class used to get a player using Map
// Returns an existing player if a player of given type exists. 
// Else creates a new player and returns it. 
class PlayerFactory{
public:
	/* Map stores the reference to the object of Terrorist(TS) or CounterTerrorist(CT). */
	static const std::map<std::string, Player> *hm;

	// Method to get a player 
	 static Player getPlayer(std::string type)
	{
		 Player* p;
		/* If an object for TS or CT has already been
		created simply return its reference */
		if (hm->find(type) == hm->end())
		{
			p = nullptr;
		}
		else {
			p = hm->find(type)->second;
		}
				
		else
		{
			/* create an object of TS/CT */
			switch (type)
			{
			case "Terrorist":
				std::cout << "Terrorist Created";
				p = new Terrorist();
				break;
			case "CounterTerrorist":
				std::cout << "Counter Terrorist Created";
				p = new CounterTerrorist();
				break;
			default:
				std::cout << "Unreachable code!";
			}

			// Once created insert it into the HashMap 
			hm.put(type, p);
		}
		return p;
	}



};

const std::map<std::string, Player> *PlayerFactory::hm =
new std::map<std::string, Player>();

// Driver class 
class CounterStrike {
public:
	// All player types and weapon (used by getRandPlayerType() and getRandWeapon() 
	static std::vector<std::string> playerType;
	static std::vector<std::string> weapons;

	// Utility methods to get a random player type and weapon 
	 static std::string getRandPlayerType()
	{
		//std::uniform_int_distribution<int> uniform_dist(0, 2);
		Random r = new Random();

		// Will return an integer between [0,2) 
		int randInt = r.nextInt(playerType.size());

		// return the player stored at index 'randInt' 
		return playerType[randInt];
	}
	static std::string getRandWeapon()
	{
		Random r = new Random();

		// Will return an integer between [0,5) 
		int randInt = r.nextInt(weapons.size());

		// Return the weapon stored at index 'randInt' 
		return weapons[randInt];
	}
};

// Initialization for static class data members 
std::vector<std::string> CounterStrike::playerType = { "Terrorist", "CounterTerrorist" };

std::vector<std::string> CounterStrike::weapons =
{ "AK-47", "Maverick", "Gut Knife", "Desert Eagle" };

// Driver code 
int main() {

	/* Assume that we have a total of 10 players in the game. */
	for (int i = 0; i < 10; i++)
	{
		/* getPlayer() is called simply using the class
		name since the method is a static one */
		Player p = PlayerFactory.getPlayer(getRandPlayerType());

		/* Assign a weapon chosen randomly uniformly
		from the weapon array */
		p.assignWeapon(getRandWeapon());

		// Send this player on a mission 
		p.mission();
	}
}

#endif // STRUCTURAL_FLIGHTWEIGHT_I

// ----------------------------------------------------
// ----------------------------------------------------