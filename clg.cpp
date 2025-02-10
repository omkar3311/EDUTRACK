#include <bits/stdc++.h>
using namespace std;
string initialcap(string);
// Class representing a student with attributes like name, roll number, password, and marks.
class student
{
protected:
    int roll, attendance;
    string name, pass;
    int os, coa, cn, at, se, per;

public:
    student() {};
    student(string a, string b, int c) : name(a), pass(b), roll(c), os(0), coa(0), cn(0), at(0), se(0), per(0), attendance(0) {}
    // Function to read student data from a file and display it
    void read(string file1)
    {
        ifstream file(file1);
        string line;
        while (getline(file, line))
        { // Parsing student data from the file
            string name, pass;
            int roll = 0, os = 0, coa = 0, cn = 0, at = 0, se = 0, attendance = 0;
            double per = 0.0;
            stringstream s(line);
            getline(s, name, ',');
            s >> roll;
            s.ignore();
            getline(s, pass, ',');
            s >> os;
            s.ignore();
            s >> coa;
            s.ignore();
            s >> cn;
            s.ignore();
            s >> at;
            s.ignore();
            s >> se;
            s.ignore();
            s >> per;
            s.ignore();
            s >> attendance;
            // Display student details to teacher & HOD
            cout << "Name: " << initialcap(name) << " Roll: " << roll
                 << "\n OS Marks: " << os << " COA Marks: " << coa
                 << " CN Marks: " << cn << " AT Marks: " << at
                 << " SE Marks: " << se << " Percentage: " << per << "%"
                 << " ATTENDANCE:" << attendance << "%\n"
                 << endl;
        }

        file.close();
    }

