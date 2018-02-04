
#include "library.h"

//Constructors
Library::Library(): books(nullptr), storageSpace(0), bookCount(0) {}

Library::Library(int storageSpace): books(new Book[storageSpace]), storageSpace(storageSpace), bookCount(0) {}

Library::~Library(){

    delete[] books;
}

// Public API
void Library::addBook(Book book) {

    if(bookCount == storageSpace) {
        throw LibraryFullException();
    }
    if(isInLibrary_addBook(book)) {
        throw AlreadyInLibraryException();
    }
    
    books[bookCount] = book;
    bookCount++;
}

void Library::checkOutBookByISBN(int ISBN){
    
    char index = '\0';
    bool bookFound = wasISBNFound_setIndex(ISBN, index);
    checkOutExceptionHandler(bookFound, index);

}

void Library::checkOutBookByTitle(string title){
    
    char index = '\0';
    bool bookFound = wasTitleFound_setIndex(title, index);
    checkOutExceptionHandler(bookFound, index);

}

void Library::returnBookByISBN(int ISBN){
    
    char index = '\0';
    bool bookFound = wasISBNFound_setIndex(ISBN, index);
    returnExceptionHandler(bookFound, index);

}

void Library::returnBookByTitle(string title){
    
    char index = '\0';
    bool bookFound = wasTitleFound_setIndex(title, index);
    returnExceptionHandler(bookFound, index);

}

// Friends and Helpers

bool Library::isInLibrary_addBook(Book book){
    for(int i = 0; i < bookCount; ++i){
        if(books[i].getISBN() == book.getISBN()){
            return true;
        }
    }
    return false;
}

bool Library::wasISBNFound_setIndex(int ISBN, char& index){
    
    bool bookFound = false;

    for(int i = 0; i < bookCount; ++i){
        if(books[i].getISBN() == ISBN){
         bookFound = true;
            index = i;
            break;
        }
    }

    index -= 48;

    return bookFound;
}

bool Library::wasTitleFound_setIndex(string title, char& index){
    
    bool bookFound = false;

    for(int i = 0; i < bookCount; ++i){
        if(books[i].getTitle() == title){
         bookFound = true;
            index = i;
            break;
        }
    }

    index -= 48;

    return bookFound;
}

void Library::checkOutExceptionHandler(bool bookFound, char index){
    
    if (bookFound && !books[index].getChecked()){
        books[index].setChecked(true);

    }else if (bookFound && books[index].getChecked()) {
        throw BookAlreadyCheckedOutException();

    }else{
        throw BookNotFoundException();
    }

}

void Library::returnExceptionHandler(bool bookFound, char index){
    
    if(bookFound && books[index].getChecked()){
        books[index].setChecked(false);

    }else if(bookFound && !books[index].getChecked()) {
        throw NotCheckedOutException();

    }else{
        throw BookNotFoundException();
    }
}

ostream& operator <<(ostream& out, const Library& lib) {

    for(int i = 0; i < lib.bookCount; ++i){
        out << lib.books[i] << endl;
    }

    return out;
}