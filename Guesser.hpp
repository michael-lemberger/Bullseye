#pragma once
//#include "caculate.hpp"
#include <string>


namespace bullpgia {
	class Guesser {
		public:
			uint length;
			virtual std::string guess(){return NULL;};
			virtual void startNewGame(uint size){};
			virtual void learn(std::string){};
 	};
}
