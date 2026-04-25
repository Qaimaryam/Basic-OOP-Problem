//#include<iostream>
//using namespace std;
//class Patient {
//	const int patientID;
//	char* patientName;
//	int age;
//public:
//	Patient(int id, const char pName[], int a) :patientID(id)
//	{
//		patientName = new char[strlen(pName) + 1]; 
//		strcpy_s(patientName, strlen(pName) + 1, pName);
//		age = a;
//	}
//	void setAge(int ag)
//	{
//		age = ag;
//
//	}
//	int getAge()
//	{
//		return age;
//	}
//	 int getId() const
//	{
//		return patientID;
//	}
//	~Patient()
//	{
//		delete[] patientName;
//	}
//	virtual void display()const {
//		cout << "Pateint Name:"<<patientName <<endl;
//		cout << "Patient Id:"<<patientID <<endl;
//		cout << "Patient Age:"<<age <<endl;
//	}
//	Patient& increaseYear(int year)
//	{
//		age += year;
//		return *this;
//	}
//};
//class Inpatient :public Patient {
//	int roomNumber;
//	double dailyCharges;
//public:
//	Inpatient(int id, const char Name[], int a, int rNum, double dc):Patient(id,Name,a) {
//		roomNumber = rNum;
//		dailyCharges = dc;
//	}
//	void updateDaily(double charges)
//	{
//		dailyCharges = charges;
//	}
//	void display() const override {
//		Patient::display();
//		cout << "Room Number:" << roomNumber << endl;
//		cout << "Daily charges:" << dailyCharges << endl;
//	}
//};
//class Hospital {
//	const int hospitalCode;
//	Patient** patients;
//	int totalPatients;
//public:
//		Hospital(int hCode, int tP) :hospitalCode(hCode)
//        {
//			totalPatients = tP;
//			patients = new Patient * [tP];
//			for (int i = 0; i < tP; i++)
//			{
//				patients[i] = nullptr;
//			}
//
//	    }
//		void addPateint(Patient* p)
//		{
//			for (int i = 0; i < totalPatients; i++)
//			{
//				if (patients[i] == nullptr)
//				{
//					patients[i] = p;
//				}
//			}
//		}
//		~Hospital()
//		{
//			for (int i = 0; i < totalPatients; i++)
//			{
//				delete patients[i];
//			}
//			delete[] patients;
//		}
//		
//		void display()
//		{
//			cout << "Hospital Code:" << hospitalCode << endl;
//			for (int i = 0; i < totalPatients; i++) {
//				if (patients[i] != nullptr)
//				{
//					patients[i]->display();
//				}
//			}
//		}
//	
//		void findPatient(int id) const {
//			cout << "Enter Patent ID you want to find:";
//			cin >> id;
//			for (int i = 0; i < totalPatients; i++)
//			{
//				if (patients[i]->getId() == id)
//				{
//					patients[i]->display();
//				}
//			}
//		}
//};
//int main()
//{
//	char pn[20];
//	int age;
//	int id,room;
//	double dailyCharge;
//	cout << "Patient Information" << endl;
//	Inpatient* ip[3];
//	for (int i = 0; i < 3; i++)
//	{
//		cout << "Enter Name:";
//		cin >> pn;
//		cout << "Enter Id:";
//		cin >> id;
//		cout << "Enter Age:";
//		cin >> age;
//		cout << "Enter Daily charge:";
//		cin >> dailyCharge;
//		cout << "Enter Room Number:";
//		cin >> room;
//		ip[i]=new Inpatient(id, pn, age, room, dailyCharge);
//	}
//	int hc;
//	int total;
//	    cout << "Enter Hospital Code:";
//		cin >> hc;
//		cout << "Enter total Patient:";
//		cin >> total;
//	 Hospital hp(hc, total);
//	
//	for (int i = 0; i < total; i++)
//	{
//		hp.addPateint(ip[i]);
//	}
//	for (int i = 0; i < total; i++)
//	{
//		hp.display();
//	}
//
//	
//	
//
//
//	return 0;
//}
