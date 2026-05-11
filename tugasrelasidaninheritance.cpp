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

// Derived Class: Admin
class Admin : public User {
public:
    Admin(string pNama, string pEmail) : User(pNama, pEmail) {}

    // Menampilkan semua member yang terdaftar
    void showAllMember(vector<Member>& daftarMember) {
        cout << "\n[Admin Panel] Daftar Semua Member:" << endl;
        for (auto& m : daftarMember) {
            cout << "ID: " << m.getId() << " | Nama: " << m.getNama() 
                 << " | Status: " << (m.getStatus() ? "Aktif" : "Mati") << endl;
        }
    }

    // Mengubah status aktif/non-aktif member berdasarkan ID
    void toggleActivationMember(vector<Member>& daftarMember, int targetId) {
        for (auto& m : daftarMember) {
            if (m.getId() == targetId) {
                m.setStatus(!m.getStatus());
                cout << "\n[Admin] Status Member ID " << targetId << " berhasil diubah." << endl;
                return;
            }
        }
        cout << "\n[Admin] Member dengan ID " << targetId << " tidak ditemukan." << endl;
    }
};

int main() {
    // Membuat Admin
    Admin adminUtama("Randi Admin", "admin@kampus.com");

    // Membuat beberapa Member
    vector<Member> listMember;
    listMember.push_back(Member("Joni", "joni@mail.com"));
    listMember.push_back(Member("Feni", "feni@mail.com"));

    // Admin melihat semua member
    adminUtama.showAllMember(listMember);

    // Admin menonaktifkan salah satu member (ID 2)
    adminUtama.toggleActivationMember(listMember, 2);

    // Cek profil member setelah diubah admin
    listMember[1].showProfile();

    return 0;
}