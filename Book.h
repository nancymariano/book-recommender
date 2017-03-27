// Nancy Mariano
// Book.h

#include <iostream>

#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book
{
 public:
  Book();           // default constructor
  Book(const Book& aBook);  // copy constructor
  Book& operator=(const Book& rhs);  // overloaded assignment operator
  ~Book(); // destructor

  //int getISBN();    //accessor methods 
  //string getTitle();
  //string getAuthor();
  //int getYear();

  //void setISBN(int isbn);    //mutator methods
  //void setTitle(string title);
  //void setAuthor(string author);
  //void setYear(int year);

  void addBook(string t, string a, int y);
  // adds a book to the array of bookInfo

  void getTitle(int i);
  void getAuthor(int i);
  
  
 private:
  struct bookInfo{
	int isbn;       // stores the information
	string title;   // for each book
	string author;
	int year;
  };

  bookInfo *bookList;
  int size;
  int top;
  // current "top" index for where data is held
  bool full();
  // checks wheter or not the "library" is full
  bool resize();
  // upon a true 
};

#endif
