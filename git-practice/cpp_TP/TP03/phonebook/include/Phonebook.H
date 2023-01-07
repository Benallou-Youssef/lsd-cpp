#include<iostream>
#include <string>

#define dashes "__________________________________________________"

class contact{			//Contains the firstname, last name, nickname and the phone number of the contact. It has functions to set the variables or extract them
	public:
	
		void set_firstname(std::string); 
        void set_lastname(std::string);
		void set_nickname(std::string);
		void set_phonenumber(std::string);
		
		std::string get_firstname();
        std::string get_lastname();
        std::string get_nickname();
		std::string get_phonenumber();
	
	private:
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string phonenumber;
};

class phonebook: public contact{		//Phonebook class is an array of 8 that stores contacts. It has functions that prints the stored contacts, add a new contact or search a stored contact
	public:
		void print_contacts();
		void add_contact();
		void search_contact(int);
	
	private:
		contact contacts[8];
		int contacts_number = 0;
};
std::string truncate(std::string);