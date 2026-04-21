#include<iostream>
using namespace std;
class Student {
	const int rollNumber;
	char* name;
	double cgpa;
public:
	Student(int r,const char n[], double cgp):rollNumber(r){
		name = new char[strlen(n) + 1];
		strcpy_s(name, strlen(n) + 1, n);
		cgpa = cgp;
	}
	Student(const Student& st):rollNumber(st.rollNumber)
	{
		this->name = new char[strlen(st.name) + 1];
	strcpy_s(name, strlen(st.name) + 1, st.name);
      this->cgpa = st.cgpa;
	}
	void setCGPA(double gp)
	{
		cgpa = gp;
	}
	Student& improve(double cg)
	{
		cgpa = cg;
		return *this;
	}
	double getGPA()
	{
		return cgpa;
	}
	int getRollNum()
	{
		return rollNumber;
	}
	virtual void display() const {
		cout << "Name" << name << endl;
		cout << "CGPA:" << cgpa << endl;
		cout << "Roll Number:" << rollNumber << endl;
	}
	~Student()
	{
		delete[] name;
	}
};
class GraduateStudent :public Student {
	char* thesisTitle;
	int researchCredits;
public:
	GraduateStudent(const char t[], int r,int rol,const char n[],double c):Student(rol,n,c) {
		thesisTitle = new char[strlen(t) + 1];
		strcpy_s(thesisTitle, strlen(t) + 1, t);
		researchCredits = r;
	}
	void display() const 
	{
		Student::display();
		cout << "Thesis Title:" << thesisTitle << endl;
		cout << "Research Credits:" << researchCredits << endl;
	}
	void UpdateCredits(int c)
	{
		researchCredits = c;
	}
	GraduateStudent(const GraduateStudent& gs):Student(gs){
		thesisTitle = new char[strlen(gs.thesisTitle) + 1];
		strcpy_s(thesisTitle, strlen(gs.thesisTitle) + 1, gs.thesisTitle);
		researchCredits = gs.researchCredits;
}
	~GraduateStudent()
	{
		delete[] thesisTitle;
	}
};
class Department {
	const int departmentCode;
	Student** students;
	int totalStudents;
public:
	Department(int dc, int t, int r,const char n[], double cgp) :departmentCode(dc) {
		totalStudents = t;
		students = new Student*[totalStudents];
		for (int i = 0; i < totalStudents; i++)
		{
			students[i] = nullptr;
		}
	}
	~Department()
	{
		for (int i = 0; i < totalStudents; i++)
		{
			delete students[i];
	}
		delete[] students;
	}
	void addStudent(Student* s)
	{
		for (int i = 0; i < totalStudents; i++)
		{
			if (students[i] != nullptr)
			{
				students[i] = s;
			}
		}

	}
	void findStudent(int index)const {
		cout << "Enter the student Roll Number you want to find:";
		cin >> index;
		for (int i = 0; i < totalStudents; i++)
		{
			if (students[i]->getRollNum() == index) {
				students[i]->display();
				break;
			}
		}
	}
		void display()
		{
			for (int i = 0; i < totalStudents; i++)
			{
				if (students[i] != nullptr) {
					students[i]->display();
				}
				else {
					cout << "No student at index " << i << endl;
				}
			}
			cout << "Department Code:" << departmentCode << endl;
			cout << "Total Student:" << totalStudents << endl;
		}
};

	int main()
	{
		Department d(101, 3, 0, "", 0.0);
		GraduateStudent* gs1 = new GraduateStudent("Thesis on AI", 6, 1, "Alice", 3.8);
		gs1->display();
		d.addStudent(gs1);
		d.display();
		return 0;



	}