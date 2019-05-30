//MYCINEMA.cpp

//Final Project

/*This Program My Cinema uses various methods to create a movie storage that can be displayed, saved, delete,
add, and search for movies. It uses functions, arrays, structures, and files.*/

//Created by Frank I. Gonzalez Soto and Edgar J. Cruz Palma

//Due date 5/20/2019

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <istream>
#include <ostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstring>
#include <cstdlib>

using namespace std;

//All function Prototype
void loadMovie(int &);// Function prototype to load movies from Text File.
void printAll();// Function prototype to display all loaded movie in screen.
void moviemenu();// Function prototype to display Main menu
int menuChoice();// Funtion prototype to get choice from user of the menu
void pressAnyKey(string);//function prototype to pause the program
void addMovie();//function prototype to add movies to the list
void saveMovie(int &fileCounterA);//function prototype updates text File with added movies
void displayMovie(int &fileCounterA);// function prototype displays one movie depending on the users ID choice
void deleteMovie();// function prototype deletes movie from list
void findMovieTitle(); //function prototype displays one movie depending on the users Title choice
void findMovieActor(); //function prototype displays one movie depending on the users Actor choice

//World variables
const int MovieLimit = 100; // limit of movie tetxt can hold
int fileCounterA;// count of movie in the text fil
bool run = false;// boolean to check if user load movie first

struct movieData // structure of each movie 
{
	bool deleted = false;
	string ID;
	string Title;
	string Actor;
	string Date;
	string MRate;

};

movieData movieArray[MovieLimit];// deffine movie array as movieData data type

int main()
{
	int choice;
	bool done = false;//boolean set to false until program is ended

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "WELCOME TO MY CINEMA APP" << endl;
	cout << "With this app you will be able to find, add,\ndelete and display all your movies in your disposal!" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	pressAnyKey("");

	while (!done) {// while loop to keep loding the menu. It stop as soon user hits number 9


		moviemenu();//displays menu

		choice = menuChoice();//Gets user choice

		switch (choice) {
		case 1:// Choice one displays all movies

			cout << "You have chosen option " << choice << endl << endl;
			printAll();//Function call to display all movies
			pressAnyKey("");
			break;

		case 2:// Choice two displays one movie depending on user inputed ID
			if (!run){
				cout << "You have chosen option " << choice << endl << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "You must load movies first!\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << endl;
			}
			else {
				cout << "You have chosen option " << choice << endl << endl;
				displayMovie(fileCounterA);//Function call to display one movie with user inputed ID
				
			}
			pressAnyKey("");
			break;

		case 3:// Choice three add Movie to the movie list
			if (!run){
				cout << "You have chosen option " << choice << endl << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "You must load movies first!\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << endl;
			}
			else {
				cout << "You have chosen option " << choice << endl << endl;
				addMovie();//Function call to add movie to movie list
			}
			pressAnyKey("");
			break;

		case 4:// Delete movie from movie list
			if (!run){
				cout << "You have chosen option " << choice << endl << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "You must load movies first!\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << endl;
			}
			else {
				cout << "You have chosen option " << choice << endl << endl;
				deleteMovie();//Function call to delete movie from the movie list
			}
			pressAnyKey("");
			break;

		case 5://Choice five displays movie depending on user inputed Title
			if (!run){
				cout << "You have chosen option " << choice << endl << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "You must load movies first!\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << endl;
			}
			else {
				cout << "You have chosen option " << choice << endl << endl;
				findMovieTitle();//Function call to display movie with user inputed Title
			}
			pressAnyKey("");
			break;

		case 6://Choice six displays movie depending on user inputed Actor 
			if (!run){
				cout << "You have chosen option " << choice << endl << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "You must load movies first!\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << endl;
			}
			else {
				cout << "You have chosen option " << choice << endl << endl;
				findMovieActor();//Function call to display movie with user intupted Actor
			}
			pressAnyKey("");
			break;

		case 7:// Choice seven Updates text file with added and deleted movies
			if (!run){
				cout << "You have chosen option " << choice << endl << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "You must load movies first!\n";
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << endl;
			}
			else {
				cout << "You have chosen option " << choice << endl << endl;
				saveMovie(fileCounterA);//Function call to save and update text file
			}
			pressAnyKey("");
			break;

		case 8:// Choice eight load list of movies from text
			cout << "You have chosen option " << choice << endl << endl;
			loadMovie(fileCounterA);// Function call to load moive from text file
			pressAnyKey("");
			run = true;
			break;

		case 9:// Choice nine quits program
			done = true;//turn done in to true to finish program
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Thank you for using My Cinema!" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << endl;
			break;

		default:// validation of invalid option
			pressAnyKey("Invalid option!");
			break;
		}

	}
}

