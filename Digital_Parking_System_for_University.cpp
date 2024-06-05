#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
using namespace std;

const int ROW = 10; // globally declare row
const int COL = 20; // globally declare column

void loading_print() // design print
{
    Sleep(650);
    for (int i = 0; i < 4; i++)
    {
        cout << ".";
        Sleep(1000);
    }
    cout << endl;
}

void inter_face() // inter face method
{
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t*****************************************" << endl;
    cout << "\t\t\t\t\t*                                       *" << endl;
    cout << "\t\t\t\t\t* WELCOME TO UNIVERSITY PARKING SYSTEM  *" << endl;
    cout << "\t\t\t\t\t*                                       *" << endl;
    cout << "\t\t\t\t\t*****************************************" << endl;
    cout << "\n\n";
    Sleep(1000);

    cout << "\t\t\t\t\t Option 1: Registration" << endl;
    cout << "\t\t\t\t\t Option 2: Login" << endl;
    cout << "\t\t\t\t\t Option 3: Exit" << endl;
    cout << "\n"
         << endl;
}

void admin_information(string email, int pass) // save admin information method
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

bool check_admin(string email, int pass) // admin information check
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

void registration_method() // registration method

{
    Sleep(1000);
    system("CLS");
    cout << "\n\n\n\n\t\t\t\t\tWELCOME TO OUR REGISTRATION PROCESS" << endl
         << endl;
    string email;
    string pass;
    char ch;

    cout << "\t\t\t\t\tEnter your email: ";
    cin >> email;
    cout << "\t\t\t\t\tEnter your password: ";
    do
    {
        ch = getch();

        if (ch != 13 && ch != 8)
        {
            pass.push_back(ch);
            cout << '*';
        }
        else if (ch == 8 && !pass.empty())
        {
            pass.pop_back();
            cout << "\b \b";
        }
    } while (ch != 13);

    admin_information(email, stoi(pass)); // save admin infomation method call
    cout << endl;
    printf("\t\t\t\t\tRegistration is processing");
    loading_print();
    Sleep(2000);

    system("CLS");

    cout << "\n\n\n\n\t\t\t\t\tYOUR REGISTRATION SUCCESSFUL " << endl
         << endl;
    system("pause");
    system("CLS");
    inter_face();
}

bool login_method() // admin login method
{
    Sleep(1000);
    system("CLS");
    cout << "\n\n\n\n\t\t\t\t\tWELCOME TO LOGIN PAGE" << endl;
    string email;
    cout << "\t\t\t\t\tEnter your email: ";
    cin >> email;
    string pass;
    char ch;
    cout << "\t\t\t\t\tEnter your password: ";

    // for password encrypted method start

    do
    {
        ch = getch();

        if (ch != 13 && ch != 8)
        {
            pass.push_back(ch);
            cout << '*';
        }
        else if (ch == 8 && !pass.empty())
        {
            pass.pop_back();
            cout << "\b \b";
        }
    } while (ch != 13);

    // for password encrypted method end

    cout << endl;
    printf("\t\t\t\t\tPlease Wait for login");
    loading_print();
    system("cls");
    Sleep(2000);
    if (check_admin(email, stoi(pass))) // admin check method call
    {
        cout << "\n\n\n\n\t\t\t\t\t\tLOGIN SUCCESSFUL" << endl;
        cout << endl
             << endl;
        system("pause");
        system("cls");
        return true;
    }
    else
    {
        cout << "\t\t\t\t\tYou Enter wrong Email and Password" << endl;
        cout << "\t\t\t\t\tPlease try again with valid email and password" << endl;
        system("pause");
    }
    return false;
}

void admin_interface_panel() // admin interface
{
    cout << "\n\n";
    cout << "\t\t\t\t\t***************************************************" << endl;
    cout << "\t\t\t\t\t             WELCOME TO OUR ADMIN PANEL            " << endl;
    cout << "\t\t\t\t\t***************************************************" << endl;
    cout << endl;
    cout << "\t\t\t\t\t---------------------------------------------------" << endl;
    cout << "\t\t\t\t\tOption 1: Park a Vehicle" << endl;
    cout << "\t\t\t\t\t---------------------------------------------------" << endl;
    cout << "\t\t\t\t\tOption 2: Retrieve a Vehicle" << endl;
    cout << "\t\t\t\t\t---------------------------------------------------" << endl;
    cout << "\t\t\t\t\tOption 3: View Parking Spaces in University" << endl;
    cout << "\t\t\t\t\t---------------------------------------------------" << endl;
    cout << "\t\t\t\t\tOption 4: Exit" << endl;
    cout << "\t\t\t\t\t***************************************************" << endl;
}

void save_parking_space(int mat[ROW][COL]) // parking space saving method
{
    ofstream save_space("save_space.txt"); // file for save spaces
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

void load_space(int mat[ROW][COL]) // load space method
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
}

