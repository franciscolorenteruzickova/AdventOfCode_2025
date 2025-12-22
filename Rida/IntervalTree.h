#ifndef INTERVALTREE_H
#define INTERVALTREE_H

#include<vector>
#include<algorithm>
using namespace std;

struct Interval{
  long long min;
  long long max;
};

struct Node{
  Interval i;
  long long maximum;
  Node *left, *right;
  
  Node(long long _min, long long _max) : i{_min, _max}, maximum(_max), left(nullptr), right(nullptr) {}
};

class IntervalTree{
  private:
    Node *root;
    int n;
    
    Node* insert(Node *node, long long _min, long long _max); //OK
    bool overlaps(const Interval& a, long long ID) const; //OK
    bool search(Node *node, long long ID) const; //OK
    void deleteTree(Node *node); //OK
    Node* buildBalanced(vector<Interval> &intervals, int _min, int _max); //Ok
  public:
    IntervalTree(); //OK
    ~IntervalTree(); //OK
    void insert(long long _min, long long _max); //OK
    bool contains(long long ID) const;
    void buildFromIntervals(vector<Interval> &intervals); //OK
    bool empty(); //OK
    int size(); //OK
};

#endif
