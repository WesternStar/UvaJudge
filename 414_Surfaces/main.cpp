#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int CalcBudget(int sqft, int eco){
    return sqft*eco;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    while(cin){
        if(!cin){
            return 0;
        }
        int num;
        cin >> num;
        vector <int> numbers;
        for(int i=0;i<num;i++){
        string line;
        getline( cin,line);
        numbers[i] = std::count_if(line.begin(),line.end(), [] (char a) {return a=='X';});

        }
        int largest=*max_element(numbers.begin(), numbers.end());
        int total=sum(numbers);


    }
    return 0;
}

