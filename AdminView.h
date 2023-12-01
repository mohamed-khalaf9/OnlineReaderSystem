#ifndef ADMINVIEW_H
#define ADMINVIEW_H
#include "BookManager.h"
#include "UserManager.h"
#include "HelperFunctions.h"



class AdminView{
    private:
    UserManager &userManager;
    BookManager &bookManager;

    public:
    AdminView(UserManager &userManager,BookManager &bookManager);
    void Display();
    void ViewProfile();
    void AddBook();
    void UpdateBook();
    void DeleteBook();
    void GetBookInformation();














};












#endif