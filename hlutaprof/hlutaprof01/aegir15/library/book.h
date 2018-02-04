
#ifndef Book_hpp
#define Book_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Book{
public:

    //Construct an empty book.
    Book();

    //Construct a book with the appropriate values.
    Book(string title, int ISBN, int pageCount);

    //A deconstructor.
    ~Book();

    //Return the ISBN value.
    int getISBN() const;

    //Return the page count.
    int getPageCount() const;

    //Return the title.
    string getTitle() const;

    //Return if the book is checked out.
    bool getChecked() const;

    //Set the value of the ISBN number.
    void setISBN(int ISBN);

    //Set the page count value.
    void setPageCount(int pageCount);

    //Set the title.
    void setTitle(string title);

    //Set if the book is checked out or not.
    void setChecked(bool checked);

    //Overwrite all the values of this book with the values of another book.
    void setBook(Book book);
    

    //Output the contents of the book.
    friend ostream& operator <<(ostream& outs, const Book& book);

private:
    //The ISBN number of the book.
    int ISBN;
    //The number of pages in the book.
    int pageCount;
    //The title of the book.
    string title;
    //If the book is checked out.
    bool checked;


};

#endif /* Book_hpp */
