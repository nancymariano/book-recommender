
// Purpose: To implement the Book, Member and Ratings classes.// A user will be able to login, logout, create an account,
// rate a book and recieve a recommendation for another book.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Book.h"
#include "Member.h"
#include "Rating.h"

using namespace std;

const string bookFile = "books.txt";
const string ratingsFile = "ratings.txt";
const char COMMA = ',';
const char YES = 'y';
const char NO = 'n'; 

const int YEAR = 1346;

bool bookRead(Book &library, string file, int &numBooks);
bool rateRead(Member &directory, string file, int &numMembers);
void welcome();
void displayMenu1();
void displayMenu2();
int addBook(int &numBooks, Book &library);
int addAccount(int &numMembers, Member &directory);
int	rateBook(Member &directory, Book library, int thisAccount, int numBooks);
int viewRatings(Member directory, Book library, int thisAccount, int numBooks);
int recommendations(Member directory, Book library, int thisAccount, int numBooks);

int main()
{
  string bFile = bookFile;
  string rFile = ratingsFile;
  char ans = YES; 
  int option = 0;
  int option2 = 0;
  int thisAccount = 0;
  int numBooks = 0;
  int numMembers = 0;
  bool loggedIn = false;
  Book library;
  Member directory; 

  cout << "Please enter a book file name: ";
  getline(cin, bFile);
  cin.ignore();

  if(!bookRead(library, bFile, numBooks)){
	cout << "FILE READ FAILED..." << endl
		 << "PRESS ENTER TO CONTINUE...";
	cin.get();
	return 0; 
  }

  cout << "Please enter a rating file name: ";
  getline(cin,rFile);
  cin.ignore();

  if(!rateRead(directory, rFile, numMembers)){
	cout << "FILE READ FAILED..." << endl
		 << "PRESS ENTER TO CONTINUE...";
	cin.get();
	return 0; 
  }
  
  cout << "Would you like to get started (y/n)? ";
  cin >> ans;
  cin.ignore();

  while (ans == YES){
	while (option < 1 || option > 4){
	  cout << "***Menu***" << endl
		   << "WARNING: non-numeric inputs are NOT ALLOWED" << endl
		   << "1) Add a book to the library" << endl
		   << "2) Create an account" << endl
		   << "3) Login" << endl
		   << "4) Quit" << endl;
	  cout << "Enter an option: ";
	  cin >> option;
	  cin.ignore();
	}
	  if (option == 4)
		ans = NO;
	  else if (option == 1)
		option = addBook(numBooks, library);
	  else if (option == 2)
		option = addAccount(numMembers, directory); 
	  else{
		cout << "Enter account #: ";
		cin >> thisAccount;
		cin.ignore();
		while (thisAccount < 0 || thisAccount > numMembers){
		  cout << "Invalid accont #... re-enter: ";
		  cin >> thisAccount;
		  cin.ignore();
		}
		loggedIn = true;
	  }
	  while(loggedIn){
		while (option2 < 1 || option2 > 4){
		cout << "***Menu***" << endl
			 << "WARNING: non-numeric inputs are NOT ALLOWED" << endl 
			 << "1) Rate a book" << endl
			 << "2) View ratings" << endl
			 << "3) See recommendations" << endl
			 << "4) Logout" << endl;
		cout << "Enter an option: "; 
		cin >> option2;
		}
		//cin.ignore();
		if (option2 == 1)
		  option2 = rateBook(directory, library, thisAccount, numBooks);
		else if (option2 == 2)
		  option2 = viewRatings(directory, library, thisAccount, numBooks);
		else if (option == 3)
		  option2 = recommendations(directory, library, thisAccount, numBooks); 
		else{
		  loggedIn = false; 
		}
	  }
  }

  return 0; 
}

