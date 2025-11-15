#include<iostream>
#include<vector>
#include<fstream>
#include<exception>
#include<cstdlib>
#include<conio.h>
#include<string>

#include <algorithm>
#include <cctype>

static bool containsAvailable(const std::string &s) {
    std::string t = s;
    std::transform(t.begin(), t.end(), t.begin(), [](unsigned char c){ return std::tolower(c); });
    return t.find("available") != std::string::npos;
}

using namespace std;

void greetings(){
	
	cout << "\t\t\t****************************************************************************** " << endl;
    cout << "\t\t\t*                                                                            * " << endl;
	cout << "\t\t\t*                       Welcome To Galaxy Gamezone                           * " << endl;
    cout << "\t\t\t*                                                                            * " << endl;
	cout << "\t\t\t****************************************************************************** " << endl << endl;
	
}

class user{
	protected :
	string name; 
	string userName;
	string password;
	
	public :
	user(){
	}
	
	virtual  void Login() = 0;
	
	virtual	 void RegisterUser() = 0;
	~user(){
	}	
};

class admin : public user{
	
	public:
		admin(){
		}
		
		void Login(){
			
		string Iu,Ip;
		char ch;
		bool got = false;
		
		try {
		
			cout << "\t\t\tEnter the username : ";
			cin >> Iu;
			cout << "\t\t\tEnter the password : ";
			 
			while (true) {
	       		ch = _getch();
	
	        	if (ch == 13) break;  
	        	if (ch == 8 && !Ip.empty()) { 
		            Ip.pop_back();
		            cout << "\b \b";
        		} 
				else if (ch != 8) {
		            Ip += ch;
		            cout << '*';
       			}
    		}
			
			ifstream file("admin.txt",ios :: app);
			if(!file) throw 'a';
			static string n,u,p;
			while(getline(file , n ,'|') && 
					getline(file,u,'|') &&
					getline(file,p)){
				if(u==Iu && p == Ip){
					got = true ;
					break;
				}
			}
			file.close();
			if(got){
					cout << "\t\t\tLogin succesfully ! welcome " << n << ". \n";
					system("pause");
					system ("start admin.exe");
			}else{
				cout << "\t\t\tInvalide Username or password ! \n" ;
				system("pause");
			}
		}
		catch(const char){
			cout << "\t\t\tError : Uncable to open admin.txt for reading! \n";
		}	
	}
	
	void RegisterUser(){
		try {
			cout << "\t\t\tEnter the Name : ";
			cin.ignore(); 
			getline(cin,name);
			cout << "\t\t\tEnter the username : ";
			cin >> userName;
			cout << "\t\t\tEnter the password : ";
			string Ip;
			char ch;
			while (true) {
	       		ch = _getch();  
	
	        	if (ch == 13) break; 
	        	if (ch == 8 && !Ip.empty()) {  
		            Ip.pop_back();
		            cout << "\b \b";
        		} 
				else if (ch != 8) {
		            Ip += ch;
		            cout << '*';  
       			}
    		}
			password = Ip;
			
			ofstream file("admin.txt",ios :: app);
			if(!file) throw 'E';
			file << name << "|" << userName << "|" << password << endl ;
			file.close();
			cout << "\t\t\tAdmin Added Succcesfully !";
				
		}
		catch(const char) {
			cout << "\t\t\tUnable to open txt file for writing ! \n";
		} 	
	}
	
	void viewAdmin() {
        ifstream file("admin.txt");
        if (!file) {
            cout << "\t\t\tError opening employee file!" << endl;
            return;
        }
        
        string name, username, password;
        while (getline(file, name, '|') && getline(file, username, '|') && getline(file, password)) {
            cout << "\t\t\t_________________________";
            cout << "\n \t\t\tName: " << name 
				 << "\n\t\t\tUsername: " << username << "\n";
            cout << "\t\t\t_________________________\n\n";
        }
        file.close();
    }
	
	void removeAdmin() {
		string AdminUN;
		cout << "\t\t\tEnter the UserName : ";
		getline(cin,AdminUN);
		
        ifstream file("admin.txt");
        ofstream tempFile("temp.txt");
        if (!file || !tempFile) {
            cout << "\t\t\tError opening file!" << endl;
            return;
        }
        
        string name, username, password;
        bool found = false;

        while (getline(file, name, '|') && getline(file, username, '|') && getline(file, password)) {
            if (username != AdminUN) {
                tempFile << name << "|" << username << "|" << password << "\n";
            } else {
                found = true;
            }
        }

        file.close();
        tempFile.close();
        remove("admin.txt");
        rename("temp.txt", "admin.txt");
        
        if (found) {
            cout << "\t\t\tAdmin with username '" << AdminUN << "' has been removed!" << endl;
        } else {
            cout << "\t\t\tAdmin not found!" << endl;
        }
    }
	
	void viewEmployees() {
        ifstream file("employee.txt");
        if (!file) {
            cout << "\t\t\tError opening employee file!" << endl;
            return;
        }
        
        string name, username, password, salary, address, phone, status;
        while (getline(file, name, '|') && getline(file, username, '|') && getline(file, password, '|') &&
               getline(file, salary, '|') && getline(file, address, '|') && getline(file, phone, '|') &&
               getline(file, status)) {
            cout << "\t\t\t_________________________";
            cout << "\n \t\t\tName: " << name << "\n\t\t\tUsername: " << username
                 << "\n\t\t\tSalary: " << salary
                 << "\n\t\t\tAddress: " << address
                 << "\n\t\t\tPhone: " << phone
                 << "\n\t\t\tStatus: " << status << "\n";
            cout << "\t\t\t_________________________\n\n";
        }
        file.close();
    }
	
