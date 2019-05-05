#include "SmartGuesser.hpp"
#include "calculate.hpp"
#include <unordered_set>
#include <math.h>
#include <iostream>

using std::string, std::to_string, std::unordered_set;
void SmartGuesser::full_search(){
//creates any possible guess
//its sould take 10^(length)
    uint END = pow(10,this->length);
    for(int i=0;i<END;++i){
        string s = to_string(i);
        while(s.length()<this->length)
            s=to_string(0)+s;//for any option under 10^(length-1)
        _set.insert(s);
    }
}


string SmartGuesser::guess() {
    //guess any possible option
	return this->Guess;
}


void SmartGuesser::startNewGame(uint Length) {
    _set.clear();//clear our set if it already full
   this->length=Length;
   this->full_search();//inserts all optional results to myset
    this->Guess = *_set.begin(); //takes the first string from the set as a guess
}

void SmartGuesser::learn(string reply) {
	char bulls= reply.at(0);//checks how many bulls we have
	char cows= reply.at(2);//checks how many cows we have
	unordered_set<string> NotTheAnswer;
	for ( auto it = _set.begin(); it != _set.end(); it++){
        string res = bullpgia::calculateBullAndPgia(*it,Guess);
		/*finds all the optional strings
		 witch sare the same amount of bulls
		  with our guess,
		 and eliminate the rest*/
		if (res.at(0)!=bulls)
			NotTheAnswer.insert(*it);
	}

	//removes from myset
	for ( auto it = NotTheAnswer.begin(); it != NotTheAnswer.end(); it++)
		_set.erase(*it);
		NotTheAnswer.clear();
		this->Guess= *_set.begin();
}


