#include <mysql.h>
#include <mysqld_error.h>
#include <iostream>
#include <windows.h> // For Sleep function
#include <string>

using namespace std;

class DatabaseManager {
public:
    DatabaseManager(const char* host, const char* user, const char* pass, const char* db);
    ~DatabaseManager();
    bool connect();
    void insertData(const string& id, const string& name, const string& section, const string& roll_no, const string& contact, const string& address, const string& hostel, const string& room);
    void updatestudentData(const string& id, const string& column1, const string& newValue);
    void updatestudent_addressData(const string& id, const string& column2, const string& newValue);
    void close();

private:
    const char* HOST;
    const char* USER;
    const char* PASSW;
    const char* DB;
    MYSQL* conn;
};

DatabaseManager::DatabaseManager(const char* host, const char* user, const char* pass, const char* db)
    : HOST(host), USER(user), PASSW(pass), DB(db), conn(mysql_init(NULL)) {}

DatabaseManager::~DatabaseManager() {
    if (conn) {
        mysql_close(conn);
    }
}

bool DatabaseManager::connect() {
    if (!mysql_real_connect(conn, HOST, USER, PASSW, DB, 3306, NULL, 0)) {
        cerr << "Connection error: " << mysql_error(conn) << endl;
        return false;
    } else {
        cout << "Logged in..." << endl << endl;
        Sleep(2000); // Pause for 2 seconds
        return true;
    }
}

void DatabaseManager::insertData(const string& id, const string& name, const string& section, const string& roll_no, const string& contact, const string& address, const string& hostel, const string& room) {
    string query1 = "INSERT INTO student (ID, Name, Section, Roll_No, Contact) VALUES('" + id + "', '" + name + "', '" + section + "', '" + roll_no + "', '" + contact + "')";
    string query2 = "INSERT INTO student_address (ID, Address, Hostel, Room_No) VALUES('" + id + "', '" + address + "', '" + hostel + "', '" + room + "')";
    
    if (mysql_query(conn, query1.c_str())) {
        cerr << "First query execution failed: " << mysql_error(conn) << endl;
        return;
    } else {
        cout << "First query executed successfully" << endl;
        Sleep(1000);
	}
	
    if (mysql_query(conn, query2.c_str())) {
        cerr << "Second query execution failed: " << mysql_error(conn) << endl;
    } else {
        cout << "Second query executed successfully" << endl;
        Sleep(1000);
    }

    Sleep(2000); // Pause for 2 seconds
}


void DatabaseManager::updatestudentData(const string& id, const string& column1, const string& newValue) {
    string query = "UPDATE student SET " + column1 + " = '" + newValue + "' WHERE ID = '" + id + "'";
    if (mysql_query(conn, query.c_str())) {
        cerr << "Query execution failed: " << mysql_error(conn) << endl;
    } else {
        cout << "Data updated successfully" << endl << endl;
    }

    Sleep(2000); // Pause for 2 seconds
}

void DatabaseManager::updatestudent_addressData(const string& id, const string& column2, const string& newValue) {
    string query = "UPDATE student_address SET " + column2 + " = '" + newValue + "' WHERE ID = '" + id + "'";
    if (mysql_query(conn, query.c_str())) {
        cerr << "Query execution failed: " << mysql_error(conn) << endl;
    } else {
        cout << "Data updated successfully" << endl << endl;
    }

    Sleep(2000); // Pause for 2 seconds
}

void DatabaseManager::close() {
    if (conn) {
        mysql_close(conn);
    }
}

void showMenu() {
    cout << "1. Insert Data" << endl;
    cout << "2. Update Data" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter value: ";
}

bool validateInput(int& val) {
    if (cin.fail()) {
        cin.clear(); // Clear the error flag
        cin.ignore(INT_MAX, '\n'); // Discard invalid input
        return false;
    }
    return true;
}

void handleInsertData(DatabaseManager& dbManager) {
    string id, name, section, roll_no, contact, address, hostel, room;

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Name: ";
    cin >> name;

    cout << "Enter Section: ";
    cin >> section;

    cout << "Enter Roll_No: ";
    cin >> roll_no;

    cout << "Enter Contact Number: ";
    cin >> contact;
    
    cout << "Enter Address: ";
    cin >> address;
    
    cout << "Enter Hostel alloted: ";
    cin >> hostel;
    
    cout << "Enter room alloted: ";
    cin >> room;

    dbManager.insertData(id, name, section, roll_no, contact,address,hostel,room);
}

void handleUpdateData(DatabaseManager& dbManager) {
    bool exitUpdate = false;
    while (!exitUpdate) {
        string id, column1,column2,newValue;
        int choice1;

        cout << "Enter ID of the record to update: ";
        cin >> id;
        
        cout << "Enter table you want to update: "<<endl;
        cout << "1. Student"<<endl;
        cout << "2. Student_address"<<endl;
        cin >> choice1;
        
        switch(choice1){
        	case 1:
        		cout << "Enter the column to update (Name, Section, Roll_No, Contact): ";
        		cin >> column1;
        		
        		cout << "Enter the new value: ";
        		cin >> newValue;
        		Sleep(1000);

        		dbManager.updatestudentData(id, column1, newValue);
        		break;
        	case 2:
        		cout << "Enter the column to update (Address, Hostel, Room_No): ";
        		cin >> column2;
        		
        		cout << "Enter the new value: ";
        		cin >> newValue;
        		Sleep(1000);

        		dbManager.updatestudent_addressData(id, column2, newValue);
        		break;
        	default:
        		cout<<"Invalid choice "<<endl;
        		break;
		}
		
        char choice;
        cout << "Do you want to update another record? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N') {
            exitUpdate = true;
        }
    }
}

int main() {
    DatabaseManager dbManager("localhost", "root", "your password", "your database");

    if (!dbManager.connect()) {
        return 1;
    }

    bool exit = false;
    while (!exit) {
        system("cls"); // Clear screen
        showMenu();
        int val;
        cin >> val;

        if (!validateInput(val)) {
            cout << "Invalid input. Please enter a number." << endl;
            Sleep(2000); // Pause for 2 seconds
            continue;
        }

        switch (val) {
            case 1:
                handleInsertData(dbManager);
                break;
            case 2:
                handleUpdateData(dbManager);
                break;
            case 0:
                exit = true;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                Sleep(2000); // Pause for 2 seconds
        }
    }

    dbManager.close();
    return 0;
}

