#include <iostream>
#include <cstring>
#include "tree.h"

using namespace std;

tree::tree(){
  root->data = 69;
}
tree::~tree(){

}
node* tree::insert(node* parent, node* ins){
  if(parent == NULL){
    parent = ins;
  }
  else{
    if(ins->data < parent->data){
      parent->left = insert(parent->left, ins); 
    }
    else if(ins->data >= parent->data){
      parent->right = insert(parent->right, ins); 
    }
  }
  return parent;
}
void tree::display(node* current){ 
  if(current != NULL){
    this->display(current->left);
    cout << current->data << " ";
    this->display(current->right);
  }
}
void tree::search(int n){

}
void tree::remove(int n){

}
node* tree::getRoot(){
  return root; 
}
