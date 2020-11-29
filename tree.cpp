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
void tree::display(node* current){
  if(current->left != NULL){
    cout << current->left->data << "(" << current->data << ")";
    this->display(current->left);
  }
  if(current->right != NULL){
    cout << current->right->data << "(" << current->data << ")";
    this->display(current->right); 
  }
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
void tree::remove(int n){
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
      if(current->left == NULL){
	node* temp = current->right;
	delete current;
	current = temp;
	break; 
      }
      else if(current->right == NULL){
	node* temp = current->left;
	delete current;
	current = temp;
	break; 
      }
      else{
	//right and left
	node* temp = current->right;
      }
    }
  }
  
}
node*& tree::getRoot(){
  return root; 
}