void show_parking_space(int mat[ROW][COL]) // view parking spaces
{
    cout << "\n\n\n";
    cout << "\t\t\t\t\tParking Space Status:" << endl;
    cout << "\t\t\t\t\t----------------------" << endl;
    for (int i = 0; i < ROW; i++)
    {
        cout << "\t\t\t\t\t";
        for (int j = 0; j < COL; j++)
        {
            if (mat[i][j] == 0)
            {
                cout << ". ";
            }
            else
            {
                cout << "X ";
            }
        }
        cout << endl;
    }
    cout << "\t\t\t\t\t----------------------" << endl;
}

bool check_owner_parked(int id) // function to check if the owner has already parked a vehicle
{
    ifstream owner("Owner_details.txt");
    if (owner.is_open())
    {
        int stored_id, coupon_num;
        while (owner >> stored_id >> coupon_num)
        {
            if (stored_id == id)
            {
                owner.close();
                return true;
            }
        }
        owner.close();
    }
    return false;
}

void park_a_vehicle(int id, int vehicle_id, int r, int c, int mat[ROW][COL]) // vehicle parking method
{
    bool flag = false;
    if (r >= 0 && r < ROW && c >= 0 && c < COL) // access matrix
    {
        if (mat[r][c] == 0)
        {
            mat[r][c] = 1;
            flag = true;
            save_parking_space(mat);
        }
        else
        {
            cout << "\t\t\t\t\tThe parking space is already booked" << endl;
        }
    }
    if (flag)
    {
        ofstream store_space("parking_details.txt", ios::app);
        if (store_space.is_open())
        {
            store_space << vehicle_id << " " << r << " " << c << endl;
        }
        srand(time(nullptr)); // seed of the random number generator
        int coupon_num;
        coupon_num = rand();
        ofstream owner("Owner_details.txt", ios::app);
        if (owner.is_open())
        {
            owner << id << " " << coupon_num << endl;
            cout << "\t\t\t\t\tThe vehicle is parked at this position(" << r << " " << c << ") successfully" << endl;
            cout << "\t\t\t\t\tPlease print this Coupon Number: " << coupon_num << endl;
            cout << "\t\t\t\t\tAnd give to the owner for again verification" << endl
                 << endl;
        }
        else
        {
            cout << "\t\t\t\t\tUnable to open file to save owner details" << endl;
        }
        owner.close();
    }
}

bool space_finder(int vehicle_id, int &s_r, int &s_c) // looking for space which input by user
{
    ifstream space_finder("parking_details.txt");
    bool found = false;
    if (space_finder.is_open())
    {
        while (space_finder >> vehicle_id >> s_r >> s_c)
        {
            if (vehicle_id == vehicle_id)
            {
                cout << "\t\t\t\t\tEnter this position(" << s_r << " " << s_c << ") for retrieve this vehicle" << endl
                     << endl;
                found = true;
                break;
            }
        }
    }
    else
    {
        cout << "\t\t\t\t\tError: cannot open file" << endl;
    }
    space_finder.close();
    if (found==false)
    {
        cout << "\t\t\t\t\tYou entered a wrong Vehicle Id. Please try again with a valid Vehicle Id" << endl;
    }
    return found;
}

bool retrieve_vehicle(int id, int coupon_num) // vehicle retrieve vehicle method
{
    ifstream owner_details("Owner_details.txt"); // owner details file open
    bool found = false;
    if (owner_details.is_open())
    {
        int s_id, s_coupon_num;
        while (owner_details >> s_id >> s_coupon_num)
        {
            if (s_id == id && coupon_num == s_coupon_num)
            {
                found = true;
                break;
            }
        }
    }
    else
    {
        cout << "\t\t\t\t\tCannot open file to retrieve vehicle" << endl;
    }
    owner_details.close();
    if (!found)
    {
        cout << "\t\t\t\t\tWrong id or coupon number. Please try again with valid credentials." << endl;
    }
    return found;
}

void remove_vehicle_details(int vehicle_id) // method to remove vehicle details after confirmation
{
    ifstream space_finder("parking_details.txt");
    ofstream temp("temp.txt");
    int s_vehicle_id, s_r, s_c;
    if (space_finder.is_open() && temp.is_open())
    {
        while (space_finder >> s_vehicle_id >> s_r >> s_c)
        {
            if (vehicle_id != s_vehicle_id)
            {
                temp << s_vehicle_id << " " << s_r << " " << s_c << endl;
            }
        }
    }
    else
    {
        cout << "\t\t\t\t\tError: cannot open file" << endl;
    }
    space_finder.close();
    temp.close();
    remove("parking_details.txt");
    rename("temp.txt", "parking_details.txt");
}