	void removeEmployee() {
		string empUsername;
		cout << "\t\t\tEnter the UserName : ";
		cin.ignore();
		getline(cin,empUsername);
		
        ifstream file("employee.txt");
        ofstream tempFile("temp.txt");
        if (!file || !tempFile) {
            cout << "\t\t\tError opening file!" << endl;
            return;
        }
        
        string name, username, password, salary, address, phone, status;
        bool found = false;

        while (getline(file, name, '|') && getline(file, username, '|') && getline(file, password, '|') &&
               getline(file, salary, '|') && getline(file, address, '|') && getline(file, phone, '|') &&
               getline(file, status)) {
            if (username != empUsername) {
                tempFile << name << "|" << username << "|" << password << "|" << salary << "|" << address << "|"
                         << phone << "|" << status << "\n";
            } else {
                found = true;
            }
        }

        file.close();
        tempFile.close();
        remove("employee.txt");
        rename("temp.txt", "employee.txt");
        
        if (found) {
            cout << "\t\t\tEmployee with username '" << empUsername << "' has been removed!" << endl;
        } else {
            cout << "\t\t\tEmployee not found!" << endl;
        }
    }
	
	void changeEmployeeStatus() {
		string empUsername,newStatus;
        cout << "\t\t\tEnter employee username: ";
        cin >> empUsername;
        cout << "\t\t\tEnter new status: ";
        cin.ignore();
        getline(cin,newStatus);
        
        ifstream file("employee.txt");
        ofstream tempFile("temp.txt");
        if (!file || !tempFile) {
            cout << "\t\t\tError opening file!" << endl;
            return;
        }
        
        string name, userName, password, salary, address, phone, status;
        bool found = false;

        while (getline(file, name, '|') && getline(file, userName, '|') && getline(file, password, '|') &&
               getline(file, salary, '|') && getline(file, address, '|') && getline(file, phone, '|') &&
               getline(file, status)) {
            if (userName == empUsername) {
                status = newStatus; 
                found = true;
            }
            tempFile << name << "|" << userName << "|" << password << "|" << salary << "|" << address << "|"
                     << phone << "|" << status << "\n";
        }

        file.close();
        tempFile.close();
        
        if (found) {
            remove("employee.txt");
            rename("temp.txt", "employee.txt");
            cout << "\t\t\t" << empUsername << "'s status changed to " << newStatus << endl;
        } else {
            cout << "\t\t\tEmployee not found!" << endl;
        }
    }

	void viewReports() {
        ifstream file("employee_reports.txt");
        if (!file) {
            cout << "\t\t\tError opening reports file!" << endl;
            return;
        }
        
        string empName,empId,report;
        cout << "\t\t\tEmployee Reports:\n";
        int i = 1;
        while (getline(file, empName,'|') && getline(file, empId,'|') && getline(file, report) ) {
            cout << "\t\t\tReport " << i << ": " << endl;
            cout << "\t\t\tEmployee Name : " << empName << "\n\t\t\tEmployee ID : " << empId
            		<< "\n\t\t\tReport : " << report << "\n\n";
            i++;
        }
        file.close();
    }
	 
	void viewMembers() {
        ifstream file("member.txt");
        if (!file) {
            cout << "\t\t\tError opening members file!" << endl;
            return;
        }
        
        string name, username, password, phone,membershipStatus,balance;
        while (getline(file, name, '|') && getline(file, username, '|') && 
			getline(file, password, '|') && getline(file, phone, '|') && getline(file, membershipStatus,'|') && getline(file, balance)) {
            cout << "\t\t\t_________________________\n";
            cout << "\t\t\tName : " << name << "\n\t\t\tUsername: " << username
            	 << "\n\t\t\tPhone No : " << phone
                 << "\n\t\t\tMembership Status : " << membershipStatus 
				 << "\n\t\t\tbalance : " << balance;
            cout << "\n\t\t\t_________________________\n\n";
        }
        file.close();
    }
	 
	 void removeMember() {
	 	string memUsername;
	 	cout << "\t\t\tEnter Username to remove : ";
	 	cin >> memUsername;
        ifstream file("member.txt");
        ofstream tempFile("tempMembers.txt");
        if (!file || !tempFile) {
            cout << "\t\t\tError opening file!" << endl;
            return;
        }
		bool found = false;
        string name, username, password, phone,membershipStatus,balance;
        while (getline(file, name, '|') && getline(file, username, '|') && 
			getline(file, password, '|') && getline(file, phone, '|') && getline(file, membershipStatus,'|') && getline(file, balance)) {
            if (username != memUsername) {
                tempFile << name << "|" << username << "|" << password << "|" << phone << "|"<< membershipStatus << "|" << balance << "\n";
            } else {
                found = true;
            }
        }
		
        file.close();
        tempFile.close();

        if (found) {
            remove("member.txt");
            rename("tempMembers.txt", "member.txt");
            cout << "\t\t\tMember with username: " << memUsername << " has been removed!" << endl;
            system("pause");
        } else {
            cout << "\t\t\tMember not found!" << endl;
        }
    }
	 
