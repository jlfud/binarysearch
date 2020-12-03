#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <cstring>

using namespace std;

struct node{
  int data;
  node* left = NULL;
  node* right = NULL; 
};
class tree{
public:
  tree();
  ~tree();
  void insert(node* &, int);
  void display(node*, node*);
  void search(int);
  node* remove(node* &current, int);
  node*& getRoot();
private:
  node* root = NULL;
};
#endif
