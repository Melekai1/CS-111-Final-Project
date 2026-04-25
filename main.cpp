#include <iostream>
#include <fstream>
#include <iomanip>
#include "library.h"
using namespace std;

int main() {
  ifstream file;    //Connects to the input file
  string file_name; //Stores the name of the input file
  Movie film;     //A Movie object
  int const CAPACITY = 10;  //Maximum capacity
  Movie movies[CAPACITY];  //An array of Movie objects
  string url;    //Contains the url from the input file
  string name_of_collection; 
  int number = 0;
  int response;  //Stores the input from the user
  string movie_search;  //Stores the name of a movie to be searched
  int search_index;  //Stores the index of a Movie object from the array
  string removed_movie; //Stores the name of a movie to be removed
  cout << "Enter the name of the file you want to process: ";
  cin >> file_name;
  while (file_name != "input.dat") {
    cout << "File not found. Try again: ";
    cin >> file_name;   
  }
  file.open(file_name);

  getline(file, url);
  getline(file, name_of_collection);
  cout << "\nThe tile of this analysis is " << '"' << name_of_collection << '"' << "\n";
  cout << "The data can be found on this link: " << url << "\n";
  collect_all(file, movies, number);
  do {
  response = menu();
  if (response == 1) { //The user wants to display all the data.
    display_all(movies, number); //This function will display all the array elements.
  }
  if (response == 2) { //The user wants to search for a specific movie.
    cout << "What movie would you like to search for?\n";
    cin.ignore();
    getline(cin, movie_search); //The user types in the name of the movie.
    search_index = search(movies, movie_search, number); /*This function searches each element      to find the movie title that matches the user's target. When a match is found, the
    function returns the index of the matching element.*/
    if (search_index == -1) {
      cout << "Sorry, we couldn't find the movie you were looking for.\n"; /*This is when the 
      function could not find a match to the user's target.*/
    } else {
      display_one(movies[search_index]); /*If the function returns an index, it will be used in 
      this display_one function call to display the matching element.*/
      }
  }
  if (response == 3) { /*The data wll be sorted based on the alphabetical order of the movie        titles.*/
    sort(movies, number);
    display_all(movies, number); /*The function will display the array elements in the new 
    order.*/
  }

  if (response == 4) { 
    cout << "Enter the name of a movie\n";
    cin.ignore();
    getline(cin, movie_search);
    analyze_one(movies, movie_search, number); /*The program sees which country 
    internationally grossed the most amount of money for a specific movie.*/
  }

  if (response == 5) { 
    filter(movies, number); //The user will choose which studio they want to see movies by.
  }

  if (response == 6) {
    analyze_multiple(movies, number); /*This function analyzes the different elements to see        which movie grossed the most amount of money domestically*/
  }

  if (response == 7) {
    cout << "Select the movie you would like to remove:\n";
    cin.ignore();
    getline(cin, removed_movie); //The user types in what movie they would like to remove.
    remove(movies, removed_movie, number); //This function removes an element from the array.
  }

  } while (response != 8); //The program will continue if the user does not choose
                            // to exit

  cout << "Thank you for using this program.";

  file.close();  //The file will close

  return 0;
} //end of main

