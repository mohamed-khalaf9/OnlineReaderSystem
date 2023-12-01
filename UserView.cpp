#include "UserView.h"
#include <iostream>
#include <vector>
#include <map>


 UserView::UserView(UserManager &userManager_,BookManager &bookManager_):userManager(userManager_),bookManager(bookManager_){

 }
void UserView::Display(){
const User* user = userManager.get_current_user();
std::cout << "\n\nHello " << user->get_name() << " | User View\n";

std::vector<std::string> menu;
menu.push_back("View Profile");
menu.push_back("List & Select from My Reading History");
menu.push_back("List & Select from Available Books");
menu.push_back("Logout");

while (true) {
    HelperFunctions helper;
	int choice = helper.ShowReadMenu(menu);
	if (choice == 1)
		ViewProfile();
	else if (choice == 2)
		ListReadingHistory();
	else if (choice == 3)
		ListAvailableBooks();
	else
		break;
}

}
void UserView::ViewProfile(){
    const User* user = userManager.get_current_user();

    std::cout << "\n" << user->Tostring() << "\n";

}
void UserView::DisplaySession(BookReadingSession* session){
std::vector<std::string> menu;
menu.push_back("Next Page");
menu.push_back("Previous Page");
menu.push_back("Stop Reading");

while (true) {
	std::cout << "Current Page: " << session->PageIdxStr() << "\n";
	std::cout << session->get_current_page_content() << "\n";
    HelperFunctions helper;
	int choice = helper.ShowReadMenu(menu);
	if (choice == 1)
		session->next_page();
	else if (choice == 2)
		session->previous_page();
	else
		break;
}
session->ResetLastAccessDate();

}
void UserView::ListReadingHistory(){
int idx = 0;
const auto& sessions = userManager.get_current_user()->get_reading_sessions();
for (auto& session : sessions) {
	std::cout << ++idx << ": " << session->Tostring() << "\n";
}

if (idx == 0)
	std::cout << "\nNo history. List books and start having fun\n";
else {
	std::cout << "\nWhich session to open?: ";
    HelperFunctions helper;
	int choice = helper.ReadInt(1, idx);
	DisplaySession(sessions[choice - 1]);
}

}
void UserView::ListAvailableBooks(){
const std::map<std::string, Book*>& mp = bookManager.get_isbn_to_book_map();

std::cout << "\nOur current book collection:\n";
int idx = 0;
for (const auto &pair : mp) {
	// As we call ToString: we don't need to worry about book data members future changes
	std::cout << "\t" << ++idx << " " << pair.second->Tostring() << "\n";
}
if(idx==0)
{
    std::cout<<"No books added from the Admins :( \n";
}
else
{

std::cout << "\nWhich book to read?: ";
HelperFunctions helper;
int choice = helper.ReadInt(1, idx);	// For simplicity, assume a new book is selected

idx = 0;
for (const auto &pair : mp) {
	if (++idx == choice) {
		BookReadingSession* session = userManager.add_reading_session(pair.second);
		DisplaySession(session);
		break;
	}
}
}


}
