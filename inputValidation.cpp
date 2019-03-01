#include "inputValidation.h"
/*
@file inputValidation.h
	Ensure that the text file for the word bank is proper or not
@author AA*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*InputValidation constructor
@param fileName string to open file name to pull data from
@pre None.
@post Must have no capital letters or special characters
@return constructs objects and wordBank for game to use if all checks are true*/
InputValidation::InputValidation(std::string fileName){
	//open file stream
	std::ifstream openFile;
	openFile.open(fileName);

	//initialize values
	wordSize = true;
	difficultyCount = true;

	//set boolean to true
	if(openFile.is_open()){
		fileFound=true;

		//ensures that there is one word on each line
		do{
			std::string temp;
			openFile>>temp;
			//add to the vector
			tempList.push_back(temp);
		}while(openFile.eof()==false);		
	}
	else{
		//file could not be opened 
		fileFound=false;
	}
	openFile.close();

	//remove all capital letters and special characters 
	if(fileFound == true){
		for(int a=0;a<tempList.size();a++){
			tempList[a] = removeSpecial(removeCap(tempList[a]));
		}
	}

	//iterate and check for words of length that are below 3 letters long
	for(int b=0;b<tempList.size()-1;b++){
		if(3>tempList[b].length()){
			//wordSize is false if there is any word below 3 letters in length
			wordSize = false;
			break;
		}
	}

	//initialize variable to hold the size of the longest word in the vector
	unsigned int maxSize=0;
	for(int c=0;c<tempList.size();c++){
		if(tempList[c].length()>maxSize){
			maxSize = tempList[c].length();
		}

	}

	//iterate through sizes of the word
	for(int d=3;d<=maxSize;d++){
		//initialize counter
		int counter=0;
		//iterate through vector
		for(int e=0;e<tempList.size();e++){
			//count the number of words of that length
			if(d==tempList[e].length()){
				counter++;
			}
		}

		//if there are numbers of a certain length that have onyl 1 or 2 members, difficulty count is false;
		if(counter==1 || counter==2){
			difficultyCount = false;
			break;
		}
	}

	//if booleans are true, export the vector into a list to be used by the program
	if(fileFound==true && wordSize==true && difficultyCount==true){
		std::ofstream bankOut;
		bankOut.open("wordlistTRUE.txt");
		for(int f=0;f<tempList.size();f++){
			bankOut<<tempList[f]<<"\n";
		}
	}
}

/*ifFileFound method
@param None.
@pre None.
@post None.
@return true if the file specified was found or not*/
bool InputValidation::ifFileFound(){
	return fileFound;
}

/*ifFileFound method
@param None.
@pre None.
@post None.
@return true if there are at least 3 words of the same difficulty for every difficulty level in the list*/
bool InputValidation::goodDifficultyCount(){
	return difficultyCount;
}

/*ifFileFound method
@param None.
@pre None.
@post None.
@return true if all words are 3 letters in length or greater*/
bool InputValidation::goodWordSize(){
	return wordSize;
}

/*removeCap method
@param reagent String to be modified 
@pre None.
@post None.
@return string with all capital letters changed to lowercase*/
std::string InputValidation::removeCap(std::string reagent){
	for(int n=0; n<reagent.size(); n++){
		//uses ascii table
		if(reagent[n]>='A' && reagent[n]<='Z'){
			reagent[n] = char (reagent[n]+32);
		}
	}
	return reagent;
}

/*removeSpecial method
@param reagent String to be modified 
@pre None.
@post None.
@return string with all special characters removed*/
std::string InputValidation::removeSpecial(std::string reagent){

	for(int m=0; m<reagent.size();m++){
		if(reagent[m]<'a' || reagent[m]>'z'){
			std::string part1 = reagent.substr(0,m);
			std::string part2 = reagent.substr(m+1,(reagent.size()-1));
			reagent = part1+part2;
		}
	}	
	return reagent;
}




