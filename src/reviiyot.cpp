#include <iostream>

#include "../include/Card.h"
#include "../include/Deck.h"
#include "../include/Game.h"
#include "../include/Hand.h"

using namespace std;

int main(int argc, char **argv) {
	/*char* configurationFile = argv[1];

	Game game = Game(configurationFile);
	game.init();
 	Game initializedGame = game;
 	game.play();  

	cout << std::endl;
 	game.printWinner();
	game.printNumberOfTurns();
	cout << "----------" << endl;
	cout<<"Initial State:"<<endl;
  	initializedGame.printState();
	cout<<"----------"<<endl;
	cout<<"Final State:"<<endl;
	game.printState();
	return 0;
	 */

	/*string* s= new string("KC QH 3D AH JH 2C 3S KS AS JS 3C KH AD QC JD QS 3H KD AC JC 2D 2H 2S QD");
    //string* s= new string("KC QH 3D");

	Deck d(*s, 3);
    cout << (d).getNumberOfCards()<<endl;
     cout << (d).isEmpty()<<endl;
	cout << (d).toString()<<endl;
*/
    Hand* h=new Hand();

    Card* c1= new FigureCard(Diamond,Jack);
  //  Card* c3= new FigureCard(Spade,Jack);
    Card* c2= new FigureCard(Diamond,Queen);
  //  Card* c10= new FigureCard(Club,Jack);
    Card* c4= new FigureCard(Heart,King);
  //  Card* c11= new NumericCard(Club,10);
  //  Card* c12= new NumericCard(Diamond,10);
    Card* c5= new NumericCard(Diamond,9);
//    Card* c6= new NumericCard(Spade,10);
    Card* c9= new FigureCard(Heart,Jack);
    Card* c7= new NumericCard(Heart,10);
    Card* c8= new NumericCard(Diamond,9);
  //  Card* c13= new NumericCard(Spade,3);
   Card* c14= new NumericCard(Heart,3);
  Card* c15  = new NumericCard(Club,3);

    (h)->addCard(*c1);
   // (h)->addCard(*c13);
  (h)->addCard(*c14);
   (h)->addCard(*c15);

    (h)->addCard(*c2);
 //   (h)->addCard(*c3);
    (h)->addCard(*c4);
    (h)->addCard(*c5);
  //  (h)->addCard(*c11);
  //  (h)->addCard(*c12);
  //  (h)->addCard(*c6);
 //   (h)->addCard(*c7);
    (h)->addCard(*c8);
    (h)->addCard(*c9);
 //   (h)->addCard(*c10);

    cout<< h->toString() <<endl;

    //h->delFour();

    cout<< h->findLeastAppeared() <<endl;
    cout<< h->toString() <<endl;

}

