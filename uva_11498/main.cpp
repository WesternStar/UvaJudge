#include <iostream>
using namespace std;
int main(){

  cin.sync_with_stdio(false);
  int QUERIES;
  cin >> QUERIES;
  if(QUERIES==0){ return ; }
  int x1,y1;
  cin >> x1 >> y1;
  for(;QUERIES; --QUERIES){
      int x2,y2;
      cin >> x2 >> y2;
      if( (x1 == x2) || (y1 == y2)){
        cout << "divisa\n"
      }
      if(y1>y2){
        cout << "S";
      }else{
        cout << "N";
      }

      if(x1>x2){
        cout << "0\n";
      }else{
        cout << "E\n";
      }
    }

}