    // Function to read only 1 student data
    void readst(string file1, string fname)
    {
        ifstream file(file1);
        string line;
        bool found = false;

        while (getline(file, line))
        {
            stringstream s(line);
            string name, pass;
            int roll = 0, os = 0, coa = 0, cn = 0, at = 0, se = 0, attendance = 0;
            double per;
            getline(s, name, ',');
            s >> roll;
            s.ignore();
            getline(s, pass, ',');
            s >> os;
            s.ignore();
            s >> coa;
            s.ignore();
            s >> cn;
            s.ignore();
            s >> at;
            s.ignore();
            s >> se;
            s.ignore();
            s >> per;
            s.ignore();
            s >> attendance;
            if (name == fname)
            {
                found = true;
                cout << "Name: " << initialcap(name) << endl
                     << "Roll: " << roll << endl;
                // Marks are shown to student when they get updated
                if (os != 0)
                {
                    cout << "OS marks: " << os << endl
                         << "COA marks: " << coa << endl
                         << "CN marks: " << cn << endl
                         << "AT marks: " << at << endl
                         << "SE marks: " << se << endl
                         << "Percentage: " << per << "%" << endl;
                }
                if (attendance != 5 && attendance < 100)
                {
                    cout << "Attendance: " << attendance << "%" << endl;
                }
                break;
            }
        }

        if (!found)
        {
            cout << "Student with name '" << fname << "' not found." << endl;
        }

        file.close();
    }
    //Function to check wheather searched line is string or int
    bool stringorint(string line)
    {
        for (auto l : line)
        {
            if (isdigit(l))
            {
                return true;
            }
        }
    }
    //Function to search student by name or roll
    void search(string file1, string find)
    {
        ifstream file(file1);
        string line;
        if (stringorint(find))
        {
            int froll;
            froll = stoi(find);
            while (getline(file, line))
            {
                stringstream s(line);
                string name, pass;
                int roll;
                double per;
                getline(s, name, ',');
                s >> roll;
                s.ignore();
                if (froll == roll)
                {
                    readst(file1, name);
                }
            }
        }
        else
        {
            readst(file1, find);
        }
    }
    // Function to enroll on file
    void write(string file1, string name, int roll = 0)
    {
        ofstream file(file1, ios::app);
        if (check(file1, name))
        {
            cout << "user exits!!" << endl;
        }
        else
        {
            file << name << "," << roll << "," << pass << endl;
        }
    }
    // Function to check user exits or not by Name
    bool check(string file1, string name)
    {
        ifstream file(file1);
        string line;
        while (getline(file, line))
        {
            stringstream s(line);
            string fname;
            getline(s, fname, ',');
            if (name == fname)
            {
                return true;
            }
        }
        return false;
    }
    // Function to check password
    bool password(string file1, string pass)
    {
        ifstream file(file1);
        string line;
        while (getline(file, line))
        {
            stringstream s(line);
            string tpass, name;
            int roll;
            getline(s, name, ',');
            s >> roll;
            s.ignore();
            getline(s, tpass, ',');
            s.ignore();
            if (pass == tpass)
            {
                return true;
            }
        }
        return false;
    }
    // Function to check user exits or not by Roll number
    bool croll(string file1, int roll)
    {
        ifstream file(file1);
        string line;
        while (getline(file, line))
        {
            stringstream s(line);
            string name;
            int troll;
            getline(s, name, ',');
            s >> troll;
            s.ignore();
            if (roll == troll)
            {
                return true;
            }
        }
        return false;
    }
};
// fuction to convert uppercase string to lowercase
string lower(string lname)
{
    for (auto &n : lname)
    {
        n = tolower(n);
    }
    return lname;
}
string initialcap(string name)
{
    bool space = true;
    for (char &s : name)
    {
        if (isspace(s))
        {
            space = true;
        }
        else if (space)
        {
            s = toupper(s);
            space = false;
        }
        else
        {
            s = tolower(s);
        }
    }
    return name;
}
// teacher file name
string file2 = "teacher.txt";
// Class representing a teacher with attributes like name, id number, password, and salary.
class teacher : public student
{
protected:
    string na, pa, sub;
    int id, c;
    double salary;

public:
    teacher() {}
    teacher(string n, string p, string su, int i = 0, double s = 0) : na(n), pa(p), sub(su), id(i), salary(s) {}
    // Update student name and roll number
    void updatestname(string file1, string oname, string nname, int nroll)
    {
        ifstream file(file1);
        vector<string> data;
        string line;
        cin.ignore();
        while (getline(file, line))
        {
            string name, pass;
            int roll;
            stringstream s(line);
            getline(s, name, ',');
            s >> roll;
            s.ignore();
            getline(s, pass);
            if (name == oname)
            {
                data.push_back(nname + "," + to_string(nroll) + pass);
            }
            else
            {
                data.push_back(line);
            }
        }
        file.close();

        ofstream newfile(file1);
        for (string &it : data)
        {
            newfile << it << endl;
        }
        cout << "data updated successfully" << endl;
    }
    // Update student marks
    void updatestmark(string file1, string fname, int os1, int coa1, int cn1, int at1, int se1)
    {
        ifstream file(file1);
        vector<string> data;
        string line;
        while (getline(file, line))
        {
            stringstream s(line);
            string name, pass;
            int roll, os, coa, cn, at, se, attendance;
            double per;
            getline(s, name, ',');
            s >> roll;
            s.ignore();
            getline(s, pass, ',');
            s >> os;
            s.ignore();
            s >> coa;
            s.ignore();
            s >> cn;
            s.ignore();
            s >> at;
            s.ignore();
            s >> se;
            s.ignore();
            s >> per;
            s.ignore();
            s >> attendance;
            if (name == fname)
            {
                double updated_per = (os1 + coa1 + cn1 + at1 + se1) / 5.0;
                data.push_back(name + "," + to_string(roll) + "," + pass + "," + to_string(os1) +
                               "," + to_string(coa1) + "," + to_string(cn1) + "," + to_string(at1) +
                               "," + to_string(se1) + "," + to_string(updated_per) + "," + to_string(attendance));
            }
            else
            {
                data.push_back(line);
            }
        }
        file.close();
        ofstream newfile(file1);
        for (const string &it : data)
        {
            newfile << it << endl;
        }
        cout << "Marks updated successfully!" << endl;
    }
    // Update student attendance
    void updatestattendance(string file1, string fname, int attendance1)
    {
        ifstream file(file1);
        vector<string> data;
        string line;
        while (getline(file, line))
        {
            stringstream s(line);
            string name, pass;
            int roll, os, coa, cn, at, se, attendance;
            double per;
            getline(s, name, ',');
            s >> roll;
            s.ignore();
            getline(s, pass, ',');
            s >> os;
            s.ignore();
            s >> coa;
            s.ignore();
            s >> cn;
            s.ignore();
            s >> at;
            s.ignore();
            s >> se;
            s.ignore();
            s >> per;
            s.ignore();
            s >> attendance;
            if (name == fname)
            {
                data.push_back(name + "," + to_string(roll) + "," + pass + "," + to_string(os) +
                               "," + to_string(coa) + "," + to_string(cn) + "," + to_string(at) +
                               "," + to_string(se) + "," + to_string(per) + "," + to_string(attendance1));
            }
            else
            {
                data.push_back(line);
            }
        }
        file.close();
        ofstream newfile(file1);
        for (const string &it : data)
        {
            newfile << it << endl;
        }
        cout << "Attendance updated successfully!" << endl;
    }
    // Function made to entertainment when teacher or student file is missing
    void fun()
    {
        char a, b, c, d, e;
        cout << "are you the one who write this code?(y/n):";
        cin >> a;
        a = tolower(a);
        if (a == 'y')
        {
            cout << "nahh!!  if you write it then you never reach here\ndid you get the permission(y/n):";
            cin >> b;
            b = tolower(b);
            if (b == 'y')
            {
                cout << "ask him again\nand try again!";
            }
            else
            {
                cout << "i cound't help you\nsorry!!!";
            }
        }
        else
        {
            cout << "did you get the permission(y/n):";
            cin >> c;
            c = tolower(c);
            if (c == 'y')
            {
                cout << "ask him again\nand try again!";
            }
            else
            {
                cout << "i cound't help you\nsorry!!!";
            }
        }
    }