//======================
// Funtion for Main Menu
//======================

void moviemenu() { 
	cout << "\n";
	cout << "%%%%%%%%%% MY CINEMA %%%%%%%%%%" << endl;
	cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
	cout << "|                             |\n";
	cout << "| 1. Display movies           |" << endl;
	cout << "| 2. Display a movie          |" << endl;
	cout << "| 3. Add movie                |" << endl;
	cout << "| 4. Delete movie             |" << endl;
	cout << "| 5. Find movies by title     |" << endl;
	cout << "| 6. Find movies by actor     |" << endl;
	cout << "| 7. Save movies to file      |" << endl;
	cout << "| 8. Load movies from file    |" << endl;
	cout << "| 9. Exit application         |" << endl;
	cout << "|                             |\n";
	cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n";
	cout << "\n";

}

int menuChoice() {// Funtion to get the user's choice from menu
	int choice;
	cout << "Please enter choice:";
	cin >> choice;
	cin.ignore();
	cout << endl;
	return (choice);
}

void pressAnyKey(string message) {// Validation function / pause for user to press any key to continue
	cout << endl << message << endl << endl;
	cout << "<Press Enter to continue>";
	cin.ignore();
	cin.clear();
	cin.get();
	

	
}

//=============================================
//Funtion to display all movies from movie list
//=============================================

