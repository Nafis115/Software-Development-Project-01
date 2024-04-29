#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
class User{
    public:
    string name;
    int id;
    string vehicle_id;
    User(){
        name=" ";
        id=0;
        vehicle_id=" ";
    }
    User(string name,int id, string vehicle_id){
        this->name=name;
        this->id=id;
        this->vehicle_id=vehicle_id;
    
    }
};

void s_infor(string name, int pass)
{
    ofstream file("admin.txt", ios::app);
    if (file.is_open())
    {
        file << name << " " << pass << endl;
        file.close();
    }
    else
    {
        cout << "Unable to open file for saving admin." << endl;
    }
}

bool check_admin(string name, int pass)
{
    ifstream file("admin.txt");
    if (file.is_open())
    {
        string stored_name;
        int stored_pass;
        while (file >> stored_name >> stored_pass)
        {
            if (stored_name == name && stored_pass == pass)
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
    cout << "Welcome to our Registration process: " << endl;
    string name;
    int pass;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Enter your password: ";
    cin >> pass;
    s_infor(name, pass);
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
    string name;
    cout << "Enter your name: ";
    cin >> name;
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
    if (check_admin(name, pass))
    {
        cout << "Login successful" << endl;
        Sleep(1500);
        system("CLS");
    }
    else
    {

        cout << "Incorrect name or password. Please try again." << endl;
        Sleep(1500);
    }

}








int main()
{
    inter_face();

    while (5)
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
