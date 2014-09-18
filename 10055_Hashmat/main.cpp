#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
     long long first,second;
    while(cin){
    cin >> first >>second;
    if (cin.fail())
        return 0;
    cout << abs(second-first) <<endl;
    }
    return 0;
}
