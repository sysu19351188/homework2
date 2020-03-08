#include<iostream>
#include<string>
using namespace std;

class identity                                                   //身份类的定义
{
public:
	identity() :number_(1234567), name_("z") {                  //构造函数
		cout << "constructor" << endl;
	}
	identity(int number, char* name1);
	identity(identity& p);                                     //复制构造函数
	~identity();                                               //析构函数
	void putnumber() {                                           //输出身份证号码函数
		cout << "The person's number is:" << number_ << "\t";
	}
	void putname() {                                             //输出名字函数
		char* name = name_;
		cout << "name is: " << *name << endl;
	}
private:
	int number_;
	char name_[32];
};
identity::identity(identity& p) {
	number_ = p.number_;
	strcpy_s(name_, p.name_);
	cout << "copy constructor" << endl;
}
identity::identity(int number, char* name1) {
	number_ = number;
	strcpy_s(name_, name1);
}
identity::~identity() {
	cout << "distructor" << endl;
}
class student {                                             //学生类的定义
private:
	identity id_;
	string school_;
public:
	student() :id_(3456789, (char*)"g"), school_("sysu") {          //构造函数
		cout << "constructor" << endl;
	}
	student(int number, char* name, string str) {
		identity id(number, name);
		id_ = id;
		school_ = str;
	};
	student(student& p);                                              //复制构造函数
	~student();                                                       //析构函数
	void putid() {                                                    //输出身份的函数
		cout << "id:  ";
		id_.putnumber();
		cout << "\t";
		id_.putname();
	}
	void putschool() {                                                //输出学校的函数
		cout << "school is:" << school_ << endl;
	}
};
student::student(student& p) {
	id_ = p.id_;
	school_ = p.school_;
	cout << "copy constructor" << endl;
}
student::~student() {
	cout << "distructor" << endl;
}
student makestudent(int number, char* name, string school) {
	student f(number, name, school);
	return f;
};
int main()
{

	//第一题
	identity a, b(2345678, (char*)"h");               //定义对象a,b
	a.putnumber();
	a.putname();
	b.putnumber();
	b.putname();
	//第二题
	student c, d(4567898, (char*)"i", "sysu2");                     //定义对象a,b
	c.putid();
	c.putschool();
	d.putid();
	d.putschool();
	//第三题
	student makestudent(5678987, (char*)"q", "sysu3");               //定义对象makestudent
	makestudent.putid();
	makestudent.putschool();
	return 0;
}