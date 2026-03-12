#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Person {
protected:
    int id;
    string name;

public:
    Person() { 
        id = 0; name = "";
     }
    Person(int i, string n) {
         id = i; name = n; 
        }

    int getId() {
         return id; 
        }
    string getName() { 
        return name; 
    }
    void setId(int i){ 
        id = i; 
    }
    void setName(string n) { 
        name = n; 
    }

    virtual void display() {
        cout << "ID   : " << id << endl;
        cout << "Name : " << name << endl;
    }

    virtual ~Person() {}
};


class Student : public Person {
private:
    int rollNo;
    string branch;
    string assignedHall;
    int assignedSeat;

public:
    Student() : Person() { rollNo = 0; branch = ""; assignedHall = ""; assignedSeat = 0; }

    Student(int id, string name, int roll, string br)
        : Person(id, name) {
        rollNo = roll;
        branch = br;
        assignedHall = "";
        assignedSeat = 0;
    }

    int getRollNo()  { 
        return rollNo; 
    }
    string getBranch() {
         return branch;
         }
    string getAssignedHall()  {
         return assignedHall;
        }
    int getAssignedSeat() { 
        return assignedSeat; 
    }

    void setRollNo(int r) { 
        rollNo = r;
     }
    void setBranch(string b){
         branch = b; 
        }
    void setAssignedHall(string h)  { 
        assignedHall = h; 
    }
    void setAssignedSeat(int s)  {
         assignedSeat = s;
    }

    void display() override {
        Person::display();
        cout << "Roll No  : " << rollNo << endl;
        cout << "Branch   : " << branch << endl;
        cout << "Hall     : " << assignedHall << endl;
        cout << "Seat No  : " << assignedSeat << endl;
    }
};


class Invigilator : public Person {
private:
    string subject;
    bool isAssigned;
    string assignedHall;

public:
    Invigilator() : Person() { 
        subject = ""; isAssigned = false; assignedHall = ""; 
    }

    Invigilator(int id, string name, string sub)
        : Person(id, name) {
        subject = sub;
        isAssigned = false;
        assignedHall = "";
    }

    string getSubject() { 
        return subject;
    }
    bool getIsAssigned() {
         return isAssigned; 
    }
    string getAssignedHall() { 
        return assignedHall; 
    }

    void assignToHall(string hall) {
        isAssigned = true;
        assignedHall = hall;
    }

    void unassign() {
        isAssigned = false;
        assignedHall = "";
    }

    void display() override {
        cout << "ID      : " << id << endl;
        cout << "Name    : " << name << endl;
        cout << "Subject : " << subject << endl;
        if(isAssigned)
            cout << "Hall    : " << assignedHall << " (Assigned)" << endl;
        else
            cout << "Hall    : Not Assigned" << endl;
    }
};


class Hall {
protected:
    string hallName;
    int totalSeats;
    int occupiedSeats;

public:
    Hall() { hallName = ""; totalSeats = 0; occupiedSeats = 0; }
    Hall(string name, int seats) {
        hallName = name;
        totalSeats = seats;
        occupiedSeats = 0;
    }

    string getHallName()  { return hallName; }
    int getTotalSeats()   { return totalSeats; }
    int getOccupied()     { return occupiedSeats; }
    bool isFull()         { return occupiedSeats >= totalSeats; }

    int assignSeat() {
        if(!isFull()) { occupiedSeats++; return occupiedSeats; }
        return -1;
    }

    virtual void displayStatus() {
        cout << "Hall    : " << hallName << endl;
        cout << "Total   : " << totalSeats << endl;
        cout << "Filled  : " << occupiedSeats << endl;
        cout << "Vacant  : " << totalSeats - occupiedSeats << endl;
    }
};


class ExamHall : public Hall {
protected:
    string examDate;
    string invigilatorName;

public:
    ExamHall() : Hall() { examDate = ""; invigilatorName = "Not Assigned"; }

    ExamHall(string name, int seats, string date)
        : Hall(name, seats) {
        examDate = date;
        invigilatorName = "Not Assigned";
    }

    string getExamDate(){ 
        return examDate; 
    }
    string getInvigilatorName(){ 
        return invigilatorName; 
    }
    void setInvigilatorName(string n) { 
        invigilatorName = n; 
    }

