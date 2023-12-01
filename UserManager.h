#ifndef USERMANAGER_H
#define USERMANAGER_H
#include "User.h"
#include <iostream>
#include <map>
#include "BookReadingSession.h"
#include "Book.h"





class UserManager{
    private:
    User* current_user{nullptr};
    std::map<std::string,User*>username_userobject_map;
    void freeLoadedData();

    public:
    UserManager(const UserManager&) = delete;
    void operator=(const UserManager&) = delete;
    UserManager();
    ~UserManager();
    void accessSystem();
    void LoadDatabase();
    void do_login();
    void do_signup();
    BookReadingSession* add_reading_session(Book* book);
    const User* get_current_user()const;
    const std::map<std::string,User*>& get_username_userobject_map()const;
    













};









#endif