#include <iostream>

class MyDate {
	const int size_mass = 5;
	int day;
	int month;
	int year;
	static int count;
	//int* mass;
public:

	const int test = 10;

	void setDay(int);
	void setMonth(int);
	void setYear(int);

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	void add(int);
	const MyDate& operator+=(int);
	const MyDate operator+(int);
	const MyDate& operator-=(int);
	const MyDate operator-(int);
	bool equals(MyDate&);
	bool lt(MyDate&);
	bool lt2(MyDate&);
	bool gt(MyDate&);
	bool n_equals(MyDate&);

	//void setMass();

	void print() const;
	friend void print(const MyDate &d);
	friend const MyDate operator+(int, const MyDate&);
	friend const MyDate operator-(int, const MyDate&);

	static int getCount() {

		return count;
	}
	MyDate(int, int, int, int);
	explicit MyDate(int, int, int);
	MyDate(int, int);
	explicit MyDate(int);
	MyDate();
	~MyDate() {
		count--;
		//delete[] mass;
	}
};

int MyDate::count { 0 };

void MyDate::setDay(int day) {
	this->day = day;
	//setMass();
}

//void MyDate::setMass() {
//    for (int i = 0; i < size_mass; i++)
//        mass[i] = i;
//}

void MyDate::setMonth(int month) {
	this->month = month;
}
void MyDate::setYear(int year) {
	this->year = year;
}

int MyDate::getDay() const {
	return this->day;
}

int MyDate::getMonth() const {
	return this->month;
}

int MyDate::getYear() const {
	return this->year;
}

bool MyDate::equals(MyDate &data) {

	if (this->day == data.getDay() && this->month == data.getMonth()
			&& this->year == data.getYear())
		return true;

	return false;
}

bool MyDate::lt(MyDate &a) {
	if (this->year < a.getYear())
		return true;
	else if (this->year > a.getYear())
		return false;

	if (this->month < a.getMonth())
		return true;
	else if (this->month > a.getMonth())
		return false;

	if (this->day < a.getDay())
		return true;

	return false;
}

bool MyDate::lt2(MyDate &data) {
	int sum = this->year * 12 * 30 + this->month * 30 + this->day;
	int sum1 = data.getYear() * 12 * 30 + data.getMonth() * 30 + data.getDay();

	/*if (sum < sum1)
	 return 1;

	 return 0;*/

	return (sum < sum1);
}

bool MyDate::gt(MyDate &a) {
	return !(this->lt(a) || this->equals(a));
}

bool MyDate::n_equals(MyDate &data) {
	return !this->equals(data);
}

MyDate::MyDate(int day, int month, int year) :
		MyDate(day, month, year, 100) {
}

MyDate::MyDate(int day, int month, int year, int test) :
		day { day }, month { month }, year { year }, test { test }, size_mass {
				5 } {
	count++;
	//mass = new int[size_mass];
}

MyDate::MyDate(int day, int month) :
		MyDate(day, month, 1970) {
}
MyDate::MyDate(int day) :
		MyDate(day, 1) {
}
MyDate::MyDate() :
		MyDate(1) {
}

void MyDate::print() const {
	//std::cout << this->getDay() << "." << this->getMonth() << "." << this->getYear() << std::endl;
	std::cout << day << "." << month << "." << year << std::endl;
}

void print(const MyDate &d) {
	//std::cout << d.getDay() << "." << d.getMonth() << "." << d.getYear() << std::endl;
	std::cout << d.day << "." << d.month << "." << d.year << std::endl;
	//for (int i = 0; i < d.size_mass; i++)
	//std::cout << d.mass[i] << " ";
	//std::cout << std::endl;
	//std::cout << day << "." << month << "." << year << std::endl;
}

void MyDate::add(int days) {
	this->day += days;
	this->month += this->day / 30;
	this->day %= 30;
	this->year += this->month / 12;
	this->month %= 12;
}

const MyDate& MyDate::operator+=(int days) {
	this->day += days;
	this->month += this->day / 30;
	this->day %= 30;
	this->year += this->month / 12;
	this->month %= 12;
	return *this;
}

const MyDate MyDate::operator+(int days) {
	MyDate t = *this;
	t += days;
	return t;
}

const MyDate operator+(int days, const MyDate &date) {
	MyDate t = date;
	t += days;
	return t;
}

const MyDate& MyDate::operator-=(int days) {
	this->day -= days;
	while (this->day <= 0){
		this->month--;
		this->day+=30;
	}
	while(this->month<=0){
		this->year--;
		this->month+=12;
	}
	return *this;
}

const MyDate MyDate::operator-(int days) {
	MyDate t = *this;
	t -= days;
	return t;
}

const MyDate operator-(int days, const MyDate &date) {
	MyDate t = date;
	t -= days;
	return t;
}

//class T3 {
//public:
//    class T4 {
//    public:
//        static int  s;
//    };
//
//    T4* t;
//};
//
//T3::T4::s{ 33 };

struct Test1 {
	int x;
};

struct Test2 {
	Test1 *t;

public:
	Test2() {
		t = new Test1[100];
	}
	~Test2() {
		delete[] t;
	}
};

int main() {

	//A d;
	//d.f();
	// void f (const A* this)
	//f(&d);

	//std::cout << "Count date is " << MyDate::getCount() << std::endl;

	MyDate a(10, 12, 2000);
	a.add(10);
	a.print();

	MyDate a1(10, 12, 2000);
	a1 += 10;
	a1.print();

	MyDate a2 = a1 + 20;
	a2.print();

	MyDate a3 = 20 + a1;
	a3.print();

	a3-=336;
	a3.print();

	/*T3::T4::*/
	//a.add(30);
	//const MyDate a1(10, 10, 2000,33333);
	//a1.print();
	//std::cout << " a test  =  " << a.test << std::endl;
	//std::cout <<" a1 test  =  " << a1.test << std::endl;
	//const MyDate date1{10,10,2000};
	//std::cout << date1.getDay() << "." << date1.getMonth() << "." << date1.getYear() << std::endl;
	//a1.test = 33;
	/*if (a.equals(a1))
	 std::cout << " == " << std::endl;
	 else
	 std::cout << " != " << std::endl;*/

	/*std::cout << "Count date is " << MyDate::getCount() << std::endl;


	 MyDate a1;
	 a1.print();

	 std::cout << "Count date is " << MyDate::getCount() << std::endl;*/

	return 0;
}
