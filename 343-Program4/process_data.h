#ifndef PROCESS_DATA_H_
#define PROCESS_DATA_H_

#include <iostream>
#include <fstream>
#include <string>
#include "hash_table.h"
#include "bintree.h"
#include "transactions.h"
//Included types movie and customer
#include "classics.h"
#include "comedy.h"
#include "drama.h"
#include "customer.h"

using namespace std;

const int NUM_GENRES = 3;

template <typename T>
class ProcessData
{
    public:
        ProcessData();
        ~ProcessData();
        void processCommands();
        void initializeMovieData(ifstream &stream);
        void initializeCustomerData(ifstream &stream);

        void displayStoredData();


    private:
        HashTable<T>* storedMovies[3];
        HashTable<Customer>* storedCustomers;  
        //to keep them sorted
        BinTree<T>* movieTree[3];
};

//Need to remove this since it doesnt work as its called multiple times if it does
//#include "process_data.cpp"

#include "process_data.h"
#include <sstream>
using namespace std;

template <typename T>
ProcessData<T>::ProcessData()
{   
    //create new 
    storedCustomers = new HashTable<Customer>();

    for (int i = 0; i < NUM_GENRES; i++)
    {
        storedMovies[i] = new HashTable<T>();
        movieTree[i] = new BinTree<T>();
    }
}

template <typename T>
ProcessData<T>::~ProcessData()
{
    delete storedCustomers;

    for (int i = 0; i < NUM_GENRES; i++)
    {
        delete storedMovies[i];
        delete movieTree[i];
    }
}

