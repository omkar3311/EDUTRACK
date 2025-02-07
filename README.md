 # EduTrack - Student Management System

## Overview
EduTrack is a **C++-based Student Management System** that allows students, teachers, and the Head of Department (HOD) to manage student records efficiently. The system provides features such as:
- Student and teacher login/signup
- Viewing and updating student details
- Managing marks, attendance, and personal information
- Teacher and HOD functionalities to update student records

## Features
### **For Students**
- Login and view personal details
- Update name and roll number
- View marks and attendance

### **For Teachers**
- Login and manage student data
- Update student marks and attendance
- Add new students to the system

### **For HOD**
- Manage teacher records
- Update teacher details
- Oversee the entire student database

## File Structure
- `Clg.cpp` - Main C++ source file implementing the system.
- `student.txt` - Stores student records.
- `teacher.txt` - Stores teacher records.

## How to Use
1. **Compile the program:**
   ```sh
   g++ Clg.cpp -o edutrack
   ```
2. **Run the program:**
   ```sh
   ./edutrack
   ```
3. **Follow on-screen instructions** to sign up or log in as a student, teacher, or HOD.

## Sample Usage
- To sign up as a student, enter your **name, roll number, and password**.
- Teachers can log in with a **special password** to access student records.
- The HOD can manage both **students and teachers**.

## Future Improvements
- Add **file encryption** for better security.
- Implement a **graphical user interface (GUI)**.
- Support **database integration** (MySQL, SQLite).

## Author
- Developed by **Omkar Waghmare**.

---
Let me know if you need any modifications! 🚀

