
#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include "../include/Card.h"
#include "../include/Deck.h"
#include "../include/Player.h"
#include "../include/Hand.h"
#include <vector>

using namespace std;

class Game {
private:
	vector<Player *> players;  //The list of the players
	Deck deck;//The deck of the game
    int currPlayer;
    int numOfTurns;
    int verbal;
    int n;
    string whoToAsk;
    string initGame;

    void split(const string &s, char delim, vector<string> &elems);
    vector<string> split(const string &s, char delim);


public:
	Game(char* configurationFile);
   // Game (const Game& other);
	~Game();

//	void init();
//	void play();
//	void printState();        //Print the state of the game as described in the assignment.
//	void printWinner();       //Print the winner of the game as describe in the assignment.
//    void printNumberOfTurns(); //Print the number of played turns at any given time.
//    bool isGameOver();
//    void turn(Player& other);
//	int haveMostOfCard();
//    void brief( string name1, string name2, int value);
//    void printInitGame();
};

#endif
