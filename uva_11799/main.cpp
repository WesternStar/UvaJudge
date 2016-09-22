#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
int TC;
cin.sync_with_stdio(false);
cin >> TC;
for(int i=0; i<TC; ++i)
{
  int n_items;
  cin >> n_items;

   vector<int>items(n_items);
   for (auto &it : items){
   cin >> it;
   }
   auto result =  *std::max_element(items.begin(),items.end());
   cout << "Case " << i+1 << ": " << result << "\n" ;
}

}
