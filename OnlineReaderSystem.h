#ifndef ONLINEREADERSYSTEM_H
#define ONLINEREADERSYSTEM_H
#include "BookManager.h"
#include "UserManager.h"


class OnlineReaderSystem{
    private:
    BookManager *bookManager;
    UserManager *userManager;
    void Loaddatabase();

    public:
    OnlineReaderSystem();
    ~OnlineReaderSystem();
    void Run();
    


};










#endif