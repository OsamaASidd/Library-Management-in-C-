#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

class Book{
	public: 
	string author, name, status;
	int id, publish_date;
	float price;
// METHODS
    book(sting x, int a); // USERDEFINED CONSTRUCTOR 
    ~book(string x, int a); // USERDEFINED DESTRUCTOR
    void displaydetails(string a); // THIS FUNCTION WILL DISPLAY THE INFORMATION ABOUT THE BOOK
    void inquiry(int a); // THIS WILL LET USER TO MAKE INQUIRY RELATED TO BOOK    	
};

class User{
	private :
		int id;
		int contact;
	public :
	    string F_name, L_name;
	    User(int x); // USERDEFINED CONSTRUCTOR (WILL TAKE
		void returnbook(); // THIS FUNCTION WILL BE LINKED WITH THE BOOK CLASS
	    
	    
	    
			
};



int main(int argc, char** argv) {
	return 0;
}
