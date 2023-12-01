#include "OnlineReaderSystem.h"
#include "AdminView.h"
#include "UserView.h"
#include <iostream>


OnlineReaderSystem::OnlineReaderSystem():bookManager(new BookManager()),userManager(new UserManager()){

}
 OnlineReaderSystem::~OnlineReaderSystem(){
    if(bookManager!=nullptr)
    {
        delete bookManager;
        bookManager=nullptr;
    }
    if(userManager!=nullptr)
    {
        delete userManager;
        userManager=nullptr;
    }

}
void OnlineReaderSystem::Run(){
    Loaddatabase();
    while(true)
    {
        userManager->accessSystem();
        if(userManager->get_current_user()->get_is_admin()==true)
        {
            AdminView view(*userManager,*bookManager);
            view.Display();
        }
        else
        {
            UserView view(*userManager,*bookManager);
            view.Display();
        }
        
    }


 }
 void OnlineReaderSystem::Loaddatabase(){
    userManager->LoadDatabase();
    bookManager->LoadDatabase();

 }