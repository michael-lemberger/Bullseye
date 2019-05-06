#include "SmartGuesser.hpp"
#include "calculate.hpp"
#include <unordered_set>
#include <math.h>
#include <iostream>
#include <bits/stdc++.h>

using std::string, std::to_string, std::unordered_set;

string SmartGuesser::guess() {
    //guess any possible option
	return this->Guess;
}


void SmartGuesser::startNewGame(uint Length) {
	Guess="";
    _set.clear();//clear our set if it already full
	tempguess="";
	guess_index=0;
   this->length=Length;
  for(int i=0;i<this->length;i++)// initialize first guess with '0'
  	Guess+='0';
}

void SmartGuesser::learn(string res) {
	if(tempguess.length()<this->length){
		int sum = (res.at(0)-'0');
		for(int i=0;i<sum;i++)
			tempguess+=to_string(guess_index);
		guess_index++;
		if(guess_index>9)
			guess_index=0;
		Guess_changer();
	}
	else
	{
		if(_set.empty())
			permute(tempguess);
	
	char bulls= res.at(0);//checks how many bulls we have
	char cows= res.at(2);//checks how many cows we have
	unordered_set<string> NotTheAnswer;
	for ( auto it = _set.begin(); it != _set.end(); it++){
		string response = bullpgia::calculateBullAndPgia(*it,Guess);
		if (response.at(0)!=bulls)
			NotTheAnswer.insert(*it);	
	}

	//removes from _set
	for ( auto it = NotTheAnswer.begin(); it != NotTheAnswer.end(); it++)
		_set.erase(*it);
		this->Guess= *_set.begin();
	}
}


void SmartGuesser::Guess_changer(){
	for(int i=0;i<this->length;i++){
		Guess.replace(i,i+1,to_string(guess_index));
	}
}

void SmartGuesser::permute(string str) 
{ 
    // Sort the string in lexicographically 
    // ascennding order 
    sort(str.begin(), str.end()); 
  
    // Keep printing next permutation while there 
    // is next permutation 
    do { 
      _set.insert(str);
    } while (std::next_permutation(str.begin(), str.end())); 
} 


