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
  node* insert(node*, node*);
  void display(node*);
  void search(int);
  void remove(int);
  node* getRoot();
private:
  node* root = new node();
};
#endif