void remove_owner_details(int id) // method to remove owner details after confirmation
{
    ifstream owner_details("Owner_details.txt");
    ofstream temp("temp.txt");
    int s_id, s_coupon_num;
    if (owner_details.is_open() && temp.is_open())
    {
        while (owner_details >> s_id >> s_coupon_num)
        {
            if (id != s_id)
            {
                temp << s_id << " " << s_coupon_num << endl;
            }
        }
    }
    else
    {
        cout << "\t\t\t\t\tCannot open file to retrieve vehicle" << endl;
    }
    owner_details.close();
    temp.close();
    remove("Owner_details.txt");
    rename("temp.txt", "Owner_details.txt");
}

int main() // main function start
{
    system("cls");
    int mat[ROW][COL] = {0}; // initially matrix 0
    load_space(mat);         // load save space
    inter_face();

    while (true)
    {
        cout << "\t\t\t\t\t Enter your option: ";
        int op;
        cin >> op;
        if (op == 1)
        {
            registration_method(); // admin registration method call
        }
        else if (op == 2)
        {
            if (login_method()) // admin login method call
            {
                while (true)
                {
                    admin_interface_panel(); // admin interface call

                    int opt;
                    cout << "\t\t\t\t\tEnter your Option: ";
                    cin >> opt;
                    if (opt == 1) // vehicle parking process start
                    {
                        system("cls");
                        string name, type;
                        int o_id, v_id, r, c;
                        cout << "\n\n\t\t\t\t\tEnter Vehicle Owner Name: ";
                        cin >> name;
                        cout << "\t\t\t\t\tEnter Vehicle Owner Id: ";
                        cin >> o_id;
                        if (check_owner_parked(o_id))
                        {
                            cout << "\t\t\t\t\tYou have already parked a vehicle. Please retrieve it before parking another one." << endl;
                            system("pause");
                            system("cls");
                        }
                        else
                        {
                            cout << "\t\t\t\t\tEnter Vehicle Type: ";
                            cin >> type;
                            cout << "\t\t\t\t\tEnter Vehicle Id: ";
                            cin >> v_id;
                            show_parking_space(mat);
                            cout << "\t\t\t\t\tEnter parking space(ex:(r c)): ";
                            cin >> r >> c;
                            cout << "\t\t\t\t\tPlease wait. We are looking for empty space.";
                            loading_print();
                            Sleep(1500);
                            system("cls");
                            park_a_vehicle(o_id, v_id, r, c, mat);
                            system("pause");
                            system("cls");
                        }
                    }
                    else if (opt == 2) // vehicle retrieve process start
                    {
                        system("cls");
                        int owner_id, vehicle_id, r, c, coupon_num;
                        cout << "\t\t\t\t\tEnter Vehicle Owner Id: ";
                        cin >> owner_id;
                        cout << "\t\t\t\t\tEnter Vehicle Id: ";
                        cin >> vehicle_id;
                        if (space_finder(vehicle_id, r, c))
                        {
                            system("pause");
                            system("cls");
                            cout << endl;
                            cout << "\t\t\t\t\tEnter parking space Where you park this Vehicle(ex:(r c)): ";
                            cin >> r >> c;
                            cout << "\t\t\t\t\tEnter the unique coupon id: ";
                            cin >> coupon_num;
                            if (retrieve_vehicle(owner_id, coupon_num))
                            {
                                if (r >= 0 && r < ROW && c >= 0 && c < COL)
                                {
                                    if (mat[r][c] == 1)
                                    {
                                        mat[r][c] = 0;
                                        save_parking_space(mat);
                                        remove_vehicle_details(vehicle_id); // remove the details of file
                                        remove_owner_details(owner_id);     // remove the details of file
                                        cout << "\t\t\t\t\tVehicle retrieved successfully" << endl;
                                    }
                                    else
                                    {
                                        cout << "\t\t\t\t\tThis space(" << r << " " << c << ")"
                                             << "is already Booked" << endl;
                                    }
                                }
                            }
                        }
                        system("pause");
                        system("cls");
                    }
                    else if (opt == 3)
                    {
                        system("cls");
                        show_parking_space(mat); // showing parking space method
                        system("pause");
                        system("cls");
                    }
                    else if (opt == 4)
                    {
                        cout << "\t\t\t\t\tYou are exiting from Admin panel" << endl; // exit from admin panel
                        Sleep(2000);
                        system("CLS");
                        break;
                    }
                    else
                    {
                        cout << "\t\t\t\t\tInvalid option" << endl;
                        cout << "\t\t\t\t\tPlease try again" << endl;
                        Sleep(2000);
                        system("CLS");
                    }
                }
            }

            system("CLS");
            inter_face(); // registration interface
        }
        else if (op == 3)
        {
            system("cls");
            cout << "n\n\n\n\t\t\t\t\tThanks for visiting our parking system" << endl; // exit from registration process
            Sleep(2000);
            break;
        }
        else
        {
            cout << "\t\t\t\t\tInvalid option" << endl;
            cout << "\t\t\t\t\tPlease try again" << endl;
            Sleep(2000);
            system("CLS");
        }
    }
    system("CLS");

    return 0;
}
