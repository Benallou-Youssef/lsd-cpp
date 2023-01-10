#include <iostream>
#include <string>

#define dashes " -------------------------------- "

class book{
	public:
	
	std::string getname();
	std::string getISBN();
	std::string getauthor();
	std::string getlink();
	
	void setname(std::string);
	void setISBN(std::string);
	void setauthor(std::string);
	void setlink(std::string);
	
	private:
		std::string name;
		std::string ISBN;
		std::string author;
		std::string link;
};

class library{
	public:
		void printlibrary();
		void ADD();
		void SEARCH(int);
	
	private:
		book books[8];
		int booksnumb = 0;
};

std::string truncate(std::string);

