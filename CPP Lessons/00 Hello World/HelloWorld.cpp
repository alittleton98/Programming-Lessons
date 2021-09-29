/*
The Hello World program is intended to represent the most basic of any programming languages syntax. It is also a somewhat comic way of having a new program/programmer "greet"
the world they've just entered.

The basic c++ program structure is described below
*/

//inclusion statements pull separate pieces of code together so the compiler can compile all necessary code chunks
//C++ works in a linear execution so code dependencies, local or not, need to be declared before the code that uses it
//Thus inclusion statements (used for library dependencies) need to be at the top of the program (or at the very least, above the code that calls for it)
#include <iostream>

//the main function is the function the program will execute upon compilation
//If there is no main function, then the program will not compile
//Any program can have any number of functions but must all be executed by main in some fashion (nested calls when not direct)
int main() {
	//std::cout is the usage of the cout function within the std namespace. Function calls and declarations within this syntax use the convention <Namespace>::<Function or Class Name>
	//std is the namespace used for the standard library
	//cout (c - out) is the function that takes an input and outputs it using the standard output stream. So when called within an environment (terminal or cmd/powershell)
	//that reads the standard output, it will be shown
	//endl is function that adds the endline flag at the end of the output so that the next is on a new line
	std::cout << "Hello World" << std::endl;
}