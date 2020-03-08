#include<iostream>
#include<string>
using namespace std;

class identity                                                   //�����Ķ���
{
public:
	identity() :number_(1234567), name_("z") {                  //���캯��
		cout << "constructor" << endl;
	}
	identity(int number, char* name1);
	identity(identity& p);                                     //���ƹ��캯��
	~identity();                                               //��������
	void putnumber() {                                           //������֤���뺯��
		cout << "The person's number is:" << number_ << "\t";
	}
	void putname() {                                             //������ֺ���
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
class student {                                             //ѧ����Ķ���
private:
	identity id_;
	string school_;
public:
	student() :id_(3456789, (char*)"g"), school_("sysu") {          //���캯��
		cout << "constructor" << endl;
	}
	student(int number, char* name, string str) {
		identity id(number, name);
		id_ = id;
		school_ = str;
	};
	student(student& p);                                              //���ƹ��캯��
	~student();                                                       //��������
	void putid() {                                                    //�����ݵĺ���
		cout << "id:  ";
		id_.putnumber();
		cout << "\t";
		id_.putname();
	}
	void putschool() {                                                //���ѧУ�ĺ���
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

	//��һ��
	identity a, b(2345678, (char*)"h");               //�������a,b
	a.putnumber();
	a.putname();
	b.putnumber();
	b.putname();
	//�ڶ���
	student c, d(4567898, (char*)"i", "sysu2");                     //�������a,b
	c.putid();
	c.putschool();
	d.putid();
	d.putschool();
	//������
	student makestudent(5678987, (char*)"q", "sysu3");               //�������makestudent
	makestudent.putid();
	makestudent.putschool();
	return 0;
}