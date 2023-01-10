#include <iostream>
#include <string>

#define dashes " -------------------------------- "

class page{
	public:
		void setpagenumb(int);
		void setcontent(std::string);
		void settitle(std::string);
		
		int getpagenumb();
		std::string getcontent();
		std::string gettitle();
	private:
		int pagenumb;
		std::string content;
		std::string title;
};

class book{
	private:
		std::string name;
		std::string ISBN;
		std::string author;
		std::string link;
		int totalpages;
		bool readable;
		
	public:
	
	std::string getname();
	std::string getISBN();
	std::string getauthor();
	std::string getlink();
	int gettotalpages();
	bool isreadable();
	
	void settotalpages(int);
	void setname(std::string);
	void setISBN(std::string);
	void setauthor(std::string);
	void setlink(std::string);
	void setread(std::string);
	
	page pages[256];
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
