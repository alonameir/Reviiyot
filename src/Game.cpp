//
// Created by romybu on 25/11/16.
//
#include "../include/Card.h"
#include "../include/Deck.h"
#include "../include/Player.h"
#include "../include/Hand.h"
#include "../include/Game.h"
#include <vector>
using namespace std;

Game::Game(char* configurationFile);
void Game:: init();
void Game:: play();
void Game:: printState();        //Print the state of the game as described in the assignment.
void Game:: printWinner();       //Print the winner of the game as describe in the assignment.
void Game:: printNumberOfTurns(); //Print the number of played turns at any given time.
bool Game:: isGameOver();
void Game:: turn(Player& other);
