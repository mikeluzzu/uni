/*This is the c++ version of a simple python program that 
I wrote after passing the python exam in 1 year of university.
It's a simple account manager.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account{
private:
	string service;
	string username;
	string password;
	string email;
	
public:
	Account(string& s, string& u, string& p, string& e) :
	service(s), username(u), password(p), email(e){}

	string getService() const {return service;}
	string getUsername() const {return username;}
	string getPassword() const {return password;}
	string getEmail() const {return email;}

	void setService(string& s) {service = s;}
	void setUsername(string& u) {username = u;}
	void setPassword(string& p) {password = p;}
	void setEmail(string& e) {email = e;}
	
	friend ostream& operator << (ostream& os, const Account& a); 

};

ostream& operator << (ostream& os, const Account& a){
	os << "Service: " << a.service << endl
	   << "Username: " << a.username << endl
	   << "Password: " << a.password << endl
	   << "Email: " << a.email << endl;
	   return os;
}

void displayAll(vector<Account> & accounts){
	if(accounts.empty()) {
		cout << "No accounts stored." << endl;
		return; 
	}else{
		cout << "Accounts list: " << endl << endl;
		for(size_t i = 0; i < accounts.size(); i++){
			cout << "Account " << (i + 1) << endl;
			cout << accounts[i] << endl;
		}
	}
}

void displayAccount(vector<Account>& accounts, string& serviceName){
	if(accounts.empty()){
		cout << "No accounts stored." << endl;
		return;
	}
	for(size_t i = 0; i < accounts.size(); i++){
		if (accounts[i].getService() == serviceName){
			cout << accounts[i] << endl;
		}
		
	}
}

void addAccount(vector<Account>& accounts){
	string iService, iUsername, iPassword, iEmail;

	cin.ignore();
	
	cout << "Enter the service name: " << endl;
	getline (cin, iService);

	cout << "Enter the username: " << endl;
	getline (cin, iUsername);

	cout << "Enter the password: " << endl;
	getline (cin, iPassword);

	cout << "Enter the email: " << endl;
	getline (cin, iEmail);

	accounts.push_back(Account(iService, iUsername, iPassword, iEmail));
	cout << "Account added successfully." << endl;
}

void removeAccount(vector<Account>& accounts, string & serviceName){
	if(accounts.empty()){
		cout << "No accounts to remove." << endl;
		return;
	}

	bool found = false;
	for(size_t i = 0; i < accounts.size(); i++){
		if (accounts[i].getService() == serviceName){
			accounts.erase(accounts.begin() + i);
			cout << "Account: " << serviceName << "removed correctly." << endl;
			found = true;
			i--;
		} 
	}
	if (!found){
		cout << "Account not found." << endl;
	}
	}

void modifyAccount(vector<Account>& accounts, string& serviceName){
	if(accounts.empty()){
		cout << "No accounts to modify." << endl;
		return; 
	}

	string mService, mUsername, mPassword, mEmail;
	
	cout << "Enter the new service name: " << endl;
	getline (cin, mService);

	cout << "Enter the new username: " << endl;
	getline (cin, mUsername);

	cout << "Enter the new password: " << endl;
	getline (cin, mPassword);

	cout << "Enter the new email: " << endl;
	getline (cin, mEmail);



	for(size_t i = 0; i < accounts.size(); i++){
		if (accounts[i].getService() == serviceName){
			accounts[i].setService(mService);
			accounts[i].setUsername(mUsername);
			accounts[i].setPassword(mPassword);
			accounts[i].setEmail(mEmail);
			cout << "Account modified correctly." << endl;
		}
	}
}

void printMenu(){
	cout << "=== Account Manager ===" << endl;
	cout << "1. Add Account" << endl;
	cout << "2. Remove Account" << endl;
	cout << "3. Display All Accounts" << endl;
	cout << "4. Modify account" << endl;
	cout << "5. Exit" << endl;
	cout << "Enter your choice: ";
	cout << endl;
}

int main(){
	vector<Account> accounts;
	
	bool exit = false;
	int choice;
	while (!exit){
		printMenu();
		cout << endl;
		cin >> choice;
		
		switch (choice){
			case 1:
				cout << endl;
				addAccount(accounts);
				cout << endl;
				break;
			case 2:
				{
				string serviceName;
				cout << endl;
				cout << "Enter the service name to remove: "; 
				cin.ignore();
				getline(cin, serviceName);
				removeAccount(accounts,serviceName);
				cout << endl;
  				}
				break;
			
			case 3:
				cout << endl;
				displayAll(accounts);
				cout << endl;
				break;
			
			case 4:
				{
				string serviceName;
				cout << endl;
				cout << "Enter the service name to modify: ";
				cin.ignore();
				getline(cin, serviceName);
				displayAccount(accounts,serviceName);
				modifyAccount(accounts,serviceName);
				}
				break;
			case 5:
				cout << "Bye" << endl;
				exit = true;
				break;
			default:
				cout << "Invalid choice. Try again" << endl;
		}
	}	

	return 0;
}
