#define DOCUMENT_H

#include <iostream>
#include <string>
using namespace std;

class Document	{
	public:
		void setText(string s)	{
			text = s;
		}
		string getText()	{
			return text;
		}
	protected:
		string text;
};

class Email: public Document	{
	public:
		void setEmail(string s, string r, string t1, string t2)	{
			sender = s;
			recipient = r;
			title = t1;
			Document::setText(t2);
		}
		string getSender()	{
			return sender;
		}
		string getRecipient()	{
			return recipient;
		}
		string getTite()	{
			return title;
		}
	protected:
		string sender, recipient, title;
};

class File: public Document{
	public:
		void setFile(string p, string t)	{
			path = p;
			Document::setText(t);
		}
		string getPath()	{
			cout << "PathSet";
		}
	protected:
		string path;
};

bool ContainsKeyword(Document& docObject, string keyword);

int main()	{
	Email e1;
	e1.setEmail("Steven", "Carly", "Meet Tomorrow?", "Hey im free tomorrow, intrested in lunch?");
	
	Email e2;
	e2.setEmail("Corey", "Steven", "DONT MISS CLASS", "DONT MISS class there will be a pop quiz during next lecture.");
	
	Email e3;
	e3.setEmail("Kloe", "Steven", "Can You Stop At The Store?", "We need groceries AND CHEETOS!");
	
	File f1;
	f1.setFile("home", "NOTES: * points to an an address");
	
	File f2;
	f2.setFile("Desktop", "NOTES: & points to an object that contains the address of pointer");
	
	File f3;
	f3.setFile("Desktop", "Dont forget to submit cs144 prereqs!");
	
	cout << "\tContains Functions returns 1 for TRUE and 0 for FALSE" << endl;
	cout << "checking file for contents of keyword: Dinner" << endl;
	cout << ContainsKeyword(e1, "Diner") << endl;
	cout << "checking file for contents of keyword: quiz" << endl;
	cout << ContainsKeyword(e2, "quiz") << endl;
	cout << "checking file for contents of keyword: walmart" << endl;
	cout << ContainsKeyword(e3, "walmart") << endl;
	cout << "checking file for contents of keyword: Hello" << endl;
	cout << ContainsKeyword(f1, "Hello") << endl;
	cout << "checking file for contents of keyword: object" << endl;
	cout << ContainsKeyword(f2, "object") << endl;
	cout << "checking file for chontents of keyword: cs144" << endl;
	cout << ContainsKeyword(f3, "cs144") << endl;
	
	return 0;
}

bool ContainsKeyword(Document& docObject, string keyword)	{
	if (docObject.getText().find(keyword) != string::npos)
		return true;
	return false;
}