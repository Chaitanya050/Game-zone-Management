#include "Functions.h"

void AdminMenu();

void AdminMenu() {
    int mainChoice;
    do {
        system("cls");
        greetings();
        cout << "\t\t\t1. Manage Admin" 	<< endl;
        cout << "\t\t\t2. Manage Employees  " 		<< endl;
		cout << "\t\t\t3. Manage Members"      << endl;
		cout << "\t\t\t4. Manage Games" 	<< endl;
		cout << "\t\t\t5. Manage Devices" 	<< endl;
		cout << "\t\t\t6. Log out" 	<< endl;

        cout << "\n\t\t\tEnter choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
        	case 1:{
			    int adminchoice;
			    admin* AdminObj = new admin();
			
			    do {
			        system("cls");
			        greetings();
			        cout << "\t\t\t\t\t\t______MANAGING ADMINS______ \n\n";
			        cout << "\t\t\t1. View all Admins" << endl;
			        cout << "\t\t\t2. Add Admin" << endl;
			        cout << "\t\t\t3. Remove Admin" << endl;
			        cout << "\t\t\t4. Back to main menu" << endl;
			
			        cout << "\n\t\t\tEnter choice: ";
			        cin >> adminchoice;
			        cin.ignore(); 
			
			        switch (adminchoice) {
			            case 1:
			            	system("cls");
			            	greetings();
							cout << "\t\t\t\t\t\t______SHOWING ADMIN______ \n\n" << endl;
			                AdminObj->viewAdmin();
			                system("pause");
			                break;
			            case 2:
			            	system("cls");
			            	greetings();
							cout << "\t\t\t\t\t\t______ADDING ADMIN______ \n\n" << endl;
			        		AdminObj->RegisterUser();
			        		system("pause");
							break;
			            case 3:
			                system("cls");
			                greetings();
							cout << "\t\t\t\t\t\t______REMOVING ADMIN______ \n\n" << endl;
							AdminObj->removeAdmin();
							system("pause");
			                break;
			            case 4:
			                cout << "\n\t\t\tReturning to main menu...\n";
			                break;
			            default:
			                cout << "\n\t\t\tInvalid option!";
			                system("pause");
			        }
			    } while (adminchoice != 4);
			
			    delete AdminObj; 
			    break;
			}
			
            case 2: { 
                int empChoice;
                admin* adminObj = new admin();
                Employee* empObj = new Employee();
                do {
                    system("cls");
                    greetings();
                    cout << "\t\t\t\t\t\t______MANAGING EMPLOYEE______ \n\n";
					cout << "\t\t\t1. View all Employees" << endl;
					cout << "\t\t\t2. Add Employee "      << endl;
					cout << "\t\t\t3. Remove Employee"    << endl;
					cout << "\t\t\t4. change status"      << endl;
					cout << "\t\t\t5. reports "   		  << endl;
					cout << "\t\t\t6. back to main menu"  << endl;

                    cout << "\n\n\t\t\tEnter choice: ";
                    cin >> empChoice;

                    switch (empChoice) {
                        case 1:
                        	system("cls");
                        	greetings();
        					cout << "\t\t\t\t\t\t______SHOWING EMPLOYEE______ \n\n" << endl;
			                adminObj->viewEmployees();
			                system("pause");
			                break;
			            case 2:
			            	system("cls");
			            	greetings();
			            	cout << "\t\t\t\t\t\t______ADDING EMPLOYEE______ \n\n" << endl;
			                empObj->RegisterUser();
			                delete empObj;
			                system("pause");
			                break;
			            case 3:
			            	system("cls");
			            	greetings();
			            	cout << "\t\t\t\t\t\t______REMOVING EMPLOYEE______ \n\n" << endl;
			                adminObj->removeEmployee();
			                system("pause");
			                break;
			            case 4:	
							system("cls");
			            	greetings();
			            	cout << "\t\t\t\t\t\t______CHANGING EMPLOYEE STATUS______ \n\n" << endl;
			                adminObj->changeEmployeeStatus();
			                system("pause");
			                break;
			            case 5:
			            	system("cls");
			            	greetings();
			            	cout << "\t\t\t\t\t\t______REPORTS BY EMPLOYEE______ \n\n" << endl;
			                adminObj->viewReports();
			                system("pause");
			                break;
                        case 6:
                            break;
                        default:
                            cout << "\n\t\tInvalid option!";
                            system("pause");
                    }
                } while (empChoice != 5);
                break;
            }

            case 3: { 
                int memChoice;
                admin* adminObj = new admin();
                do {
                    system("cls");
                    greetings();
                    cout << "\t\t\t\t\t\t______MANAGING MEMBERS______ \n\n";
					cout << "\t\t\t1. View all Members" << endl;
					cout << "\t\t\t2. Remove member"      << endl;
					cout << "\t\t\t3. update membership type" << endl;
					cout << "\t\t\t4. Back to main menu"   << endl;

                    cout << "\n\t\t\tEnter choice: ";
                    cin >> memChoice;

                    switch (memChoice) {
                        case 1:
                        	system("cls");
                        	greetings();
			            	cout << "\t\t\t\t\t\t______ALL MEBMERS______ \n\n" << endl;
			                adminObj->viewMembers();
			                system("pause");
                            break;
                        case 2:
                        	system("cls");
                        	greetings();
			            	cout << "\t\t\t\t\t\t______REMOVE MEMBERS______ \n\n" << endl;
			                adminObj->removeMember();
			                system("pause");
                            break;
                        case 3:
                        	system("cls");
                        	greetings();
			            	cout << "\t\t\t\t\t\t______UPDATE MEMBERSHIP______ \n\n" << endl;
			                adminObj->updateMembership();
			                system("pause");
                            break;
                        case 4:
                            break;
                        default:
                            cout << "\n\t\t\tInvalid option!";
                            system("pause");
                    }
                } while (memChoice != 4);
                break;
            }

            case 4: 
				{ 
				    int gameChoice;
				    Games* gameObj = new Games();
				
				    do {
				        system("cls");
				        greetings();
				        cout << "\t\t\t\t\t\t______MANAGING GAMES______ \n\n";
				        cout << "\t\t\t1. View all games" << endl;
				        cout << "\t\t\t2. Add game" << endl;
				        cout << "\t\t\t3. Update game" << endl;
				        cout << "\t\t\t4. Remove game" << endl;
				        cout << "\t\t\t5. Back to main menu" << endl;
				
				        cout << "\n\t\t\tEnter choice: ";
				        cin >> gameChoice;
				        cin.ignore(); 
				
				        switch (gameChoice) {
				            case 1:
				            	system("cls");
				                gameObj->showGames();
				                system("pause");
				                break;
				            case 2:
				            	system("cls");
				                gameObj->addGame();
				                system("pause");
				                break;
				            case 3:
				                system("cls");
								gameObj->updateGame();
								system("pause");
				                break;
				            case 4:
				                system("cls");
								gameObj->removeGame();
								system("pause");
				                break;
				            case 5:
				                cout << "\n\t\t\tReturning to main menu...\n";
				                break;
				            default:
				                cout << "\n\t\t\tInvalid option!";
				                system("pause");
				        }
				    } while (gameChoice != 5);
				
				    delete gameObj; 
				    break;
				}

            case 5: 
				{ 
				    int devChoice;
				    Device* d = new Device(); 
				    do {
				        system("cls");
				        greetings();
				        cout << "\t\t\t\t\t\t______MANAGING DEVICES______ \n\n";
				        cout << "\t\t\t1. View all Devices" << endl;
				        cout << "\t\t\t2. Add devices" << endl;
				        cout << "\t\t\t3. Update devices" << endl;
				        cout << "\t\t\t4. Remove Devices" << endl;
				        cout << "\t\t\t5. View not working devices " << endl;
				        cout << "\t\t\t6. Back to main menu" << endl;
				
				        cout << "\n\t\t\tEnter choice: ";
				        cin >> devChoice;
				
				        switch (devChoice) {
				            case 1:
    							system("cls");
				                d->showDevices();
				                system("pause");
				                break;
				            case 2:
				            	system("cls");
				                d->addDevice();
				                system("pause");
				                break;
				            case 3:
				            	system("cls");
				                d->updateDevice();
				                system("pause");
				                break;
				            case 4:
				            	system("cls");
				                d->removeDevice();
				                system("pause");
				                break;
				            case 5:
				            	system("cls");
				                d->showNotWorkingDevices();
				                system("pause");
				                break;
				            case 6:
				                break;
				            default:
				                cout << "\n\t\tInvalid option!";
				                system("pause");
				        }
				    } while (devChoice != 6);
				    
				    delete d; 
				    break;
				}
            case 6:
                cout << "\n\t\t\tLogging out...";
                break;

            default:
                cout << "\n\t\t\tInvalid option!";
                system("pause");
        }

    } while (mainChoice != 6);

    exit(0);
}



