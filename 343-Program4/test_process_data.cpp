#include <iostream>
#include "process_data.h"
#include <fstream>

using namespace std;

int main()
{
    // Create instances for movies and customers
    ProcessData<Movie> movieData;
    ProcessData<Customer> customerData;

    // Open movie and customer files
    ifstream movieFile("data4movies.txt");
    ifstream customerFile("data4customers.txt");
    
    if (!movieFile || !customerFile)
    {
        cout << "Error opening input files!" << endl;
        return 1;
    }

    // Initialize movie and customer data
    movieData.initializeMovieData(movieFile);
    customerData.initializeCustomerData(customerFile);
    
    // Close files
    movieFile.close();
    customerFile.close();

    // Display stored movies and customers using ProcessData's display function
    cout << "\n=== Movie Data ===" << endl;
    movieData.displayStoredData();
    
    cout << "\n=== Customer Data ===" << endl;
    customerData.displayStoredData();

    return 0;
}
