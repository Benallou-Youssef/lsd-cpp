#include "../include/Library.h"

using namespace std;

string book::getname(){
	return name;
}

string book::getISBN(){
	return ISBN;
}

string book::getauthor(){
	return author;
}

string book::getlink(){
	return link;
}

int book::gettotalpages(){
	return totalpages;
}

bool book::isreadable(){
	return readable;
}

void book::setname(string str){
	name = str;
	return;
}

void book::setISBN(string str){
	ISBN = str;
	return;	
}

void book::setauthor(string str){
	author = str;
	return;
}

void book::setlink(string str){
	link = str;
	return;
}

void book::settotalpages(int tot){
	totalpages = tot;
}

void book::setread(string x){
	if(std::stoi(x) == 0)
		readable = false;
	else
		readable = true;
	return;
}
	
void library::printlibrary(){
	cout << " ________________________________ " << endl;
	cout << "|ID        |Book name |author    |" << endl;
	for(int i=0;i<booksnumb && i<8;i++){
		cout << dashes << endl;
		cout << "|" << "         " << i;
		cout << "|" << truncate(books[i].getname());
		cout << "|" << truncate(books[i].getauthor());
		cout << "|" << endl;
    }
	cout << " ________________________________ ";
	return;
}

void library::ADD(){
	string name,ISBN,author,link,readable;
	int nbpages;
	
	cout << endl << "will this book be readable ? (0/1) : ";
	cin >> readable;
	cout << endl << "name of the book : ";
	cin >> name;
	cout << endl << "ISBN number of the book : ";
	cin >> ISBN;
	cout << endl << "name of the author of the book : ";
	cin >> author;
	cout << endl << "link to the book : ";
	cin >> link;
	cout << endl << "number of pages in the book : ";
	cin >> nbpages;
	
	books[booksnumb%8].setread(readable);
	books[booksnumb%8].setname(name);
	books[booksnumb%8].setISBN(ISBN);
	books[booksnumb%8].setauthor(author);
	books[booksnumb%8].setlink(link);
	books[booksnumb%8].settotalpages(nbpages);
	if(books[booksnumb%8].isreadable()){
		for(int i=0;i<books[booksnumb%8].gettotalpages();i++){
			string c,t;
			
			cout << endl << "please input the title of the page number " << i << " : ";
			cin >> t;
			books[booksnumb%8].pages[i].settitle(t);
	
			cout << endl << "please input the content of the page number " << i << " : ";
			cin >> c;
			books[booksnumb%8].pages[i].setcontent(c);
		}
	}
	booksnumb++;
	cout << endl << "Book added succefully !" << endl;
	return;
}

void library::SEARCH(int id){
	if(id < 0 || id >= booksnumb || id > 7){
		cout <<"ERROR : No book found with the given ID"<<endl;
        return;
	}
	int pn=0;
	cout << " _____________________ " << endl;
	cout << "|page numb |title     |" << endl;
	cout << "|---------------------|" << endl;
	cout << "|" << truncate(to_string(pn));
	cout << "|" << truncate(books[id].pages[pn].gettitle());
	cout << "|" << endl;
	cout << " _____________________ "<< endl;
	cout << books[id].pages[pn].getcontent() << endl;
	string searchchoice;
	cout << "please give the number of the page you want to read,or type n for the next page, or EXIT to exit : ";
	cin >> searchchoice;
	while(searchchoice != "exit" && searchchoice != "EXIT"){
		if(searchchoice == "n"){
			if(pn+1 < books[id].gettotalpages()){
				pn++;
				cout << " _____________________ " << endl;
				cout << "|page numb |title     |" << endl;
				cout << "|---------------------|" << endl;
				cout << "|" << truncate(to_string(pn));
				cout << "|" << truncate(books[id].pages[pn].gettitle());
				cout << "|" << endl;
				cout << " _____________________ " << endl;
				cout << books[id].pages[pn].getcontent() << endl;
			}
			else
				cout<< "the previous page was the last one" << endl;
		}
		if (searchchoice != "EXIT" && searchchoice != "exit" && searchchoice != "n"){
			if(stoi(searchchoice) < 0 || stoi(searchchoice) > books[id].gettotalpages())
				cout << " out of range " << endl;
			else{
				cout << " _____________________ " << endl;
			cout << "|page numb |title     |" << endl;
			cout << "|---------------------|" << endl;
			cout << "|" << truncate(searchchoice);
			cout << "|" << truncate(books[id].pages[stoi(searchchoice)].gettitle());
			cout << "|" << endl;
			cout << " _____________________ " << endl;
			cout << books[id].pages[stoi(searchchoice)].getcontent() << endl;
			}
		}
		cout << "please give the number of the page you want to read,or type n for the next page, or EXIT to exit : ";
		cin >> searchchoice;
	}
}

void page::setpagenumb(int num){
	pagenumb = num;
	return;
}

void page::setcontent(string str){
	content = str;
	return;
}

void page::settitle(string str){
	title = str;
	return;
}

int page::getpagenumb(){
	return pagenumb;
}

string page::getcontent(){
	return content;
}

string page::gettitle(){
	return title;
}	

string truncate(string str){
	if(str.size() > 10){
		str.resize(9);
		str += ".";
	}
	while(str.size()<10)
	str = " " + str;
	return str;
}
	
	
	
	