	void updateMembership() {
	    string usernameToUpdate, newMembership;
	    cout << "\t\t\tEnter the username of the member: ";
	    cin >> usernameToUpdate;
	    cout << "\t\t\tEnter new membership type (Gold/Silver/Platinum/Inactive): ";
	    cin >> newMembership;
	
	    ifstream file("member.txt");
	    ofstream tempFile("temp_members.txt");
	
	    if (!file || !tempFile) {
	        cout << "\t\t\tError opening file!" << endl;
	        return;
	    }
	
	    string name, username, password, phone, membershipType,balance;
	    bool found = false;
	
	    while (getline(file, name, '|') &&
	           getline(file, username, '|') &&
	           getline(file, password, '|') &&
	           getline(file, phone, '|') &&
	           getline(file, membershipType, '|')&&
	           getline(file, balance)) {
	        
	        if (username == usernameToUpdate) {
	            membershipType = newMembership;
	            found = true;
	        }
	
	        tempFile << name << "|" << username << "|" << password << "|" << phone << "|" << membershipType << "|" << balance << '\n';
	    }
	
	    file.close();
	    tempFile.close();
	
	    if (found) {
	        remove("member.txt");
	        rename("temp_members.txt", "member.txt");
	        cout << "\t\t\tMembership updated successfully for user: " << usernameToUpdate << endl;
	    } else {
	        remove("temp_members.txt");
	        cout << "\t\t\tMember with username '" << usernameToUpdate << "' not found." << endl;
	    }
	}

	 	
	~admin(){
	}
};

class member : public user{
	
	public :
	string MembershipType,phone,balance;
	member(){
	}	
		void Login(){
			
		string Iu,Ip;
		char ch;
		bool got = false;
		
		try {
		
			cout << "\t\t\tEnter the username : ";
			cin >> Iu;
			cout << "\t\t\tEnter the password : ";
			 
			while (true) {
	       		ch = _getch(); 
	
	        	if (ch == 13) break; 
	        	if (ch == 8 && !Ip.empty()) { 
		            Ip.pop_back();
		            cout << "\b \b";
        		} 
				else if (ch != 8) {
		            Ip += ch;
		            cout << '*'; 
       			}
    		}
			
			ifstream file("member.txt",ios :: app);
			if(!file) throw 'a';
			static string n;
			while(getline(file , n ,'|') && 
					getline(file, userName, '|') &&
					getline(file, password, '|') &&
					getline(file, phone, '|') 	&& 
					getline(file,MembershipType) &&
					getline(file,balance)){
				if(userName==Iu && password == Ip){
					got = true ;
					break;
				}
			}
			file.close();
			if(got){
					cout << "\t\t\tLogin succesfully ! welcome " << n << ". \n";
					system("pause");
					system ("start member.exe");
			}else{
				cout << "\t\t\tInvalide Username or password ! \n" ;
				system("pause");
			}
		}
		catch(const char){
			cout << "\t\t\tError : Uncable to open member.txt for reading! \n";
		}	
	}
	
	void RegisterUser(){
		try {
			cout << "\t\t\tEnter the Name : ";
			cin.ignore(); 
			getline(cin,name);
			cout << "\t\t\tEnter the username : ";
			cin >> userName;
			cout << "\t\t\tEnter the password : ";
			string Ip;
			char ch;
			while (true) {
	       		ch = _getch();  
	
	        	if (ch == 13) break; 
	        	if (ch == 8 && !Ip.empty()) {  
		            Ip.pop_back();
		            cout << "\b \b";
        		} 
				else if (ch != 8) {
		            Ip += ch;
		            cout << '*';  
       			}
    		}
			password = Ip;
			cout << "\t\t\tEnter phone number :";
			cin.ignore(); 
			getline(cin,phone);
			cout << "\t\t\tEnter Membership Tpye :";
			cin.ignore(); 
			getline(cin,MembershipType);
			cout << "\t\t\tEnter Balance (minimum 500) :";
			cin.ignore(); 
			getline(cin,balance);
			ofstream file("member.txt",ios :: app);
			if(!file) throw 'E';
			file << name << "|" << userName << "|" << password << "|"  << phone << "|" << MembershipType << "|" << balance << endl ;
			file.close();
			cout << "\t\t\tsuccess";
			system("pause");
		
		}
		catch(const char) {
			cout << "\t\t\tUnable to open txt file for writing ! \n";
		} 	
	}
	
	void ViewDetails() {
	    ifstream file("member.txt");
	    if (!file) {
	        cout << "\t\t\tError: Unable to open employee.txt file!\n";
	        return;
	    }
		string u;
		cout << "\t\t\tEnter The Username : " ;
		getline(cin,u);
	    bool found = false;
	    while (getline(file, name, '|') && getline(file, userName, '|') && getline(file, password, '|') &&
	           getline(file, phone, '|') && getline(file, MembershipType , '|') &&
	           getline(file, balance)) {
	        if (userName == u ) {
	            found = true;
	            cout << "\t\t\t_________________________\n";
	            cout << "\t\t\tName     : " << name << "\n";
	            cout << "\t\t\tUsername : " << userName << "\n";
	            cout << "\t\t\tpassword : " << password << "\n";
	            cout << "\t\t\tphone no : " << phone << "\n";
	            cout << "\t\t\tMembershipType   : " << MembershipType << "\n";
	            cout << "\t\t\tBalance   : " << balance << "\n";
	            cout << "\t\t\t_________________________\n";
	            break;
	          
		    }
	    }
	
	    if (!found) {
	        cout << "\t\t\tMember  details not found!\n";
	    }
	
	    file.close();
	}
	
