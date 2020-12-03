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
    //when we arrive at a null node, replace the node
    current = new node();
    current->data = value; 
  }
  else{
    if(value < current->data){
      //insert to the left if value is smaller
      this->insert(current->left, value); 
    }
    else if(value >= current->data){
      //insert to the right if value is larger
      this->insert(current->right, value); 
    }
  }
}
void tree::display(node* current, node* parent){
  //prints recursively with parent
  if(current != NULL){
    //if there is a node, display the left
    display(current->left, current);
    if(current == root){
      //if it is the root, there is no parent
      cout << current->data << " ";
    }
    else{
      //print out with parent
      cout << current->data << "(" << parent->data << ") "; 
    }
    //displat the right
    display(current->right, current);
  }
}
void tree::search(int n){
  if(root == NULL){
    cout << "no data in the tree yet" << endl;
    return;
  }
  //for traversing
  node* current = root;
  while(true){
    if(n > current->data){
      if(current->right == NULL){
	//if we have reached the end of the subtree the node is not present
	cout << "not in tree" << endl;
	break; 
      }
      //keep on traversing
      current = current->right; 
    }
    else if(n < current->data){
      //same logic with left subtree
      if(current->left == NULL){
	cout << "not in tree" << endl;
	break; 
      }
      current = current->left;
    }
    else{
      //if it's not greater or less than, it's in the tree because it is the value
      cout << "value is in the tree" << endl;
      break;
    }
  }
}
node* tree::remove(node* &current, int n){
  if(root==NULL){ //nothing in tree
    cout << "no data in tree yet" << endl;
    return NULL;
  }
  //traverse through tree until the correct node is found
  if(n < current->data){
    current->left = remove(current->left, n); 
  }
  else if(n > current->data){
    root->right = remove(current->right, n);
  }
  else{
    //node has no children
    if(current->right == NULL && current->left == NULL){
      delete current; //just delete the node
      current = NULL;
    }
    else if(current->left == NULL){
      //node has a right child
      node* no = current;
      current = current->right;
      delete no; 
    }
    else if(current->right == NULL){
      //node has a left child
      node* no = current;
      current = current->left;
      delete no; 
    }
    else{
      //hibbard's algorithm to delete a node with left and right child 
      //node has two children
      node* no = current; //node to delete
      node* min = current->right; //leftmost element in right subtree
      //preparing to replace node to delete with min
      node* parent = current;  //parent of min
      if(min->left == NULL){
	//if the node is already at the bottom
	//replace parent (unchanged so node to delete) with min
	parent->data = min->data;
	parent->right = min->right;
      }
      else if(parent->right->left == NULL){
	//if the right node of the parent is the bottom node
	parent->data = parent->right->data;
	parent->right = parent->right->right;
	//parent is now parent's right now
      }
      else{
	while(min->left != NULL){
	  //loop until we get to the bottom
	  parent = min;
	  min = min->left;
	}
	//replace the node to delete
	no->data = min->data;
	//right subtree link to parent's left
	parent->left = min->right;
      }
    }
  }
  return current; //for recursion
}
node*& tree::getRoot(){
  return root; 
}
