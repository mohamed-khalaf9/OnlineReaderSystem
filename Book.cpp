#include "Book.h"
#include <iostream>
#include <string>
#include <sstream>


void Book::readBook(){
   std::string str;

   std::cout << "Enter ISBN: ";
   std::cin >> str;
   set_ISBN(str);

   std::cout << "Enter Title: ";
   std::cin >> str;
   set_title(str);

   std::cout << "Enter Author Name: ";
   std::cin >> str;
   set_author(str);

   std::cout << "Enter How many pages: ";
   int pages_count;
   std::cin >> pages_count;

   for (int page = 0; page < pages_count; ++page) {
	 std::cout << "Enter page # " << page + 1 << ": ";
	 std::cin >> str;
	pages.push_back(str);
}
}

void Book::setBook(Book* updatedBook){
    set_ISBN(updatedBook->get_ISBN());
    set_title(updatedBook->get_title());
    set_author(updatedBook->get_author());
    set_pages(updatedBook->get_pages());
}

const std::string & Book::get_ISBN()const{
    return ISBN;

}
const std::string & Book::get_title()const{
    return title;

}
const std::string & Book::get_author()const{
    return author;

}
const std::vector<std::string>& Book::get_pages()const{
    return pages;

}
void Book::set_ISBN(const std::string &isbn){
   this->ISBN=isbn;

}
void Book::set_title(const std::string &title_){
    this->title=title_;

}
void Book::set_author(const std::string &author_){
    this->author=author_;

}
void Book::set_pages(const std::vector<std::string> &pages_){
    this->pages=pages;

}
std::string Book::Tostring() {
    return title;
}

