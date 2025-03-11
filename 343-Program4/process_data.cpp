#include "process_data.h"

ProcessData::ProcessData()
{
    HashTable storedMovies; // maybe change later
    HashTable storedCustomers;
}

void ProcessData::processCommands()
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
}