#include "Employee.h" // Defines class Employee
#include "Map.h"
#include <iostream>
#include <string>

using namespace std;

class BookDetails {
private:
    string author;
    string category;
    unsigned int numberOfPages;
    bool isOnShelf;

public:
    BookDetails(string a, string c, unsigned int n, bool o) : author(a), category(c), numberOfPages(n), isOnShelf(o) {}

    friend ostream &operator<<(ostream &out, const BookDetails &book) {
        out << "Author: " << book.author << ", Category: " << book.category << ", Number of pages: " << book.numberOfPages << ", Is on shelf: " << (book.isOnShelf ? "Yes" : "No");
        return out;
    }
};

typedef string Title;
typedef Map<Title, BookDetails> BookDatabase; 

void addBooks(BookDatabase& database);
void modifyBooks(BookDatabase& database);


int main() {
    BookDatabase database;
    addBooks(database);
    BookDatabase newDatabase = database; 
    newDatabase.add("Romeo and Juliet", BookDetails("William Shakespeare", "Tragedy", 300, true));
    modifyBooks(newDatabase);
    cout << "Original database:" << endl << database << endl;
    cout << "Modified database:" << endl << newDatabase << endl;
    database = newDatabase;
    cout << "Database after the assignment:" << endl << database << endl;
}

void addBooks(BookDatabase& database) {
    database.add("Macbeth", BookDetails("William Shakespeare", "Tragedy", 160, true));
    database.add("Hamlet", BookDetails("William Shakespeare", "Tragedy", 200, false));
    database.add("Othello", BookDetails("William Shakespeare", "Tragedy", 180, true));
}

void modifyBooks(BookDatabase& database) {
    BookDetails* bookPtr;
    bookPtr = database.find("Macbeth");
    if (bookPtr) {
        bookPtr->changeCategory("Classic tragedy");
    }
    bookPtr = database.find("Hamlet");
    if (bookPtr) {
        bookPtr->changeNumberOfPages(220);
    }
    bookPtr = database.find("Romeo and Juliet");
    if (bookPtr) {
        bookPtr->changeIsOnShelf(false);
    }
}