#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"

/**
 * ConstantGuesser is a guesser that always guesses the same string. 
 */
class SmartGuesser: public bullpgia::Guesser {

	public:
		std::string guess() override;
		void startNewGame(uint size) override;
		void learn(std::string s) override;
};


