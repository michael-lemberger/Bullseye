#include "calculate.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
using std::string, std::to_string;
using namespace std;
namespace bullpgia {
	const string calculateBullAndPgia(const string choosen, const string guess){

        uint bull = 0;
        uint pgia = 0;
		uint size= guess.length();

		if(size>choosen.length())
			size=choosen.length();

 		bool f_guess[guess.length()];
 		bool f_chooser[choosen.length()];
		
 		for(uint i=0;i<choosen.length();i++){
 			f_chooser[i]=false;
 		}
		for(uint i=0;i<guess.length();i++){
 			f_guess[i]=false;
 		}

 		for(uint i = 0; i<size; i++){
 			if(choosen[i]==guess[i]){
 				f_chooser[i]=true;
 				f_guess[i]=true;
 				bull++;
 			}
 		}

        for(int i = 0; i<choosen.length(); i++){
        	if(f_chooser[i]!=true){
                for(int j = 0; j<guess.length(); j++){
                    if(choosen[i]==guess[j]){
                    	if(f_guess[j]!=true){
                            pgia++;
                            f_guess[j]=true;
                            break;
        	}
            }
        }
    }
    }
        	std::string s=(to_string(bull)+","+to_string(pgia));
         return s;
    }
	}
