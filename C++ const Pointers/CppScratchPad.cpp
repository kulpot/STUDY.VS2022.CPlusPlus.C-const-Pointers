#include <iostream>
using std::cout;
using std::endl;

//----------------------- C++ const Pointers -----------------------------------------------------------------
//ref link:https://www.youtube.com/watch?v=tFjcDICYvE0&list=PLRwVmtr-pp070AKU7G71q8XyCRttsWIvi&index=5&t=3s

class Cow
{
public:
	int maxHeartBeats;
	Cow(int maxBeats)
	{
		maxHeartBeats = maxBeats;
		// class_name* const this;
		this->maxHeartBeats = 234234234;
		this = new Cow(234234);
	}
};

void main()
{
	Cow betsy(5);
	// class_name* const this;
	
	Cow* betsyPtr = &betsy;
	//Cow const* const betsyPtr = &betsy;
	//Cow const*  betsyPtr = &betsy;
	//Cow * const betsyPtr = &betsy;
	betsyPtr->maxHeartBeats = 10;

	Cow georgy(5000);
	betsyPtr = &georgy;
}
































//------------------------- C++ const data members ----------------------------------------------------
//ref link:https://www.youtube.com/watch?v=L1Jc4Mz6lp8&list=PLRwVmtr-pp070AKU7G71q8XyCRttsWIvi&index=5

//class Cow {
//	//const int ID;		// const cant initialize a assign value but in C#/Java it can
//public:
//	//Cow() : ID(5)	
//	//static const int ID;			// const means you cant change it, static just determines where its storage is located whether its 1value per instance or all instance
//	const int ID;		// move inside public for direct access
//	Cow(int myId) : ID(myId)		// more dynamic
//	{
//		//ID = 5;	//error ID is const , needs base class constructors ex. Cow() : ID(5) {}
//	}
//};
//
//void main()
//{
//	//const int MY_VALUE = 5;
//
//	Cow c(5);
//	Cow c2(13);
//	cout << c.ID << endl;
//	cout << c2.ID << endl;
//}


































//----------------------- C++ const_cast ------------------------------------------------------------------
//ref link:https://www.youtube.com/watch?v=SJ7ZTpNydTk&list=PLRwVmtr-pp070AKU7G71q8XyCRttsWIvi&index=5&t=1s

/*
* const_cast allows you to remove the const definition of the object.
* You can use this thing when you should pass an regular object to a function but your object is a const object. The function will not accept the const object.
*/

//class Cow {
//public:
//	void saySomething() { cout << "waaa" << endl; }
//};
//
//void f(Cow* c)		//none-const pointer
//{
//	c->saySomething();
//}
//
//void main()
//{
//	const Cow* c = new Cow;
//	//f(c);			//error: f function is not const
//	//Cow* c2 = c;		//error: c is not const
//	Cow* c2 = const_cast<Cow*>(c);
//	f(const_cast<Cow*>(c));
//
//	delete c;
//}
































//------------------------- const pointers -----------------------------------------------------------------
//ref link:https://www.youtube.com/watch?v=BimM1lLeZg8&list=PLRwVmtr-pp070AKU7G71q8XyCRttsWIvi&index=2&t=1s

//class Cow
//{
//	int mooCount;
//public:
//	Cow() { mooCount = 0; }
//	void moo() { cout << mooCount++ << endl; }
//	void saySomething() const { cout << "Hello" << endl; }
//};
//
//void main()
//{
//	Cow* c = new Cow;
//	//const Cow* constCow = c;
//	//Cow* const constCow = c;		//pointer itself is const
//	//constCow = new Cow;		// error cant modify const constCow
//	const Cow* const constCow = c;		// the object and the pointer is const
//	c->moo();
//	//constCow->moo();		// error cant modify const Cow*	, solution: Cow* const constCow = c;
//	delete c;
//}



































//------------------ C++ const functions (const correctness) --------------------------
//ref link:https://www.youtube.com/watch?v=ehJKvbbe9hk

//const int MY_INT = 5;

//class Cow
//{
//	int mooCount;
//	//const int mooCount;
//
//public:
//	Cow() { mooCount = 0; }
//	//void moo() { cout << mooCount++ << endl; }		//none-const func	, modifies int mooCount;
//	//void saySomething() { cout << "Hello" << endl; }	// none modify int mooCount;
//	
//	//void moo() const { cout << mooCount++ << endl; }		//error: const cant modify mooCount to mooCount++
//	void moo() const { cout << mooCount << endl; }			
//	void saySomething() const { cout << "Hello" << endl; }
//};
//
//void main()
//{
//	//Cow c;
//	const Cow c;
//	c.moo();
//	c.moo();
//	c.saySomething();
//	c.moo();
//
//	//cout << MY_INT << endl;
//}