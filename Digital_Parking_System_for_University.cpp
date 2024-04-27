#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
class User{
    public:
    string email;
    int id;
    string vehicle_id;
    User(){
        email=" ";
        id=0;
        vehicle_id=" ";
    }
    User(string email,int id, string vehicle_id){
        this->email=email;
        this->id=id;
        this->vehicle_id=vehicle_id;
    
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
    cout << "\n"  << endl;
}

void registration_method()
{
    cout << "Welcome to our Registration process" << endl;
    string email;
    int pass;
    cout << "Enter your email: ";
    cin >> email;
    cout << "Enter your password: ";
    cin >> pass;
    s_infor(email, pass);
    printf("Registration is processign.");
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    cout << ("\n");
    cout << "Your Registration Successful" << endl;
    Sleep(1500);
    system("CLS");
    inter_face();

    
}

void login_method()
{
    cout << "Welcome To Login Page" << endl;
    string email;
    cout << "Enter your Email: ";
    cin >> email;
    int pass;
    cout << "Enter your password: ";
    cin >> pass;
    printf("Please Wait for login.");
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf("\n");
    if (check_admin(email, pass))
    {
        cout << "Login successful" << endl;
        Sleep(1500);
    }
    else
    {

        cout << "Incorrect email or password. Please try again." << endl;
        Sleep(1500);
    }

}








int main()
{
    inter_face();

    while (5)
    {
        cout << "Enter your option:" << endl;
        int op;
        cin >> op;
        if (op == 1)
        {
            registration_method();
        }
        else if (op == 2)
        {
            login_method();
            inter_face();
            
        }
        else
        {
            
            cout << "Thanks for visiting our parking system" << endl;
            Sleep(1500); 
            break;
        }
    }
    system("CLS");





    return 0;
}