	void showAvailableDevices(){
	    ifstream file("device.txt");
	    if (!file) {
	        cout << "\t\t\tError opening device file!" << endl;
	        return;
	    }
	    string id, type, price, status, availability;
	    while (getline(file, id, '|') && getline(file, type, '|') && getline(file, price, '|') &&
	           getline(file, status, '|') && getline(file, availability)) {
	           	if (containsAvailable(availability)){
	           		cout << "\t\t\t_________________________\n";
		       		cout << "\t\t\tID: " << id << "\n\t\t\tType: " << type
		             << "\n\t\t\tPrice per Hour: " << price
		             << "\n\t\t\tStatus: " << status
		             << "\n\t\t\tAvailability: " << availability << "\n";
		          	cout << "\t\t\t_________________________\n\n";
				}
	    }
	
	    file.close();
	}
	
	void RechargeMembership(){
		string memUsername;
		int recharge;
        cout << "\t\t\tEnter  username: ";
        getline(cin,memUsername);
        cout << "\t\t\tEnter amount : ";
        cin >> recharge;
        
        ifstream file("member.txt");
        ofstream tempFile("temp.txt");
        if (!file || !tempFile) {
            cout << "\t\t\tError opening file!" << endl;
            return;
        }
        
        bool found = false;

       while (getline(file, name, '|') && getline(file, userName, '|') && getline(file, password, '|') &&
	           getline(file, phone, '|') && getline(file, MembershipType , '|') &&
	           getline(file, balance)) {
	           	
            if (memUsername == userName) {
            	
                int bal = stoi(balance); 
                bal += recharge;
                balance = to_string(bal);
                found = true;
            }
            tempFile << name << "|" << userName << "|" << password << "|" << phone << "|" << MembershipType << "|"
                     << balance  << "\n";
        }

        file.close();
        tempFile.close();
        
        if (found) {
            remove("member.txt");
            rename("temp.txt", "member.txt");
            cout << "\t\t\t" << memUsername << "'s balance changed " << endl;
        } else {
            cout << "\t\t\tEmployee not found!" << endl;
        }
	}
	
	void GetBill() {
	    cout << "\t\t\tEnter your Username: ";
	    getline(cin, userName);
	
	    ifstream file("bills.txt");
	    if (!file) {
	        cout << "\t\t\tError opening bills.txt!" << endl;
	        return;
	    }
	
	    string name, user, deviceID, deviceType, duration, pricePerHour, total;
	    bool found = false;
	
	    cout << "\n\t\t\t_________ Your Bill(s) __________\n\n";
	
	    while (
	        getline(file, name, '|') &&
	        getline(file, user, '|') &&
	        getline(file, deviceID, '|') &&
	        getline(file, deviceType, '|') &&
	        getline(file, duration, '|') &&
	        getline(file, pricePerHour, '|') &&
	        getline(file, total)
	    ) {
	        if (user == userName) {
	            found = true;
	            cout << "\t\t\t-------------------------------\n";
	            cout << "\t\t\tName           : " << name << endl;
	            cout << "\t\t\tUsername       : " << user << endl;
	            cout << "\t\t\tDevice ID      : " << deviceID << endl;
	            cout << "\t\t\tDevice Type    : " << deviceType << endl;
	            cout << "\t\t\tDuration       : " << duration << " hour(s)" << endl;
	            cout << "\t\t\tPrice per Hour : " << pricePerHour << endl;
	            cout << "\t\t\tTotal Amount (with discount)  : " << total << endl;
	            cout << "\t\t\t-------------------------------\n";
	        }
	    }
	
	    file.close();
	
	    if (!found) {
	        cout << "\t\t\tNo bills found for this username.\n";
	    }
	}

	
	void SendRequest(){
	    string name, id, deviceID, type, duration;
	
	    cin.ignore(); 
	    cout << "\t\t\tEnter your name: ";
	    getline(cin, name);
	    cout << "\t\t\tEnter your ID: ";
	    getline(cin, id);
	    cout << "\t\t\tEnter Device ID to book: ";
	    getline(cin, deviceID);
	    cout << "\t\t\tEnter Device Type (PC/Console): ";
	    getline(cin, type);
	    cout << "\t\t\tEnter Duration (hours): ";
	    getline(cin, duration);
	
	    ofstream File("requests.txt");
	    if (!File) {
	        cout << "\t\t\tError opening requests.txt file!" << endl;
	        return;
	    }
	
	   	File << name << "|" << id << "|" << deviceID << "|" << type << "|" << duration << "\n";
	    File.close();
	
	    cout << "\t\t\tBooking request sent successfully!\n";
	}
	
	~member(){
	}
};

class Employee : public user{
	
	protected:
	string  address, phone, salary, status;
	
	public:
			
