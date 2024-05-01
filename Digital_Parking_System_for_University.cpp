#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
bool login = false;
const int ROW = 10;
const int COL = 20;

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
    cout << "Option 3: View Parking Spaces in University" << endl;

    cout << "Option 4: Exit" << endl;
    cout << "*****************************************" << endl;
}
void save_parking_space(int mat[ROW][COL])
{
    ofstream save_space("save_space.txt");
    if (save_space.is_open())
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                save_space << mat[i][j] << " ";
            }
            save_space << endl;
        }
        save_space.close();
    }
    else
    {
        cout << "Can not save parking space" << endl;
    }
}

void load_space(int mat[ROW][COL])
{
    ifstream load_space("save_space.txt");
    if (load_space.is_open())
    {
        for (int i = 0; i < ROW; i++)
        {
            for (int j = 0; j < COL; j++)
            {
                load_space >> mat[i][j];
            }
        }
        load_space.close();
    }
    else
    {
        cout << "Error to open file for load save parking space" << endl;
    }
}
void show_parking_space(int mat[ROW][COL])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
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
void park_a_vehicle(int id, int vehicle_id, int r, int c, int mat[ROW][COL]) {
    bool flag = false;
    if (r >= 0 && r < ROW && c >= 0 && c < COL) {
        if (mat[r][c] == 0) {
            mat[r][c] = 1;
            flag = true;
            save_parking_space(mat);
        }
        else {
            cout << "The parking space is already booked" << endl;
        }
    }
    if (flag) {
        ofstream store_space("parking_details.txt", ios::app);
        if (store_space.is_open()) {
            store_space << vehicle_id << " " << r << " " << c << endl;
        }
        srand(time(nullptr));
        int coupon_num;
        coupon_num = rand();
        ofstream owner("Owner_details.txt", ios::app);
        if (owner.is_open()) {
            owner << id << " " << coupon_num << endl;
            cout << "Please print this Coupon Number: " << coupon_num << endl;
            cout << "And give to the student for verification" << endl;
        }
        else {
            cout << "Unable to open file to save owner details" << endl;
        }
        owner.close();
        cout << "The vehicle is parked at space (" << r << "," << c << ") successfully" << endl;
    }
}

bool space_finder(int vehicle_id) {
    ifstream space_finder("parking_details.txt");
    ofstream temp("temp.txt");
    int s_vehicle_id, s_r, s_c;
    bool found = false;
    if (space_finder.is_open() && temp.is_open()) {
        while (space_finder >> s_vehicle_id >> s_r >> s_c) {
            if (vehicle_id == s_vehicle_id) {
                cout << "Enter this Space(" << s_r << " " << s_c << ") for this vehicle" << endl << endl;
                found = true;
            }
            else {
                temp << s_vehicle_id << " " << s_r << " " << s_c << endl;
            }
        }
    }
    else {
        cout << "Error: cannot open file" << endl;
        return false;
    }
    space_finder.close();
    temp.close();
    remove("parking_details.txt");
    rename("temp.txt", "parking_details.txt");
    if (!found) {
        cout << "You entered a wrong Vehicle Id. Please try again with a valid Vehicle Id." << endl;
    }
    return found;
}

bool retrieve_vehicle(int id, int coupon_num) {
    ifstream owner_details("Owner_details.txt");
    ofstream temp("temp.txt");
    int s_id, s_coupon_num;
    bool found = false;
    if (owner_details.is_open() && temp.is_open()) {
        while (owner_details >> s_id >> s_coupon_num) {
            if (s_id == id) {
                if (coupon_num == s_coupon_num) {
                    found = true;
                    continue;
                }
            }
            temp << s_id << " " << s_coupon_num << endl;
        }
    }
    else {
        cout << "Cannot open file to retrieve vehicle" << endl;
        return false;
    }
    owner_details.close();
    temp.close();
    remove("Owner_details.txt");
    rename("temp.txt", "Owner_details.txt");
    if (!found) {
        cout << "Wrong id or coupon number. Please try again with valid credentials." << endl;
    }
    return found;
}

int main()
{
    int mat[ROW][COL] = {0};
    load_space(mat);
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
                        show_parking_space(mat);
                        cout << "Enter parking space(ex:(r c)): ";
                        cin >> r >> c;

                        park_a_vehicle(o_id, v_id, r, c, mat);
                    }
                    else if (opt == 2)
                    {

                        int owner_id, vehicle_id, r, c, coupon_num;
                        cout << "Enter Vehicle Owner Id: ";
                        cin >> owner_id;
                        cout << "Enter Vehicle Id: ";
                        cin >> vehicle_id;
                        if (space_finder(vehicle_id))
                        {   cout<<endl;
                            cout << "Enter parking space Where you park this Vehicle(ex:(r c)): ";
                            cin >> r >> c;
                            cout << "Enter the unique coupon id: ";
                            cin >> coupon_num;
                            if (retrieve_vehicle(owner_id, coupon_num))
                            {
                                if (r >= 0 && r < ROW && c >= 0 && c < COL)
                                {
                                    if (mat[r][c] == 1)
                                    {
                                        mat[r][c] = 0;
                                        save_parking_space(mat);
                                        cout << "Vehicle retrieve successfull" << endl;
                                    }
                                    else
                                    {
                                        cout << "This space(" << r << " " << c << ")"
                                             << "is already Booked" << endl;
                                    }
                                }
                            }
                        }
                    }
                    else if (opt == 3)
                    {
                        show_parking_space(mat);
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
