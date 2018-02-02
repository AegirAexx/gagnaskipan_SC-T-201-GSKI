
#include "book.h"

//Constructors
Book::Book(): title(""), ISBN(0), pageCount(0), checked(false){}

Book::Book(string title, int ISBN, int pageCount): title(title), ISBN(ISBN), pageCount(pageCount) {
    this->checked = false;
}

Book::~Book(){}

//Getters
int Book::getISBN() const{

    return ISBN;
}
int Book::getPageCount() const{

    return pageCount;
}
string Book::getTitle() const{

    return title;
}
bool Book::getChecked() const{

    return checked;
}

//Setters
void Book::setISBN(int ISBN){

    this->ISBN = ISBN;
}
void Book::setPageCount(int pageCount){

    this->pageCount = pageCount;
}
void Book::setTitle(string title){

    this->title = title;
}
void Book::setChecked(bool checked){

    this->checked = checked;
}

void Book::setBook(Book book){

    this->ISBN = book.getISBN();
    this->pageCount = book.getPageCount();
    this->title = book.getTitle();
    this->checked = book.getChecked();

}

//Friends
ostream& operator <<(ostream& out, const Book& book){

    out << "Title: " << book.title << endl;
    out << "ISBN: " << book.ISBN << endl;
    out << "Page count: " << book.pageCount << endl;
    if(book.checked){
        out << "Book is on loan." << endl;
    }else{
        out << "Book is available" << endl;
    }


    return out;
}
