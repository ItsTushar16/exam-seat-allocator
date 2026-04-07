# 📚 Exam Seating Management System (C++)


A **menu-driven Exam Seating Management System** developed in **C++** using **Object Oriented Programming (OOP)** principles.
The system automates the process of **assigning students to exam halls and seats**, managing **invigilator assignments**, and **saving seating records using file handling**.

This project simulates how educational institutions manage **exam seating arrangements efficiently and systematically**.

---

# 🚀 Features

✔ Automatic **seat allocation for students**

✔ **Exam hall management** with seat tracking

✔ **Special exam hall** support for accessibility

✔ **Invigilator management and assignment**

✔ **Search student by roll number**

✔ **View students hall-wise**

✔ **Hall occupancy summary**

✔ **File handling for saving seating records**

✔ **Menu driven console interface**


---

# 🧠 OOP Concepts Used

This project demonstrates the following **Object Oriented Programming concepts**:

* **Encapsulation**
* **Inheritance**
* **Multilevel Inheritance**
* **Polymorphism (Function Overriding)**
* **Abstraction**
* **Constructor Overloading**
* **Destructors**
* **Arrays of Objects**

---

# 🏗 Project Structure

The system is organized using multiple classes:

| Class           | Description                                               |
| --------------- | --------------------------------------------------------- |
| `Person`        | Base class containing common attributes like ID and Name  |
| `Student`       | Derived class representing student information            |
| `Invigilator`   | Derived class representing exam invigilators              |
| `Hall`          | Base class representing a general exam hall               |
| `ExamHall`      | Derived class containing exam specific details            |
| `SpecialHall`   | Extended hall for accessibility features                  |
| `SeatingSystem` | Core class that manages students, halls, and invigilators |

---

# ⚙ System Workflow

1️⃣ Students are added to the system.
2️⃣ The system automatically assigns the **next available seat**.
3️⃣ Halls are filled sequentially **Hall A → Hall I → Special Hall**.
4️⃣ Invigilators can be added and assigned to halls.
5️⃣ Users can view student lists, hall assignments, and system summary.
6️⃣ Seating records can be **saved to a file** and **loaded later**.

---

# 🖥 Example Menu

```
1. Add Student
2. Display All Students
3. View Students Hall-wise
4. Search Student by Roll No
5. Display All Halls Status
6. Display Summary
7. Add Invigilator
8. Assign Invigilator to Hall
9. View Invigilator Assignments
10. Save to File
11. Load from File
0. Exit
```

---

# 💾 File Storage

The system stores records in:

```
seating.txt
```

The file contains:

* Hall information
* Invigilator assignments
* Student seating details

---

# 🛠 Technologies Used

* **C++**
* **Object Oriented Programming**
* **File Handling (fstream)**


---


# 🎯 Learning Purpose

This project was developed as a **semester project** to demonstrate how **C++ OOP concepts can be applied to solve real-world problems**, such as managing exam seating arrangements in educational institutions.

---

# 🔮 Future Improvements

Possible enhancements for the system:

* GUI interface
* Database integration
* Randomized seating algorithm
* Dynamic memory allocation
* Admin authentication system

---



If you found this project helpful, consider giving it a ⭐.
