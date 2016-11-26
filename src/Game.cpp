//
// Created by romybu on 25/11/16.
//

#include <vector>
#include <string>
#include "../include/Card.h"
#include "../include/Deck.h"
#include "../include/Player.h"
#include "../include/Hand.h"
#include "../include/Game.h"
#include <fstream>
#include <sstream>

using std::ifstream;
using namespace std;


//TO-DO: function that recieves line and returns vector<Player>
Game::Game(char *configurationFile)
        : deck(), players(), whoToAsk(), initGame(), verbal(-1), numOfTurns(0), currPlayer(0) {
    ifstream toRead(string() + configurationFile);
    string content((std::istreambuf_iterator<char>(toRead)),
                   (std::istreambuf_iterator<char>()));
    int parameter = 0;

    string line;
    istringstream f(content);

    while (parameter <= 3) {
        getline(f, line);//trim
        if ((!line.empty()) && line.at(0) != '#') {
            if (parameter == 0) {//reading verbal parameter
                if (line.at(0) == '0')
                    verbal = 0;
                else
                    verbal = 1;
            } else if (parameter == 1) {//reading highest numeric value parameter
                string s("");
                istringstream iss(line);
                iss >> s;
                n = stoi(line);
            } else if (parameter == 2) {//reading the deck parameter
                deck = Deck(line, n);
            } else { // (parameter==3)reading the players
                int pos = 0;
                while (!line.empty()) {
                    vector<string> s(split(line, ' '));
                    int strategy = stoi(s[1]);
                    if (strategy == 1) {
                        PlayerType1 tmp(s[0], pos);
                        players.push_back(&tmp);
                    } else if (strategy == 2) {
                        PlayerType2 tmp(s[0], pos);
                        players.push_back(&tmp);
                    } else if (strategy == 3) {
                        PlayerType3 tmp(s[0], pos);
                        players.push_back(&tmp);
                    } else { // (strategy==4)
                        PlayerType4 tmp(s[0], pos);
                        players.push_back(&tmp);
                    }
                    pos++;
                    getline(f, line);
                }
            }
            parameter++;
        }
    }
}

void Game::split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

vector<string> Game::split(const string &s, char delim) {
    vector<std::string> elems;
    split(s, delim, elems);
    return elems;
}

/*
void Game::init();

void Game::play();

void Game::printState();        //Print the state of the game as described in the assignment.
void Game::printWinner();       //Print the winner of the game as describe in the assignment.
void Game::printNumberOfTurns(); //Print the number of played turns at any given time.
bool Game::isGameOver();

void Game::turn(Player &other);
*/