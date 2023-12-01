#ifndef USERVIEW_H
#define USERVIEW_H

#include "BookManager.h"
#include "UserManager.h"
#include "BookReadingSession.h"
#include "HelperFunctions.h"


class UserView{
    private:
    UserManager &userManager;
    BookManager &bookManager;

    public:
    UserView(UserManager &userManager_, BookManager &bookManager_);
    void Display();
    void ViewProfile();
    void DisplaySession(BookReadingSession* session);
    void ListReadingHistory();
    void ListAvailableBooks();




















};










#endif