template <typename T>
void ProcessData<T>::processCommands()
{
    ifstream movieFile("data4movies.txt");
    if (!movieFile)
    {
        cout << "Movie file could not be opened." << endl;
        return;
    }
    initializeMovieData(movieFile);

    ifstream customerFile("data4customers.txt");
    if (!customerFile)
    {
        cout << "Customer file could not be opened." << endl;
        return;
    }
    initializeCustomerData(customerFile);

    ifstream commandFile("data4commands.txt");
    if (!commandFile)
    {
        cout << "Command file could not be opened." << endl;
        return;
    }

    // process command file line by line
    int currentLine = 0;    // tracking the current line being read in file
    string line;
    while (getline(commandFile, line)) //reading the full line instead in each part 
    {
 
       
        currentLine++;
        stringstream ss(line);
        string transactionType; 
        ss >> transactionType; //Reading BRIH


        if (transactionType == "B" || transactionType == "R")         // borrow
        {
            // make transaction object and use the inherited method
            //Borrow b;
            // obtain information from lines
            int customerID;
            string mediaType, genre;
            ss >> customerID >> mediaType >> genre; //the three common attributes
            
            //cout << "[READ] Borrow command at line " << currentLine << " for customer " << customerID << "\n";

            Movie* foundMovie = nullptr;
            if(genre == "F")
            {
                string title;
                int releaseYear;

                getline(ss, title, ',');
                ss >> releaseYear;
                cout << "[READ] " << transactionType << " command at line " << currentLine 
                << " for customer " << customerID << " - Comedy: " 
                << "Title: " << title << ", Year: " << releaseYear << "\n";

                string searchKey = title + ", " + to_string(releaseYear);
                foundMovie = storedMovies[0]->retrieveString(searchKey); // Comedy table
            }
            //each search key will be based on the title 
            else if(genre == "D") 
            {
                string director, title;
                getline(ss, director, ',');  // Read director (until first comma)
                getline(ss, title, ',');     // Read title (until second comma)
                cout << "[READ] " << transactionType << " command at line " << currentLine 
                << " for customer " << customerID << " - Drama: " 
                << "Director: " << director << ", Title: " << title << "\n";

                string searchKey = director + ", " + title;
                foundMovie = storedMovies[1]->retrieveString(searchKey); // Drama table
            }
            else if (genre == "C")  // Classics: Extract Month, Year, and Actor
            {
                int month, year;
                string MAfirstName, MAlastName;
                ss >> month >> year >> MAfirstName >> MAlastName;

                cout << "[READ] " << transactionType << " command at line " << currentLine 
                     << " for customer " << customerID << " - Classics: " 
                     << "Month: " << month << ", Year: " << year 
                     << ", Actor: " << MAfirstName << " " << MAlastName << "\n";
                
                    string searchKey = to_string(month) + " " + to_string(year) + " " + MAfirstName + " " + MAlastName;
                    foundMovie = storedMovies[2]->retrieveString(searchKey); // Classics table
            }
            else
            {
                cout << "[ERROR] Invalid genre '" << genre << "' at line " << currentLine << "\n";
                   continue; 
            }
            
            // check if customerID exists in hashtable
            Customer* foundCustomer = storedCustomers->retrieveInt(customerID);
            if(!foundCustomer)
            {
                cout << "[ERROR] Customer ID " << customerID << " not found at line " << currentLine << "\n";
                continue; 
            }
            // check for valid item type
            // Check if media type is valid
            if (mediaType != "D") 
            {
                cout << "[ERROR] Invalid media type '" << mediaType 
                    << "' for customer " << customerID << " at line " << currentLine << "\n";
                continue; 
            }

            // check for valid movie type
            // check last arguments to see if movie exists in corresponding hashtable
            if(!foundMovie)
            {
                cout << "[ERROR] Movie not found in inventory at line " << currentLine << "\n";
                continue; 
            }
            
            cout << "[SUCCESS] Movie found: " << foundMovie->formatSortCriteria() << " at line " << currentLine << "\n";
            
            // process movie if all valid arguments
            int genreIndex = -1;
            if (genre == "F") genreIndex = 0;  // Comedy
            else if (genre == "D") genreIndex = 1;  // Drama
            else if (genre == "C") genreIndex = 2;  // Classics

            if (transactionType == "B") { 
                if (foundMovie->getStock() > 0) {
                    Borrow<Movie> borrowTransaction;  // ✅ Create Borrow object
                    bool success = borrowTransaction.processMovie(foundMovie, foundCustomer, storedMovies[genreIndex], movieTree[genreIndex]);
            
                    if (success) {
                        cout << "[SUCCESS] Borrowed: " << foundMovie->formatSortCriteria() 
                             << " for customer " << customerID << " at line " << currentLine << "\n";
                    } else {
                        cout << "[ERROR] Failed to borrow: " << foundMovie->formatSortCriteria() 
                             << " at line " << currentLine << "\n";
                    }
                } else {
                    cout << "[ERROR] Movie out of stock: " << foundMovie->formatSortCriteria() 
                         << " at line " << currentLine << "\n";
                }
            }
            
            else if (transactionType == "R") { 
                if (foundMovie->getStock() > 0) {
                    Borrow<Movie> borrowTransaction;  // ✅ Create Borrow object
                    bool success = borrowTransaction.processMovie(foundMovie, foundCustomer, storedMovies[genreIndex], movieTree[genreIndex]);
            
                    if (success) {
                        cout << "[SUCCESS] Returned: " << foundMovie->formatSortCriteria() 
                             << " for customer " << customerID << " at line " << currentLine << "\n";
                    } else {
                        cout << "[ERROR] Failed to return: " << foundMovie->formatSortCriteria() 
                             << " at line " << currentLine << "\n";
                    }
                } else {
                    cout << "[ERROR] Movie out of stock: " << foundMovie->formatSortCriteria() 
                         << " at line " << currentLine << "\n";
                }
            }


            /*
            //im not sure how you wanted to approach this... 
            //regarding time im just going to try to finish the validations
            int steps = 0;
            bool customerFound = false;
            while (!customerFound)
            {
                
            }
            */
        }
        else if (transactionType == "I")    // inventory
        {
             //print all types of movies  
             cout << "[READ] Inventory command at line " << currentLine << "\n";
             cout << "Displaying Inventory:\n";
 
            //from fdc

           
        }
        else if (transactionType == "H")    // history
        {
            int customerID;
            ss >> customerID;
        
            // Debug: Print when History is read
            cout << "[READ] History command at line " << currentLine << " for customer " << customerID << "\n";

           
            //check if customer is in hashtable to print inventroy then pring transaction history
        }
        else                                // invalid commands
        {
            cout << "Invalid transaction attemped at line " << currentLine << "." << endl;
            cout << "Skipping line " << currentLine << "." << endl;
        }
    }  
}

