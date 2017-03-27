// Nancy Mariano
// Rating.h

#include <iostream>

#ifndef RATING_H
#define RATING_H

using namespace std;

class Rating
{
 public:
  Rating(); //default constructor
  int getRating(); //accessor method
  int getISBN(); 
  
  void setRating(int r); //mutator method
  void setISBN(int i); 

 private:
  int score;  //member's rating
  int ISBN;     // book's ISBN
};

#endif
