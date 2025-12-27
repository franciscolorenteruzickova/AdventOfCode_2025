#include"IntervalTree.h"

IntervalTree::IntervalTree(){
  root = nullptr;
  n = 0;
}

IntervalTree::~IntervalTree(){
    deleteTree(root);
}

void IntervalTree::deleteTree(Node *node) {
  if (node != nullptr) {
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
  }
}

void IntervalTree::insert(long long _min, long long _max){
  root = insert(root, _min, _max);
}

Node* IntervalTree::insert(Node *node, long long _min, long long _max){

  if (node == nullptr){
    ++n;
    return new Node(_min, _max);
  }
  
  if (_min < node->i.min) {
    node->left = insert(node->left, _min, _max);
  } 
  
  else{
    node->right = insert(node->right, _min, _max);
  }

  long long m = node->i.max;
  if(node->left){
    m = max(m, node->left->maximum);
  }
  if(node->right){
    m = max(m, node->right->maximum);
  }
  node->maximum = m;

  return node;
}

bool IntervalTree::contains(long long ID) const{
    return search(root, ID);
}

bool IntervalTree::overlaps(const Interval &a, long long ID) const{
    return (a.min <= ID && ID <= a.max);
}

bool IntervalTree::search(Node *node, long long ID) const{

  if(node == nullptr){
    return false;
  }

  if(overlaps(node->i, ID)){
    return true;
  }

  if(node->left != nullptr && node->left->maximum >= ID){
    if(search(node->left, ID)){
      return true;
    }
  }

  return search(node->right, ID);
}

bool comparator(Interval a, Interval b){
  return a.min < b.min;
}

void IntervalTree::buildFromIntervals(vector<Interval> &intervals){
  if (intervals.empty()){
    return;
  }
  sort(intervals.begin(), intervals.end(), comparator);
  deleteTree(root);
  n = 0;
  root = buildBalanced(intervals, 0, intervals.size() - 1);
}

Node* IntervalTree::buildBalanced(vector<Interval> &intervals, int start, int end){

  if(start > end){
    return nullptr;
  }

  int mid = start + (end - start) / 2;
  Node* node = new Node(intervals[mid].min, intervals[mid].max);
  ++n;

  node->left = buildBalanced(intervals, start, mid - 1);
  node->right = buildBalanced(intervals, mid + 1, end);

  node->maximum = node->i.max;
  if(node->left && node->left->maximum > node->maximum) {
    node->maximum = node->left->maximum;
  }
  if (node->right && node->right->maximum > node->maximum) {
    node->maximum = node->right->maximum;
  }

  return node;
}

long long IntervalTree::dfs(){
  long long IDs = 0;
  preorderTraversal(root, &IDs);
  return IDs;
}

void IntervalTree::preorderTraversal(Node *node, long long *IDs){
  if(node == nullptr){
    return ;
  }
  *IDs += node->i.max - node->i.min + 1;
  preorderTraversal(node->left, IDs);
  preorderTraversal(node->right, IDs);
}

bool IntervalTree::empty(){
  if(n==0){
    return true;
  }
  else{
    return false;
  }
}

int IntervalTree::size(){
  return n;
}
