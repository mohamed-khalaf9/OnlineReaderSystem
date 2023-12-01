#include "UserManager.h"



 UserManager::UserManager(){

 }
 UserManager::~UserManager(){
    freeLoadedData();

}
void UserManager::accessSystem(){
    HelperFunctions helper;
    int choice=helper.ShowReadMenu({"Login","Sign up"});
    if(choice==1)
    do_login();
    else
    do_signup();
}
void UserManager::freeLoadedData(){
    for(auto p:username_userobject_map)
    {
        delete p.second;
    }
    username_userobject_map.clear();
    current_user=nullptr;
}
void  UserManager::LoadDatabase(){
    if(username_userobject_map.size()>0)
    return;
    freeLoadedData();
    // Some "Dummy Data" 
    User* user1 = new User();
    user1->set_username("mohamed");
    user1->set_password("111");
    user1->set_email("mohamed@gmail.com");
    user1->set_is_admin(true);
    user1->set_name("Mohamed khalaf");
    username_userobject_map[user1->get_username()] = user1;

}
void  UserManager::do_login(){
    LoadDatabase();

while (true) {
	std::string user_name, pass;
	std::cout << "Enter user name (no spaces): ";
	std::cin >> user_name;
	std::cout << "Enter password (no spaces): ";
	std::cin >> pass;

	if (!username_userobject_map.count(user_name)) {
		std::cout << "\nInvalid user user_name or password. Try again\n\n";
		continue;
	}
	User* user_exist = username_userobject_map.find(user_name)->second;

	if (pass != user_exist->get_password()) {
		std::cout << "\nInvalid user user_name or password. Try again\n\n";
		continue;
	}
	current_user = user_exist;
	break;
}

}
void  UserManager::do_signup(){
    std::string user_name;
    while (true) {
	std::cout << "Enter user name (No spaces): ";
	std::cin >> user_name;

	if (username_userobject_map.count(user_name))
		std::cout << "Already used. Try again\n";
	else
		break;
    }
    current_user = new User();
    current_user->ReadUser(user_name);
    std::string t = current_user->get_username();
    username_userobject_map[current_user->get_username()] = current_user;

}
BookReadingSession*  UserManager::add_reading_session(Book* book){
    return current_user->AddReadingSession(book);

}
const User*  UserManager::get_current_user()const{
    return current_user;

}
const std::map<std::string,User*>& UserManager::get_username_userobject_map()const{
    return username_userobject_map;
}