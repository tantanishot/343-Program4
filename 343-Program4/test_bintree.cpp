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
    BinTree<Movie> tree2;
    Movie* comedy1 = new Comedy(10, "cDirector1", "Zebra Laughter", 2010); // Last in order
    Movie* comedy2 = new Comedy(10, "cDirector2", "Apple Laughs", 2015); // First in order
    Movie* comedy3 = new Comedy(10, "cDirector3", "Banana Chuckles", 2012);
    Movie* comedy4 = new Comedy(10, "cDirector4", "Banana Chuckles", 2018); // Same title, different year
    Movie* comedy5 = new Comedy(10, "cDirector5", "Orange Jokes", 2017);

    cout << "Beginning Comedy movie inserts..." << endl;
    tree2.insert(comedy1);
    tree2.insert(comedy2);
    tree2.insert(comedy3);
    tree2.insert(comedy4);
    tree2.insert(comedy5);

    // ---------------- DRAMA MOVIES ----------------
    BinTree<Movie> tree3;
    Movie* drama1 = new Drama(10, "Spielberg", "Saving Private Ryan", 1998);
    Movie* drama2 = new Drama(10, "Tarantino", "Pulp Fiction", 1994);
    Movie* drama3 = new Drama(10, "Nolan", "Inception", 2010);
    Movie* drama4 = new Drama(10, "Spielberg", "Schindler's List", 1993); // Same director, different title
    Movie* drama5 = new Drama(10, "Nolan", "Dunkirk", 2017); // Same director, different title

    cout << "Beginning Drama movie inserts..." << endl;
    tree3.insert(drama1);
    tree3.insert(drama2);
    tree3.insert(drama3);
    tree3.insert(drama4);
    tree3.insert(drama5);

    cout << "Inserts finished, beginning displays" << endl;

    tree.displayInorder();
    tree2.displayInorder();
    tree3.displayInorder();

    cout << endl << endl;

    tree.displaySideways();

    cout << endl << endl;
    cout << "Testing hasObject() for movies:" << endl;
    cout << "Tree " << (tree2.hasObject(comedy1) ? "has " : "doesn't have ") << "Comedy1 (Zebra Laughter)" << endl;
    cout << "Tree " << (tree3.hasObject(drama3) ? "has " : "doesn't have ") << "Drama3 (Inception)" << endl;
    cout << "Tree " << (tree.hasObject(classic5) ? "has " : "doesn't have ") << "Classic5 (etitle, elast)" << endl;

    cout << "classic2 similar titles: " << to_string(tree.findNumSimilarTitles(classic2)) << endl; // 2 similar
    cout << "classic3 similar titles: " << to_string(tree.findNumSimilarTitles(classic3)) << endl; // 2 similar
    cout << "classic7 similar titles: " << to_string(tree.findNumSimilarTitles(classic7)) << endl; // 0 similar

    cout << endl << endl;

    cout << "Tree " << (tree.hasObject(classic1) ? "has " : "doesn't have ") << "classic1" << endl; // has
    cout << "Tree " << (tree.hasObject(classic_nonexistent) ? "has " : "doesn't have ") << "classic_nonexistent" << endl; // doesnt have

    return 0;
}