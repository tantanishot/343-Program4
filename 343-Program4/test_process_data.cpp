#include <iostream>
#include "process_data.h"
#include <fstream>

using namespace std;

int main()
{
    cout << "=== TESTING ProcessData::processCommands() ===" << endl;

    ProcessData<Movie> pd; // Will initialize both movies and customers

    // Run processCommands(), allowing it to initialize and process commands
    pd.processCommands();

    cout << "\n=== TEST COMPLETED ===" << endl;
    return 0;
}
