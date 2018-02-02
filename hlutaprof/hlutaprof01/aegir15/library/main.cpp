
#include <iostream>
#include "library.h"
#include "book.h"

void addBookTest(Library &lib, Book &book) {

    try {
        lib.addBook(book);
    }
    catch(AlreadyInLibraryException) {
        cout << "Book with title " << book.getTitle()<< "  already in library!" << endl;
        return;
    }
    catch(LibraryFullException) {
        cout << "Library is full!" << endl;
        return;
    }
    cout << book.getTitle() << " added to library!" << endl;
}

void CheckOutBookTest(Library &lib, int ISBN) {

    try {
        lib.checkOutBookByISBN(ISBN);
    }
    catch(BookAlreadyCheckedOutException e) {
        cout << "Book with ISBN " << ISBN << " was already checked out!" << endl;
        return;
    }
    catch(BookNotFoundException e) {
        cout << "Book not found!" << endl;
        return;
    }
    cout << "Book with ISBN " << ISBN << " is now checked out!" << endl;
}

void CheckOutBookTest(Library &lib, string title) {

    try {
        lib.checkOutBookByTitle(title);
    }
    catch(BookAlreadyCheckedOutException e) {
        cout << "Book with Title " << title << " was already checked out!" << endl;
        return;
    }
    catch(BookNotFoundException e) {
        cout << "Book not found!" << endl;
        return;
    }
    cout << "Book with Title " << title << " is now checked out!" << endl;
}

void ReturnBookTest(Library &lib, int ISBN) {

    try {
        lib.returnBookByISBN(ISBN);
    }
    catch(NotCheckedOutException e) {
        cout << "Book with ISBN " << ISBN << " is already in library!" << endl;
        return;
    }
    catch(BookNotFoundException e) {
        cout << "Book not found!" << endl;
        return;
    }
    cout << "Book with ISBN " << ISBN << " has been returned!" << endl;
}

void ReturnBookTest(Library &lib, string title) {

    try {
        lib.returnBookByTitle(title);
    }
    catch(NotCheckedOutException e) {
        cout << "Book with Title " << title << " is already in library!" << endl;
        return;
    }
    catch(BookNotFoundException e) {
        cout << "Book not found!" << endl;
        return;
    }
    cout << "Book with Title " << title << " has been returned!" << endl;
}

int main(int argc, const char * argv[]) {

    cout << endl;
    cout << "TEST 1" << endl;
    cout << endl;

    Book book1("The Fellowship of the Ring", 1338, 600);
    cout << book1 << endl;

    Book book2("The Way of Kings", 1337, 800);
    cout << book2 << endl;

    Book book3("The Windup Bird Chronicle", 9000, 700);
    cout << book3 << endl;

    Book book4("The Alloy of Law", 87665, 300);
    cout << book4 << endl;


    Library library(3);
    addBookTest(library, book1);
    addBookTest(library, book2);
    addBookTest(library, book3);
    addBookTest(library, book4);

    cout << endl;

    cout << library << endl;

    CheckOutBookTest(library, 1337);
    CheckOutBookTest(library, 1000);

    CheckOutBookTest(library, "The Way of Kings");
    CheckOutBookTest(library, "The Way of Nerds");

    ReturnBookTest(library, 1338);
    ReturnBookTest(library, 87665);

    ReturnBookTest(library, "The Way of Kings");
    ReturnBookTest(library, "The Alloy of Law");

    cout << endl;
    cout << endl;
    cout << endl;
    cout << "TEST 2" << endl;
    cout << endl;


    Book book01("1", 1, 1);
    Book book02("2", 2, 2);
    Book book03("3", 3, 3);
    Book book04("4", 4, 4);
    Book book05("5", 5, 5);
    Book book06("6", 6, 6);
    Book book07("7", 7, 7);
    Book book08("8", 8, 8);
    Book book09("9", 9, 9);
    Book book10("10", 10, 10);


    Library library2(10);

    addBookTest(library2, book01);
    addBookTest(library2, book02);
    addBookTest(library2, book03);
    addBookTest(library2, book04);
    addBookTest(library2, book05);
    addBookTest(library2, book06);
    addBookTest(library2, book07);
    addBookTest(library2, book08);
    addBookTest(library2, book09);
    addBookTest(library2, book01);

    cout << library2 << endl;


    CheckOutBookTest(library2, 10);  //Book not found

    CheckOutBookTest(library2, 11);  //Book not found
    CheckOutBookTest(library2, 1);   //1 now checked out
    CheckOutBookTest(library2, 1);   //1 is already checked out
    ReturnBookTest(library2, 1);     //1 now returned
    ReturnBookTest(library2, 1);     //1 is already in library

    CheckOutBookTest(library2, "11");  //Book not found
    CheckOutBookTest(library2, "1");   //1 now checked out
    CheckOutBookTest(library2, "1");   //1 is already checked out
    ReturnBookTest(library2, "1");     //1 now returned
    ReturnBookTest(library2, "1");     //1 is already in library

    return 0;
}
