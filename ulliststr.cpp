#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
using namespace std;
ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
/**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val){
  if ((head_ == NULL)&&(tail_ == NULL)){
    Item* firstnode = new Item;
    firstnode->first = 0;
    firstnode->last = 1;
    firstnode -> val[0] = val;
    head_ = firstnode;
    tail_ = firstnode;
    ++size_;
   // cout <<firstnode->val[0] << endl;
  }else{
    if((tail_->last == ARRSIZE)){
      Item* newnode = new Item;
      newnode->first = 0;
      newnode->last = 1;
      newnode -> val[0] = val;
      newnode -> next = NULL;
      Item* temp = tail_;
      newnode -> prev = temp;
      temp -> next = newnode;
      tail_ = newnode;
      ++size_;
    }else{
      tail_->val[tail_->last] = val;
      ++tail_->last;
      ++size_;
    }
  }
}

/**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
void ULListStr::push_front(const std::string& val){
  if ((head_ == NULL)&&(tail_ == NULL)){
    Item* firstnode = new Item();
    firstnode->first = ARRSIZE-1;
    firstnode->last = ARRSIZE;
    firstnode -> val[ARRSIZE-1] = val;
    head_ = firstnode;
    tail_ = firstnode;
    ++size_;
  }else{
    if((head_->first == 0)){
      Item* newnode = new Item;
      newnode->first = ARRSIZE-1;
      newnode->last = ARRSIZE;
      newnode -> val[ARRSIZE-1] = val;
      Item* temp = head_;
      newnode -> next = temp;
      newnode -> prev = NULL;
      temp ->prev = newnode;
      head_ = newnode;
      ++size_;
    }else{
      head_->val[head_->first-1] = val;
      --(head_->first);
      ++size_;
    }
  }
}

/**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_back(){
  tail_->val[(tail_->last)-1] = "0";
  --tail_->last;
  if((tail_->first == 0 )&& (tail_->last == 0)){
    Item* temp = tail_;
		if(tail_!=head_){
			tail_ = tail_->prev;
    	tail_->next = NULL;
			delete temp;
		}
  }else{
    
  }

  --size_;
  
}


/**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::pop_front(){
  head_->val[head_->first] = "0";
  ++head_->first;
  if ((head_->first == ARRSIZE)&& (head_->last = ARRSIZE)){
    Item* temp = head_;
		if(head_!=tail_){
			head_ = head_->next;
    	delete temp;
    	head_->prev = NULL;
		}
  }else{
  
  
  }
  --size_;
  
}

/**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
std::string const & ULListStr::back() const{
  return tail_ -> val[tail_->last-1];
}

/**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
std::string const &  ULListStr::front() const{
  return head_ -> val[head_->first];
}

/** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
std::string* ULListStr::getValAtLoc(size_t loc) const{
  if (loc > size()){
    return NULL;
  }else if (loc < ARRSIZE){
    if((head_->first+loc)<ARRSIZE){
      return (&head_->val[head_->first+loc]);
    }else{
      int index = loc-(head_->last-head_->first);
      Item* node = head_-> next;
      return (&node->val[index]);
    }
  }else{
    bool found = false;
    int place = 0;
    Item* node = head_;
    while(found == false){
      int oldplace = place;
      // cout << "come" << endl;
      // cout << (node->last) <<endl;
      // cout << "on" << endl;
      // cout <<(node->first) <<endl;
      place = place + ((node->last) - (node->first));

      if (loc <= place-1){
        found = true;
        return (&node->val[(node->last)- (place-loc)]);
      }else{
        node = node->next;
        // cout << loc<< " " <<place << endl;
      }
    }
  }
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
