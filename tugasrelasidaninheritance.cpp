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
