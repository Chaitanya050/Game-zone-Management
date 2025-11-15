 #include "Functions.h"

void EmployeeWindow();

void EmployeeWindow() {
    int choice;
    do {
        system("cls");
        greetings();
        cout << "\t\t\t________ EMPLOYEE MENU ________\n\n";
        cout << "\t\t\t1. View Profile" << endl;
        cout << "\t\t\t2. Show Not Working PCs" << endl;
        cout << "\t\t\t3. Show Available PCs" << endl;
        cout << "\t\t\t4. Show Booking Requests" << endl;
        cout << "\t\t\t5. Generate Bill" << endl;
        cout << "\t\t\t6. Give Report to Admin" << endl;
        cout << "\t\t\t7. Logout" << endl;

        cout << "\t\t\tEnter choice: ";
        cin >> choice;
        cin.ignore();
		Employee* obj = nullptr;
		Device* dobj = nullptr;
        switch (choice) {
            case 1:
                system("cls");
            	greetings();
            	cout << "\t\t\t\t\t\t______YOUR PROFILE______ \n\n" << endl;
            	obj = new Employee();
                obj->ViewDetails();
                system("pause");
                break;

            case 2:
                system("cls");
            	dobj = new Device();
                dobj->showNotWorkingDevices();
                system("pause");
                break;

            case 3:
                system("cls");
            	greetings();
            	cout << "\t\t\t\t\t\t______AVAILABLE DEVICES______ \n\n" << endl;
            	obj = new Employee();
                obj->showAvailableDevices();
                system("pause");
                break;

            case 4:
                system("cls");
            	greetings();
            	cout << "\t\t\t\t\t\t______MEMBER REQUEST______ \n\n" << endl;
            	obj = new Employee();
                obj->ShowRequest();
                system("pause");
                break;

            case 5:
                system("cls");
            	greetings();
            	cout << "\t\t\t\t\t\t______GENERATING BILL______ \n\n" << endl;
            	obj = new Employee();
                obj->GenerateBill();
                system("pause");
                break;

            case 6:
                system("cls");
            	greetings();
            	cout << "\t\t\t\t\t\t______GIVING REPORT______ \n\n" << endl;
            	obj = new Employee();
                obj->GiveReorts();
                system("pause");
                break;

            case 7:
                cout << "Logged out succesfully !! ";
                system("pause");
                break;

            default:
                cout << "\n\t\t\tInvalid choice. Please try again.\n";
                system("pause");
        }
    } while (choice != 7);
    exit(0);
}


