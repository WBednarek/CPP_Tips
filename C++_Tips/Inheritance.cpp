#include <iostream>

using namespace std;

class B1
{
public:
	virtual void vf() const;
	void f() const;
	virtual void pvf() const = 0; //Exercise 5. One virtual function creates abstract class - you can't create an object of that class.

};
void B1::vf() const
{
	cout << "B1::vf()" << endl;
}

void B1::f() const
{
	cout << "B1::f()" << endl;
}



class D1 : public B1 // Okay
{
public:
	void vf() const;
	void f() const;
	void pvf() const;
};

void D1::vf() const
{
	cout << "D1::vf()" << endl;
}

void D1::f() const
{
	cout << "D1::f()" << endl;
}

void D1::pvf() const
{
	cout << "D1::pvf()" << endl;
}



class D2 : public D1
{
public:
	void pvf() const;
};

void D2::pvf() const
{
	cout << "D2::pvf()" << endl;
}



class B2
{
public:
	virtual void pvf() const = 0;
};



class D21 :
	public B2

{
public:
	string D21_string;
	D21();
	void pvf() const;
};

D21::D21() : D21_string("D21::string")
{
}



void D21::pvf() const
{
	cout << D21_string << endl;
}



class D22 : public B2
{
public:
	int D22_int;
	D22();
	void pvf() const;
};

D22::D22() : D22_int(98)
{

}

void D22::pvf() const
{
	cout << D22_int << endl;
}




void Ex7(B2& B2_ref)
{
	B2_ref.pvf();

}


int main()
{
	//Ex1();
	//Ex2();

	//Exricise 1
	/*B1 B1_obj;
	B1_obj.f();
	B1_obj.vf();*/

	//Exercise 2
	D1 D1_obj;
	D1_obj.f();
	D1_obj.vf();
	D1_obj.pvf();


	//Exercise 3
	B1& B1_ref = D1_obj;
	B1_ref.vf();
	B1_ref.f();
	B1_ref.pvf();

	//Exercise 6
	D2 D2_obj;
	D2_obj.vf();
	D2_obj.f();
	D2_obj.pvf();

	//Exercise 7
	D21 D21_obj;
	D22 D22_obj;

	Ex7(D21_obj);
	Ex7(D22_obj);






	return 0;

}





/*
//Exercise4
Results
B1::f()
B1::vf()
B1::f()
D1::vf()
D1::vf()
B1::f()

after declaring function f() in D1 class
B1::f()
B1::vf()
D1::f()
D1::vf()
D1::vf()
B1::f()
*/

