#pragma once

#include <string>

namespace bullpgia {
	class Chooser {
		public:
			uint length;
			virtual std::string choose(uint length){return NULL;}=0;
	};
}