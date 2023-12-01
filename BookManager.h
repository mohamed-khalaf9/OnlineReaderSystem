#ifndef BOOKMANAGER_H
#define BOOKMANAGER_H


#include "Book.h"
#include <map>
#include <string>
#include <iostream>
#include "Book.h"


class BookManager{
    private:
    std::map<std::string,Book*>isbn_to_book_map;
    void freeLoadedData();

    public:
    BookManager();
    ~BookManager();
    BookManager(const BookManager&) = delete;
    void operator=(const BookManager&) = delete;
    void LoadDatabase();
    void AddBook(Book* book);
    bool UpdateBook(std::string isbn,Book* newbook,std::string newISBN);
    bool DeleteBook(std::string isbn);
    Book* getBook(std::string isbn);
    const std::map<std::string,Book*>& get_isbn_to_book_map();
    void set_isbn_to_book_map(std::map<std::string,Book*>isbn_to_book_map_);
    Book* get_book_by_its_isbn(std::string isbn);











};










#endif