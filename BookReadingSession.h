#ifndef BOOKREADINGSESSION_H
#define BOOKREADINGSESSION_H
#include "Book.h"
#include <iostream>
#include "HelperFunctions.h"

class BookReadingSession{
    private:
    Book* book;
    int current_page;
    std::string last_access_date;
    HelperFunctions helper;

    public:
    BookReadingSession();
    Book* get_book()const;
    BookReadingSession(Book*);
    std::string Tostring();
    std::string get_current_page_content();
    const std::string &get_last_access_date();
    void ResetLastAccessDate();
    int get_current_page();
    std::string PageIdxStr();
    void next_page();
    void previous_page();
    void setBook(Book* updatedbook);// for update book feature for admins 

    



















};















#endif