#include "calculate.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
using std::string, std::to_string;
using namespace std;
namespace bullpgia {
	const string calculateBullAndPgia(const string choosen, const string guess){
		if(choosen.length() != guess.length()){//if the length are not equals
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
        string nully= "";

			if(a.compare(nully)==0||b.compare(nully)==0)
				throw invalid_argument("Error: empty!");

			for(uint i=0;i<a.length();i++){
			if(b.at(i)<'0'||b.at(i)>'9')
				throw invalid_argument("Error: empty!");

			if(a[i]<'0'||a[i]>'9'){
				throw std::invalid_argument("Error: not a number!");
			}
		}
	}
	}
