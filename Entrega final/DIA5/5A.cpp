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
  
  tree.buildFromIntervals(intervals);
  
  int fresh = 0;
  for (long long q : IDs) {
    if (tree.contains(q)) {
      ++fresh;
    }
  }
  cout << fresh << "\n";
  return 0;
}