void printAll(){

	fstream inFile;
	inFile.open("Movies.txt");

	cout << "%%%%%%%%% \t Movie Catalog \t\t %%%%%%%%%" << endl;
	cout << "ID" << setw(25) << "Title" << setw(19) << "Year" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	for (int i = 0; i < fileCounterA; i++) {// For loops to go trought all movie in the list

		if (inFile) {
			if (movieArray[i].deleted == false) {//check if movie is deleted or not
				cout << movieArray[i].ID;
				cout << setw(25) << movieArray[i].Title;
				cout << setw(17) << movieArray[i].Date << endl;
			}
		}


	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	inFile.close();

}


void loadMovie(int &fileCounterA)//Funtion to load all movie from text File
{
	int i = 0;
	fstream inFile;
	inFile.open("Movies.txt");

	if (inFile)
	{
		//While loop to get movie information from text file
		while (i < MovieLimit && getline(inFile, movieArray[i].ID, '|') && getline(inFile, movieArray[i].Title, '|') && getline(inFile, movieArray[i].Date, '|') && getline(inFile, movieArray[i].MRate, '|') && getline(inFile, movieArray[i].Actor)
			)
		{
			i++;
			fileCounterA = i;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Your moives have been loaded." << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	}


	inFile.close();
}

//============================================
//Funtion to add a new movie to the movie list
//============================================

void addMovie() {
	int i = 0;
	fstream inFile;
	inFile.open("Movies.txt");

	string ID;
	string title;
	string Actor;
	string Date;
	int MRate;


	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Please enter ID:" << endl;
	cin.clear();
	getline(cin, ID);

	//While loop to get movie information from text file
	while (i < MovieLimit && getline(inFile, movieArray[i].ID, '|') && getline(inFile, movieArray[i].Title, '|') && getline(inFile, movieArray[i].Date, '|') && getline(inFile, movieArray[i].MRate, '|') && getline(inFile, movieArray[i].Actor)
		)

	{
		while (ID == movieArray[i].ID && movieArray[i].deleted == false)// Validation loop to check if the User iputed ID is allready in use and movie is not deleted
		{
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "This ID is already in use. Please try another one" << endl;
			getline(cin, ID);
		}

		i++;
		fileCounterA = i;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Please enter Title:" << endl;
	getline(cin, title);
	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Please enter Actor:" << endl;
	getline(cin, Actor);
	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Please enter Date:" << endl;
	getline(cin, Date);
	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Please enter number for rating" << endl;
	cout << endl;
	cout << "0 - NONE" << endl;
	cout << "1 - G" << endl;
	cout << "2 - PG" << endl;
	cout << "3 - PG-13" << endl;
	cout << "4 - R" << endl;
	cout << "5 - N17" << endl;
	cout << endl;
	cout << "Number:";
	cin >> MRate;
	cout << endl;
	while (MRate < 0 || MRate > 5) {// loop to make sure user enter number between 0 and 5
		cout << "Please enter number for rating between 0 and 5" << endl;
		cout << endl;
		cout << "0 - NONE" << endl;
		cout << "1 - G" << endl;
		cout << "2 - PG" << endl;
		cout << "3 - PG-13" << endl;
		cout << "4 - R" << endl;
		cout << "5 - N17" << endl;
		cout << endl;
		cout << "Number:";
		cin >> MRate;
		cout << endl;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Your Movie has been added! Make sure select to option 7 to update data in text file." << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "ID         :" << ID << endl;
	cout << "Title      :" << title << endl;
	cout << "Date       :" << Date << endl;
	if (MRate == 0) {
		cout << "Rating     :" << "NONE" << endl;
	}
	else if (MRate == 1) {
		cout << "Rating     :" << "G" << endl;
	}
	else if (MRate == 2) {
		cout << "Rating     :" << "PG" << endl;
	}
	else if (MRate == 3) {
		cout << "Rating     :" << "PG-13" << endl;
	}
	else if (MRate == 4) {
		cout << "Rating     :" << "R" << endl;
	}
	else if (MRate == 5) {
		cout << "Rating     :" << "N17" << endl;
	}
	cout << "Main Actor :" << Actor << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	i = 0;

	//reload all movies to movie list
	while (i < MovieLimit && getline(inFile, movieArray[i].ID, '|') && getline(inFile, movieArray[i].Title, '|') && getline(inFile, movieArray[i].Date, '|') && getline(inFile, movieArray[i].MRate, '|') && getline(inFile, movieArray[i].Actor)
		)
	{
		i++;
		fileCounterA = i;
	}
	//Add user new movie to the list
	movieArray[fileCounterA].ID = ID;
	movieArray[fileCounterA].Title = title;
	movieArray[fileCounterA].Actor = Actor;
	movieArray[fileCounterA].Date = Date;
	if (MRate == 0) {
		movieArray[fileCounterA].MRate = "NONE";
	}
	else if (MRate == 1) {
		movieArray[fileCounterA].MRate = "G";
	}
	else if (MRate == 2) {
		movieArray[fileCounterA].MRate = "PG";
	}
	else if (MRate == 3) {
		movieArray[fileCounterA].MRate = "PG-13";
	}
	else if (MRate == 4) {
		movieArray[fileCounterA].MRate = "R";
	}
	else if (MRate == 5) {
		movieArray[fileCounterA].MRate = "N17";
	}


	fileCounterA++;

}

//============================================================
// Funtion to updates text file with added and deleted movies
//============================================================

void saveMovie(int &fileCounterA)
{
	fstream inFile;
	inFile.open("Movies.txt");
	int i = 0;
	int c;
	if (fileCounterA <= MovieLimit) {//Check if there is space to add movie

		if (inFile) {//check if the txt file was open

			for (c = 0; c < fileCounterA; c++)// to add all the movies to the file including new movie
			{


				inFile << movieArray[c].ID << "|";
				inFile << movieArray[c].Title << "|";
				inFile << movieArray[c].Date << "|";
				inFile << movieArray[c].MRate << "|";
				inFile << movieArray[c].Actor;
				inFile << endl;

			}
		}
		else if (!inFile)
		{
			cout << "Error while opening file";
		}
		if (c && fileCounterA) {// If movie was added
			cout << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "Your added movie is saved" << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << endl;
		}
		else {

			cout << "Movie file capcity is full";
			cout << endl;
		}
	}
	inFile.close();
}


//===============================================================================
//Function that look for a movie depending on the user inputed ID and displays it
//===============================================================================

void displayMovie(int &fileCounterA)
{
	int findMovie = 0;
	string ID;
	fstream inFile;
	inFile.open("Movies.txt");


	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Enter Moive ID: ";
	cin.clear();
	getline(cin, ID);

	int i = 0;


	while (i < MovieLimit && getline(inFile, movieArray[i].ID, '|') && getline(inFile, movieArray[i].Title, '|') && getline(inFile, movieArray[i].Date, '|') && getline(inFile, movieArray[i].MRate, '|') && getline(inFile, movieArray[i].Actor)
		)

	{
		if (ID == movieArray[i].ID)//compare ID to see if there is a movie with the same ID
		{

			if (movieArray[i].deleted == false) {// Checks if the movie is deleted or not

				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "ID         :" << movieArray[i].ID << endl;
				cout << "Title      :" << movieArray[i].Title << endl;
				cout << "Date       :" << movieArray[i].Date << endl;
				cout << "Rating     :" << movieArray[i].MRate << endl;
				cout << "Main Actor :" << movieArray[i].Actor << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

				findMovie = 1;
			}
		}

		i++;
	}
	if (findMovie == 0)// check if movie was successfully founded
	{
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Movie was not found" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~" << endl;
		cout << "Movie was found!" << endl;
		cout << "~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;
	}

	inFile.close();


}

//===========================================
//Function that deletes Movie from movie list
//===========================================

void deleteMovie() {
	int findMovie = 0;
	string ID;
	fstream inFile;
	inFile.open("Movies.txt");



	cout << "Enter Moive ID: ";
	cin.clear();
	getline(cin, ID);

	int i = 0;


	while (i < MovieLimit && getline(inFile, movieArray[i].ID, '|') && getline(inFile, movieArray[i].Title, '|') && getline(inFile, movieArray[i].Date, '|') && getline(inFile, movieArray[i].MRate, '|') && getline(inFile, movieArray[i].Actor)
		)

	{

		if (ID == movieArray[i].ID && movieArray[i].deleted == false)// compare ID to see if there is a movie with the same ID and if the Movie is deleted
		{
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			cout << "ID         :" << movieArray[i].ID << endl;
			cout << "Title      :" << movieArray[i].Title << endl;
			cout << "Date       :" << movieArray[i].Date << endl;
			cout << "Rating     :" << movieArray[i].MRate << endl;
			cout << "Main Actor :" << movieArray[i].Actor << endl;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

			movieArray[i].deleted = true;// Make Selected movie deleted


			findMovie = 1;// lets the program know the movie was found
		}

		i++;
	}
	if (findMovie == 0)//check if movie was successfully founded
	{
		cout << endl;
		cout << "Movie was not found";
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "Movie was found and Deleted";
		cout << endl;
	}



}

//==================================================================================
//Function that look for a movie depending on the user inputed Title and displays it
//==================================================================================

void findMovieTitle(){

	int findMovie = 0;
	string Title;
	fstream inFile;
	inFile.open("Movies.txt");


	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Enter Moive Title: ";
	cin.clear();
	getline(cin, Title);

	int i = 0;


	while (i < MovieLimit && getline(inFile, movieArray[i].ID, '|') && getline(inFile, movieArray[i].Title, '|') && getline(inFile, movieArray[i].Date, '|') && getline(inFile, movieArray[i].MRate, '|') && getline(inFile, movieArray[i].Actor)
		)

	{
		if (Title == movieArray[i].Title)//compare Title to see if there is a movie with the same Title
		{

			if (movieArray[i].deleted == false) {// Checks if the movie is deleted or not

				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "ID         :" << movieArray[i].ID << endl;
				cout << "Title      :" << movieArray[i].Title << endl;
				cout << "Date       :" << movieArray[i].Date << endl;
				cout << "Rating     :" << movieArray[i].MRate << endl;
				cout << "Main Actor :" << movieArray[i].Actor << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

				findMovie = 1;// lets the program know the movie was found
			}
		}

		i++;
	}
	if (findMovie == 0)// check if movie was successfully founded
	{
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Movie was not found" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~" << endl;
		cout << "Movie was found!" << endl;
		cout << "~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;
	}

	inFile.close();

}

//==================================================================================
//Function that look for a movie depending on the user inputed Actor and displays it
//==================================================================================
void findMovieActor() {

	int findMovie = 0;
	string Actor;
	fstream inFile;
	inFile.open("Movies.txt");


	cout << "~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Enter Moive Actor: ";
	cin.clear();
	getline(cin, Actor);

	int i = 0;


	while (i < MovieLimit && getline(inFile, movieArray[i].ID, '|') && getline(inFile, movieArray[i].Title, '|') && getline(inFile, movieArray[i].Date, '|') && getline(inFile, movieArray[i].MRate, '|') && getline(inFile, movieArray[i].Actor)
		)

	{
		if (Actor == movieArray[i].Actor)//compare Actor to see if there is a movie with the same Actor
		{

			if (movieArray[i].deleted == false) {// Checks if the movie is deleted or not

				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
				cout << "ID         :" << movieArray[i].ID << endl;
				cout << "Title      :" << movieArray[i].Title << endl;
				cout << "Date       :" << movieArray[i].Date << endl;
				cout << "Rating     :" << movieArray[i].MRate << endl;
				cout << "Main Actor :" << movieArray[i].Actor << endl;
				cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

				findMovie = 1;// lets the program know the movie was found
			}
		}

		i++;
	}
	if (findMovie == 0)// check if movie was successfully founded
	{
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << "Movie was not found" << endl;
		cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "~~~~~~~~~~~~~~~~~" << endl;
		cout << "Movie was found!" << endl;
		cout << "~~~~~~~~~~~~~~~~~" << endl;
		cout << endl;
	}

	inFile.close();
}