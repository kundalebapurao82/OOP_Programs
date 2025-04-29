#include<iostream>
using namespace std;

class StringShifter{
    public:
        bool canBeShifted(string s, string goal){
            if(s.length() != goal.length()){
                return false;
            }
            string doubled = s + s;
			int position = doubled.find(goal); // check if goal is part of rotated string
			if(position != -1){
			    return true;
			} else {
			    return false;
			}
        }
};

int main(){
    StringShifter s;

    string s1 ="abcde";   //given string
    string g1 ="cdeab";	//goal string
    string s2 ="abcde";
    string g2 ="abced";

    cout<<"Test 1: "<<(s.canBeShifted(s1,g1)?"true" : "false")<<endl;
    cout<<"Test 2: "<<(s.canBeShifted(s2,g2)?"true" : "false")<<endl;

    return 0;
}

