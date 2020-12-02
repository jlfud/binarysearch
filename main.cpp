#include <iostream>
#include <cstring>
#include <fstream>
#include "tree.h"

using namespace std;
void par(tree* &t, char in[80]); //parse 
int main(){
  char in[80]; 
  int intin;
  tree* t = new tree();
  cout << "binary search tree: add, remove, print, search, delete, quit" << endl;
  cout << "file input (f) or manual input (m)?" << endl;
  cin >> in;
  //handle input later
  if(strcmp(in, "f")==0){
    cout << "file address:" << endl;
    cin >> in; 
    ifstream text;
    text.open(in); 
    text.getline(in, 80);
    text.close();
    par(t, in); 
  }
  else if(strcmp(in, "m")==0){
    cout << "nums: ";
    cin.ignore(80, '\n');
    cin.getline(in, 80);
    par(t, in);
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
void par(tree* &t, char in[80]){
  char token[80];
  int a = 0; 
  for(int i = 0; i < strlen(in); i++){
    if(in[i] == ' '){
      t->insert(t->getRoot(), atoi(token));
      strcpy(token, "");
      a = 0; 
    }
    else{
      token[a] = in[i];
      a++;
    }
  }
  t->insert(t->getRoot(), atoi(token));
}
