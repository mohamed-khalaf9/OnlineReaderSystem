#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include "BookReadingSession.h"
#include "Book.h"
#include <sstream>

class User{
    private:
    std::string username;
    std::string password;
    std::string name;
    std::string email;
    std::vector<BookReadingSession*> reading_sessions;
    bool isadmin;


    public:
    User(const User&) = delete;
    void operator=(const User&) = delete;

    User();
    ~User();
    void ReadUser(const std::string &username);
    std::string Tostring()const;
    BookReadingSession* AddReadingSession(Book *book);
    const std::string & get_username()const;
    const std::string & get_password()const;
    const std::string & get_name()const;
    const std::string & get_email()const;
    const bool & get_is_admin()const;
    const std::vector<BookReadingSession*> & get_reading_sessions()const;
    void update_reading_sessions(Book* oldbook,Book* updatedbook);
    void remove_reading_sessions(Book* tobedeleted);
    void set_username(const std::string &username_);
    void set_password(const std::string &password_);
    void set_name(const std::string &name_);
    void set_email(const std::string &email_);
    void set_is_admin(const int &is_admin_);





    














};









#endif