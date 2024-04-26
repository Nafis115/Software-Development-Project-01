#include<bits/stdc++.h>
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

void s_infor(string email, int pass)
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
            cout << "Enter your email: ";
            cin >> email;
            cout << "Enter your password: ";
            cin >> pass;
            s_infor(email, pass);
            cout << "Your Registration Successful" << endl;
        }
        else if (op == 2)
        {
            cout << "Welcome To Login Page" << endl;
            string email;
            cout << "Enter your Email: ";
            cin >> email;
            int pass;
            cout << "Enter your password: ";
            cin >> pass;

            if (check_admin(email, pass))
            {
                cout << "Login successful" << endl;
            }
            else
            {
                cout << "Incorrect email or password. Please try again." << endl;
            }
        }
        else
        {
            cout << "Thanks for visiting our parking system" << endl;
            break;
        }
    }

    return 0;
}
