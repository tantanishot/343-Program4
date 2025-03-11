#include "movie.h"


Movie::Movie() : stock(0), director(""), title(""), releaseYear(0) {}

Movie::Movie(int movStock, string movDirector, string movTitle, int movRelease) {
    stock = movStock;
    director = movDirector;
    title = movTitle;
    releaseYear = movRelease;
}
// ✅ Implement getDVDType() (since Movie inherits from DVD)
string Movie::getDVDType() const {
    return "DVD";
}

// ✅ Implement getItemType() (since Movie inherits from Item)
string Movie::getItemType() const {
    return "Movie";
}
