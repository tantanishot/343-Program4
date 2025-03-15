#include "bintree.h"
//removing customer for now
#include "customer.h"
#include "item.h"

using namespace std;

int main() // has not been tested yet
{
    BinTree<Movie> tree;
    // test inserting exact same movie
    Movie* classic1 = new Classics(10, "classics1", "title1", 1, 1000, "first1", "last1");
    
    // exact same parameters as classic1
    Movie* classic1_dupe = new Classics(10, "classics1", "title1", 1, 1000, "first1", "last1");

    Movie* classic2 = new Classics(10, "classics1", "title1", 1, 1000, "first0", "last0");
    Movie* classic3 = new Classics(10, "classics1", "title1", 1, 1000, "first3", "last3");

    // for viewing placement in tree
    Movie* classic4 = new Classics(10, "classics4", "title4", 4, 4000, "first4", "last4");

    // viewing in tree
    Movie* classic5 = new Classics(10, "classics1", "title1", 1, 1000, "first5", "last5");

    // different release date than classic1
    Movie* classic6 = new Classics(10, "classics1", "title1", 6, 6000, "first1", "last1");

    // unique entry
    Movie* classic7 = new Classics(10, "classics7", "title7", 7, 7000, "first7", "last7");

    // don't add
    Movie* classic_nonexistent = new Classics(10, "classics1", "title1", 1, 1000, "nonexistant", "nonexistant");

    cout << "Beginning inserts" << endl;
    tree.insert(classic1);

    // should not work
    tree.insert(classic1);
    tree.insert(classic1_dupe);

    tree.insert(classic2);
    tree.insert(classic3);
    tree.insert(classic4);
    tree.insert(classic5);
    tree.insert(classic6);
    tree.insert(classic7);

    cout << "Inserts finished, beginning displays" << endl;

    tree.displayPreorder();

    cout << endl << endl;

    tree.displaySideways();

    cout << endl << endl;

    cout << "classic1 similar titles: " << to_string(tree.findNumSimilarTitles(classic1)) << endl;
    cout << "classic4 similar titles: " << to_string(tree.findNumSimilarTitles(classic4)) << endl;
    cout << "classic7 similar titles: " << to_string(tree.findNumSimilarTitles(classic7)) << endl;

    cout << endl << endl;

    cout << "Tree " << (tree.hasObject(classic1) ? "has " : "doesn't have ") << "classic1" << endl;
    cout << "Tree " << (tree.hasObject(classic_nonexistent) ? "has " : "doesn't have ") << "classic_nonexistent" << endl;

    return 0;
}