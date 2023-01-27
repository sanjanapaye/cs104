#include <string>
#include <vector>
#include <iostream>
using namespace std;
#include <sstream>

#include "ulliststr.h"


//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;
  list.push_back("oldfront");
	list.push_back("oldback");

	// this should create an empty slot at the front of the list, and the new element can be put there
	list.pop_front();
	list.push_front("newfront");


	// now, a new element struct should get created at the front
	list.pop_back();
	list.push_front("cloudfront");


	// now, the original head should get deleted
	list.pop_back();


	list.pop_front();


	list.push_front("newback");

  // for(int i = 0; i < 50; ++i){
  //   dat.push_back("i");
  // }

  // for(int i = 0; i < 50; ++i){
  //   dat.pop_back();
  // }
  // dat.push_back("7");
  // // dat.push_front("8");
  // // dat.push_front("9");
  // // dat.push_front("10");
  // dat.push_back("9");
  // dat.push_back("3");
  // dat.pop_front();

  // ULListStr list;

	// list.push_back("1");
	// list.push_front("2");
  // list.push_back("3");
  // cout << list.get(0) << " " << list.get(1) << endl;

  //print out list
  
  //cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
  //cout << dat.size() << end;  // prints 3 since there are 3 strings stored

 
}
