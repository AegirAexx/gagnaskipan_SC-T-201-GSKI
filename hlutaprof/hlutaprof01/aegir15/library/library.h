
#ifndef Library_hpp
#define Library_hpp

#include <stdio.h>
#include "book.h"

class AlreadyInLibraryException{};
class LibraryFullException{};
class BookAlreadyCheckedOutException{};
class NotCheckedOutException{};
class BookNotFoundException{};

class Library{
public:

    Library();
    //Initialize a library based on the size of bookCount.
    Library(int bookCount);
    //A destructor.
    ~Library();

    //Add a book to the library.
    //If the library is full throw LibraryFullException.
    //If the book is already in the library throw AlreadyInLibraryException.
    void addBook(Book book);

    //Mark the book with the corresponding ISBN checked out.
    //If the book is already checked out throw BookAlreadyCheckedOutException.
    //If the book is not found throw BookNotFoundException.
    void checkOutBookByISBN(int ISBN);

    //Mark the book with the corresponding title checked out.
    //If the book is already checked out throw BookAlreadyCheckedOutException.
    //If the book is not found throw BookNotFoundException.
    void checkOutBookByTitle(string title);

    //Mark the book with the corresponding ISBN returned (not checked out).
    //If the book is already in the library (not checked out) throw NotCheckedOutException.
    //If the book is not found throw BookNotFoundException.
    void returnBookByISBN(int ISBN);

    //Mark the book with the corresponding title returned (not checked out).
    //If the book is already in the library (not checked out) throw NotCheckedOutException.
    //If the book is not found throw BookNotFoundException.
    void returnBookByTitle(string title);

    //Print out all the books in the library.
    friend ostream& operator <<(ostream& out, const Library &lib);

private:
    Book *books;
    int storageSpace;
    int bookCount;
    ///TODO: Add private variables, helper functions if needed and implement in library.cpp
    bool isInLib(Book book);
};

#endif /* Library_hpp */