//pass in a new movie object
template <typename T>
void ProcessData<T>::initializeMovieData(ifstream &stream)
{
    string line;
    while(getline(stream,line))
    {
        stringstream ss(line);

        string genre, director, title;
        string firstActor, lastActor;
        int stock, month = 0, year = 0;

        getline(ss, genre, ',');
       
        ss >> stock;
        ss.ignore();

        getline(ss, director, ',');
        getline(ss, title, ',');


        cout << "[DEBUG] Processing line: " << line << endl;
        cout << "[DEBUG] Parsed values - Genre: " << genre 
             << ", Stock: " << stock 
             << ", Director: " << director 
             << ", Title: " << title << endl;

        if (genre == "C")  // If it's a Classics movie
        {
            ss >> firstActor >> lastActor >> month >> year;
            cout << "[DEBUG] Extracted Classics - Actor: " << firstActor << " " << lastActor
                 << ", Month: " << month << ", Year: " << year << endl;

            Movie* newMovie = new Classics(stock, director, title, month, year, firstActor, lastActor);
            storedMovies[2]->insertString(newMovie->formatSortCriteria(), newMovie);
            movieTree[2]->insert(newMovie);
        }
        else if (genre == "F")  // If it's a Comedy movie
        {
            ss >> year;
            cout << "[DEBUG] Extracted Comedy - Year: " << year << endl;

            Movie* newMovie = new Comedy(stock, director, title, year);
            storedMovies[0]->insertString(newMovie->formatSortCriteria(), newMovie);
            movieTree[0]->insert(newMovie);
        }
        else if (genre == "D")  // If it's a Drama movie
        {
            ss >> year;
            cout << "[DEBUG] Extracted Drama - Year: " << year << endl;

            Movie* newMovie = new Drama(stock, director, title, year);
            storedMovies[1]->insertString(newMovie->formatSortCriteria(), newMovie);
            movieTree[1]->insert(newMovie);
        }
        else
        {
            cout << "[ERROR] Invalid genre: " << genre << endl;
        }

    }
}


template <typename T>
void ProcessData<T>::initializeCustomerData(ifstream &stream)
{
    string line;
    while (getline(stream, line))
    {
        stringstream ss(line);  // Use stringstream to parse line
        string customerIDStr, firstName, lastName;
        int customerID;

        getline(ss, customerIDStr, ' ');  // Extract customer ID
        ss >> firstName >> lastName;      // Extract names

        try
        {
            customerID = stoi(customerIDStr);  // Convert string ID to integer
        }
        catch (const invalid_argument &e)
        {
            cout << "[ERROR] Invalid Customer ID: " << customerIDStr << endl;
            continue; // Skip invalid entries
        }

        string fullName = firstName + " " + lastName;

        cout << "[DEBUG] Reading Customer: ID=" << customerID << ", Name=" << fullName << endl;

        //doing that passed it in as movei for some reason
        //Customer* newCustomer = new Customer(customerID, fullName);
        storedCustomers->insertInt(customerID, new Customer(customerID, fullName));
    }
}


// I had to search this up but 
//since theres two types of printing I explicitly calleed display data
template <>
void ProcessData<Movie>::displayStoredData()
{
    cout << "\n=== Movie Hash Table ===" << endl;
    for (int i = 0; i < NUM_GENRES; i++)
    {
        if (storedMovies[i])
        {
            storedMovies[i]->display();
        }
    }
}


template <>
void ProcessData<Customer>::displayStoredData()
{
    cout << "\n=== Customer Hash Table ===" << endl;
    if (storedCustomers)
    {
        storedCustomers->display();
    }
}


#endif