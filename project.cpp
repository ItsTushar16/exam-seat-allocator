#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    int seatNo;
    string examHall;

public:
    Student() {
        rollNo = 0;
        name = "";
        seatNo = 0;
        examHall = "";
    }

    Student(int r, string n, int s, string hall){
        rollNo = r;
        name = n;
        seatNo = s;
        examHall = hall;
    }

    int getRollNo(){
        return rollNo;
    }
    string getName(){
        return name;
    }
    int getSeatNo(){
        return seatNo;
    }
    string getHall(){
        return examHall;
    }

    void setRollNo(int r){
        rollNo = r;
    }
    void setName(string n){
        name = n;
    }
    void setSeatNo(int s){
        seatNo = s;
    }
    void setHall(string hall){
        examHall = hall;
    }

    void displayStudent() {
        cout << "Roll No : " << rollNo << endl;
        cout << "Name    : " << name << endl;
        cout << "Seat No : " << seatNo << endl;
        cout << "Hall    : " << examHall << endl;
        cout << "----------------------------" << endl;
    }
};

class ExamHall {
private:
    string hallName;
    int totalSeats;
    int occupiedSeats;

public:
    ExamHall() {
        hallName = "";
        totalSeats = 0;
        occupiedSeats = 0;
    }

    ExamHall(string name, int seats) {
        hallName = name;
        totalSeats = seats;
        occupiedSeats = 0;
    }

    string getHallName(){
        return hallName;
    }
    int getTotalSeats(){
        return totalSeats;
    }
    int getOccupiedSeats(){
        return occupiedSeats;
    }

    bool isSeatAvailable() {
        return occupiedSeats < totalSeats;
    }

    int assignSeat() {
        if(isSeatAvailable()) {
            occupiedSeats++;
            return occupiedSeats;
        }
        return -1;
    }

    void displayHallStatus() {
        cout << "Hall    : " << hallName << endl;
        cout << "Total   : " << totalSeats << endl;
        cout << "Filled  : " << occupiedSeats << endl;
        cout << "Empty   : " << totalSeats - occupiedSeats << endl;
        cout << "----------------------------" << endl;
    }
};

class SeatingSystem {
private:
    Student students[100];
    ExamHall halls[5];
    int studentCount;

public:
    // Constructor - initialize halls
    SeatingSystem() {
        studentCount = 0;
        halls[0] = ExamHall("Hall A", 5);
        halls[1] = ExamHall("Hall B", 4);
        halls[2] = ExamHall("Hall C", 8);
        halls[3] = ExamHall("Hall D", 10);
        halls[4] = ExamHall("Hall E", 20);
    }

  
    ~SeatingSystem() {
        cout << "\nSystem closed." << endl;
    }

    void addStudent() {
        if(studentCount >= 100) {
            cout << "Max student limit reached!" << endl;
            return;
        }

        int roll;
        string name;

        cout << "Enter Roll No : ";
        cin >> roll;
        for(int i = 0; i < studentCount; i++) {
            if(students[i].getRollNo() == roll) {
                cout << "Roll number already exists!" << endl;
                return;
            }
        }
        cout << "Enter Name    : ";
        cin.ignore();
        getline(cin, name);

        // Assign to available hall
        int assignedHall = -1;
        int seatNo = -1;

        for(int i = 0; i < 5; i++) {
            if(halls[i].isSeatAvailable()) {
                seatNo = halls[i].assignSeat();
                assignedHall = i;
                break;
            }
        }

        if(assignedHall == -1) {
            cout << "No seats available in any hall!" << endl;
            return;
        }

        students[studentCount] = Student(roll, name, seatNo, halls[assignedHall].getHallName());
        studentCount++;

        cout << "Student assigned to " << halls[assignedHall].getHallName()
             << ", Seat No: " << seatNo << endl;
    }

    void displayAllStudents() {
        if(studentCount == 0) {
            cout << "No students added yet." << endl;
            return;
        }
        cout << "\n===== SEATING ARRANGEMENT =====" << endl;
        for(int i = 0; i < studentCount; i++) {
            students[i].displayStudent();
        }
    }

    void searchByRoll() {
        int roll;
        cout << "Enter Roll No to search: ";
        cin >> roll;

        bool found = false;
        for(int i = 0; i < studentCount; i++) {
            if(students[i].getRollNo() == roll) {
                cout << "\n--- Student Found ---" << endl;
                students[i].displayStudent();
                found = true;
                break;
            }
        }
        if(!found)
            cout << "Student not found!" << endl;
    }

    void displayHallStatus() {
        cout << "\n===== HALL STATUS =====" << endl;
        for(int i = 0; i < 5; i++) {
            halls[i].displayHallStatus();
        }
    }

    void saveToFile() {
        ofstream file("seating.txt");
        if(!file) {
            cout << "Error opening file!" << endl;
            return;
        }
        file << "===== EXAM SEATING ARRANGEMENT =====\n";
        for(int i = 0; i < studentCount; i++) {
            file << "Roll No : " << students[i].getRollNo() << "\n";
            file << "Name    : " << students[i].getName() << "\n";
            file << "Seat No : " << students[i].getSeatNo() << "\n";
            file << "Hall    : " << students[i].getHall() << "\n";
            file << "----------------------------\n";
        }
        file.close();
        cout << "Data saved to seating.txt" << endl;
    }

    void loadFromFile() {
        ifstream file("seating.txt");
        if(!file) {
            cout << "No saved data found." << endl;
            return;
        }
        string line;
        cout << "\n===== LOADED FROM FILE =====\n";
        while(getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
};

int main() {
    SeatingSystem sys;
    int choice;

    do {
        cout << "\n===== EXAM SEATING SYSTEM =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search by Roll No" << endl;
        cout << "4. Display Hall Status" << endl;
        cout << "5. Save to File" << endl;
        cout << "6. Load from File" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: sys.addStudent();       
                    break;
            case 2: sys.displayAllStudents(); 
                    break;
            case 3: sys.searchByRoll();    
                    break;
            case 4: sys.displayHallStatus(); 
                    break;
            case 5: sys.saveToFile();     
                    break;
            case 6: sys.loadFromFile();    
                    break;
            case 0: cout << "Exiting..." << endl; 
                    break;
            default: cout << "Invalid choice!" << endl;
        }
    } while(choice != 0);

    return 0;
}