#include <iostream>
using namespace std;

int CalcBudget(int sqft, int eco){
    return sqft*eco;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    int cases;
    cin >> cases;

    for(int i =0; i !=cases; ++i){
        int farmers,budget=0;
        cin >> farmers;

        for(int i=0; i != farmers; ++i){
            int sqft,eco,animals;
            cin >>sqft >> animals >> eco;
            budget+=CalcBudget(sqft,eco);
        }
        cout << budget << endl;


    }
    return 0;
}

