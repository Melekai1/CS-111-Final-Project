#include "library.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;

// Returns the user's input based on the menu's options.
int menu() {
  int response;
  cout << "\nChoose from one of the following options:\n";
  cout << "1. Display the data.\n";
  cout << "2. Search for a specific object.\n";
  cout << "3. Sort the data.\n";
  cout << "4. Country with highest gross amount.\n";
  cout << "5. Movies distributed by a specific studio\n";
  cout << "6. Movie with the highest domestic box office gross.\n";
  cout << "7. Remove a movie\n";
  cout << "8. Exit the program.\n";
  cin >> response;

  return response;
} // end of function

// Removes a Movie object from the list
void remove(Movie a[], string item, int &n) {
  int pos = -1;
  for (int i = 0; i < n; i++) { // Get the index for the Movie object
    if (a[i].title == item) {
      pos = i;
      break; // Break out of the loop
    }        // end of if
  }          // end of for
  if (pos != -1) {
    for (int j = pos; j < n - 1; j++) {
      a[j] = a[j + 1]; // Move the following elements by 1 index
    }
    n = n - 1;         // Decrement the size of the array by 1
    display_all(a, n); // Display the updated list
  } else {             // If the name of the movie wasn't found in the list
    cout << "Sorry, we couldn't find the movie you were looking for." << endl;
  }
} // end of function

// Analyzes the list of movies to see which movie grossed the most money
// domestically
void analyze_multiple(Movie a[], int n) {
  int highest_domestic_gross = 0;
  string movie_with_highest_domestic_gross;
  for (int i = 0; i < n;
       i++) { // Determine which movie grossed more domestically
    if (a[i].domestic_gross > highest_domestic_gross) {
      highest_domestic_gross = a[i].domestic_gross;
      movie_with_highest_domestic_gross = a[i].title;
    } // end of if
  }   // end of for
  cout << "The movie with the highest domestic box office gross is ";
  cout << movie_with_highest_domestic_gross << ". The movie grossed $";
  cout << highest_domestic_gross << " domestically.\n";
} // end of function

// Only allows movies distributed by a certain studio to be displayed
void filter(Movie a[], int n) {
  string distributor; // Stores the name of the distributor
  int index = -1;     // Is set to -1 as a default value
  cout << "Which distributor's movies would you like to see?\n";
  cin.ignore();
  getline(cin, distributor);
  for (int i = 0; i < n; i++) {
    if (a[i].distributor == distributor) { // If there is a match
      display_one(a[i]); // Display the information about the movie
      index = i;         // Store the index number
    } // end of if
  } //end of for
  if (index == -1) { //If the name of a studio is not in the list
    cout << "\nSorry, we couldn't find the studio you were looking for.";
  } //end of if
} //end of function

// Analyzes a particular movie to see which country the movie grossed
// the most money in
void analyze_one(Movie a[], string movie_search, int n) {
  int highest_gross = 0;
  string country_with_highest_gross;
  int index = -1;
  for (int i = 0; i < n; i++) { 
    if (a[i].title == movie_search) { //If the movie exists in the list
      index = i; //Get the index of the object
    } //end of if
  } //end of for
  if (index == -1) { //If the movie does not exist in the list
    cout << "Sorry, we couldn't find the movie you were looking for.";
  } else {
    for (int j = 0; j < n; j++) { 
      if (a[index].country_gross[j] > highest_gross) {
        highest_gross = a[index].country_gross[j];
        country_with_highest_gross = a[index].country[j];
      } //Find the country that grossed the most money for a specific movie
    } //end of for
    cout << "The country that grossed the most amount of money worldwide is: ";
    cout << country_with_highest_gross << ".\nThere was a total gross of $";
    cout << highest_gross << "\n";
  } //end of else
} //end of function

// Sorts the movies in alphabetical order
void sort(Movie a[], int n) {
  for (int i = 1; i < n; i++) {
    for (int j = i; j > 0; j--) {
      if (a[j - 1].title > a[j].title) {
        swap(a[j - 1], a[j]); //Swap if the movie titles are out of order
      } //end of if
    }
  } //end of for-loops
} //end of function

// Searches to see if a movie exists. If it does, returns the index of the Movie
// object from the array.
int search(Movie a[], string movie_search, int n) {
  int index = -1;  //Set index to -1 as a default value

  for (int j = 0; j < n; j++) {
    if (a[j].title == movie_search) { //If there is a match
      index = j;     //Store the value of the index in 'index'
    } //end of if
  } //end of for

  return index;
} //end of function

// Reads through the entire input file and collects data for each Movie object
void collect_all(istream &input, Movie a[], int &n) {
  for (int i = 0; i < 10; i++) {
    collect_one(input, a[i]); //Call the collect_one function for each Movie
                              //object
    n++;    //Increment n by 1. n keeps track of the size of the array.
  } //end of for
} //end of function

// Displays all the data collected from the input file
void display_all(Movie a[], int n) {
  for (int i = 0; i < n; i++) {
    display_one(a[i]);  //Call the display_one function for each Movie object
  } //end of for
} //end of function

// Reads from the input file to collect data for one Movie object
void collect_one(istream &input, Movie &m) { 
  input.ignore();
  getline(input, m.title, ',');  //Get the title of a movie
  getline(input, m.distributor, ','); //Get the name of the distributor
  input >> m.domestic_gross;  //Get the domestic gross
  input.ignore();
  for (int i = 0; i < 10; i++) {
    getline(input, m.country[i], ',');
  } //Get the names of the countries that the movie released in 
  for (int j = 0; j < 10; j++) {
    input >> m.country_gross[j];
    input.ignore();
  } //Get the gross amounts for each of those countries
} //end of function

// Displays all the information for one Movie object
void display_one(Movie m) {
  cout << " ___________________________________________________________________";
  cout << "___________\n";
  cout << "|";
  cout << setw(41) << "|" << setw(39) << "|\n";
  cout << left;
  cout << setw(2) << "|";
  cout << "TITLE";
  cout << right;
  cout << setw(35) << "|";
  cout << setw(12) << "DISTRIBUTOR" << setw(26) << "|";
  cout << "\n";
  cout << left;
  cout << setw(2) << "|";
  cout << setw(39) << m.title;
  cout << "| ";
  cout << setw(36) << m.distributor << setfill(' ');
  cout << setw(5) << "|" << endl;
  cout << "|________________________________________|__________________________";
  cout << "___________|\n";
  cout << "|";
  cout << right;
  cout << setw(79) << "|" << "\n";
  cout << "|Domestic Gross";
  cout << right;
  cout << setw(23) << "$";
  cout << left;
  cout << setw(41) << m.domestic_gross << "|" << "\n";
  cout << "|___________________________________________________________________";
  cout << "___________|\n";
  cout << left;
  cout << "|";
  cout << right;
  cout << setw(80) << "|\n";
  for (int i = 0; i < 10; i++) {
    cout << left;
    cout << "|";
    cout << setw(36) << m.country[i] << setfill(' ') << "$";
    cout << setw(41) << m.country_gross[i];
    cout << right;
    cout << "|\n";
    cout << "|_________________________________________________________________";
    cout << "_____________|\n";
    if (i != 9) {
      cout << left;
      cout << "|";
      cout << right;
      cout << setw(80) << "|\n";
    } //end of if
  } //end of for
} //end of function 