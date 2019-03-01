#ifndef GAMEDRIVER_H
#define GAMEDRIVER_H

/*
@file gameDriver.h
	Block functions for different parts of the game to be run
@author AA*/

#include "gameDriver.h"
#include "gameLogic.h"
#include "player.h"
#include "drawBoard.h"

class GameDriver{
	public:
		/*theGame method 
		@param Player thisPlayer Player object to pull stats from.
		@param GameLogic currentGame GameLogic object of the current state 
		@param nextWord Confirmed next word of difficulty for.
		@param DrawBoard gameUI DrawBoard object used to draw the GUI
		@pre None.
		@post None.
		@return Unsigned int of the players choice*/
		unsigned int theGame(Player &thisPlayer, GameLogic &currentGame, std::string nextWord, DrawBoard &gameUI);

		/*guess method 
		@param Player thisPlayer Player object to pull stats from.
		@param GameLogic currentGame GameLogic object of the current state 
		@param nextWord Confirmed next word of difficulty for.
		@param DrawBoard gameUI DrawBoard object used to draw the GUI
		@pre None.
		@post None.
		@return .*/
		bool guess(Player &thisPlayer, GameLogic &currentGame, std::string nextWord, DrawBoard &gameUI);

		/*correct method 
		@param Player thisPlayer Player object to pull stats from.
		@param GameLogic currentGame GameLogic object of the current state 
		@param nextWord Confirmed next word of difficulty for.
		@param DrawBoard gameUI DrawBoard object used to draw the GUI
		@pre None.
		@post None.
		@return Integer that incdicates that the player has been alerted about their answer being correct.*/
		unsigned int correct(Player &thisPlayer, GameLogic &currentGame, std::string nextWord, DrawBoard &gameUI);

		/*lifeline method 
		@param Player thisPlayer Player object to pull stats from.
		@param GameLogic currentGame GameLogic object of the current state 
		@param nextWord Confirmed next word of difficulty for.
		@param DrawBoard gameUI DrawBoard object used to draw the GUI
		@pre None.
		@post None.
		@return Integer that incdicates that the player has been alerted about their a life line being used.*/
		unsigned int lifeline(Player &thisPlayer, GameLogic &currentGame, std::string nextWord, DrawBoard gameUI);

		/*getScrambeledWord
		@param None.
		@pre None.
		@post None.
		@return string scrambeledWord of this data memeber*/
		std::string getScrambledWord();

		/*setSaveWord
		@param lastWord string of the scrambeled word displayed last game.
		@pre None.
		@post None.
		@return changes scrambeledWord for save file update*/
		void setSaveWord(std::string lastWord);

		/*check123 method 
		@param None.
		@pre None.
		@post Must be either 1,2,or 3.
		@return Unsigned int that is the players choice.*/	
		unsigned int check123();

		/*check12 method 
		@param None.
		@pre None.
		@post Must be either 1 or 2.
		@return Unsigned int that is the players choice.*/	
		unsigned int check13();

		/*pressContinue method
		@param None.
		@pre None.
		@post Must be 1.
		@return Unisnged int to progress the game.*/
		unsigned pressContinue();

	private:
		//hold on to the same version of a scrambled word
		std::string scrambledWord = "no change";
};

#endif
