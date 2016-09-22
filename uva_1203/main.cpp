#include <iostream>
#include <queue>
using namespace std;

struct query{
    int id{};
    int period{};
    int next_exec{};
    query(int id , int period): id(id),period(period),next_exec(period){};
  };
struct query_greater{
    public:
    bool operator()(const query& lhs,const query& rhs){
      if (rhs.next_exec>lhs.next_exec) {return false;}
      if (lhs.next_exec>rhs.next_exec) {return true;}
      else {if(rhs.id> lhs.id){return false;} else {return true;} } }
};

int main(){
  std::priority_queue<query,std::vector<query>,query_greater> heap;
  std::string s;

  for(cin>>s;s!="#";cin>>s){
  int q,num;
  cin >> q >>num;
  heap.emplace(q,num);
  }
  int n_queries;
  cin >> n_queries;
  for(int i=0;i<n_queries;++i){
      auto query= heap.top();
      heap.pop();
       
      cout << query.id << "\n";


      query.next_exec+=query.period;
      heap.push(query);

  }


}
