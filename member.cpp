#include"Functions.h"
void memberWindow();

void memberWindow() {
    int choice;
    do {
        system("cls");
        greetings();
        cout << "\t\t\t________ MEMBER MENU ________\n\n";
        cout << "\t\t\t1. View Profile" << endl;
        cout << "\t\t\t2. Recharge Membership" << endl;
        cout << "\t\t\t3. View Available Devices" << endl;
        cout << "\t\t\t4. Request Booking" << endl;
        cout << "\t\t\t5. Get Bills" << endl;
        cout << "\t\t\t6. Logout" << endl;

        cout << "\t\t\tEnter choice: ";
        cin >> choice;
        cin.ignore();
		member* obj = nullptr;
		Employee* eobj = nullptr;
		Device* dobj = nullptr;
        switch (choice) {
            case 1:
                system("cls");
            	greetings();
            	cout << "\t\t\t\t\t\t______YOUR PROFILE______ \n\n" << endl;
            	obj = new member();
                obj->ViewDetails();
                system("pause");
                break;

            case 2:
                system("cls");
                greetings();
            	cout << "\t\t\t\t\t\t______RECHARGING MEMBERSHIP______ \n\n" << endl;
            	obj = new member();
                obj->RechargeMembership();
                system("pause");
                break;

            case 3:
                system("cls");
            	greetings();
            	cout << "\t\t\t\t\t\t______AVAILABLE DEVICES______ \n\n" << endl;
            	eobj = new Employee();
                eobj->showAvailableDevices();
                system("pause");
                break;

            case 4:
                system("cls");
            	greetings();
            	cout << "\t\t\t\t\t\t______MEMBER REQUEST______ \n\n" << endl;
            	obj = new member();
                obj->SendRequest();
                system("pause");
                break;

            case 5:
                system("cls");
            	greetings();
            	cout << "\t\t\t\t\t\t______GENERATING BILL______ \n\n" << endl;
            	obj = new member();
                obj->GetBill();
                system("pause");
                break;

            case 6:
                cout << "Logged out succesfully !! ";
                system("pause");
                break;
                
            default:
                cout << "\n\t\t\tInvalid choice. Please try again.\n";
                system("pause");
        }
    } while (choice != 6);
    exit(0);
}

