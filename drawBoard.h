#ifndef DRAWBOARD_H
#define DRAWBOARD_H

/*
@file drawBoard.h
	Funcitons to draw the board, handle input validation of the game, and act as a GUI
	**REQUIRES PLAYER CLASS***
	**REQUIRES GAMELOGIC CLASS***
@author AA*/

#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "gameLogic.h"

class DrawBoard{
	public:
		/*welcomeScreen method 
		@param None.
		@pre None.
		@post None.
		@return Draws the welcome screen, displays "How to Play".*/
		void welcomeScreen();


		/*postStart method 
		@param bool specificInput True if user has specified input at command line
		@pre None.
		@post None.
		@return Draws the post welcome screen.*/
		void postStart(bool specificInput);

		/*saveCheckAll method
		@param
		@pre
		@post
		@return Checks if all the save files are available, draws screen*/
		void saveCheckAll(/*SaveState saveFile*/);

		/*saveCheckSome method
		@param
		@pre
		@post
		@return Checks if some the save files are available, draws screen*/
		void saveCheckSome(/*SaveState saveFile*/);

		/*saveCheckNone method
		@param
		@pre
		@post
		@return Checks if none the save files are available, draws screen*/
		void saveCheckNone(/*SaveState saveFile*/);

		/*playerBegin method
		@param
		@pre
		@post
		@return Player can decide to continue or start a new game*/
		void playerBegin();

		/*banner method
		@param Player thisPlayer: Player object to pull player stat info.
		@pre None.
		@post None.
		@return Draws the banner with players stats*/
		void banner(Player &thisPlayer);

		/*body method
		@param Scrambeled word for the player to guess
		@pre None.
		@post None.
		@return Draws the body of the game with the scrambeled word*/
		void body(std::string &scrambledWord);

		/*choiceLife method
		@param None.
		@pre None.
		@post None.
		@return Choice GUI for player who has LifeLines*/
		void choiceLife();

		/*choiceNoLife method
		@param None.
		@pre None.
		@post None.
		@return Choice GUI for player who has LifeLines*/
		void choiceNoLife();

		/*guessScreen method
		@param None.
		@pre None.
		@post None.
		@return Choice GUI for player who has chosen to guess*/
		void guessScreen();

		/*guessRight method
		@param None.
		@pre None.
		@post None.
		@return Draws message when player has guessed correctly*/
		void guessRight();

		/*usedLifeLine method
		@param None.
		@pre None.
		@post None.
		@return Draws message when player has used a lifeline*/
		void usedLifeLine();

		/*playerQuit method
		@param None.
		@pre None.
		@post None.
		@return Draws message when player has chosen to quit correctly, autosave of the state of the game*/
		void playerQuit();

		/*playerWin method
		@param None.
		@pre None.
		@post None.
		@return Draws message when player has won the game*/
		void playerWin();

	private:

};

#endif
