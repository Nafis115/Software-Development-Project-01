#include <bits/stdc++.h>
using namespace std;
class Admin
{
private:
    string email;
    int pass;

public:
    Admin()
    {
        email = "demo@gmail.com";
        pass = 1234;
    }

    Admin(string email, int pass)
    {
        this->email = email;
        this->pass = pass;
    }

    string get_email()
    {
        return email;
    }
    int get_pass()
    {
        return pass;
    }
};

int main()
{
    Admin admin;
    cout << "\n\n";
    cout << "*****************************************" << endl;
    cout << "*                                       *" << endl;
    cout << "* Welcome to Parking university systeam *" << endl;
    cout << "*                                       *" << endl;
    cout << "*****************************************" << endl;
    cout << "\n\n";

    cout << "Option 1: Registration" << endl;
    cout << "Option 2: Login" << endl;
    cout << "Option 3: Exit" << endl;
    cout << "\n"
         << endl;
    while (true)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            cout << "Welcome to our Registration process" << endl;
            string email;
            int pass;
            cout << "Enter you email" << endl;
            cin >> email;
            cout << "Enter you password" << endl;
            cin >> pass;
            Admin a(email, pass);
            if (admin.get_email() == email)
            {
                cout << "Your Registration Successfull" << endl;
            }
            else
            {
                cout << "Enter wrong Email" << endl;
                cout << "Please try again later" << endl;
            }
        }
        else if (op == 2)
        {
            cout << "Welcome To Login Page" << endl;

            string email;
            cout << "Enter you Email" << endl;
            cin >> email;
            int pass;
            cout << "Enter your pass" << endl;
            cin >> pass;

            if (admin.get_email() == email && admin.get_pass())
            {
                cout << "Login successfull" << endl;
            }
        }
        else
        {
            cout << "Thanks for visit our parking systeam" << endl;
            break;
        }
    }

    return 0;
}