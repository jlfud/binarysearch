#include <iostream>
#include <cstring>
#include "tree.h"

using namespace std;

int main(){
  char in[80]; 
  int intin;
  tree* t = new tree(); 
  
  cout << "binary search tree: add, remove, print, search, delete, quit" << endl;
  cout << "file input (f) or manual input (m)?" << endl;
  cin >> in;
  //handle input later
  if(strcmp(in, "f")==0){

  }
  else if(strcmp(in, "m")==0){

  }
  while(true){
    cout << "add, remove, print, search, delete, quit: " << endl;
    cin >> in;
    if(strcmp(in, "add")==0){
      cout << "value to insert: " << endl;
      cin >> intin;
      t->insert(t->getRoot(), intin);
    }
    else if(strcmp(in, "print")==0){
      cout << "printing root in the middle, work our way out" << endl;
      t->display(t->getRoot(), t->getRoot());
      cout << endl;
    }
    else if(strcmp(in, "search")==0){
      cout << "value to find: " << endl;
      cin >> intin;
      t->search(intin); 
    }
    else if(strcmp(in, "delete")==0){
      cout << "value to delete:" << endl;
      cin >> intin;
      t->remove(t->getRoot(), intin); 
    }
    else if(strcmp(in, "quit")==0){
      return 0;
    }
    else{
      cout << "invalid input" << endl; 
    }
  }
}
