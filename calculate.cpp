#include "calculate.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
using std::string, std::to_string;

namespace bullpgia {
	const string calculateBullAndPgia(const string choosen, const string guess){
		if(choosen.length() != guess.length()){
        return "0,0";
		}

    else{
    	check(choosen,guess);
    	
        uint bull = 0;
        uint pgia = 0;
 		char bulled;
 		bool count[guess.length()];
 		for(uint i=0;i<guess.length();i++){
 			count[i]=false;
 		}

        for(int i = 0; i<choosen.length(); i++){
        	bool flag=false;
				if(choosen[i]==guess[i]){
					bull++;
					flag=true;
					bulled=choosen[i];
				}

				if(!flag){
                for(int j = 0; j<guess.length(); j++){
                	if(i!=j){
                    if(choosen[i]==guess[j]&&choosen[i]!=bulled){
                    	if(count[j]!=true){
                            pgia++;
                            count[j]=true;
                            break;
                        }
                            }
                    			}
                	}
                }
            }
        	std::string s=(to_string(bull)+","+to_string(pgia));
         return s;
    }
	}
		void check(string a, string b){
			if(a.compare("")==0||b.compare("")==0)
				throw std::invalid_argument("Error: empty!");

			for(uint i=0;i<a.length();i++){
			if((a[i]<48||a[i]>57)||(b[i]<48||b[i]>57)){
				throw std::invalid_argument("Error: not a number!");
			}
		}
	}
	}