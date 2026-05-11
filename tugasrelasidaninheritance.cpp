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

