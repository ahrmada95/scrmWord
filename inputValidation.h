#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

/*
@file inputValidation.h
	Ensure that the text file for the word bank is proper or not
@author Ahnaf Ahmad*/

#include <iostream>
#include <string>
#include <vector>

class InputValidation{
	public:
		/*InputValidation constructor
		@param fileName string to open file name to pull data from
		@pre None.
		@post Must have no capital letters or special characters
		@return constructs objects and wordBank for game to use if all checks are true*/
		InputValidation(std::string fileName);

		/*ifFileFound method
		@param None.
		@pre None.
		@post None.
		@return true if the file specified was found or not*/
		bool ifFileFound();

		/*ifFileFound method
		@param None.
		@pre None.
		@post None.
		@return true if there are at least 3 words of the same difficulty for every difficulty level in the list*/		
		bool goodDifficultyCount();

		/*ifFileFound method
		@param None.
		@pre None.
		@post None.
		@return true if all words are 3 letters in length or greater*/
		bool goodWordSize();

		/*removeCap method
		@param reagent String to be modified 
		@pre None.
		@post None.
		@return string with all capital letters changed to lowercase*/
		std::string removeCap(std::string reagent);

		/*removeSpecial method
		@param reagent String to be modified 
		@pre None.
		@post None.
		@return string with all special characters removed*/
		std::string removeSpecial(std::string reagent);

		std::vector<std::string> tempList;

	private:
		//status of a files existence
		bool fileFound;
		//condition if there are at least 3 words of every difficulty level in the list
		bool difficultyCount;
		//condition if all words of 3 letters or greater are in the list
		bool wordSize;
		//std::vector<std::string> tempList;
};


#endif 
