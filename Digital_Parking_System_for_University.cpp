#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
bool login = false;
class User
{
public:
    string email;
    int id;
    string vehicle_id;
    User()
    {
        email = " ";
        id = 0;
        vehicle_id = " ";
    }
    User(string email, int id, string vehicle_id)
    {
        this->email = email;
        this->id = id;
        this->vehicle_id = vehicle_id;
    }
};
void dot_degin()
{
    Sleep(650);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf("\n");
}

void admin_information(string email, int pass)
{
    ofstream file("admin.txt", ios::app);
    if (file.is_open())
    {
        file << email << " " << pass << endl;
        file.close();
    }
    else
    {
        cout << "Unable to open file for saving admin." << endl;
    }
}

bool check_admin(string email, int pass)
{
    ifstream file("admin.txt");
    if (file.is_open())
    {
        string stored_email;
        int stored_pass;
        while (file >> stored_email >> stored_pass)
        {
            if (stored_email == email && stored_pass == pass)
            {
                file.close();
                return true;
            }
        }
        file.close();
    }
    return false;
}

void inter_face()
{
    cout << "\n\n";
    cout << "*****************************************" << endl;
    cout << "*                                       *" << endl;
    cout << "* Welcome to Parking university systeam *" << endl;
    cout << "*                                       *" << endl;
    cout << "*****************************************" << endl;
    cout << "\n\n";
    Sleep(1000);

    cout << "Option 1: Registration" << endl;
    cout << "Option 2: Login" << endl;
    cout << "Option 3: Exit" << endl;
    cout << "\n"
         << endl;
}

void registration_method()
{
    cout << "Welcome to our Registration process: " << endl;
    string email;
    int pass;
    cout << "Enter your email: ";
    cin >> email;
    cout << "Enter your password: ";
    cin >> pass;
    admin_information(email, pass);
    printf("Registration is processing");
    dot_degin();
    cout << ("\n");
    cout << "Your Registration Successful" << endl;
    Sleep(2000);
    system("CLS");
    inter_face();
}

void login_method()
{
    cout << "Welcome To Login Page" << endl;
    string email;
    cout << "Enter your email: ";
    cin >> email;
    int pass;
    cout << "Enter your password: ";
    cin >> pass;
    printf("Please Wait for login");
    dot_degin();
    if (check_admin(email, pass))
    {
        cout << "Login successful" << endl;
        login = true;
        Sleep(2000);
        system("CLS");
    }
    else
    {

        cout << "Incorrect email or password. Please try again." << endl;
        Sleep(2000);
    }
}

void admin_panel()
{
    cout << "*****************************************" << endl;
    cout << "      Welcome to Our Admin Panel         " << endl;
    cout << "*****************************************" << endl;

    cout << "Please Select an Option:" << endl;
    cout << "Option 1: Park a Vehicle" << endl;
    cout << "Option 2: Retrieve a Vehicle" << endl;
    cout << "Option 3: View Available Parking Spaces in University" << endl;
    cout << "Option 4: Exit" << endl;
    cout << "*****************************************" << endl;
}
void admin_work_panel()
{
    if (login)
    {
        while (true)
        {
            admin_panel();
            int opt;
            cout << "Enter your Option: ";
            cin >> opt;
            if (opt == 1)
            {
                cout << "processing.";
                dot_degin();
                system("CLS");
            }
            else if (opt == 2)
            {
                cout << "processing.";
                dot_degin();
                system("CLS");
            }
            else if (opt == 3)
            {
                cout << "processing.";
                dot_degin();
                system("CLS");
            }
            else if (opt == 4)
            {
                cout << "You are exiting from Admin panel" << endl;
                Sleep(2000);
                system("CLS");
                break;
            }
            else
            {
                cout << "Invalid option" << endl;
                cout << "Please try again" << endl;
                Sleep(2000);
                system("CLS");
            }
        }
    }
}

int main()
{
    inter_face();

    while (true)
    {
        cout << "Enter your option: ";
        int op;
        cin >> op;
        if (op == 1)
        {
            registration_method();
        }
        else if (op == 2)
        {
            login_method();
            admin_work_panel();
            system("CLS");
            inter_face();
        }
        else
        {

            cout << "Thanks for visiting our parking system" << endl;
            Sleep(2000);
            break;
        }
    }
    system("CLS");

    return 0;
}
