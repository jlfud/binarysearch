//tests

//imports
#include <iostream>
#include <cstring>
#include <fstream>
#include "tree.h"

using namespace std;
void par(tree* &t, char in[80]); //parse 
int main(){
  char in[80]; //for cstring input 
  int intin; //for int input
  tree* t = new tree(); 
  cout << "binary search tree: add, remove, print, search, delete, quit" << endl;
  cout << "file input (f) or manual input (m)?" << endl;
  cin >> in;
  //handle input later
  if(strcmp(in, "f")==0){
    cout << "file address:" << endl;
    cin >> in;
    //open the file, get the line with the numbers, close the file
    ifstream text;
    text.open(in); 
    text.getline(in, 80);
    text.close();
    //parse the cstring
    par(t, in); 
  }
  else if(strcmp(in, "m")==0){
    //get the line and parse
    cout << "nums: ";
    cin.ignore(80, '\n');
    cin.getline(in, 80);
    par(t, in);
  }
  while(true){
    cout << "add, remove, print, search, delete, quit: " << endl;
    cin >> in;
    if(strcmp(in, "add")==0){
      //get the value and insert
      cout << "value to insert: " << endl;
      cin >> intin;
      t->insert(t->getRoot(), intin);
    }
    else if(strcmp(in, "print")==0){
      cout << "printing root in the middle, work our way out" << endl;
      //input with root and root (root 2 shows parent child relationship)
      t->display(t->getRoot(), t->getRoot());
      cout << endl;
    }
    else if(strcmp(in, "search")==0){
      //search
      cout << "value to find: " << endl;
      cin >> intin;
      t->search(intin); 
    }
    else if(strcmp(in, "delete")==0){
      //delete
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
  char token[80]; //for each number
  int a = 0; //what index on token we are on
  for(int i = 0; i < strlen(in); i++){
    //loop through string
    if(in[i] == ' '){
      //if we are at a space insert int of token and reset
      t->insert(t->getRoot(), atoi(token));
      strcpy(token, "   ");
      a = 0; 
    }
    else{
      //add characters to token
      token[a] = in[i];
      a++;
    }
  }
  //insert the last number
  t->insert(t->getRoot(), atoi(token));
}
