#include <iostream>
#include <cstring>
#include "tree.h"

using namespace std;

tree::tree(){
  
}
tree::~tree(){

}
void tree::insert(node* &current, int value){
  if(current == NULL){
    current = new node();
    current->data = value; 
  }
  else{
    if(value < current->data){
      this->insert(current->left, value); 
    }
    else if(value >= current->data){
      this->insert(current->right, value); 
    }
  }
}
void tree::display(node* current, node* parent){
  if(current == NULL){
    return; 
  }
  display(current->left, current);
  cout << current->data << "(" << parent->data << ") ";
  display(current->right, current);
}
void tree::search(int n){
  if(root == NULL){
    cout << "no data in the tree yet" << endl;
    return;
  }
  node* current = root;
  while(true){
    if(n > current->data){
      if(current->right == NULL){
	cout << "not in tree" << endl;
	break; 
      }
      current = current->right; 
    }
    else if(n < current->data){
      if(current->left == NULL){
	cout << "not in tree" << endl;
	break; 
      }
      current = current->left;
    }
    else{
      cout << "value is in the tree" << endl;
      break;
    }
  }
}
node* tree::remove(node* &current, int n){
  if(root==NULL){
    cout << "no data in tree yet" << endl;
    return NULL;
  }
  if(n < current->data){
    current->left = remove(current->left, n); 
  }
  else if(n > current->data){
    root->right = remove(current->right, n);
  }
  else{
    //no children
    if(current->right == NULL && current->left == NULL){
      delete current;
      current = NULL;
    }
    else if(current->right == NULL){
      node* no = current;
      current = current->left;
      delete no; 
    }
    else if(current->left == NULL){
      node* no = current;
      current = current->left;
      delete no; 
    }
    else{
      node* no = current->left;
      while(no->right != NULL){
	no = no->right; 
      }
      current->data = no->data;
      root->left = remove(root->left, no->data); 
    }
  }
  return current;
}
node*& tree::getRoot(){
  return root; 
}