bool bookRead(Book &library, string file, int &numBooks)
{
  
  string author;
  string title;

  //string memName;
  int count = 0;
  
  ifstream infile;
  bool success = true;
  
  infile.open(file);
  
  if (infile.fail())
	return !success;

  while (getline(infile, author, COMMA)){
	//cout << author;
	getline(infile, title);
	//cout << title;
	library.addBook(title, author, YEAR);
	count++;
  }

  infile.close();

  //count = 50; 
  numBooks = count;
  //cout << count; 
  return success;
 
}
bool rateRead(Member &directory, string file, int &numMembers)
{ 
  string memName;
  int memRate = 0; 

  int ratingCount = 0;
  int memberID = 0;
  //int num = 0;

  string var; 

  ifstream infile;
  bool success = true;
  
  infile.open(file);
  
  if (infile.fail())
	return !success;

  while(getline(infile, memName, '\n')){
	ratingCount = 0; 
	//set name for member in class
	directory.createMember(memName, memberID);
	// increment whose ID
	//cout << memName << endl; 
	stringstream stream;
	getline(infile, var, '\n');
	
	stream << var;
	  
	while (stream >> memRate){
	  //set rating for specific index
	  directory.addRating(memRate, ratingCount, memberID); 
	  // increment rating array count
	  ratingCount++;
	  //cout << memRate;
	  //cout << ratingCount; 
	}
	memberID++; 
	//cout << endl; 
  }
  
  infile.close();

  numMembers = memberID; 
  return success;
  
}
void welome()
{
  cout << endl << endl
	   << "Welcome to Recommendations!";
  cout << endl << endl;
}
void displayMenu1()
{
  cout << "***Menu***" << endl
	   << "WARNING: non-numeric inputs are NOT ALLOWED" << endl
	   << "1) Add a book to the library" << endl
	   << "2) Create an account" << endl
	   << "3) Login" << endl
	   << "4) Quit" << endl;
  cout << "Enter an option: ";
  
}
void displayMenu2()
{
  cout << "***Menu***" << endl
			 << "WARNING: non-numeric inputs are NOT ALLOWED" << endl 
			 << "1) Rate a book" << endl
			 << "2) View ratings" << endl
			 << "3) See recommendations" << endl
			 << "4) Logout" << endl;
		cout << "Enter an option: "; 
}
int addBook(int &numBooks, Book &library)
{
  int ans = 0;
  string title;
  string author;

  numBooks++;

  cout << "Enter title: " << endl;
  getline(cin, title);
  cout << "Enter Author: " << endl;
  getline(cin, author);

  library.addBook(title, author, numBooks);

  library.getTitle(numBooks);
  cout << endl << "If this was the title you entered, "
	   << "add was a success." << endl; 
   

  while (ans < 1 || ans > 4){
	displayMenu1();
	cin >> ans;
  }
  
  return ans; 
}
int addAccount(int &numMembers, Member &directory)
{
  int ans = 0;
  string name;
  
  numMembers++;

  cout << "Enter your name: ";
  getline(cin, name); 
  cin.ignore();
  
  directory.createMember(name, numMembers); 
  
  directory.getName(numMembers);

  cout << endl << "If this is the name you entered, "
	   << "account was created." << endl;

  cout << "Your account number is: " << numMembers << endl; 

  while (ans < 1 || ans > 4){
	displayMenu1();
	cin >> ans;
	cin.ignore();
  }
  return ans;
}
int	rateBook(Member &directory, Book library, int thisAccount, int numBooks)
{
  int selection = 0;
  int ans = 0; 
  int rating = 0; 
  //while (selection < 0 || selection > numBooks){
	cout << "***BOOK LIST***" << endl
		 << "WARNING: non-numeric inputs are NOT ALLOWED" << endl
		 << "ISBN               Title" << endl;
	cout << numBooks;
	for( int i = 0; i < numBooks; i++){
	  cout << i << ")";
	  library.getTitle(i);
	  cout << endl; 
	}
	
	cout << "Enter the ISBN number: ";
	cin >> selection;
	//while (rating != -5 || rating != -3 || rating != 3 || rating != 5){
	  cout << "Enter your rating (-5, -3, 3 or 5): ";
	  cin >> rating;
	  cin.ignore();
	  //	}
	  // }

  directory.addRating(rating, selection, thisAccount);
  cout << endl << "If this number matches your rating, it was a success" << endl
	   << directory.getRating(thisAccount, selection);

  while (ans < 1 || ans > 4){
	displayMenu2();
	cin >> ans;
  }
  return ans; 
  //menu of options
}
int viewRatings(Member directory, Book library, int thisAccount, int numBooks)
{
  int ans = 0;

  cout << "These are your ratings: "; 

  cout << "Book Title                   Rating" << endl; 
  for (int i = 0; i < numBooks; i++){
	library.getTitle(i); 
	cout << directory.getRating(thisAccount, i) << endl; 
  }
  
  while (ans < 1 || ans > 4){
	displayMenu2();
	cin >> ans;
  }
  return ans; 
  
}
int recommendations(Member directory, Book library, int thisAccount, int numBooks)
{
  return 0; 
}
