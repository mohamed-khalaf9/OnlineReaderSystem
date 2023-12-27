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
 bool BookManager::UpdateBook(std::string isbn,Book* newBook){
       auto it = isbn_to_book_map.find(isbn);

    if (it != isbn_to_book_map.end()) {
        // Update information in the map directly
      it->second->set_ISBN(newBook->get_ISBN());
      it->second->set_title(newBook->get_title());
      it->second->set_author(newBook->get_author());
      it->second->set_pages(newBook->get_pages());
      


        // If the old ISBN is different from the new ISBN
        if (isbn != newBook->get_ISBN()) {
            // Check if the new ISBN already exists in the map
            auto existingIt = isbn_to_book_map.find(newBook->get_ISBN());
            if (existingIt != isbn_to_book_map.end()) {
                std::cout << "Cannot update ISBN to " << newBook->get_ISBN()<< ". ISBN already exists.\n";
                return false;
            }

            // Update the key in the map
            isbn_to_book_map[newBook->get_ISBN()] = std::move(it->second);
            isbn_to_book_map.erase(it);
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