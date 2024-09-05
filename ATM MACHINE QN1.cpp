#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>

using namespace std;

void login();
void registration();
void atmOperations(double &balance);  // Function declaration for ATM operations

int main()
{
    int c;
    cout<<"\t\t\t                         Hi! Welcome to ATM machine   \n\n\n";
    cout<<"\t 1 LOGIN                         "<<endl;
    cout<<"\t 2 CREATE A NEW ACCOUNT                    "<<endl;
    cout<<"\t 3 EXIT                          "<<endl;
    cout<<"\t\t\t   select enter your choice: ";
    cin>>c;
    cout<<endl;

    switch(c){
        case 1:
            login();
            break;

        case 2:  
            registration();
            break;

        case 3:
            cout<<"\t\t\t   Thank you! \n\n"<<endl;
            break;

        default:
            cout<<"Please select a valid option from the menu.\n";
            main();
    }

    return 0;
}

void login()
{
    int count = 0;
    string userId, password, id, pass;
    double balance = 0.0;  // Variable to keep track of the user's balance
    system("cls");
    cout<<"\t\t\t Please enter your username and password"<<endl;
    cout<<"\t\t\t USERNAME: ";
    cin>>userId;
    cout<<"\t\t\t PASSWORD: ";
    cin>>password;

    ifstream input("records.txt");


    while(input >> id >> pass)
    {
        if(id == userId && pass == password)
        {
            count = 1;
            system("cls");
            break;
        }
    }
    input.close();

    if (count == 1)
    {
        cout << userId << "\nYour LOGIN is successful\nThanks for logging in!\n";
        atmOperations(balance);  // Call the ATM operations after successful login
    }
    else
    {
        cout << "\nLOGIN ERROR \nPlease check your username and password\n";
        main();  // Return to the main menu on a failed login attempt
    }
}

void atmOperations(double &balance)
{
    int option;
    double amount;

    while (true) {
        cout << "                                     Select an option:" << endl;
        cout << "1. Deposit Money" << endl;
        cout << "2. Withdraw Money" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        switch(option) {
            case 1: // Deposit Money
                cout << "Enter the amount to deposit: ";
                cin >> amount;
                if (amount > 0) {
                    balance += amount;
                    cout << "Amount deposited successfully. New balance: " << balance << endl;
                } else {
                    cout << "Please enter a positive amount." << endl;
                }
                break;
            
            case 2: // Withdraw Money
                cout << "Enter the amount to withdraw: ";
                cin >> amount;
                if (amount > balance) {
                    cout << "Error: Enter the amount less than or equals the account balance." << endl;
                } else if (amount > 0) {
                    balance -= amount;
                    cout << "Amount withdrawn successfully. New balance: " << balance << endl;
                } else {
                    cout << "Please enter a positive amount." << endl;
                }
                break;

            case 3: // Exit
                cout << "Exiting the program. Thank you!" << endl;
                return;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }
}

void registration()
{
    string ruserId, rpassword;
    system("cls");
    cout<<" pusername: ";
    cin>>ruserId;
    cout<<" password: ";
    cin>>rpassword;

    ofstream f1("records.txt", ios::app);
    if(!f1) {
        cout << "Error: Please try later.\n";
        return;
    }
    f1 << ruserId << ' ' << rpassword << endl;
    f1.close();

    system("cls");
    cout<<"\t\t\t  Your account has been created!\n";
    main();
}

