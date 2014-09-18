#include <iostream>
#include <sstream>
using namespace std;

int CalcBudget(int sqft, int eco){
    return sqft*eco;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    while(cin){
        string line;
        getline( cin,line);
        if(!cin){
            return 0;
        }
        for(char &a:line){
            if(( a < 65 || a > 90 )&&( a < 96 || a > 123 )){
                a =' ';
            }
        }

        stringstream in(line);
        int count=0;
        string word;

        while(in){

            in >> word;

            auto letter=word.find_first_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
            if(!in){
                break;
            }

            if(letter!=std::string::npos){
                ++count;

            }

        }
        if(count>0)
            cout << count <<endl;

    }
    return 0;
}

