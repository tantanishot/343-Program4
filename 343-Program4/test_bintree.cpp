#include "bintree.h"
//removing customer for now
#include "customer.h"
#include "item.h"

using namespace std;

int main() // possibility that operators arent evaluating correctly if tree doesnt follow order
{
    BinTree<Movie> tree;
    // test inserting exact same movie
    Movie* classic1 = new Classics(10, "ddirector", "dtitle", 5, 5000, "dfirst", "dlast"); // root
    
    // exact same parameters as classic1 so should not add to tree
    Movie* classic1_dupe = new Classics(10, "ddirector", "dtitle", 5, 5000, "dfirst", "dlast"); // N/A

    Movie* classic2 = new Classics(10, "bdirector", "btitle", 3, 3000, "bfirst", "blast"); // left

    Movie* classic3 = new Classics(10, "bdirector", "btitle", 3, 3000, "cfirst", "clast"); // left right sim1

    Movie* classic4 = new Classics(10, "adirector", "atitle", 1, 1000, "afirst", "alast"); // left left

    Movie* classic5 = new Classics(10, "edirector", "etitle", 7, 7000, "efirst", "elast"); // right

    Movie* classic6 = new Classics(10, "fdirector", "ftitle", 5, 5000, "ffirst", "flast"); // right left

    Movie* classic7 = new Classics(10, "gdirector", "gtitle", 3, 3000, "bfirst", "dlast"); // left right left

    Movie* classic8 = new Classics(10, "bdirector", "btitle", 3, 3000, "hfirst", "hlast"); // left right right sim2

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
    tree.insert(classic8);
    
    // should have 8 total movies

    cout << "Inserts finished, beginning displays" << endl;

    tree.displayInorder(); // a, bb, g, bc, bh, d, f, e

    cout << endl << endl;

    tree.displaySideways();

    cout << endl << endl;

    cout << "classic2 similar titles: " << to_string(tree.findNumSimilarTitles(classic2)) << endl; // 2 similar
    cout << "classic3 similar titles: " << to_string(tree.findNumSimilarTitles(classic3)) << endl; // 2 similar
    cout << "classic7 similar titles: " << to_string(tree.findNumSimilarTitles(classic7)) << endl; // 0 similar

    cout << endl << endl;

    cout << "Tree " << (tree.hasObject(classic1) ? "has " : "doesn't have ") << "classic1" << endl; // has
    cout << "Tree " << (tree.hasObject(classic_nonexistent) ? "has " : "doesn't have ") << "classic_nonexistent" << endl; // doesnt have

    return 0;
}