	void Login(){
		
		string Iu,Ip;
		char ch;
		bool got = false;
		
		try {
		
			cout << "\t\t\tEnter the username : ";
			cin >> Iu;
			cout << "\t\t\tEnter the password : ";
			 
			while (true) {
	       		ch = _getch(); 
	
	        	if (ch == 13) break;  
	        	if (ch == 8 && !Ip.empty()) { 
		            Ip.pop_back();
		            cout << "\b \b";
        		} 
				else if (ch != 8) {
		            Ip += ch;
		            cout << '*'; 
       			}
    		}
			
			ifstream file("employee.txt",ios :: app);
			if(!file) throw 'a';
			static string n;
	        while (getline(file, n, '|') && getline(file, userName, '|') && getline(file, password, '|') &&
               getline(file, salary, '|') && getline(file, address, '|') && getline(file, phone, '|') &&
               getline(file, status)){
				if(Iu==userName &&  Ip == password ){
					got = true ;
					break;
				}
			}
			file.close();
			if(got){
					cout << "\t\t\tLogin succesfully ! welcome " << n << ". \n";
					system("pause");
					system ("start Employee.exe");
			}else{
				cout << "\t\t\tInvalide Username or password ! \n" ;
				system("pause");
			}
		}
		catch(const char){
			cout << "\t\t\tError : Uncable to open member.txt for reading! \n";
		}	
	}
	
	void RegisterUser(){
		try {
			cout << "\t\t\tEnter the Name : ";
			cin.ignore(); 
			getline(cin,name);
			cout << "\t\t\tEnter the username : ";
			cin >> userName;
			cout << "\t\t\tEnter the password : ";
			string Ip;
			char ch;
			while (true) {
	       		ch = _getch();  
	
	        	if (ch == 13) break; 
	        	if (ch == 8 && !Ip.empty()) {  
		            Ip.pop_back();
		            cout << "\b \b";
        		} 
				else if (ch != 8) {
		            Ip += ch;
		            cout << '*';  
       			}
    		}
			password = Ip;
			cout << "\n\t\t\tEnter Adress : ";
			cin.ignore();
			getline(cin,address);
			cout << "\t\t\tEnter Phone Number : ";
			cin.ignore();
			getline(cin,phone);
			salary = "6000";
			status = "Working";
			
			ofstream file("employee.txt",ios :: app);
			if(!file) throw 'E';
			file << name << "|" << userName << "|" << password
				 << "|" << salary << "|" << address << "|" << phone << "|" << status << endl ;
			file.close();
			cout << "\t\t\tEMPLOYEE ADDED SUCCESFULLY";
			system("pause");	
		}
		catch(const char) {
			cout << "\t\t\tUnable to open txt file for writing ! \n";
		} 	
	}
	
	void ViewDetails() {
	    ifstream file("employee.txt");
	    if (!file) {
	        cout << "\t\t\tError: Unable to open employee.txt file!\n";
	        return;
	    }
		
		cout << "\t\t\tEnter The Username : " ;
		getline(cin,userName);
	    string n, u, p, s, a, ph, st;
	    bool found = false;
	
	    while (getline(file, n, '|') && getline(file, u, '|') && getline(file, p, '|') &&
	           getline(file, s, '|') && getline(file, a, '|') && getline(file, ph, '|') &&
	           getline(file, st)) {
	        if (u == userName) {
	            found = true;
	            cout << "\t\t\t_________________________\n";
	            cout << "\t\t\tName     : " << n << "\n";
	            cout << "\t\t\tUsername : " << u << "\n";
	            cout << "\t\t\tSalary   : " << s << "\n";
	            cout << "\t\t\tAddress  : " << a << "\n";
	            cout << "\t\t\tPhone    : " << ph << "\n";
	            cout << "\t\t\tStatus   : " << st << "\n";
	            cout << "\t\t\t_________________________\n";
	            break;
		    }
	    }
	
	    if (!found) {
	        cout << "\t\t\tEmployee details not found!\n";
	    }
	
	    file.close();
	}

	
	void showAvailableDevices(){
	    ifstream file("device.txt");
	    if (!file) {
	        cout << "\t\t\tError opening device file!" << endl;
	        return;
	    }
	    string id, type, price, status, availability;
	    while (getline(file, id, '|') && getline(file, type, '|') && getline(file, price, '|') &&
	           getline(file, status, '|') && getline(file, availability)) {
	           	if (containsAvailable(availability)){
	           		cout << "\t\t\t_________________________\n";
		       		cout << "\t\t\tID: " << id << "\n\t\t\tType: " << type
		             << "\n\t\t\tPrice per Hour: " << price
		             << "\n\t\t\tStatus: " << status
		             << "\n\t\t\tAvailability: " << availability << "\n";
		          	cout << "\t\t\t_________________________\n\n";
				}
	    }
	
	    file.close();
	}
	
