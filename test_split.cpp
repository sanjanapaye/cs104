/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
  Node* head = NULL;
  Node* odds = NULL;
  Node* evens = NULL;
  Node* firstnode = new Node(10, NULL);
  head = firstnode;
  for (int i = 9; i > 0; i-=2){
    Node* temp = head;
    Node* newnode = new Node(i, temp);
    // newnode -> value = i;
    // newnode ->next = temp;
    head = newnode;
  } 
  Node*temp = head;
  while (temp != NULL){
    cout << temp->value << endl;
    temp = temp->next;
  }
  split(head, odds, evens);
  Node*temp2 = odds;
  while (temp2 != NULL){
    cout << temp2->value << endl;
    temp2 = temp2->next;
  }
  Node*temp3 = evens;
  while (temp3 != NULL){
    cout << temp3->value << endl;
    temp3 = temp3->next;
  }

  while (head != NULL){
    Node* temp = head;
    head = temp->next;
    delete temp;
  }
  while (odds != NULL){
    Node* temp = odds;
    odds = temp->next;
    delete temp;
  }
  while (evens != NULL){
    Node* temp = evens;
    evens = temp->next;
    delete temp;
  }
}
