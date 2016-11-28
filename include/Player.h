#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include "../include/Card.h"
#include <list>
#include <string>
#include <vector>
#include "../include/Hand.h"
#include "../include/Deck.h"

using namespace std;

class Player : public Hand {
private:
	const string name;
	int position;
public:
	Player(string _name, int _position);
	Player(const Player& other);
	string getName();   //Returns the name of the player
	int exchange(int value, Player& other);
    int myPosition();
	virtual int whatToAsk()=0;
	virtual int getType()=0;
	virtual int whoToAsk(int numOfPlayers)=0;
};

class PlayerType1 : public Player {  //For strategy 1
public:
	PlayerType1(const Player& other);
	PlayerType1(string _name, int _position);
	int whatToAsk();
	int getType();
	int whoToAsk(int numOfPlayers);

};

class PlayerType2 : public Player {  //For strategy 2
public:
    PlayerType2(string _name, int _position);
    int whatToAsk();
	int getType();
	int whoToAsk(int numOfPlayers);
	PlayerType2(const Player& other);

};

class PlayerType3 : public Player {  //For strategy 3
private:
    int nextPosition;
public:
    PlayerType3(string _name, int _position);
    int whoToAsk(int numOfPlayers);
    int whatToAsk();
	int getType();
	PlayerType3(const Player& other);

};

class PlayerType4 : public Player {  //For strategy 4
private:
    int nextPosition;
public:
    PlayerType4(string _name, int _position);
    int whoToAsk(int numOfPlayers);
    int whatToAsk();
	int getType();
	PlayerType4(const Player& other);


};

#endif
