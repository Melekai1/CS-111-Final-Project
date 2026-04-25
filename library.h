#include <string>
using namespace std;

struct Movie {  
  string title, distributor;
  int domestic_gross;  
  string country[10];  //Contains the names of the countries that
                      //the movie released in
  int country_gross[10]; //Contains the gross amounts for each of those countries
}; 

//Reads from the input file to collect data for one Movie object
void collect_one(istream& input, Movie& m);

//Displays all the information for one Movie object
void display_one(Movie m);

//Reads through the entire input file and collect data for each Movie object
void collect_all(istream& input, Movie f[], int& n);

//Displays all the data collected from the input file
void display_all(Movie f[], int n);

//Searches to see if a movie exists. If it does, returns the index of the Movie
//object from the array.
int search(Movie f[], string movie_search, int n);

//Sorts the movies in alphabetical order
void sort(Movie f[], int n);

//Returns the user's input based on the menu's options.
int menu();

//Analyzes a particular movie to see which country the movie grossed
//the most money in
void analyze_one(Movie f[], string movie_search, int n);

//Only allows movies distributed by a certain studio to be displayed
void filter(Movie f[], int n);

//Analyzes the list of movies to see which movie grossed the most money 
//domestically
void analyze_multiple(Movie f[], int n);

//Removes a Movie object from the list
void remove(Movie f[], string item, int& n);
