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
- Default HOD password= 123
- Manage teacher records
- Update teacher details
- Oversee the entire student database

## File Structure
- `Clg.cpp` - Main C++ source file implementing the system.
   You have to create those 2 files in your system
- `student.txt` - Stores student records. 
- `teacher.txt` - Stores teacher records.

## How to Use
1. **Compile the program:**
   ```
   g++ Clg.cpp -o edutrack
   ```
2. **Run the program:**
   ```
   ./edutrack
   ```
3. **Follow on-screen instructions** to sign up or log in as a student, teacher, or HOD.

## Sample Usage
- To sign up as a student, enter your **name, roll number, and password**.
- Teachers can log in with a **special password** ("teacher") to access student records.
- The HOD can manage both **students and teachers**.


## Author
- Developed by **Omkar Waghmare**.


