#include "AdminView.h"
#include "Book.h"


AdminView::AdminView(UserManager &userManager_,BookManager &bookManager_):userManager(userManager_),bookManager(bookManager_){

}
void AdminView::Display(){
 const User* user =userManager.get_current_user();

std::cout << "\n\nHello " << user->get_name() << " | Admin View\n";
std::vector<std::string> menu;
menu.push_back("View Profile");
menu.push_back("Add Book");
menu.push_back("Update Book");
menu.push_back("Delete Book");
menu.push_back("Get Book Information ");
menu.push_back("Logout");


while (true) {
    HelperFunctions helper;
	int choice = helper.ShowReadMenu(menu);
	if (choice == 1)
		ViewProfile();
	else if (choice == 2)
		AddBook();
    else if(choice==3)
       UpdateBook();
    else if(choice==4)
       DeleteBook();
    else if(choice==5)
      GetBookInformation();
	else
		break;
}

}
void AdminView::ViewProfile(){
    const User* user = userManager.get_current_user();

    std::cout << "\n" <<user->Tostring() << "\n";

}
void AdminView::AddBook(){
    Book* book=new Book();
    book->readBook();
    bookManager.AddBook(book);

}
void AdminView::UpdateBook(){
    std::string OldISBN;
    std::cout << "Enter ISBN of the book to update: ";
    std::cin >> OldISBN;

    Book* existedBook = bookManager.get_book_by_its_isbn(OldISBN);
    if (!existedBook->get_ISBN().empty()) {
        Book* updatedBook = new Book();
        updatedBook->readBook();

        
       

        if (!(bookManager.UpdateBook(OldISBN, updatedBook))) {
            std::cout << "Failed to update book. Invalid ISBN.\n";
            return;
        }

        std::cout << "Book updated successfully!\n";
        for (auto& user : userManager.get_username_userobject_map()) {
            User* u = user.second;
            u->update_reading_sessions(existedBook, updatedBook);
        }

      
    } else {
        std::cout << "Book with ISBN " << OldISBN << " not found.\n";
    }

}
void AdminView::DeleteBook()
{
    std::string isbn;
    std::cout<<"Enter ISBN of the book to delete : ";
    std::cin>>isbn;
    Book* tobedeleted;
    tobedeleted=bookManager.get_book_by_its_isbn(isbn);
    //delete the reading session of the book from User reading_session vector<BookReadingSession*>
    for(auto &user:userManager.get_username_userobject_map())
        {
            User* u=user.second;
            u->remove_reading_sessions(tobedeleted);
        
        }

    if(tobedeleted)
    {
        if(!(bookManager.DeleteBook(isbn))){
            std::cout << "Failed to delete book. Invalid ISBN.\n";
            return;
        }
        std::cout<<"Book Deleted successfully!\n";
    }
    else
    {
        std::cout<<"No book with such ISBN try again :\n";
    }

}
void AdminView::GetBookInformation(){
    std::string isbn;
    std::cout<<"Enter ISBN of the book : ";
    std::cin>>isbn;
    Book* booktobedispalyed= new Book();
    booktobedispalyed=bookManager.get_book_by_its_isbn(isbn);
    if(booktobedispalyed)
    {
        std::cout<<"ISBN : "<<booktobedispalyed->get_ISBN()<<"\n";
        std::cout<<"Title : "<<booktobedispalyed->get_title()<<"\n";
        std::cout<<"Author Name : "<<booktobedispalyed->get_author()<<"\n";
        std::cout<<"Total Pages: "<<(booktobedispalyed->get_pages().size())<<"\n";
    
    }
    
    else
    {
        std::cout<<"No book with such ISBN try again : ";
    }
}