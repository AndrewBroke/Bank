// Bank.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
//#include <windows.h>


using namespace std;
vector<string> split(string s, string sep) {
    vector<string> result = {};
    
    bool flag = true;
    while (flag) {
        flag = false; // world
        if (s.find(sep) != string::npos) {
            string t = s.substr(0, s.find(sep));
            result.push_back(t);
            flag = true;
            s = s.substr(s.find(sep) + 1, s.length() - s.find(sep));
        }
        else {
            result.push_back(s);
            break;
        }
    }
    return result;
}

class User {
private:
    string name;
    double money;
    string password;

public:
    User() {
        name = "";
        money = 0;
        password = "";
    }

    User(string newName, double newMoney, string newPassword) {
        name = newName;
        money = newMoney;
        password = newPassword;
    }
};

enum class AppState {
    Enter,
    EnterLogin,
    EnterPassword,
    Menu
};

class Bank {
private:
    vector<User> users;
    AppState state;

    User currentUser;

    void load_users() {
        // Загружать данные из файла users.dat
        // Закидывать их в users
        fstream file;
        file.open("users.dat", ios::in);

        string line;
        
        while (getline(file, line)) {
            // {"username", "password", 10000}
            vector<string> userData = split(line, ":");
            User user = User(userData[0], stod(userData[2]), userData[1]);
            users.push_back(user);
        }

    }

    void save_users() {

    }

    void create_user() {

    }

    void login() {

    }

    void render_ui() {
        system("cls");

        switch (state)
        {
        case AppState::Enter:
            cout << "========== Bank++ ==========" << endl;
            cout << "Welcome, dear user. Choose next step." << endl;
            cout << "Enter \"login\" to login to your account." << endl;
            cout << "Enter \"register\" to register as a new user." << endl;
            cout << "10 000$ bonus to every new user!" << endl;
            break;
        case AppState::EnterLogin:
            cout << "========== Bank++ ==========" << endl;
            cout << "Enter your login below.";
            break;
        case AppState::EnterPassword:
            break;
        case AppState::Menu:
            break;
        default:
            break;
        }
    }

    void get_user_input() {
        string input;
        cout << "\nYour input: ";
        getline(cin, input);
        //cin >> input;

        // TODO: обработка ввода
        switch (state)
        {
        case AppState::Enter:
            cout << endl << input << " login" << endl;
            if (input == "login") {
                state = AppState::EnterLogin;
            }
            else if (input == "register") {

            }
            break;
        case AppState::EnterLogin:
            break;
        case AppState::EnterPassword:
            break;
        case AppState::Menu:
            break;
        default:
            break;
        }
    }

public:
    
    Bank() {
        state = AppState::Enter;
        load_users();
        login();

    }

    void start_app() {
        while (true) {
            render_ui();
            get_user_input();
        }
    }
};

int main()
{
    Bank bank;
    bank.start_app();
    //vector<string> s = split("Hello my little world", " ");

    /*string s = "password2";
    hash<string> my_hash;
    string res = to_string(my_hash(s));
    cout << res;*/
}

