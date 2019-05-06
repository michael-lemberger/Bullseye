#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
#include <unordered_set>
#include <iostream>


/**
 * SmartGuesser is a guesser that guesses the secret in maximum 100 turns.
 */
class SmartGuesser: public bullpgia::Guesser {
	private:
		std::string Guess="";
		std::unordered_set<std::string> _set;
		void Guess_changer();
		void permute(std::string str); 
		int guess_index=0;
		std::string tempguess = "";
	public:
		std::string guess() override;
		void startNewGame(uint Length) override;
		void learn(std::string res) override;
};
