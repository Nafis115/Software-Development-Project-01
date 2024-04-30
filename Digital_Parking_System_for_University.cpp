#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
bool login = false;
const int row = 10;
const int col = 20;
int mat[row][col];
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
    cout << "* Welcome to university parking system *" << endl;
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

void show_parking_space()
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (mat[i][j] == 0)
            {
                cout << "."
                     << " ";
            }
            else
            {
                cout << "X"
                     << " ";
            }
        }
        cout << endl;
    }
}
void park_a_vehicle(int id, int vehicle_id, int r, int c)
{
    bool flag = false;
    if (r >= 0 && r < row && c >= 0 && c < col)
    {
        if (mat[r][c] == 0)
        {
            mat[r][c] = 1;

            flag = true;
        }
        else
        {
            cout << "The parking space Already Booked" << endl;
        }
    }
    if (flag == true)
    {
        ofstream store_space("parking_space.txt", ios::app);
        if (store_space.is_open())
        {
            store_space << vehicle_id << " " << r << " " << c << endl;
        }
        srand(time(nullptr));
        int coupon_num;
        coupon_num = rand();
        ofstream owner("Owner_details.txt", ios::app);
        if (owner.is_open())
        {
            owner << id << " " << coupon_num << endl;
            cout << "Please print this Coupon Number: " << coupon_num << endl;
            cout << "And give to the student for again verified" << endl;
        }
        else
        {
            cout << "Unable to open to save owner details" << endl;
        }
        owner.close();
        cout << "The vehicle Parked this space(" << r << "," << c << ")"
             << "successfully" << endl;
    }
}

void space_finder(int vehicle_id)
{
    bool flag = false;
    ifstream space_finder("parking_space.txt");
    int s_vehicle_id, s_r, s_c;
    if (space_finder.is_open())
    {

        while (space_finder >> s_vehicle_id >> s_r >> s_c)
        {
            if (vehicle_id == s_vehicle_id)
            {
                flag = true;
                cout << "Enter this Space(" << s_r << "," << s_c << ")"
                     << "for this vehicle" << endl;
            }
        }
    }
    else
    {
        cout << "Error: can not open file" << endl;
    }

    if (flag == false)
    {
        cout << endl;
        cout << "You Enter wrong Vehicle Id" << endl;
        cout << "Please try again valid Vehicle Id" << endl;
    }
}

void retrive_vehicle(int id, int coupon_num, int r, int c)
{
    bool flag = false;
    ifstream owner_ver("Owner_details.txt");
    int s_id, s_coupon_num;
    if (owner_ver.is_open())
    {
        while (owner_ver >> s_id >> s_coupon_num)
        {
            if (s_id == id)
            {
                flag = true;
            }
            else
            {
                cout << "Wrong id" << endl;
                cout << "Please try again with valid id" << endl;
            }
        }

        if (flag)
        {
            if (coupon_num == s_coupon_num)
            {
                if (mat[r][c] == 1)
                {
                    mat[r][c] = 0;
                    cout << "Your car retrieve successully" << endl;
                }
                else
                {
                    cout << "The parking space is empty" << endl;
                    cout << "Please Enter Valid space" << endl;
                }
            }
        }
    }
}
int main()
{
    mat[10][20] = {0};
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

                        string name, type;
                        int o_id, v_id, r, c;
                        cout << "Enter Vehicle Owner Name: ";
                        cin >> name;
                        cout << "Enter Vehicle Owner Id: ";
                        cin >> o_id;
                        cout << "Enter Vehicle Type: ";
                        cin >> type;
                        cout << "Enter Vehicle Id: ";
                        cin >> v_id;
                        show_parking_space();
                        cout << "Enter parking space(ex:(r,c)): ";
                        cin >> r >> c;

                        park_a_vehicle(o_id, v_id, r, c);
                        
                    }
                    else if (opt == 2)
                    {

                        int o_id, v_id, r, c, c_n;
                        cout << "Enter Vehicle Owner Id: ";
                        cin >> o_id;
                        cout << "Enter Vehicle Id: ";
                        cin >> v_id;
                        space_finder(v_id);
                        cout << "Enter parking space Where you park this Vehicle(ex:(r,c)): ";
                        cin >> r >> c;
                        cout << "Enter the unique coupon id: ";
                        cin >> c_n;
                        retrive_vehicle(o_id, c_n, r, c);
                    }
                    else if (opt == 3)
                    {
                        show_parking_space();
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
