// Nancy Mariano
// Member.h

#include <iostream>
#include "Rating.h"

#ifndef MEMBER_H
#define MEMBER_H

using namespace std;

class Member
{
 public:
  Member();   // default constructor
              // the "big four" since the  
              //array must be dynamically allocated 
  Member(const Member& aMember); // copy constructor
  Member& operator=(const Member& rhs); //overloaded assignment
  ~Member();  // destructor
 
  //string getName(); //mutator 
  //string getID();
  //void setName(string name); //accessor
  //void setID(int ID);

  void createMember(string n, int id);
  // creates a member and their ID
  void addRating(int r, int isbn, int id);
  // adds a Rating for the member

  //int getID(string n);
  // displays rating for member via name
  void getName(int id);
  // displays name for member via ID
  
  int getRating(int id, int ISBN);
  
 private:
  struct memberInfo{
	int ID;
	int rateSize; 
	string name; 
	Rating* ratingList; //pointer for dynamically
  };
  memberInfo* memberList;// allocated array that links
                         // ratings to each member
  int memSize; // keeps tabs on size of the array of structs
  const int RATE_SIZE = 5; // keeps tabs on the size of the arrays of ratings
  //int memTop; // keeps tabs on the last used index of the array
  //int rateTop;
  int location; // which member i am at
  bool resizeMem();
  bool resizeRate(int id); 
  bool full(int s, int t); // flags whether or not the array is full

};         

#endif 
