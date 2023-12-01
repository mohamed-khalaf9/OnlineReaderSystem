#ifndef BOOK_H
#define BOOK_H
#include<vector>
#include <string>


class Book{
    private:
    std::string ISBN;
    std::string title;
    std::string author;
    std::vector<std::string>pages;

    public:
    void readBook();
    void setBook(Book* updatedBook);//for update book feature for Admins 
    const std::string & get_ISBN()const;
    const std::string & get_title()const;
    const std::string & get_author()const;
    const std::vector<std::string>& get_pages()const;
    void set_ISBN(const std::string &isbn);
    void set_title(const std::string &title_);
    void set_author(const std::string &author_);
    void set_pages(const std::vector<std::string> &pages_);
    std::string Tostring();
    










};









#endif