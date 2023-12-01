#include "BookManager.h"
#include <vector>
#include <algorithm>

 BookManager::BookManager(){

 }
 BookManager::~BookManager(){
    freeLoadedData();

 }
 void BookManager::LoadDatabase(){
    freeLoadedData();


}
 void BookManager::freeLoadedData(){
    for(auto p:isbn_to_book_map){
        delete p.second;
    }
    isbn_to_book_map.clear();
 }
 void BookManager::AddBook(Book* book){
    isbn_to_book_map[book->get_ISBN()]=book;

 }
 bool BookManager::UpdateBook(std::string isbn,Book* newBook,std::string newISBN){
     if (isbn_to_book_map.count(isbn)) {
        
        Book* bookToUpdate = isbn_to_book_map[isbn];
        bookToUpdate->set_ISBN(newISBN);
        bookToUpdate->set_title(newBook->get_title());
        bookToUpdate->set_author(newBook->get_author());
        bookToUpdate->set_pages(newBook->get_pages());

        // If the old ISBN is different from the new ISBN, update the key in the map
        if (isbn!= newISBN) {
            isbn_to_book_map[newISBN] = bookToUpdate;
            isbn_to_book_map.erase(isbn);
        }

        return true;
    } else {
        std::cout << "Book with ISBN " << isbn << " not found.\n";
        return false;
    }

 }
 bool BookManager::DeleteBook(std::string isbn){
    for (auto it = isbn_to_book_map.begin(); it != isbn_to_book_map.end(); ) {
        if (it->first == isbn) {
            delete it->second;
            it = isbn_to_book_map.erase(it);
            return true;
        } else {
            it++;
        }
    }
    return false;
 
 }
 Book* BookManager::getBook(std::string isbn){
    for (const auto& entry : isbn_to_book_map) {
        if (entry.first == isbn) {
            return entry.second; // Return the Book pointer when found
        }
    }


    return nullptr; 
 }
 
 const std::map<std::string,Book*>& BookManager::get_isbn_to_book_map(){
    return isbn_to_book_map;

 }
 void BookManager::set_isbn_to_book_map(std::map<std::string,Book*>isbn_to_book_map_){
    this->isbn_to_book_map=isbn_to_book_map_;
 }

  Book* BookManager::get_book_by_its_isbn(std::string isbn){
    auto it = isbn_to_book_map.find(isbn);

    if (it != isbn_to_book_map.end()) {
        return it->second;
    } else {
        return nullptr;
    }

  }