    void displayStatus() override {
        Hall::displayStatus();
        cout << "Exam Date    : " << examDate << endl;
        cout << "Invigilator  : " << invigilatorName << endl;
        cout << "----------------------------" << endl;
    }
};

class SpecialHall : public ExamHall {
private:
    string specialFeature;

public:
    SpecialHall() : ExamHall() { specialFeature = "None"; }

    SpecialHall(string name, int seats, string date, string feature)
        : ExamHall(name, seats, date) {
        specialFeature = feature;
    }

    void displayStatus() override {
        ExamHall::displayStatus();
        cout << "Feature      : " << specialFeature << endl;
        cout << "----------------------------" << endl;
    }
};

class SeatingSystem {
private:
    Student     students[50];       
    ExamHall    halls[9];          
    SpecialHall specialHall;  
    Invigilator invigilators[10];
    int studentCount;
    int invigilatorCount;

    ExamHall* getHallByIndex(int idx) {
        if(idx >= 0 && idx <= 8) return &halls[idx];
        if(idx == 9) return &specialHall;
        return nullptr;
    }

    void printHallList() {
        cout << "\n===== HALLS =====" << endl;
        for(int i = 0; i < 9; i++) {
            cout << i+1 << ". " << halls[i].getHallName()
                 << " [" << halls[i].getOccupied() << "/"
                 << halls[i].getTotalSeats() << "]"
                 << " | Invigilator: " << halls[i].getInvigilatorName() << endl;
        }
        cout << "10. " << specialHall.getHallName()
             << " [" << specialHall.getOccupied() << "/"
             << specialHall.getTotalSeats() << "]"
             << " | Invigilator: " << specialHall.getInvigilatorName() << endl;
        cout << "----------------------------" << endl;
    }

public:
    SeatingSystem() {
        studentCount     = 0;
        invigilatorCount = 0;

     
        string hallNames[9] = {"Hall A","Hall B","Hall C","Hall D","Hall E",
                               "Hall F","Hall G","Hall H","Hall I"};
        for(int i = 0; i < 9; i++)
            halls[i] = ExamHall(hallNames[i], 5, "15-March-2026");


        specialHall = SpecialHall("Hall J (Special)", 5, "15-March-2026", "Wheelchair Accessible");
    }

    ~SeatingSystem() {
        cout << "\nSystem shut down. Goodbye!" << endl;
    }

    void addStudent() {
        if(studentCount >= 50) { cout << "All seats full!" << endl; return; }

        int roll;
        string name, branch;
        cout << "Enter Roll No : "; cin >> roll;
        cout << "Enter Name    : "; cin.ignore(); getline(cin, name);
        cout << "Enter Branch  : "; getline(cin, branch);

        int seatNo = -1;
        string assignedHallName = "";

        for(int i = 0; i < 9; i++) {
            if(!halls[i].isFull()) {
                seatNo = halls[i].assignSeat();
                assignedHallName = halls[i].getHallName();
                break;
            }
        }

        if(seatNo == -1 && !specialHall.isFull()) {
            seatNo = specialHall.assignSeat();
            assignedHallName = specialHall.getHallName();
        }

        if(seatNo == -1) { cout << "No seats available in any hall!" << endl; return; }

        students[studentCount] = Student(studentCount+1, name, roll, branch);
        students[studentCount].setAssignedHall(assignedHallName);
        students[studentCount].setAssignedSeat(seatNo);
        studentCount++;

        cout << " Assigned -> " << assignedHallName << " | Seat No: " << seatNo << endl;
    }

    //  Display All Students 
    void displayAllStudents() {
        if(studentCount == 0) { cout << "No students added yet." << endl; return; }
        cout << "\n===== ALL STUDENTS =====" << endl;
        for(int i = 0; i < studentCount; i++) {
            students[i].display();
            cout << "----------------------------" << endl;
        }
    }

    //  Display Students Hall-wise 
    void displayHallWise() {
        printHallList();
        int choice;
        cout << "Select Hall to view students (1-10): ";
        cin >> choice;
        if(choice < 1 || choice > 10) { cout << "Invalid!" << endl; return; }

        string selectedHall = (choice <= 9) ? halls[choice-1].getHallName()
                                            : specialHall.getHallName();

        cout << "\n===== STUDENTS IN " << selectedHall << " =====" << endl;
        bool found = false;
        for(int i = 0; i < studentCount; i++) {
            if(students[i].getAssignedHall() == selectedHall) {
                students[i].display();
                cout << "----------------------------" << endl;
                found = true;
            }
        }
        if(!found) cout << "No students assigned to this hall yet." << endl;
    }

