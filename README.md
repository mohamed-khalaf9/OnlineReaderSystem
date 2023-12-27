# OnlineReaderSystem
A streamlined system crafted to elevate the book-reading journey while preserving an extensive reading history for users. This system empowers administrators with effortless CRUD operations on books, providing exclusive control over book management. Through this system , I have applied OOP concepts an, Design principles, to make the source code fit the non-functional requriments and the functional requirments , and also I have got solid  understanding for Pointers and how to handle them properly as I faced a lot of problems through development process .
## Features
- Simple start menu to make the user signup or login.
- The system has two types of users : Administrative and Customer users, the administrative users are initially added to the system so no SignUp for them.
- When the admin login (by enter his username and password ) to the system he has a menu of these features :
  - View profile : from this feature the Admin can display its account informations.
  - Add Book : Here the Admin can add the info of the book (ISBN,title,Author Name,Number of pages , and the content of pages ).
  - Update Book : By enter the Admin the ISBN of the book , he can update its information and automatically the book info will be updated in reading sessions for customers that read this book .
  - Delete Book : Through this feature the Admin can enter ISBN for book ,then the book will be deleted from the system and from reading sessions for Customers .
  - Get Book Information : The Admin can get all details about specific book by enter its ISBN.
  - Logout : and finally the Admin can logout and return to Start Menu
- When the Customer User Login or Signup , he has a menu of these features : 
  - View Profile : The customer can display its account information.
  - List and Select from my reading sessions :  Through this Feature the customer can see all detials about his last reading sessions and each reading session has these information (Book name , current page,last Time and Date when customer was reading this book ),Then the customer can enter the number of session  to continue reading the book and a menu  from three choices (1- Next page , 2- previous page,3-Stop reading )will be apeared to the customer to make it navigate the book , Once he choose "Stop reading" the session will be saved to its reading sessions history with consieder current Time and Date . 
  - List and Select from available Books : Through this feature the customer can see all books that  have been added from the Admins , and open new reading session by enter the number of the book which he want to read , and then can navigate the book and once he choose "Stop reading" the session of this book will be saved to its reading sessions history .
  - Logout : The customer can return to the Start menu of the system and logout from his account .
### Upcoming features 
- I will  make Admins activate new signup before the customers use the system .
- I will make a customer can clear it's all reading sessions history .
- I will make the system a file based system .
- I will Provide parallel access sessions
- Finally I have many ideas that can make the system more bigger and complex.
### UML (class diagram)
![OnlineReaderSystempic](https://github.com/mohamed-khalaf9/OnlineReaderSystem/assets/149758845/aa83e053-d25f-405f-94b5-11ab18a4c77d)

# Demo : 
LinkedIn Post : 






