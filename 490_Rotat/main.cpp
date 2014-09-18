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
            a=a-7;
        }

    cout <<line<<endl;
    }
    return 0;
}

