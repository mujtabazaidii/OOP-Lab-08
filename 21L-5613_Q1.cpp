#include <iostream>
using namespace std;
class Student{
	char name[50];
	char rollNo[8];
	float cgpa;
public:
	Student(char r[], char n[], float c){
		int i = 0;
		for (int i=0; n[i] != '\0'; i++){
			name[i] = n[i];
		}
		name[i] = '\0';
		int j = 0;
		for (; r[j] != '\0'; j++)
		{
			rollNo[j] = r[j];
		}
		rollNo[j] = '\0';
		cgpa = c;
	}
	void Print()
	{
		cout << endl;
		cout << endl << " Roll Number is : " << rollNo << endl;
		cout << " Name of Student : " << name << endl;
		cout << " CGPA : " << cgpa << endl;
		cout << "-----------------------------------------------------";
	}
	float getcgpa(){
		return cgpa;
	}
	char* getname(){
		return name;
	}
};
class Society{
	char name[50];
	Student* president;
	Student* members[5];
public:
	Society(char n[]){
		int i = 0;
		for (; n[i] != '\0'; i++)
		{
			name[i] = n[i];
		}
		name[i] = '\0';
		president = NULL;
		int j = 0;
		for (; members[j] != '\0'; j++)
		{
			members[j] = NULL;
		}
	}
	void PrintInfo(){
		cout << endl << " NAME OF THE SOCIETY: " << name << endl;
		cout << endl << " PRESIDENT: ";
		if (president == NULL){
			cout << "NOT AVAILABLE " << endl;
		}
		for (int i = 0; i < 5; i++){
			if (members[i] == NULL){
				cout << " MEMBER " << i << ":" << " NOT AVAILABLE " << endl;
			}
		}
		cout << endl << endl;
	}
	void AppointPresident(Student& a) {
		if (a.getcgpa() >= 3.0) {
			if (president == NULL) {
				cout << a.getname() << " has been appointed as President." << endl;
				president = &a;
			}
			else {
				cout << a.getname() << " cannot be appointed as President. President position is NOT vacant." << endl;
			}
		}
		else {
			cout << a.getname() << " cannot be appointed as President. CGPA criteria not met." << endl;
		}
	}
};
int main()
{
	Student s1("12L1111", "Hashim Amla", 3.99);
	Student s2("13L1121", "Virat Kohli", 3.45);
	Student s3("13L1126", "Quinton de Kock", 2.98);
	Student s4("14L1361", "Joe Root", 2.99);
	Student s5("14L1124", "Martin Guptil", 3.09);
	Student s6("15L1314", "Rohit Sharma", 3.19);

	s1.Print();
	s2.Print();
	s3.Print();
	s4.Print();
	s5.Print();
	s6.Print();

	Society obj1("SPORTS");
	obj1.PrintInfo();
	obj1.AppointPresident(s3);
	obj1.AppointPresident(s1);
	obj1.AppointPresident(s2);

	return 0;
}
