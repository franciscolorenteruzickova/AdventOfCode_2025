#include"IntervalTree.h"
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main(){
  IntervalTree tree;
  vector<Interval> intervals;
  vector<long long> IDs;
  
  string line;
  while(getline(cin, line)){
    if(line.empty()){
      continue;
    }
    size_t dash = line.find('-');
    if(dash != string::npos && dash > 0){
      long long start = stoll(line.substr(0, dash));
      long long end = stoll(line.substr (dash + 1));
      intervals.push_back({start, end});
    }
    else{
      IDs.push_back(stoll(line));
    }
  } 
  
  //Hay que gestionar la intersección de intervalos antes de crear el arbol
  
  tree.buildFromIntervals(intervals);
  
  cout << tree.dfs() << "\n";
  return 0;
}
