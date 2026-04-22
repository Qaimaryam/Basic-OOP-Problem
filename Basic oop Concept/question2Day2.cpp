//#include<iostream>
//using namespace std;
//class Book {
//	int bookId;
//	char title[100];
//	char auther[40];
//	float price;
//	int branchId;
//	bool isIssued;
//	static int totalBooks;
//	static int totalIssuedBooks;
//	static int  nextBookId;
//public:
//	Book() {
//		bookId = nextBookId++;
//		isIssued = false;
//		strcpy(title, "");
//		strcpy(auther, "");
//		totalBooks++;
//	}
//	Book(char* t, char* a, float p, int brId, bool isIss) {
//		bookId = nextBookId++;
//		strcpy(title, t);
//		strcpy(auther, a);
//		price = p;
//		isIssued = isIss;
//		branchId = brId;
//		totalBooks++;
//	}
//	~Book() {
//		cout << "Book destroyed. ID: " << bookId << endl;
//		totalBooks--;
//		if (isIssued) totalIssuedBooks--;
//	}
//	void issue()
//	{
//		if (isIssued == false)
//		{
//			isIssued = true;
//			totalIssuedBooks++;
//		}
//
//	}
//	void returnBack()
//	{
//		if (isIssued == true)
//		{
//			isIssued = false;
//			totalIssuedBooks--;
//		}
//
//	}
//	void display()
//	{
//		cout << "Book id" << bookId << endl;
//		cout << "Book title" << title << endl;
//		cout << "Book auther" << auther << endl;
//		cout << "Book price" << price << endl;
//		cout << "Branch ID: " << branchId << endl;
//		cout << "Issued: " << (isIssued ? "Yes" : "No") << endl;
//
//	}
//	static void displayStatistics()
//	{
//		cout << "Total book" << totalBooks << endl;
//		cout << "Total issued book" << totalIssuedBooks << endl;
//
//	}
//
//
//};
//int Book::totalBooks = 0;
//int Book::totalIssuedBooks = 0;
//int Book::nextBookId = 1;
//
//class digitalMedia {
//	int resourceId;
//	char title[60];
//	char auther[40];
//	float price;
//	int branchId;
//	bool isIssued;
//	char format[10];
//	float fileSize;
//	static int totalMediaCreated;
//	static int nextResourceId;
//public:
//	digitalMedia() {
//		resourceId = nextResourceId++;
//		isIssued = false;
//		totalMediaCreated++;
//		strcpy(title, "");
//		strcpy(auther, "");
//		strcpy(format, "");
//		price = 0;
//		branchId = 0;
//		fileSize = 0;
//	}
//	digitalMedia(const char* t, const char* a, float p, int bID, const char* f, float size) {
//		resourceId = nextResourceId++;
//		strncpy(title, t, 59); title[59] = '\0';
//		strncpy(auther, a, 39); auther[39] = '\0';
//		price = p;
//		branchId = bID;
//		strncpy(format, f, 9); format[9] = '\0';
//		fileSize = size;
//		isIssued = false;
//		totalMediaCreated++;
//	}
//	~digitalMedia() {
//		cout << "DigitalMedia destroyed. ID: " << resourceId << endl;
//	}
//	void issue() {
//		if (!isIssued) {
//			isIssued = true;
//			cout << "DigitalMedia ID " << resourceId << " issued.\n";
//		}
//		else {
//			cout << "Already issued!\n";
//		}
//	}
//
//
//	void returnBack() {
//		if (isIssued) {
//			isIssued = false;
//			cout << "DigitalMedia ID " << resourceId << " returned.\n";
//		}
//		else {
//			cout << "Was not issued!\n";
//		}
//	}
//	void display() {
//		cout << "Resource ID: " << resourceId << endl;
//		cout << "Title: " << title << endl;
//		cout << "Author: " << auther << endl;
//		cout << "Price: " << price << endl;
//		cout << "Branch ID: " << branchId << endl;
//		cout << "Format: " << format << endl;
//		cout << "File Size: " << fileSize << " MB" << endl;
//		cout << "Issued: " << (isIssued ? "Yes" : "No") << endl;
//	}
//
//	static void displayStatistics() {
//		cout << "Total DigitalMedia Created: " << totalMediaCreated << endl;
//	}
//};
//int digitalMedia::totalMediaCreated = 0;
//int digitalMedia::nextResourceId = 1;
//class member {
//	int memberID;
//	char name[40];
//	int branchID;
//	int activeBorrowCount;
//	int totalFineDue;
//	static int borrowLimit;
//	static int totalMember;
//public:
//	/*borrowResource()
//		 returnResource()
//		 addFine(float)
//		 payFine(float)
//		 static changeBorrowLimit(int)*/
//};
//class transaction {
//	int transactionID;
//	int resourceID;
//	int memberID;
//	int branchID;
//	int daysBorrowed;
//	bool isActive;
//	static int totalTransactions;
//	static int activeTransactions;
//public:
//	/*Required Logic
//		 Automatically increment IDs
//		 Calculate fine if :
//		o daysBorrowed& gt; allowed limit
//		o Mark inactive upon return
//		o Destructor must log destruction*/
//};
//class fine {
//	int fineID;
//	int  memberID;
//	int  amount;
//	bool  isPaid;
//	static int  totalFinesGenerated;
//	static int  totalFinesCollected;
//};
//class branch {
//	Book books[40];
//	digitalMedia media[20];
//	member Members[25];
//	transaction transactions[100];
//	fine Fines[100];
//	int bookCount;
//	int  mediaCount;
//	int  memberCount;
//	int  transactionCount;
//	int  fineCount;
//	/*Required Operations
//	 addBook()
//	 addMedia()
//	 registerMember()
//	 issueBook()
//	 issueMedia()
//	 returnResource()
//	 collectFine()
//	 displayBranchReport()*/
//};
//class uniLibrary {
//private:
//	branch branches[5];
//	int branchCount;
//	/*Required
//	addBranch()
//	 displayGlobalStatistics()
//	 findBranchByID()
//	 systemAuditReport()*/
//};
//int main() {
//	// Step 1: Create books
//	Book b1; // default constructor
//	Book b2("C++ Programming", "Bjarne Stroustrup", 1200.5, 1);
//	Book b3("Data Structures", "Seymour Lipschutz", 800, 2);
//
//	cout << "\n--- Display all books ---\n";
//	b1.display();
//	cout << "-----------------\n";
//	b2.display();
//	cout << "-----------------\n";
//	b3.display();
//	cout << "-----------------\n";
//
//	// Step 2: Issue a book
//	cout << "\n--- Issuing Book 2 ---\n";
//	b2.issue();
//	b2.display();
//
//	// Step 3: Display statistics
//	cout << "\n--- Book Statistics ---\n";
//	Book::displayStatistics();
//
//	// Step 4: Return the book
//	cout << "\n--- Returning Book 2 ---\n";
//	b2.returnBack();
//	b2.display();
//
//	// Step 5: Display statistics again
//	cout << "\n--- Book Statistics After Return ---\n";
//	Book::displayStatistics();
//
//	return 0;
//}