	void ShowRequest() {
    ifstream file("requests.txt");
	    if (!file) {
	        cout << "\t\t\tError: Unable to open requests.txt!\n";
	        return;
	    }
	
	    string mname, mid, did, dtype, duration;
	    int count = 0;
	
	    while (getline(file, mname, '|') && getline(file, mid, '|') && getline(file, did, '|') &&
	           getline(file, dtype, '|') && getline(file, duration)) {
	        cout << "\t\t\t_________________________\n";
	        cout << "\t\t\tMember Name  : " << mname << "\n";
	        cout << "\t\t\tMember ID    : " << mid << "\n";
	        cout << "\t\t\tDevice ID    : " << did << "\n";
	        cout << "\t\t\tDevice Type  : " << dtype << "\n";
	        cout << "\t\t\tDuration (h) : " << duration << "\n";
	        cout << "\t\t\t_________________________\n\n";
	        count++;
	    }
	
	    if (count == 0) {
	        cout << "\t\t\tNo booking requests found!\n";
	    }
	
	    file.close();
	}

	
void GenerateBill() {
    ifstream reqFile("requests.txt");
    if (!reqFile) {
        cout << "\t\t\tError: Unable to open requests.txt!\n";
        return;
    }

    vector<string> updatedRequests;
    string mname, mid, did, dtype, duration;
    bool anyBill = false;

    while (getline(reqFile, mname, '|') && getline(reqFile, mid, '|') &&
           getline(reqFile, did, '|') && getline(reqFile, dtype, '|') && getline(reqFile, duration)) {

        ifstream devFile("device.txt");
        if (!devFile) {
            cout << "\t\t\tError: Unable to open device.txt!\n";
            return;
        }

        string d_id, d_type, price, d_status, avail;
        bool found = false;
        vector<string> updatedDevices;

        while (getline(devFile, d_id, '|') && getline(devFile, d_type, '|') &&
               getline(devFile, price, '|') && getline(devFile, d_status, '|') && getline(devFile, avail)) {

            if (d_id == did) {
                found = true;
                int rate = stoi(price);
                int hrs = stoi(duration);
                int total = rate * hrs;

                // Load member details to find balance and membership type
                ifstream memFile("member.txt");
                if (!memFile) {
                    cout << "\t\t\tError: Unable to open member.txt!\n";
                    return;
                }

                string name, id, pass, phone, memtype, balance;
                vector<string> updatedMembers;
                bool memberFound = false;
                float finalTotal = total;

                while (getline(memFile, name, '|') && getline(memFile, id, '|') &&
                       getline(memFile, pass, '|') && getline(memFile, phone, '|') &&
                       getline(memFile, memtype, '|') && getline(memFile, balance)) {

                    if (id == mid) {
                        memberFound = true;
                        int bal = stoi(balance);

                        // Apply discount based on membership type
                        if (memtype == "Platinum") {
                            finalTotal = total * 0.7;
                        } else if (memtype == "Gold") {
                            finalTotal = total * 0.8;
                        }else if (memtype == "Silver") {
                            finalTotal = total * 0.9;
                        } else {
                            finalTotal = total * 1;
                        }

                        if (bal < finalTotal) {
                            cout << "\t\t\tInsufficient balance for Member ID " << mid << ". Skipping billing.\n";
                            updatedRequests.push_back(mname + "|" + mid + "|" + did + "|" + dtype + "|" + duration);
                            found = false;  // Revert device update
                            break;
                        }

                        // Deduct bill from balance
                        bal -= finalTotal;
                        balance = to_string(bal);
                    }

                    updatedMembers.push_back(name + "|" + id + "|" + pass + "|" + phone + "|" + memtype + "|" + balance);
                }

                memFile.close();

                if (!memberFound || !found) break;

                // Write updated member balances
                ofstream memOut("member.txt");
                for (const string& line : updatedMembers) {
                    memOut << line << "\n";
                }
                memOut.close();

                // Write bill
                ofstream billFile("bills.txt", ios::app);
                if (!billFile) {
                    cout << "\t\t\tError: Unable to write to bills.txt!\n";
                    return;
                }

                billFile << mname << "|" << mid << "|" << did << "|" << dtype << "|"
                         << hrs << "|" << rate << "|" << static_cast<int>(finalTotal) << "\n";
                billFile.close();

                // Show bill
                cout << "\t\t\t__________ BILL __________\n";
                cout << "\t\t\tMember Name  : " << mname << "\n";
                cout << "\t\t\tMember ID    : " << mid << "\n";
                cout << "\t\t\tDevice ID    : " << did << "\n";
                cout << "\t\t\tDevice Type  : " << dtype << "\n";
                cout << "\t\t\tRate/hour    : " << rate << "\n";
                cout << "\t\t\tDuration (h) : " << hrs << "\n";
                cout << "\t\t\tMembership   : " << memtype << "\n";
                cout << "\t\t\tTOTAL BILL   : ?" << static_cast<int>(finalTotal) << "\n";
                cout << "\t\t\t_________________________\n\n";

                // Mark device unavailable
                avail = "Not available";
            }

            updatedDevices.push_back(d_id + "|" + d_type + "|" + price + "|" + d_status + "|" + avail);
        }

        devFile.close();

        // Rewrite device file
        ofstream devOut("device.txt");
        for (const string& line : updatedDevices) {
            devOut << line << "\n";
        }
        devOut.close();

        // If bill not generated, keep the request
        if (!found) {
            updatedRequests.push_back(mname + "|" + mid + "|" + did + "|" + dtype + "|" + duration);
        } else {
            anyBill = true;
        }
    }

    reqFile.close();
    
    ofstream reqOut("requests.txt");
    for (const string& line : updatedRequests) {
        reqOut << line << "\n";
    }
    reqOut.close();

    if (!anyBill) {
        cout << "\t\t\tNo valid requests were billed.\n";
    }
}


	
	void GiveReorts(){
        ofstream file("employee_reports.txt");
        string empName,empId,report;
        if (!file) {
            cout << "\t\t\tError opening reports file!" << endl;
            return;
        }
        cout << "\t\t\tEnter the Name : " ;
        cin.ignore();
        getline(cin,empName);
        cout << "\t\t\tEnter the Username : " ;
        cin.ignore();
        getline(cin,empId);
		cout << "\t\t\tEnter the Report : " ;
        cin.ignore();
        getline(cin,report);
        
        file << empName << "|" << empId << "|" << report << "\n";
        file.close();
        
        cout << "\n\t\t\tRepot addedd succesfully !!";
	}
	
