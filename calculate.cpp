#include "calculate.hpp"
#include <string>
using std::string, std::to_string;

namespace bullpgia {
	const string calculateBullAndPgia(const string choosen, const string guess){
		if(choosen.length() != guess.length())
        return "0,0";

    else{
        uint bull = 0;
        uint pgia = 0;

        for(int i = 0; i<=guess.length(); i++){
            if(choosen.find(guess[i])){
                for(int j = 0; j<=choosen.length(); j++){
                    bool flag = false;
                    if(guess[i] == choosen[j]){
                        if(i==j){
                            bull++;
                            if(flag)
                            pgia--;
                        break;
                            }
                        else if(!flag){
                            pgia++;
                            flag=true;
                            }
                    }
                }
            }
        }
        	std::string s=(to_string(bull)+","+to_string(pgia));
         return s;
    }
	}

	}