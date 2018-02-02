
#include "library.h"

//Constructors
Library::Library(): books(nullptr), storageSpace(0), bookCount(0) {}

Library::Library(int storageSpace): books(new Book[storageSpace]), storageSpace(storageSpace), bookCount(0) {}

Library::~Library(){

    delete[] books;
}

void Library::addBook(Book book) {

    if(bookCount == storageSpace) {
        throw LibraryFullException();
    }
    if(isInLib(book)) {
        throw AlreadyInLibraryException();
    }

    books[bookCount] = book;
    bookCount++;
}

void Library::checkOutBookByISBN(int ISBN){
    bool bookIndexFound = false;
    char index = '\0';

    for(int i = 0; i < bookCount; ++i){
        if(books[i].getISBN() == ISBN){
            bookIndexFound = true;
            index = i;
            break;
        }
    }
    index -= 48;

    if(bookIndexFound && !books[index].getChecked()){
        books[index].setChecked(true);

    }else if(bookIndexFound && books[index].getChecked()) {
        throw BookAlreadyCheckedOutException();

    }else{
        throw BookNotFoundException();
    }

}

void Library::checkOutBookByTitle(string title){
    bool bookIndexFound = false;
    char index = '\0';

    for(int i = 0; i < bookCount; ++i){
        if(books[i].getTitle() == title){
            bookIndexFound = true;
            index = i;
            break;
        }
    }
    index -= 48;

    if(bookIndexFound && !books[index].getChecked()){
        books[index].setChecked(true);

    }else if(bookIndexFound && books[index].getChecked()) {
        throw BookAlreadyCheckedOutException();

    }else{
        throw BookNotFoundException();
    }
}

void Library::returnBookByISBN(int ISBN){
    bool bookIndexFound = false;
    char index = '\0';

    for(int i = 0; i < bookCount; ++i){
        if(books[i].getISBN() == ISBN){
            bookIndexFound = true;
            index = i;
            break;
        }
    }
    index -= 48;

    if(bookIndexFound && books[index].getChecked()){
        books[index].setChecked(false);

    }else if(bookIndexFound && !books[index].getChecked()) {
        throw NotCheckedOutException();

    }else{
        throw BookNotFoundException();
    }
}


void Library::returnBookByTitle(string title){
    bool bookIndexFound = false;
    char index = '\0';

    for(int i = 0; i < bookCount; ++i){
        if(books[i].getTitle() == title){
            bookIndexFound = true;
            index = i;
            break;
        }
    }
    index -= 48;

    if(bookIndexFound && books[index].getChecked()){
        books[index].setChecked(false);

    }else if(bookIndexFound && !books[index].getChecked()) {
        throw NotCheckedOutException();

    }else{
        throw BookNotFoundException();
    }
}
        

ostream& operator <<(ostream& out, const Library &lib) {

    for(int i = 0; i < lib.bookCount; ++i){
        out << lib.books[i] << endl;
    }

    return out;
}

bool Library::isInLib(Book book){
    for(int i = 0; i < bookCount; ++i){
        if(books[i].getISBN() == book.getISBN()){
            return true;
        }
    }
    return false;
}

