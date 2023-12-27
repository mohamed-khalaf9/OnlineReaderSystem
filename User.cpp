#include "User.h"
#include <iostream>
#include<algorithm>


 User::User(){
    isadmin=false;

 }
User::~User(){
    for (auto &session : reading_sessions)
	delete session;

   reading_sessions.clear();

}
void User::ReadUser(const std::string &username){
    set_username(username);
    std::string str;
    
    std::cout<< "Enter password (no spaces): ";
    std::cin>> str;
    set_password(str);
    std::cout<< "Enter name (no spaces): ";
    std::cin>> str;
    set_name(str);
    std::cout<< "Enter email (no spaces): ";
    std::cin>> str;
    set_email(str);
    

}
std::string User::Tostring()const{
    std::ostringstream oss;
    oss << "Name: " << username;
    if (get_is_admin())
	oss << " | Admin";
    oss << "\n";
    oss << "Email: " << email << "\n";
    oss << "User name: " << username << "\n";
return oss.str();

}
BookReadingSession* User::AddReadingSession(Book *book){
    BookReadingSession* session =new BookReadingSession(book);
    reading_sessions.push_back(session);
    return session;

}
const std::string & User::get_username()const{
    return username;

}
const std::string & User::get_password()const{
    return password;

}
const std::string & User::get_name()const{
    return name;

}
const std::string & User::get_email()const{
    return email;


}
const bool & User::get_is_admin()const{
    return isadmin;

}
const std::vector<BookReadingSession*> & User::get_reading_sessions()const{
    return reading_sessions;

}
void User::update_reading_sessions(Book* oldbook,Book* updatedbook){
    for(auto &b:reading_sessions)
    {
        if(b->get_book()->get_ISBN()==oldbook->get_ISBN())
        b->setBook(updatedbook);
    }

}
void User::set_username(const std::string &username_){
    this->username=username_;

}
void User::set_password(const std::string &password_){
    this->password=password_;

}
void User::set_name(const std::string &name_){
    this->name=name_;

}
void User::set_email(const std::string &email_){
    this->email=email_;

}
void User::set_is_admin(const int &is_admin_){
    this->isadmin=is_admin_;

}
void User::remove_reading_sessions(Book* tobedeleted){
     BookReadingSession* SessionTobeDeleted = nullptr;
    
    for (auto &session : reading_sessions) {
        if (session->get_book()->get_ISBN() == tobedeleted->get_ISBN()) {
            SessionTobeDeleted = session;
            break;
        }
    }

    if (SessionTobeDeleted != nullptr) {
        reading_sessions.erase(std::remove_if(reading_sessions.begin(), reading_sessions.end(),
            [SessionTobeDeleted](BookReadingSession* session) {
                return session == SessionTobeDeleted;
            }), reading_sessions.end());

        delete SessionTobeDeleted;
    }
}