    //  Search Student 
    void searchStudent() {
        int roll;
        cout << "Enter Roll No: "; cin >> roll;
        bool found = false;
        for(int i = 0; i < studentCount; i++) {
            if(students[i].getRollNo() == roll) {
                cout << "\n--- Student Found ---" << endl;
                students[i].display();
                found = true; break;
            }
        }
        if(!found) cout << "Student not found!" << endl;
    }

    // Add Invigilator 
    void addInvigilator() {
        if(invigilatorCount >= 10) { cout << "Max 10 invigilators allowed!" << endl; return; }

        string name, subject;
        cout << "Enter Invigilator Name : "; cin.ignore(); getline(cin, name);
        cout << "Enter Subject          : "; getline(cin, subject);

        invigilators[invigilatorCount] = Invigilator(invigilatorCount+1, name, subject);
        invigilatorCount++;
        cout << " Invigilator added successfully!" << endl;
    }

    //  Assign Invigilator to Hall 
    void assignInvigilator() {
        if(invigilatorCount == 0) { cout << "No invigilators added yet!" << endl; return; }

        // Show invigilators
        cout << "\n===== INVIGILATORS =====" << endl;
        for(int i = 0; i < invigilatorCount; i++) {
            cout << i+1 << ". " << invigilators[i].getName()
                 << " (" << invigilators[i].getSubject() << ")"
                 << " | " << (invigilators[i].getIsAssigned()
                    ? "Assigned to: " + invigilators[i].getAssignedHall()
                    : "Not Assigned") << endl;
        }

        int invChoice;
        cout << "Select Invigilator (1-" << invigilatorCount << "): ";
        cin >> invChoice;
        if(invChoice < 1 || invChoice > invigilatorCount) { cout << "Invalid!" << endl; return; }
        invChoice--;

        // Show halls
        printHallList();
        int hallChoice;
        cout << "Select Hall (1-10): ";
        cin >> hallChoice;
        if(hallChoice < 1 || hallChoice > 10) { cout << "Invalid hall!" << endl; return; }
        hallChoice--;

        ExamHall* selectedHall = getHallByIndex(hallChoice);

        // Handle reassignment
        if(selectedHall->getInvigilatorName() != "Not Assigned") {
            cout << "Hall already has: " << selectedHall->getInvigilatorName() << endl;
            cout << "Reassign? (1=Yes / 0=No): ";
            int confirm; cin >> confirm;
            if(confirm != 1) return;

            // Unassign old invigilator
            for(int i = 0; i < invigilatorCount; i++) {
                if(invigilators[i].getAssignedHall() == selectedHall->getHallName()) {
                    invigilators[i].unassign();
                    break;
                }
            }
        }

        invigilators[invChoice].assignToHall(selectedHall->getHallName());
        selectedHall->setInvigilatorName(invigilators[invChoice].getName());

        cout << "✓ " << invigilators[invChoice].getName()
             << " assigned to " << selectedHall->getHallName() << endl;
    }

    // View Invigilator Assignments
    void viewInvigilatorAssignments() {
        if(invigilatorCount == 0) { cout << "No invigilators added yet!" << endl; return; }
        cout << "\n===== INVIGILATOR ASSIGNMENTS =====" << endl;
        for(int i = 0; i < invigilatorCount; i++) {
            invigilators[i].display();
            cout << "----------------------------" << endl;
        }
    }

    // Display All Halls Status
    void displayHalls() {
        cout << "\n===== ALL HALL STATUS =====" << endl;
        for(int i = 0; i < 9; i++) halls[i].displayStatus();
        specialHall.displayStatus();
    }

