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
  
  sort(intervals.begin(), intervals.end(), mincomparator);
  vector<Interval> noIntersection;
  noIntersection.push_back(intervals[0]);
  for(int i = 1; i < intervals.size(); i++) {
    if (intervals[i].min <= noIntersection[noIntersection.size()-1].max + 1) {
      noIntersection[noIntersection.size()-1].max = max(noIntersection[noIntersection.size()-1].max, intervals[i].max);
    }
    else{
      noIntersection.push_back(intervals[i]);
    }
  }
  
  tree.buildFromIntervals(intervals);
  
  cout << tree.dfs() << "\n";
  return 0;
}
