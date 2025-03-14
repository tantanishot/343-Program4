#include "process_data.h"
#include <sstream>
using namespace std;

template <typename T>
ProcessData<T>::ProcessData()
{   
    //create new 
    storedCustomers = new HashTable<T>();

    for (int i = 0; i < NUM_GENRES; i++)
    {
        storedMovies[i] = new HashTable<T>();
    }
}

template <typename T>
ProcessData<T>::~ProcessData()
{
    delete storedCustomers;

    for (int i = 0; i < NUM_GENRES; i++)
    {
        delete storedMovies[i];
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
    /*
      // process command file line by line
    int currentLine = 0;    // tracking the current line being read in file
    while (!commandFile.eof())
    {
        string line;
        getline(commandFile, line, ' ');    // gets first character indicating transaction
        currentLine++;
        
        if (line.compare("B") == 0)         // borrow
        {
            // make transaction object and use the inherited method
            Borrow b;

            // obtain information from lines
            getline(commandFile, line, ' ');
            int customerID = stoi(line);

            // check if customerID exists in hashtable

            // check item type

            // check last arguments to see if movie exists

            // process movie if all valid arguments
            b.processMovie();
        }
        else if (line.compare("R") == 0)    // return
        {

        }
        else if (line.compare("I") == 0)    // inventory
        {

        }
        else if (line.compare("H") == 0)    // history
        {

        }
        else                                // invalid commands
        {
            cout << "Invalid transaction attemped at line " << currentLine << "." << endl;
            cout << "Skipping line " << currentLine << "." << endl;
        }
    }
    
    
    */
  
}

//pass in a new movie object
template <typename T>
void ProcessData<T>::initializeMovieData(ifstream &stream)
{
    string line;
    while(getline(stream, line))
    {
        stringstream ss(line);

        string genre, director, title;
        string firstActor, lastActor;
        int stock, month = 0, year = 0;

        ss >> genre;
        ss.ignore();

        ss >> stock;
        ss.ignore();

        getline(ss, director, ',');
        getline(ss, title, ',');

        if (genre == "C")  // If it's a Classics movie
        {
            ss >> firstActor >> lastActor >> month >> year;
            cout << "[DEBUG] Extracted Classics - Actor: " << firstActor << " " << lastActor
                 << ", Month: " << month << ", Year: " << year << endl;

            Movie* newMovie = new Classics(stock, director, title, month, year, firstActor, lastActor);
            storedMovies[2]->insertString(newMovie->formatSortCriteria(), newMovie);
        }
        else if (genre == "F")  // If it's a Comedy movie
        {
            ss >> year;
            cout << "[DEBUG] Extracted Comedy - Year: " << year << endl;

            Movie* newMovie = new Comedy(stock, director, title, year);
            storedMovies[0]->insertString(newMovie->formatSortCriteria(), newMovie);
        }
        else if (genre == "D")  // If it's a Drama movie
        {
            ss >> year;
            cout << "[DEBUG] Extracted Drama - Year: " << year << endl;

            Movie* newMovie = new Drama(stock, director, title, year);
            storedMovies[1]->insertString(newMovie->formatSortCriteria(), newMovie);
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
   
}

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

