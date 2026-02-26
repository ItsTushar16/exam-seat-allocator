# Exam Seating Allocator 🎓

A robust, console-based **Exam Seating Management System** built in C++. This application automates the process of assigning students to specific exam halls and seats based on availability, ensuring no double-booking and providing easy data persistence.



## 🚀 Features

* **Automated Seat Assignment**: Automatically finds the next available hall and assigns a unique seat number.
* **Conflict Prevention**: Validates duplicate roll numbers to ensure data integrity.
* **Real-time Hall Status**: Track total capacity, occupied seats, and remaining vacancy across 5 different halls (A through E).
* **Search Functionality**: Quickly locate a student's hall and seat number using their unique Roll No.
* **Data Persistence**: Save the entire seating arrangement to a `seating.txt` file and load it back during your next session.

## 🛠️ Technical Implementation

The project is built using **C++ Object-Oriented Programming (OOP)** concepts:
* **Encapsulation**: Private data members with public getter/setter methods.
* **Abstraction**: Internal logic for seat increments and hall selection is hidden within the `ExamHall` and `SeatingSystem` classes.
* **File I/O**: Utilizes the `<fstream>` library for persistent storage.

### System Configuration
| Hall Name | Capacity |
| :--- | :--- |
| Hall A | 5 Seats |
| Hall B | 4 Seats |
| Hall C | 8 Seats |
| Hall D | 10 Seats |
| Hall E | 20 Seats |
| **Total** | **47 Seats** |

---


## 📊 Sample Interaction

```text
===== EXAM SEATING SYSTEM =====
1. Add Student
2. Display All Students
3. Search by Roll No
4. Display Hall Status
5. Save to File
6. Load from File
0. Exit

Enter choice: 1
Enter Roll No : 251302165
Enter Name    : Tushar Tiwari
Student assigned to Hall A, Seat No: 1
