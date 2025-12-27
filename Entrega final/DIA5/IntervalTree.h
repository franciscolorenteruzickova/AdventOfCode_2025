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
    
    Node* insert(Node *node, long long _min, long long _max);
    bool overlaps(const Interval& a, long long ID) const;
    bool search(Node *node, long long ID) const;
    void deleteTree(Node *node);
    Node* buildBalanced(vector<Interval> &intervals, int _min, int _max);
    void preorderTraversal(Node *node, long long *IDs);
  public:
    IntervalTree();
    ~IntervalTree();
    void insert(long long _min, long long _max);
    bool contains(long long ID) const;
    void buildFromIntervals(vector<Interval> &intervals);
    long long dfs();
    bool empty();
    int size();
};

#endif