	~Employee(){}
};

class Games {
private:
    string ID;
    string Name;
    string deviceType;
    string genre;
    int maxPlayers;

public:
    void addGame(){
    	greetings();
	    cout << "\t\t\t\t\t\t______ADDING GAMES______ \n\n";
	    ofstream file("games.txt", ios::app);
	    if (!file) {
	        cout << "\t\t\tError: Could not open file.\n";
	        return;
	    }
	
	    cout << "\t\t\tEnter Game ID: ";
	    getline(cin, ID);
	    cout << "\t\t\tEnter Game Name : ";
	    getline(cin, Name);
	    cout << "\t\t\tEnter Device Type: ";
	    getline(cin, deviceType);
	    cout << "\t\t\tEnter Genre: ";
	    getline(cin, genre);
	    cout << "\t\t\tEnter Max Players: ";
	    cin >> maxPlayers;
	    cin.ignore();
	
	    file << ID << "|" << Name << "|" << deviceType << "|" << genre << "|" << maxPlayers << "\n";
	    file.close();
	    cout << "\t\t\tGame added successfully.\n";
	}  
	     
    void showGames(){
	    ifstream file("games.txt");
	    if (!file) {
	        cout << "\t\t\tError: Could not open file.\n";
	        return;
	    }
		greetings();
	    cout << "\t\t\t\t\t\t______SHOWING GAMES______ \n\n";
	    string id, name, device, genre,players;
	    
	    while(getline(file, id, '|') && 
				getline(file, name, '|') &&
				getline(file, device, '|') && 
				getline(file, genre, '|') && 
				getline(file,players)) {
	        
	        cout << "\t\t\t--------------------------\n";
	        cout << "\t\t\tID          : " << id << "\n";
	        cout << "\t\t\tName        : " << name << "\n";
	        cout << "\t\t\tDevice Type : " << device << "\n";
	        cout << "\t\t\tGenre       : " << genre << "\n";
	        cout << "\t\t\tMax Players : " << players << "\n";
	        cout << "\t\t\t--------------------------\n\n\n";
	    }	
	    file.close();
	}    
    void removeGame() {
	    string targetID;
	    greetings();
	    cout << "\t\t\t\t\t\t______REMOVING GAMES______ \n\n";
	    cout << "\t\t\tEnter Game ID to remove: ";
	    getline(cin, targetID);
	
	    ifstream file("games.txt");
	    ofstream temp("temp.txt");
	    bool found = false;
	
	    string id, name, device, g, players;
	    while (getline(file, id, '|') &&
	           getline(file, name, '|') &&
	           getline(file, device, '|') &&
	           getline(file, g, '|') &&
	           getline(file, players)) {
	        
	        if (id != targetID) {
	            temp << id << "|" << name << "|" << device << "|" << g << "|" << players << "\n";
	        } else {
	            found = true;
	        }
	    }
	
	    file.close();
	    temp.close();
	    remove("games.txt");
	    rename("temp.txt", "games.txt");
	
	    if (found)
	        cout << "\t\t\tGame removed successfully.\n";
	    else
	        cout << "\t\t\tGame ID not found.\n";
	}
    void updateGame() {
    
		string targetID;
		greetings();
	    cout << "\t\t\t\t\t\t______UPDATING GAMES______ \n\n";
	    cout << "\t\t\tEnter Game ID to update: " << endl;
	    getline(cin, targetID);
	
	    ifstream file("games.txt");
	    ofstream temp("temp.txt");
	    bool found = false;
	
	    string id, name, device, g, players;
	    while (getline(file, id, '|') &&
	           getline(file, name, '|') &&
	           getline(file, device, '|') &&
	           getline(file, g, '|') &&
	           getline(file, players)) {
	           	
	        if (targetID == id) {
	            found = true;
	            cout << "\t\t\tEnter new Name: ";
	            getline(cin, name);
	            cout << "\t\t\tEnter new Device Type: ";
	            getline(cin, device);
	            cout << "\t\t\tEnter new Genre: ";
	            getline(cin, g);
	            cout << "\t\t\tEnter new Max Players: ";
	            getline(cin, players);
	        }
	        temp << id << "|" << name << "|" << device << "|" << g << "|" << players << "\n";
	    }
	    file.close();
	    temp.close();
	    remove("games.txt");
	    rename("temp.txt", "games.txt");
	
	    if (found)
	        cout << "\t\t\tGame updated successfully.\n";
	    else
	        cout << "\t\t\tGame ID not found.\n";
	}
	 
};

class Device {
private:
    string id;
    string type;  
    float pricePerHour;
    string status;
    string availability;

public:
    void addDevice() {
    	greetings();
	    cout << "\t\t\t\t\t\t______ADDING DEVICE______ \n\n";
	    ofstream file("device.txt", ios::app);
	    if (!file) {
	        cout << "\t\t\tError opening device file!" << endl;
	        return;
	    }
	
	    cin.ignore();
	    cout << "\t\t\tEnter ID: ";
	    getline(cin, id);
	    cout << "\t\t\tEnter Type (PC/Console): ";
	    getline(cin, type);
	    cout << "\t\t\tEnter Price per Hour: ";
	    cin >> pricePerHour;
	    cin.ignore();
	    cout << "\t\t\tEnter Status (Working/Not Working): ";
	    getline(cin, status);
	    cout << "\t\t\tEnter Availability (Available/Occupied): ";
	    getline(cin, availability);
	
	    file << id << "|" << type << "|" << pricePerHour << "|" << status << "|" << availability << "\n";
	    file.close();
	
	    cout << "\n\t\t\tDevice added successfully!";
	}
	
