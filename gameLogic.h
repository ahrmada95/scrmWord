#ifndef GAMELOGIC_H
#define GAMELOGIC_H

/*
@file gameLogic.h
	A class of game logic and actions that the drawer will use to display the game. 
	**REQUIRES PLAYER CLASS**
@author AA*/

#include <iostream>
#include <string>
#include <vector>
#include "player.h"

class GameLogic{
	public:
		/*GameLogic Object Constructor
		@param properList A vector of strings from the InputValidation class.
		@pre None.
		@post None.
		@return Returns a GameLogic object to represent the game backend, all private members are initalized.*/
		GameLogic(std::vector<std::string> &properList);


		/*gameWin method
		@param thisPlayer Player object to get stats from.
		@pre None.
		@post None.
		@return True if player has won the game, by reaching a difficulty level higher than maxDifficulty.*/		
		bool gameWin(Player &thisPlayer);

		/*getKey method
		@param posList The positon on the wordList the player wants to return.
		@pre Must be less than size of the list.
		@post None.
		@return String of the word on the vector at that location.
				Else will return ERROR 5GL*/
		std::string getKey(unsigned int posList);

		/*nextWord method
		@param currentLevel The current level of the player to base the next 	word to be scrambled.
		@pre None.
		@post None.
		@return String of the next word the player is to guess
			Will return "ERROR 4GL" if there is no next word.*/		
		std::string nextWord(unsigned int currentLevel);

		/*addCorrect method
		@param correctGuess The correct guess the player has made.
		@pre None.
		@post None.
		@return Adds correctGuess to correctList vector.*/		
		void addCorrect(std::string &correctGuess);

		/*getCorrectList method
		@param None.
		@pre None.
		@post None.
		@return vector of strings of correctList data member.*/	
		std::vector<std::string> getCorrectList();		

		/*addSkipped method	
		@param skippedWord The word the player decided to skip.
		@pre None.
		@post None.
		@return Adds skippedWord to skippedList vector.*/		
		void addSkipped(std::string &skippedWord);	

		/*getSkippedList method
		@param None.
		@pre None.
		@post None.
		@return vector of strings of skippedList data member.*/	
		std::vector<std::string> getSkippedList();	

		/*compare method
		@param guess The player's guess.
		@param key The unscrambeled word.
		@pre None.
		@post None.
		@return True if they are the same.*/		
		bool compare(std::string &guess, std::string &key);

		/*scrambleWord method
		@param specialWord The word the player is to guess for next.
		@pre None.
		@post None.
		@return String of a scrambeled word.*/		
		std::string scrambleWord(std::string &specialWord);	

		/*nextLevel method
		@param thisPlayer Player object
		@pre None.
		@post None.
		@return Level increases, correct guesses counter is set to 0.*/		
		void nextLevel(Player &thisPlayer);

	private:
		/*The longest word in the vector, is the highest level of difficulty*/
		unsigned int maxDifficulty;

		/*The parsed vector of strings that will be used as the word bank for the game*/
		std::vector<std::string> wordList;

		/*A vector of strings filled with words the player has guessed correctly*/
		std::vector<std::string> correctList;

		/*A vector of strings filled with words the player has skipped using the lifelines*/
		std::vector<std::string> skippedList;
};

#endif 
