#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base Class
class User {
protected:
    static int globalId; // Static member untuk auto-increment ID
    int id;
    string nama;
    string email;

public:
    User(string pNama, string pEmail) : nama(pNama), email(pEmail) {
        id = generateId();
    }

    // Member function untuk generate ID secara otomatis
    int generateId() {
        return ++globalId;
    }

    // Getter untuk kebutuhan display
    int getId() { return id; }
    string getNama() { return nama; }
};

// Inisialisasi static member
int User::globalId = 0;

// Forward declaration untuk class Member agar Admin bisa mengenalnya
class Member;

// Derived Class: Member
class Member : public User {
private:
    bool status; // true untuk aktif, false untuk non-aktif

public:
    Member(string pNama, string pEmail) : User(pNama, pEmail) {
        status = true; // Default member baru adalah aktif
    }

    void setStatus(bool pStatus) {
        status = pStatus;
    }

    bool getStatus() {
        return status;
    }

    void showProfile() {
        cout << "--- Profil Member ---" << endl;
        cout << "ID     : " << id << endl;
        cout << "Nama   : " << nama << endl;
        cout << "Email  : " << email << endl;
        cout << "Status : " << (status ? "Aktif" : "Non-Aktif") << endl;
        cout << "---------------------" << endl;
    }
};
