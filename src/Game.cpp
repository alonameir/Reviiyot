//
// Created by romybu on 25/11/16.
//

#include <vector>
#include <string>
#include "../include/Card.h"
#include "../include/Deck.h"
#include "../include/Hand.h"
#include "../include/Player.h"
#include "../include/Game.h"
#include <fstream>
#include <sstream>

using std::ifstream;
using namespace std;

//void Game:: init(){
//    for (int i=0; i< players.size(); i++){
//        for(int j=0; j<7; j++){
//            Card* toAdd=deck.fetchCard();
//            if(!((*(players[i])).addCard(toAdd))){
//                throw invalid_argument ("impossible to add card to a player");
//            }
//        }
//        (*(players[i])).delfour();
//    }
//}
//
//void Game:: play(){
//    init();
//    while(!(isGameOver())){
//        turn(&(players[currPlayer]);
//        if (currPlayer==players.size()-1)
//            currPlayer=0;
//        else{
//            currPlayer=currPlayer+1;
//        }
//        numOfTurns=numOfTurns+1;
//    }
//    printState();
//}
//
//void Game:: printNumberOfTurns(){
//    cout<< "Number of turns: "<< numOfTurns<< endl;
//}
//
////assume that only 1 or 2 winners;
//void Game:: printWinner(){
//    if (isGameOver()){
//        int numOfWinners=0;
//        int firstWinner=-1;
//        int secondWinner=-1;
//        int i;
//        for(i=0; i<players.size() && (numOfWinners!=2); i=i+1){
//            if ((*(players[i]))->getNumberOfCards()==0) {
//                if (firstWinner == -1) {
//                    firstWinner = i;
//                    numOfWinners = 1;
//                } else {
//                    secondWinner = i;
//                    numOfWinners = 2;
//                }
//            }
//        }
//        if (numOfWinners==1)
//            cout<< "***** The Winner is: " << ((*(players[firstWinner]))->getName()) << "*****"<<endl;
//        else if (numOfWinners==2)
//            cout<< "***** The Winners are: " << ((*(players[firstWinner]))->getName())
//                << ((*(players[secondWinner]))->getName())<< "*****"<<endl;
//    }
//}
//
////Print the number of played turns at any given time.
//void Game:: printState(){
//    if (!isGameOver()) {
//        cout << "Turn " << numOfTurns << endl;
//        cout << "Deck: " << deck.toString() << endl;
//        for (int i = 0; i < players.size(); i++) {
//            cout << players[i]->getName() << ": " << players[i]->toString() << endl;
//        }
//        cout << whoAskWho << endl;
//    }
//    else if (isGameOver()) && verbal==1){
//        printWinner();
//        printNumberOfTurns();
//        cout<< "----------"<< endl;
//        cout<< "Initial State:"<< endl;
//        cout <<initGame <<endl;
//        cout<< "----------"<< endl;
//        cout<< "Final State:"<< endl;
//        cout<< "Deck: "<< deck.toString() <<endl;
//        for( int i=0; i<players.size(); i++){
//            cout<< players[i]->getName() << ": " << players[i]->toString() <<endl;
//        }
//    }
//}
//
//bool Game:: isGameOver(){
//    bool ans=false;
//    for(int i=0; i<players.size() &!ans; i++){
//        if ((*(players[i]))->getNumberOfCards()==0)
//            ans=true;
//    }
//    return ans;
//}
//
//void Game:: turn(Player& current){
//    int value=current.whatToAsk();
//    int position=0;
//    if (current.getType()==1)
//        position=haveMostOfCard();
//    else if (current.getType()==2)
//        position=haveMostOfCard();
//    else if (current.getType()==3)
//        position= current.whoToAsk();
//    else if (current.getType()==4)
//        position= current.whoToAsk();
//
//    brief(current.getName(), (*(players[position]))->getName(), value);
//    printState();
//
//    int k=current.exchange(value, (*(players[position]));
//    bool toCheck= true;
//    for(int i=0; i<k && toCheck; i++){
//        if(!((*(players[position])).addCard(deck.fetchCard())))
//            toCheck=false;
//    }
//    if (!toCheck)
//        throw invalid_argument ("invalid fetch Card ");
//
//}
//
//int Game:: haveMostOfCard(){
//    int highesCardsAmount=0;
//    int posOfHighest=0;
//    for(int i=0; i<players.size(); i++){
//        if (highesCardsAmount <= (players[i]->getNumberOfCards())){
//            highesCardsAmount=players[i]->getNumberOfCards();
//            posOfHighest=i;
//        }
//    }
//    return posOfHighest;
//}
//
//void Game:: brief(string name1, string name2, int value){
//    string s("");
//    s.append(name1);
//    s.append(" asked ");
//    s.append(name2);
//    s.append(" for the value ");
//    if (value>0){
//        s.append(to_string(value));
//    }
//    if (value<0){
//        if (value==-1)
//            s.append("A");
//        if (value==-2)
//            s.append("K");
//        if (value==-3)
//            s.append("Q");
//        if (value==-4)
//            s.append("J");
//    }
//
//    whoAskWho=s;
//}
//
//void Game:: printInitGame(){
//    string s("");
//    s.append(deck.toString());
//    for( int i=0; i<players.size(); i++){
//        s.append(players[i]->getName());
//        s.append(": ");
//        s.append(players[i]->toString());
//        if (i!=players.size()-1)
//        s.append("\n");
//    }
//    s= initGame;
//
//}

Game::~Game(){
    for (vector<Player*>::iterator it=players.begin(); it!=players.end(); ++it){
        delete (*it);
    }
    players.clear();
}

Game::Game(char *configurationFile)
        : deck(), players(), whoToAsk(""), verbal(-1), numOfTurns(1), currPlayer(0) {
    ifstream toRead(string() + configurationFile);
    string content((std::istreambuf_iterator<char>(toRead)),
                   (std::istreambuf_iterator<char>()));
    int parameter = 0;

    string line;
    istringstream f(content);

    while (parameter <= 3) {
        getline(f, line);
        if ((!line.empty()) && line.at(0) != '#') {
            if (parameter == 0) {//reading verbal parameter
                if (line.at(0) == '0')
                    verbal = 0;
                else
                    verbal = 1;
            } else if (parameter == 1) {//reading highest numeric value parameter
                n = stoi(line);
            } else if (parameter == 2) {//reading the deck parameter
                deck = Deck(line, n);
            } else { // (parameter==3)reading the players
                int pos = 0;
                while (!line.empty()) {
                    vector<string> s(split(line, ' '));
                    int strategy = stoi(s[1]);
                    if (strategy == 1) {
                        PlayerType1* tmp= new PlayerType1(s[0], pos);
                        players.push_back(tmp);
                    } else if (strategy == 2) {
                        PlayerType2* tmp= new PlayerType2(s[0], pos);
                        players.push_back(tmp);
                    } else if (strategy == 3) {
                        PlayerType3* tmp= new PlayerType3(s[0], pos);
                        players.push_back(tmp);
                    } else { // (strategy==4)
                        PlayerType4* tmp= new PlayerType4(s[0], pos);
                        players.push_back(tmp);
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

//Game::Game(const Game &other) {
//
//}
