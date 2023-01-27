/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>


/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  if(in != NULL){
    Node* current = in;
    in = current -> next;
    if((current->value)%2 != 0){
      if(odds == NULL){
        // odds->value = current->value;
        // odds->next = current->next;
        odds = current;
        odds -> next = NULL;
      }else{
        Node* temp = odds;
        // odds -> value = current->value;
        // odds -> next = temp;
        current->next = temp;
        odds = current;
      }
    }else{
      if(evens == NULL){
        // evens->value = current->value;
        // evens->next = current -> next;
        evens = current;
        evens -> next = NULL;
      }else{
        Node* temp = evens;
        // evens -> value = current->value;
        // evens -> next = temp;
        current->next = temp;
        evens = current;
      }
    }
    split(in, odds, evens);
  }
  
}

/* If you needed a helper function, write it here */
