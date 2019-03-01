#include "drawBoard.h"
#include "gameLogic.h"
#include "player.h"

/*
@file drawBoard.cpp
	Funcitons to draw the board, handle input validation of the game, and act as a GUI
	**REQUIRES PLAYER CLASS***
	**REQUIRES GAMELOGIC CLASS**
@author AA*/

#include <iostream>
#include <string>

using namespace std;

/*welcomeScreen method 
@param None.
@pre None.
@post None.
@return Draws the welcome screen, displays "How to Play".*/

//global function used to clear the screen
void clear(){
	cout << "\033[2J\033[1;1H";
}

//global function to get a linebreak 
void lineBrk(){
	cout<<endl;
}

/*welcomeScreen method 
@param None.
@pre None.
@post None.
@return Draws the welcome screen, displays "How to Play".*/
void DrawBoard::welcomeScreen(){
	clear();
	cout<<"---------------------------------------------------------"<<endl;
	cout<<"                Welcome to GuessScramble!"<<endl;
	cout<<"---------------------------------------------------------"<<endl;
	cout<<"HOW TO PLAY: "<<endl;
	cout<<"1. Object of the game is to correctly guess the"<<endl;
	cout<<"   correct form of a scrambled word."<<endl;
	cout<<"2. Unlimited number of guesses until you're right!"<<endl;
	cout<<"3. If you guess 3 words of the same length you level up"<<endl;
	cout<<"   and have to guess longer words!"<<endl;
	cout<<"4. If you don't think you can guess the word, use a"<<endl;
	cout<<"   lifeline!"<<endl;
	cout<<"   Lifelines allow you to skip a word forever! But you"<<endl;
	cout<<"   may have to solve another word of the same or higher"<<endl;
	cout<<"   difficulty level! And remember, you only get 5!"<<endl;
	cout<<"5. Type in your choices and press enter when prompted!"<<endl;
	cout<<"6. The game will autosave when you quit properly"<<endl;
	lineBrk();
	cout<<"                    GOOD LUCK!"<<endl;
}


/*banner method
@param Player thisPlayer: Player object to pull player stat info.
@pre None.
@post None.
@return Draws the banner with players stats*/
void DrawBoard::banner(Player &thisPlayer){
	clear();
	cout<<"---------------------------------------------------------"<<endl;
	cout<<"Player Level"<<" = "<<thisPlayer.getLevel()<<endl;
	cout<<"Life Lines remaining"<<" = "<<thisPlayer.getLife()<<endl;
	cout<<"---------------------------------------------------------"<<endl;
}


/*body method
@param Scrambeled word for the player to guess
@pre None.
@post None.
@return Draws the body of the game with the scrambeled word*/
void DrawBoard::body(string &scrambledWord){
	lineBrk();
	lineBrk();
	cout<<"\t"<<"\t"<<scrambledWord<<endl;
}

/*choiceLife method
@param None.
@pre None.
@post None.
@return Choice GUI for player who has LifeLines*/
void DrawBoard::choiceLife(){
	lineBrk();
	lineBrk();
	cout<<"Enter the choice and press enter:"<<endl;
	cout<<"1. Guess"<<endl;
	cout<<"2. Use Life Line"<<endl;
	cout<<"3. Quit"<<endl;
}

/*choiceNoLife method
@param None.
@pre None.
@post None.
@return Choice GUI for player who has no LifeLines*/
void DrawBoard::choiceNoLife(){
	lineBrk();
	lineBrk();
	cout<<"Enter the choice and press enter:"<<endl;
	cout<<"1. Guess"<<endl;
	cout<<"2. [No more Life Lines!]"<<endl;
	cout<<"3. Quit"<<endl;
}

/*guessScreen method
@param None.
@pre None.
@post None.
@return Choice GUI for player who has chosen to guess*/
void DrawBoard::guessScreen(){
	cout<<"You have chosen to Guess the word!"<<endl;
	cout<<"Enter your guess and press enter: ";
}

/*guessRight method
@param None.
@pre None.
@post None.
@return Draws message when player has guessed correctly*/
void DrawBoard::guessRight(){
	cout<<"\t"<<"\t"<<"\t"<<"was the correct answer!"<<endl;
}

/*usedLifeLine method
@param None.
@pre None.
@post None.
@return Draws message when player has used a lifeline*/
void DrawBoard::usedLifeLine(){
	cout<<"Player has chosen to use a Life Line."<<endl;
	cout<<"Number of life lines will be decreased by one."<<endl;
}

/*playerQuit method
@param None.
@pre None.
@post None.
@return Draws message when player has chosen to quit correctly, autosave of the state of the game*/
void DrawBoard::playerQuit(){
	cout<<"Player has chosen to quit."<<endl;
	cout<<"Game has been saved."<<endl;
}

/*playerWin method
@param None.
@pre None.
@post None.
@return Draws message when player has won the game*/
void DrawBoard::playerWin(){
	cout<<"Congratulations!"<<endl;
	cout<<"You won the game!"<<endl;

}