    void showDevices(){
    	greetings();
	    cout << "\t\t\t\t\t\t______SHOWING DEVICE______ \n\n";
	    ifstream file("device.txt");
	    if (!file) {
	        cout << "\t\t\tError opening device file!" << endl;
	        return;
	    }
	    string id, type, price, status, availability;
	    while (getline(file, id, '|') && getline(file, type, '|') && getline(file, price, '|') &&
	           getline(file, status, '|') && getline(file, availability)) {
	           	cout << "\t\t\t_________________________\n";
	       		cout << "\t\t\tID: " << id << "\n\t\t\tType: " << type
	             << "\n\t\t\tPrice per Hour: " << price
	             << "\n\t\t\tStatus: " << status
	             << "\n\t\t\tAvailability: " << availability << "\n";
	          	cout << "\t\t\t_________________________\n\n";
	    }
	
	    file.close();
	}
	
    void removeDevice(){
    	greetings();
	    cout << "\t\t\t\t\t\t______REMOVING DEVICE______ \n\n";
	    ifstream file("device.txt");
	    ofstream temp("temp.txt");
	
	    if (!file || !temp) {
	        cout << "\n\t\t\tError opening files!";
	        return;
	    }
	
	    string delID;
	    cout << "\n\t\t\tEnter Device ID to remove: ";
	    cin.ignore();
	    getline(cin, delID);
	
	    string id, type, price, status, availability;
	    bool found = false;
	
	    while (getline(file, id, '|') && getline(file, type, '|') && getline(file, price, '|') &&
	           getline(file, status, '|') && getline(file, availability)) {
	        if (id != delID) {
	            temp << id << "|" << type << "|" << price << "|" << status << "|" << availability << "\n";
	        } else {
	            found = true;
	        }
	    }
	
	    file.close();
	    temp.close();
	    remove("device.txt");
	    rename("temp.txt", "device.txt");
	
	    if (found)
	        cout << "\n\t\t\tDevice removed successfully!";
	    else
	        cout << "\n\t\t\tDevice ID not found!";
	}
	
    void showNotWorkingDevices(){
    	greetings();
	    cout << "\t\t\t\t\t\t______SHOWING OUT OF ORDER DEVICES DEVICE______ \n\n";
	    ifstream file("device.txt");
	    if (!file) {
	        cout << "\n\t\t\tError opening device file!";
	        return;
	    }
	
	    string id, type, price, status, availability;
	    
	    while (getline(file, id, '|') && getline(file, type, '|') && getline(file, price, '|') &&
	           getline(file, status, '|') && getline(file, availability)) {
	        if (status == "Not working" || status == "not working" || availability == "Not available" || availability == "not available") {
	        	cout << "\t\t\t_________________________\n";
	            cout << "\t\t\tID: " << id << "\n\t\t\tType: " << type
	                 << "\n\t\t\tPrice per Hour: " << price
	                 << "\n\t\t\tStatus: " << status
	                 << "\n\t\t\tAvailability: " << availability << "\n";
	            cout << "\t\t\t_________________________\n\n";
	        }
	    }
	
	    file.close();
	}
	
	void updateDevice(){
    	greetings();
	    cout << "\t\t\t\t\t\t______UPDATING DEVICE______ \n\n";
	    ifstream file("device.txt");
	    ofstream temp("temp.txt");
	
	    if (!file || !temp) {
	        cout << "\n\t\t\tError opening files!";
	        return;
	    }
	
	    string updateID;
	    cout << "\n\t\t\tEnter Device ID to update: ";
	    cin.ignore();
	    getline(cin, updateID);
	
	    string id, type, price, status, availability;
	    bool found = false;
	
	    while (getline(file, id, '|') && getline(file, type, '|') && getline(file, price, '|') &&
	           getline(file, status, '|') && getline(file, availability)) {
	
	        if (id == updateID) {
	            found = true;
	            cout << "\n\t\t\t--- Current Details ---\n";
	            cout << "\t\t\tID: " << id << "\n\t\t\tType: " << type
	                 << "\n\t\t\tPrice per Hour: " << price
	                 << "\n\t\t\tStatus: " << status
	                 << "\n\t\t\tAvailability: " << availability << "\n\n";
	            cout << "\t\t\tEnter New Status (Working/Not Working): ";
	            getline(cin, status);
	            cout << "\t\t\tEnter New Availability (Available/Occupied): ";
	            getline(cin, availability);
	
	            temp << id << "|" << type << "|" << price << "|" << status << "|" << availability << "\n";
	        } else {
	            temp << id << "|" << type << "|" << price << "|" << status << "|" << availability << "\n";
	        }
	    }
	
	    file.close();
	    temp.close();
	    remove("device.txt");
	    rename("temp.txt", "device.txt");
	
	    if (found)
	        cout << "\n\t\t\tDevice updated successfully!";
	    else
	        cout << "\n\t\t\tDevice ID not found!";
	}
};

