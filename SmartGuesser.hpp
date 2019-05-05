#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
#include <unordered_set>
#include <math.h>
#include <iostream>


/**
 * ConstantGuesser is a guesser that always guesses the same string.
 */
class SmartGuesser: public bullpgia::Guesser {
	private:
		std::string Guess="";
		std::unordered_set<std::string> _set;
		void Guess_changer();
		void full_search();
		void permute(std::string str); 
		int guess_index=0;
		std::string tempguess = "";
	public:
		std::string guess() override;
		void startNewGame(uint Length) override;
		void learn(std::string res) override;
};

//std::string numToGuess(int num, uint length);