    void updatestudentdata(const string &file1, string &name)
    {

        int c;
        string nm, line, t;

        cout << "what do you want to update:\n1.details\n2.marks\n3.attendance\nselect:";
        cin >> c;
        cin.ignore();
        switch (c)
        {
        case 1:
            cout << "change name:";
            getline(cin, nm);
            cout << "change roll number:";
            cin >> roll;
            updatestname(file1, name, nm, roll);
            t = nm;
            nm = name;
            name = t;
            break;
        case 2:
            cout << "Enter mark of 'OS':";
            cin >> os;
            cout << "Enter mark of 'COA':";
            cin >> coa;
            cout << "Enter mark of 'CN-II':";
            cin >> cn;
            cout << "Enter mark of 'AT':";
            cin >> at;
            cout << "Enter mark of 'SE':";
            cin >> se;
            updatestmark(file1, name, os, coa, cn, at, se);
            break;
        case 3:
            cout << "update attendance:";
            cin >> attendance;
            if (attendance > 100)
            {
                cout << "do you have any limit?" << endl;
            }
            else
            {
                updatestattendance(file1, name, attendance);
                break;
            }
        default:
            cout << "invalid choice!" << endl;
        }
    }
    // Add teacher data in teacher file
    void writet(string file2, string name)
    {
        ofstream file(file2, ios::app);
        if (check(file2, name))
        {
            cout << "user exits!!" << endl;
        }
        else
        {
            file << na << "," << id << "," << pa << "," << sub << "," << salary << endl;
        }
    }
    // all teachers data access by HOD
    void readt(string file2)
    {
        ifstream file(file2);
        string line;
        while (getline(file, line))
        {
            stringstream s(line);
            getline(s, na, ',');
            s >> id;
            s.ignore();

            getline(s, pa, ',');
            s >> sub;
            s.ignore();
            s >> salary;
            cout << "name:" << initialcap(na) << " id:" << id << " subject:" << sub << " salary:" << salary << "rs" << endl;
        }
    }
    // only 1 teachers data access by HOD or teacher view himself
    void readt(string file1, string fname)
    {
        ifstream file(file1);
        string line;
        while (getline(file, line))
        {
            stringstream s(line);
            getline(s, na, ',');
            s >> id;
            s.ignore();
            getline(s, pa, ',');
            getline(s, sub, ',');
            s >> salary;
            if (fname == na)
            {
                cout << "name:" << initialcap(na) << " id:" << id << " subject:" << sub << " salary:" << salary << "rs" << endl;
                break;
            }
        }
    }
    // HOD can update salary of teacher
    void updatetsalary(string file2, string fname, int nsalary)
    {
        cout << fname << endl;
        ifstream file(file2);
        string line;
        vector<string> data;
        while (getline(file, line))
        {
            stringstream s(line);
            string name, pass;
            int id, salary;
            getline(s, name, ',');
            s >> id;
            s.ignore();
            getline(s, pass, ',');
            s >> sub;
            s.ignore();
            s >> salary;
            if (name == fname)
            {
                data.push_back(name + "," + to_string(id) + "," + pass + "," + sub + "," + to_string(nsalary));
            }
            else
            {
                data.push_back(line);
            }
        }
        file.close();
        ofstream newfile(file2);
        for (const string &it : data)
        {
            newfile << it << endl;
        }
        cout << "Salary updated successfully!" << endl;
    }
    // Function change teacher name and id
    void updateteachername(string file2, string oname, string nname, string nsub, int nid)
    {
        ifstream file(file2);
        vector<string> data;
        string line;
        while (getline(file, line))
        {
            string name, pass;
            int id, salary;
            stringstream s(line);
            getline(s, name, ',');
            s >> id;
            s.ignore();
            getline(s, pass, ',');
            s >> sub;
            s.ignore();
            s >> salary;
            if (name == oname)
            {
                data.push_back(nname + "," + to_string(nid) + "," + pass + "," + sub + "," + to_string(salary));
            }
            else
            {
                data.push_back(line);
            }
        }
        file.close();
        ofstream newfile(file2);
        for (const string &it : data)
        {
            newfile << it << endl;
        }
        cout << "Data updated successfully!" << endl;
    }
    void updateteacherdata(string file2, string name1)
    {

        int c, sal;
        string nm, nsub;
        cout << "what do you want to update:\n1.details\n2.salary\nselect:";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "change name:";
            cin.ignore();
            getline(cin, nm);
            cout << "change id number:";
            cin >> roll;
            cout << "change subject:";
            cin >> nsub;
            updateteachername(file2, name1, nm, nsub, roll);
            break;
        case 2:
            cout << "change salary:";
            cin >> sal;
            updatetsalary(file2, name1, sal);
        }
    }
};
// Class representing the Head of Department (HOD), inheriting from teacher
// which shows multilevel inheritance   //hod inherited teacher inherited student
class hod : public teacher
{

public:
    string name = "hod", pass = "123";
    double salary = 10;
};
// Function declaration
void signup(string file1, string file2, string s);
// Student file name
string file1 = "student.txt";
// Function to give option to student ,teacher &HOD
void option(string prof, string file1, string file2, string name1 = "")
{
    student st;
    teacher t;
    hod h;
    string n, nm, sub;
    string temp;
    int c, a = 0, roll;
    if (prof == "student")
    {
        while (a != 1)
        {
            cout << "1.change profile\n2.view profile\n3.back:";
            cin >> c;
            cin.ignore();
            switch (c)
            {
            case 1:
                cout << "change name:";
                getline(cin, nm);
                nm = lower(nm);
                cout << "change roll number:";
                cin >> roll;
                t.updatestname(file1, name1, nm, roll);
                temp = name1;
                name1 = nm;
                nm = temp;
                break;
            case 2:

                st.readst(file1, name1);
                break;
            case 3:
                a = 1;
                break;
            default:
                cout << "invalid option!";
            }
        }
    }
    else if (prof == "teacher")
    {
        char a;
        while (a != 1)
        {
            cout << "1.change profile\n2.view profile\n3.detail of all class\n4.detail of student\n5.add student\n6.back:";
            cin >> c;
            switch (c)
            {
            case 1:
                cout << "change name:";
                cin.ignore();
                getline(cin, nm);
                nm = lower(nm);
                cout << "change id number:";
                cin >> roll;
                cout << "change subject:";
                cin >> sub;
                t.updateteachername(file2, name1, nm, sub, roll);
                temp = name1;
                name1 = nm;
                nm = temp;
                break;
            case 2:
                t.readt(file2, name1);
                break;
            case 3:
                t.read(file1);
                break;
            case 4:
                int nn;
                cout << "search student(name/roll):";
                cin.ignore();
                getline(cin, n);
                if (st.stringorint(n))
                {
                    nn = stoi(n);
                }
                else
                {
                    n = lower(n);
                }
                if (st.check(file1, n) || st.croll(file1, nn))
                {
                    // t.readst(file1, n);
                    if(st.stringorint(n)){
                    t.search(file1,n);}
                    else{
                        t.search(file1,n);
                    }
                    cout << "do you want to update(y/n):";
                    cin >> a;
                    if (a == 'y')
                    {
                        t.updatestudentdata(file1, n);
                    }
                }
                else
                {
                    cout << "no one is there!" << endl;
                }
                break;
            case 5:
                signup(file1, file2, "student");
                break;
            case 6:
                a = 1;
                break;
            default:
                cout << "invalid option!";
            }
        }
    }
    else if (prof == "hod")
    {
        while (a != 1)
        {
            char aa;
            cout << "1.view profile\n2.detail of all teachers\n3.detail of teacher\n4.add teacher\n"
                 << "5.detail of all class\n6.detail of student\n7.add student\n8.back:";
            cin >> c;
            switch (c)
            {
            case 1:
                cout << "name:" << h.name << " salary:" << h.salary << endl;
                break;
            case 2:
                h.readt(file2);
                break;
            case 3:
                cout << "enter name to find:";
                cin.ignore();
                getline(cin, n);
                n = lower(n);
                if (st.check(file2, n))
                {
                    h.readt(file2, n);
                    cout << "do you want to update(y/n):";
                    cin >> a;
                    if (a == 'y')
                    {
                        t.updateteacherdata(file2, n);
                    }
                }
                else
                {
                    cout << "no one is there!" << endl;
                }

                break;
            case 4:
                signup(file1, file2, "teacher");
                break;
            case 5:
                t.read(file1);
                break;
            case 6:
                cout << "enter name to find:";
                cin.ignore();
                getline(cin, n);
                n = lower(n);
                if (st.check(file1, n))
                {
                    t.readst(file1, n);
                    cout << "do you want to update(y/n):";
                    cin >> a;
                    if (aa == 'y'||aa == '1')
                    {
                        t.updatestudentdata(file1, n);
                    }
                }
                else
                {
                    cout << "no one is there!" << endl;
                }
                break;
            case 7:
                signup(file1, file2, "student");
                break;
            case 8:
                a = 1;
                break;
            default:
                cout << "invalid option!";
            }
        }
    }
}
void signup(string file1, string file2, string s)
{
    string name, pass, file;
    student st;
    teacher t;
    hod h;
    if (s == "student")
    {
        file = "student.txt";
    }
    else if (s == "teacher")
    {
        file = "teacher.txt";
    }
    cin.ignore();
    cout << "enter details\nenter name:";
    getline(cin, name);
    name = lower(name);
    if (st.check(file, name))
    {
        cout << "user exits!!" << endl;
    }
    else
    {
        if (s == "student")
        {

            cout << "enter roll number:";
        }
        else if (s == "teacher")
        {

            cout << "enter id number:";
        }
        int roll;
        cin >> roll;
        if (st.croll(file, roll))
        {
            cout << "roll number taken!" << endl;
        }
        else
        {
            cout << "create password:";
            cin >> pass;
            if (s == "student")
            {

                cout << "remember your password" << " ' " << pass << " '" << endl
                     << "registered successfully!" << endl;

                student st(name, pass, roll);
                st.write(file1, name, roll);
            }
            else if (s == "teacher")
            {

                cout << "enter your salary:";
                double salary;
                cin >> salary;
                string sub;
                cout << "enter your subject:";
                cin >> sub;
                cout << "remember your password" << " ' " << pass << " '" << endl
                     << "registered successfully!" << endl;
                teacher t(name, pass, sub, roll, salary);
                t.writet(file2, name);
            }
            option(s, file1, file2, name);
        }
    }
}
// Function to login & sign in
string sign(string &file1, string &file2)
{

    student st;
    teacher t;
    hod h;
    ifstream file_1(file1);
    ifstream file_2(file2);
    if (!file_1.is_open() || !file_2.is_open())
    {
        t.fun();
    }
    else
    {
        int a, c = 0, i = 0, t = 0;
        string name, s, pass, swap, file, tea;
        bool tr = true;
        while (tr)
        {
            cout << "who are you:\nstudent\t\tteacher\t\thod\t\texit" << endl
                 << "enter here:";
            cin >> s;
            s = lower(s);
            cout << s << endl;
            t = 0;
            if (s == "student" || s == "teacher")
            {
                while (1)
                {
                    if (s == "teacher" && t == 0)
                    {
                        cout << "enter teacher special password:";
                        cin.ignore();
                        getline(cin, tea);
                        if (tea == "teacher"|| tea=="123")
                        {
                            file = "teacher.txt";
                            t = 1;
                        }
                        else
                        {
                            cout << "wrong password!" << endl;
                            break;
                        }
                    }
                    cout << "LOGIN" << endl;
                    cout << "1.log in\t2.sign up\t3.back" << endl;
                    cin >> a;
                    cin.ignore();
                    if (s == "student")
                    {
                        file = "student.txt";
                    }
                    else if (s == "teacher")
                    {
                        file = "teacher.txt";
                    }

                    if (a == 1)
                    {
                        cout << "enter name:";
                        getline(cin, name);
                        name = lower(name);
                        if (st.check(file, name))
                        {
                            cout << "welcome back!\n";
                            c = 0;
                            while (c < 3)
                            {
                                cout << "enter password:";
                                cin >> pass;
                                if (st.password(file, pass))
                                {
                                    option(s, file1, file2, name);
                                    break;
                                }
                                else
                                {
                                    cout << "wrong password!!!\ntry again" << endl;
                                    c++;
                                }
                                if (c == 3)
                                {
                                    cout << "sorry!!!trials are over!";
                                    break;
                                }
                            }
                        }
                        else
                        {
                            cout << "no one is there!" << endl;
                        }
                    }
                    else if (a == 2)
                    {
                        signup(file1, file2, s);
                    }
                    else if (a == 3)
                    {
                        break;
                    }
                    else
                    {
                        cout << "invalid choice!!" << endl;
                    }
                }
            }

            else if (s == "hod")
            {
                cout << "enter password:";
                cin >> pass;
                if (h.pass == pass)
                {
                    cout << "welcome back hod!" << endl;
                    option(s, file1, file2);
                }
            }
            else if (s == "exit" || s == "4")
            {
                cout << "thanks for visiting !! ";
                tr = false;
            }
            else
            {
                cout << "Invalid role! Please enter a valid role." << endl;
            }
        }
    }
}
// Main function to execute the program
int main()
{
    sign(file1, file2);
    return 0;
}
