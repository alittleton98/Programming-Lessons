/*
Lesson 1: Data Types and Pointers
Programming languages use variables of different types to store data. Pointers and references are used by the program to access data and/or memory locations of these variables.
*/

#include <stdlib.h>
#include <iostream>
#include <stdint.h>

int main() {

	//Data types represent how much space a variable will take up in memory and how its data will be stored in bits
	//Data types for most languages are built from the following primitives:

	bool Boolean; //Logical type that can be TRUE or FALSE only.
	char Character; //Data type for individual letters
	int Integer; //Numerical type representing 2^32 integer values. There are other versions related to how to represent different ranges of the integers while some include less or more depending on memory requirements
	float FloatingPoint; //Numerical data type designed with 32bit precision. Reasonably precise for most applications
	double DoubleFloatingPoint; //Numerical data type designed with 64bit precision. Exceptionally precise but also twice the size of the float
	void Valueless(); //Void is a valueless identifier used with functions and pointers to indicate that the function will not be returning a variable of any type or to identify that the pointer can hold the address of any variable agnostic of type
	wchar_t WideCharacter; //Data type capable of holding 65535 different characters. It is the UNICODE standard so encoding characters from virtually any language can be done

	Boolean = false;
	std::cout << "The Boolean variable is " << Boolean << " and it is " << sizeof(Boolean) << "bytes in size" << std::endl; //Notice what the printed line is
	Character = 'a'; 
	std::cout << "The Character variable is " << Character << " and it is " << sizeof(Character) << "bytes in size" <<std::endl;
	Integer = 3274;
	std::cout << "The Integer variable is " << Integer << " and it is " << sizeof(Integer) << "bytes in size" << std::endl;
	
	/*
	Numeric types come in various different sizes and this gives the programmer more flexibilty when it comes to memory usage and extreme numerical boundaries
	used. The extremes boundaries are always the 2^BitSize - 1. For signed numeric types the extremes are +- (2^BitSize)/2 - 1. Subtracting 1 is done because of
	place value operations in the binary representation of data. Computer memory uses transitors set to an "On" (1) or "Off" (0) position for each bit of data
	representing a power of two. Visually, this is presented as:
	[2^n]...[2^7][2^6][2^5][2^4][2^3][2^2][2^1][2^0]
	With this visual representation in mind, notice that counting starts from the 0 exponent because 2^0 = 1. Counting in this fashion is done in the same way as any other base. Each place's max value is always BaseNumber^PlaceValue - 1 because BaseNumber^PlaceValue is represented with an additional spot due to the inclusion of 0. Place values determine the number of values possible within that place and 0 must always be included in that so subtracting 1 accounts for this. Referring back to memory usage in computing, numeric types are bounded by the same place value rules. An unsigned 16 bit integer's number of possible values is 65536, but one of those must be 0, so there are 65535 possible positive values. Signed types follow the same rule except the number of possible rational numbers (recall that a rational number is any non-zero real number) is distrubuted evenly around 0 (ie 65535 distrubuted evenly about 0 is [-32767, 32767])
	*/
	
	//Take note of what the output in the console looks like vs the actual value
	FloatingPoint = 19.385728493f;
	std::cout << "The FloatingPoint variable is " << FloatingPoint << " and it is " << sizeof(FloatingPoint) << "bytes in size" << std::endl;
	DoubleFloatingPoint = 25.4747474872928382839302839;
	std::cout << "The DoubleFloatingPoint variable is " << DoubleFloatingPoint << " and it is " << sizeof(DoubleFloatingPoint) << "bytes in size" << std::endl;
	//Floating point numbers and double precision numbers generally hold values of great precision so operations within code can use them, but outputting them to be viewed requires them to be formatted, such as the case with the std::cout 
	std::cout << std::endl;

	//Expanded Primitive Data Types allow for values to be represented in different ways as necessary
	//the int is the most straight forward example
	//Integers can be represented as having a numerical sign or without as well as having different 
	int8_t signedInt8Bit = -55; //Represents an 8bit integer with a sign bit 
	uint8_t unsignedInt8bit = 255; //Represents an 8bit integer with no sign bit 
	//unsigned integers can't hold negative numbers so they circle back to the max if the programmer tries to store one
	//This is the case with all numerical types. If the max or minimum is reached, the value with then count from the opposite end
	std::cout << "Signed 8 bit integer = " << (int) signedInt8Bit << std::endl;
	std::cout << "Unsigned 8 bit integer maximum = " << (int) unsignedInt8bit << std::endl;
	unsignedInt8bit = 0;
	unsignedInt8bit --;
	std::cout << "Unsigned 8 bit integer after subtracting from 0 = " << (int) unsignedInt8bit << std::endl;
	//There are many different ints of varying sizes that are used for various memory or performance requirements
	//Expanding on primitive data types gives the programmer more flexibility when building on different systems and architectures
	std::cout << std::endl;


	//Data Types can be created as necessary to be used for whatever the program requires
	//They are made using a typedef declaration
	typedef int meter;
	meter distance = 1374; //distance given in meters
	float kilometerNoCast = distance / 1000; //float is used because whole number precision is insufficient. Notice what happens when the program runs
	float kilometerCast = (float) distance / 1000; 
	std::cout << kilometerNoCast << std::endl;
	std::cout << kilometerCast << std::endl;
	//Typedefs usage are up to the programmer and often make more sense when primitive types require a modification of some kind
	//When using typedefs related to primitive types, casting will help with possible data loss between values 
	//such as between the kilometerCast and kilometerNoCast
	//Casting a variable performs a lowlevel and compiler time conversion of the type to the designated type. Convention is as follows: (type to cast to) nameOfVariableToBeCastFrom
	//Casting can only be done if the types are comparable 
	std::cout << std::endl;

	//Pointers hold memory locations for other variables
	//References are the memory address of the pointer can be accessed using the &
	//Pointers are created and dereferenced (accessing the value at the stored memory location) using the * operator 
	int VariablePointedTo = 10;
	int* pVariablePointer;
	pVariablePointer = &VariablePointedTo;

	std::cout << "The variable we are pointing to has been assigned a value of " << VariablePointedTo << std::endl;
	std::cout << "The memory address of the pointer we are using is " << pVariablePointer << std::endl;
	std::cout << "The dereferenced data from the variable at the memory address stored in the pointer " << *pVariablePointer << std::endl;
	std::cout << "Using a reference, the memory address from the variable we are pointing to is " << &pVariablePointer << std::endl;



	return 0;
}