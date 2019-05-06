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
		std::string tempguess = "";//temporery guess to check witch number are in the secret
		std::unordered_set<std::string> _set;
		int guess_index=0;// help varible to go oer all numbers (0-9)
		void Guess_changer();// help function to change the tempguess
		void permute(std::string str); // help function to create all prmutations of tempguess
	public:
		std::string guess() override;
		void startNewGame(uint Length) override;
		void learn(std::string res) override;
};
