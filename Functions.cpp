#include "Functions.h"
#include<iostream>

using namespace std;

void mainWindow();

int main(){
	
	mainWindow();
	return 0;
}


void mainWindow(){
	int choice;
	do
	{
		system("cls");
		greetings();
		cout << "\t\t\t1. Admin   " 		<< endl;
		cout << "\t\t\t2. Customer  "      << endl;
		cout << "\t\t\t3. Employee " 	<< endl;
		cout << "\t\t\t4. Exit" 	<< endl;
		
		cout << "\t\t\tEnter choice : ";
		cin >> choice;
		
		user* obj ;	
		switch(choice){
			case 1 :
				{
					system("cls");
					greetings();
					cout << "\t\t\t\t\t\t______ADMIN PAGE______ \n\n";
					int chose;
					cout << "\t\t\t1. Login \n";
					cout << "\t\t\t2. Exit \n";
					
					cout << "\t\t\tEnter choice : ";
					cin >> chose;
					if(chose == 1){
						obj = new admin();
						obj->Login();
						break;
					}else if(chose == 2){
						break;
					}else{
						cout << "\t\t\tWrong Option !!" << endl;
						break;
					}
					break;	
				}
			case 2 : 
				{
					system("cls");
					greetings();
					cout << "\t\t\t\t\t\t______CUSTOMER PAGE______ \n\n";
					int chose;
					cout << "\t\t\t1. Login \n";
					cout << "\t\t\t2. sign Up \n";
					cout << "\t\t\t3. Exit \n";
					
					cout << "\t\t\tEnter choice : ";
					cin >> chose;
					if(chose == 1){
						obj = new member();
						obj->Login();
						break;
					}else if(chose == 2){
						obj = new member();
						obj->RegisterUser();
						break;
					}else if(chose == 3){
						break;
					}else{
						break;
					}
					break;
				}
			case 3 : 
				{
					system("cls");
					greetings();
					cout << "\t\t\t\t\t\t______EMPLOYEE PAGE______ \n\n";
					int chose;
					cout << "\t\t\t1. Login \n";
					cout << "\t\t\t2. Exit \n";
					
					cout << "\t\t\tEnter choice : ";
					cin >> chose;
					if(chose == 1){
						obj = new Employee();
						obj->Login();
						break;
					}else if(chose == 2){
						break;
					}else{
						cout << "\t\t\tWrong Option !!" << endl;
						break;
					}
					break;
				}
			case 5 : 
					cout << "\t\t\tExiting.....\n";
					break;
			default:
				cout << "\t\t\tOptions coming soon or invalid.\n";
		}
	}while(choice !=5);
}