    // Summary 
    void displaySummary() {
        int totalSeats = 10 * 5;
        int totalFilled = studentCount;
        int totalVacant = totalSeats - totalFilled;

        cout << "\n===== SUMMARY =====" << endl;
        cout << "Total Halls       : 10" << endl;
        cout << "Total Seats       : " << totalSeats << endl;
        cout << "Seats Filled      : " << totalFilled << endl;
        cout << "Seats Vacant      : " << totalVacant << endl;
        cout << "Invigilators Added: " << invigilatorCount << endl;
        cout << "----------------------------" << endl;
        cout << left;
        cout.width(15); cout << "Hall";
        cout.width(10); cout << "Filled";
        cout.width(10); cout << "Vacant";
        cout << "Invigilator" << endl;
        cout << "----------------------------" << endl;
        for(int i = 0; i < 9; i++) {
            cout.width(15); cout << halls[i].getHallName();
            cout.width(10); cout << halls[i].getOccupied();
            cout.width(10); cout << halls[i].getTotalSeats() - halls[i].getOccupied();
            cout << halls[i].getInvigilatorName() << endl;
        }
        cout.width(15); cout << specialHall.getHallName();
        cout.width(10); cout << specialHall.getOccupied();
        cout.width(10); cout << specialHall.getTotalSeats() - specialHall.getOccupied();
        cout << specialHall.getInvigilatorName() << endl;
    }

    //  Save to File 
    void saveToFile() {
        ofstream file("seating.txt");
        if(!file) { cout << "File error!" << endl; return; }

        file << "========================================\n";
        file << "       EXAM SEATING ARRANGEMENT\n";
        file << "========================================\n\n";

        file << "--- HALL STATUS ---\n";
        for(int i = 0; i < 9; i++) {
            file << "Hall: " << halls[i].getHallName()
                 << " | Invigilator: " << halls[i].getInvigilatorName()
                 << " | Seats: " << halls[i].getOccupied() << "/" << halls[i].getTotalSeats() << "\n";
        }
        file << "Hall: " << specialHall.getHallName()
             << " | Invigilator: " << specialHall.getInvigilatorName()
             << " | Seats: " << specialHall.getOccupied() << "/" << specialHall.getTotalSeats() << "\n\n";

        file << "--- STUDENTS ---\n";
        for(int i = 0; i < studentCount; i++) {
            file << "Roll: " << students[i].getRollNo()
                 << " | Name: "   << students[i].getName()
                 << " | Branch: " << students[i].getBranch()
                 << " | Hall: "   << students[i].getAssignedHall()
                 << " | Seat: "   << students[i].getAssignedSeat() << "\n";
        }
        file.close();
        cout << "✓ Saved to seating.txt" << endl;
    }

    //  Load from File 
    void loadFromFile() {
        ifstream file("seating.txt");
        if(!file) { cout << "No saved file found." << endl; return; }
        string line;
        cout << "\n===== FROM FILE =====\n";
        while(getline(file, line)) cout << line << endl;
        file.close();
    }
};

int main() {
    SeatingSystem sys;
    int choice;

    do {
        cout << "\n========================================" << endl;
        cout << "       EXAM SEATING SYSTEM" << endl;
        cout << "========================================" << endl;
        cout << "1.  Add Student" << endl;
        cout << "2.  Display All Students" << endl;
        cout << "3.  View Students Hall-wise" << endl;
        cout << "4.  Search Student by Roll No" << endl;
        cout << "5.  Display All Halls Status" << endl;
        cout << "6.  Display Summary" << endl;
        cout << "7.  Add Invigilator" << endl;
        cout << "8.  Assign Invigilator to Hall" << endl;
        cout << "9.  View Invigilator Assignments" << endl;
        cout << "10. Save to File" << endl;
        cout << "11. Load from File" << endl;
        cout << "0.  Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
               sys.addStudent();                
               break;
            case 2:
              sys.displayAllStudents();        
              break;
            case 3:
              sys.displayHallWise();           
              break;
            case 4:
              sys.searchStudent();             
              break;
            case 5:
              sys.displayHalls();              
              break;
            case 6:
              sys.displaySummary();            
              break;
            case 7:
              sys.addInvigilator();            
              break;
            case 8:
              sys.assignInvigilator();         
              break;
            case 9:
              sys.viewInvigilatorAssignments();
              break;
            case 10:
              sys.saveToFile();                
              break;
            case 11:
             sys.loadFromFile();              
             break;
            case 0:
              cout << "Exiting..." << endl;   
              break;
            default:
              cout << "Invalid choice!" << endl;
        }
    } while(choice != 0);

    return 0;
}
