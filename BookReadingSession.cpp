#include "BookReadingSession.h"


BookReadingSession::BookReadingSession():BookReadingSession(nullptr){
   

}
BookReadingSession::BookReadingSession(Book* book_):current_page(0),book(book_),last_access_date(helper.GetCurrentTimeDate()){

}
Book* BookReadingSession::get_book()const
{
    return book;

}
std::string BookReadingSession::Tostring(){
    std::ostringstream oss;
    oss <<get_book()->get_title() << " Page: " << PageIdxStr() << " - " << get_last_access_date();
    return oss.str();

}
std::string BookReadingSession::get_current_page_content(){
    std::vector<std::string> pages_content;
    if(book!=nullptr&&current_page<book->get_pages().size())
    {
    pages_content=book->get_pages();
    return pages_content[current_page];
    }
    return "invalid page";

}
const std::string& BookReadingSession::get_last_access_date(){
    return last_access_date;

}
void BookReadingSession::ResetLastAccessDate(){
    last_access_date=helper.GetCurrentTimeDate();

}
int BookReadingSession::get_current_page(){
    return current_page;

}
std::string BookReadingSession::PageIdxStr(){
    std::ostringstream oss;
    oss << get_current_page() + 1 << "/" << book->get_pages().size();
    return oss.str();
}
void BookReadingSession::next_page(){
    if (current_page < (int) book->get_pages().size() - 1)
	current_page++;

}
void BookReadingSession::previous_page(){
    if(current_page>0)
    current_page--;

}
void BookReadingSession::setBook(Book* updatedbook)
{
    book=updatedbook;
    current_page=0;
}