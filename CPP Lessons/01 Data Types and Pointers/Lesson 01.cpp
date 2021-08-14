/*
Lesson 1: Data Types and Pointers
Programming languages use variables of different types to store data. Pointers and references are used by the program to access data and/or memory locations of these variables.
*/

#include <stdlib.h>
#include <iostream>

int main() {

	//Data types represent how much space a variable will take up in memory and how its data will be stored in bits
	//Data types for most languages are built from the following primitives:

	bool Boolean; //Logical type that can be TRUE or FALSE only.
	char Character; //Data type for individual letters
	int Integer; //Numerical type representing 2^32 integer values. There are other versions related to how to represent different ranges of the integers while some include less or more depending on memory requirements
	float FloatingPoint; //Numerical data type designed with 32bit precision. Reasonably precise for most applications
	double DoubleFloatingPoint; //Numerical data type designed with 64bit precision. Exceptionally precise but also twice the size of the float
	void Valueless(); //Void is a valueless identifier used with functions and pointers to indicate that the function will not be returning a variable of any type or to identify that the pointer can hold the address of any variable agnostic of type
	wchar_t WideCharacter; //Data type capable of holding 65536 different characters. It is the UNICODE standard so encoding characters from virtually any language can be done


	//Pointers hold memory locations for other variables
	//References are the memory address of the pointer can be accessed using the &
	//Pointers are created and dereferenced using the * operator 
	int VariablePointedTo = 10;
	int* pVariablePointer;
	pVariablePointer = &VariablePointedTo;

	std::cout << "The variable we are pointing to has been assigned a value of " << VariablePointedTo << std::endl;
	std::cout << "The memory address stored in the pointer " << pVariablePointer << std::endl;
	std::cout << "The dereferenced data from the variable at the memory address stored in the pointer " << *pVariablePointer << std::endl;
	std::cout << "Using a reference, the memory address from the variable we are pointing to is " << &pVariablePointer << std::endl;



	return 0;
}