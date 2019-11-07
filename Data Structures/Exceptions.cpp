#include <iostream>
#include <exception>

using namespace std;

class NullException : public exception {

	virtual const char* what() const throw() {
		return "My class NullException happened";
	}
} null_exception;


class CompareException : public exception {

	virtual const char* what() const throw() {
		return "My class CompareException happened";
	}
} compare_exception;


class RandonException : public exception {

	virtual const char* what() const throw() {
		return "My class RandonException happened";
	}
} randon_exception;

/*
#-------------------------------------------------------------------------------
*/

template<class A, class B>
void NullExceptionVerify(A variable, B exceptionClass) {

	try {
		if(variable == NULL)
			throw exceptionClass;
	}
	catch(exception& e) {
		cout << e.what() << endl;
	}
}

template<class B>
void ConditionalExceptionVerify(bool verify, B exceptionClass) {

	try {
		if(verify)
			throw exceptionClass;
	}
	catch(exception& e) {
		cout << e.what() << endl;
	}
}

template<class B>
void ExceptionVerify(B exceptionClass) {

	try {
		throw exceptionClass;
	}
	catch(exception& e) {
		cout << e.what() << endl;
	}
}

/*
#-------------------------------------------------------------------------------
*/

int main() {

	int pointer = NULL;
	NullExceptionVerify<int, NullException>(pointer, null_exception);

	bool conditional = true;
	ConditionalExceptionVerify<CompareException>(conditional, compare_exception);

	ExceptionVerify<RandonException>(randon_exception);

	return 0;
}
