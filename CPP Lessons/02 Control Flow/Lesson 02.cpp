/*
This lesson covers the usage of control flow and scope principles used. 

+ Control Flow is the order in which individual statements, instructions, or calls are executed by the program. Control flow is ajusted using conditional evaluations. Sometimes the conditions are binary, but as the complexity of the program grows, they may not be
+ Scope represents the visibility and life-time of variables and/or functions executed/evaluated throughout the execution time of the program. The primary levels of scope are:
	* Global: Is linked to all parts of the executable code for the lifetime of the program execution
	* Local: Linked to the life of the executable block of code (function) within the code block (in C++, curly braces define code blocks)
  To the compiler, scope represents how object instances and variables are linked to the execution of the program. There are more advanced scope modifiers that will be covered later.
*/
#include <iostream>
#include <stdlib.h>
#include <vector>



int main() {

	// The most basic control flow statement is the conditional. In its simplest form, it operates as follows
	/*
		if( <CONDITIONAL STATEMENT TO BE EVALUATED> ){
			<STATEMENT THAT EXECUTES IF TRUE>
		}
	*/
	// This is the most basic for because it only evaluates for and executes on the condition being True. False yields a simple skip of the entire code block. This is helpful if that functionality is desired. There are other ways to handle a False evaluation though.

	/*
		if( <CONDITIONAL STATEMENT TO BE EVALUATED> ){
			<STATEMENT THAT EXECUTES IF TRUE>
		}
		else if ( <CONDITIONAL STATEMENT TO BE EVALUATED IF THE PRIOR CONDITION IS FALSE> ){
			<STATEMENT THAT EXECUTES IF SECOND CONDITION IS TRUE>
		}
		else{
			<STATEMENT THAT EXECUTES IF ALL ARE FALSE>
		}


		NOTE: When writing functions, the "return" keyword should remain outside of conditionals if possible. The return statement must always be in a position to execute so wrapping it inside a section of code that MAY OR MAY NOT execute will cause a compilation error. Wrapping the conditional in an else statement is an intuitive remedy, but can yield unexpected behavior depending on the conditions and return value/type. This will be covered in greater detail in a later section 

		There are specific operators that go with logical evaluations:
		! The exclamation point denotes "NOT" or a false evaluation
		== The double equals sign is different from the normal equals sign! == is a logical equality operator while = is an assignment operator. a == b checks if a is equal to b. a = b assigns b to the value of a
		> < The greater than or less than symbols are the numeric comparison operators. Their names imply their functions and they can only be applied to numberic values
		? The ternary operator is used within single line conditionals to evaluate a condition and execute one of two statements. Is referred to as "ternary" because it has 3 operands
		&& The logical AND operator checks ALL conditions (there must be at least two, but any number of conditions are allowed) to be true within the conditional statement
		|| The logical OR operator checks to see if AT LEAST ONE condition evaluates to true within the conditional statement (again, there must be at least 2, but any number of conditions are allowed)

	*/

	// Example 2a
	std::cout << "EXAMPLE 2a (Lines 53 to 66)" << std::endl;
	const int NumberToBeEvaluated = 13;
	if (NumberToBeEvaluated == 0) { // Check if condition evaluates to true
		// Execute statement if True
		std::cout << "Number is 0" << std::endl; 
	}
	else if (NumberToBeEvaluated % 2 == 0) {
		// Execute statement if the number does not equal 0 AND 
		// else if is the keyword combination for when the programmer is checking an alternate condition. There can be any number of else if statements as long as they follow an initial if 
		std::cout << "Number is even" << std::endl;
	}
	else {
		// Execute statement if all others are false
		std::cout << "Number is greater than 0 and odd" << std::endl;
	}

	// Conditionals can be written in many different ways using the different operators. They can be used in combination, multiplicity, or even nested
	// Be careful when writing conditionals though. They can grow in complexity very quickly when they often don't need to be so diligent planning and refactoring (when necessary) is recommended

	// Another Conditional form is the ternary conditional. It operates by evaluating the first expression and executing the second if True and the third if False
	// <CONDITION TO BE EVALUATED> ? <EXECUTE IF TRUE> : <EXECUTE IF FALSE>
	// This operator is helpful when replacing if-else conditionals that only execute a single line of code or are performing value assignments such as the example below

	// Example 2
	std::cout << "EXAMPLE 2b (Lines 81 to 84)" << std::endl;
	int NumberToBeEvaluatedByTernary = 15;
	bool bVarToBeAssignedTo;

	bVarToBeAssignedTo = (NumberToBeEvaluatedByTernary % 5 == 0) ? true : false;
	std::cout << "Result of the ternary operation is " << bVarToBeAssignedTo << std::endl;
	/*
	The above conditional is equivalent to:

	if (NumberToBeEvaluatedByTernary % 5 == 0){
		bVarToBeAssignedTo = true;
	}
	else{
		bVarToBeAssignedTo = false;
	}

	In this case, it is helpful to turn 6 lines of code into one. While the ternary operator is not used often and is rather specific in its usage, it can prove useful when replacing simple conditional statements
	*/ 

	// There is another conditional form that operates as an if-else with multiple OR statements. The Switch statement is used as follows
	/*
	
		switch ( <EXPRESSION THAT EVALUATES TO A VALUE>) {
			case x:
				<EXECUTES IF EXPRESSION == X>
			case y:
				<EXECUTES IF EXPRESSION == Y>
			case z:
				<EXECUTES IF EXPRESSION == Z>
			default:
				<EXECUTES IF NONE OF THE OTHER CONDITIONS ARE MET>
	}
	*/

	// The switch statement is the equivalent of an if, multiple else if statmments, and and else statement. The "default" keyword within the switch represents "default" functionality and executes on no conditions. The switch statement is helpful when different values or ranges of values need to be evaluated and executed upon. Keep in mind that each subsequent case will be executed (excluding the default) when a matching case is found so a "break" statement is necessary if the programmer only wants one case exectuted per call.

	// Example 3
	std::cout << "EXAMPLE 2c (Lines 117 to 127)" << std::endl;
	int a = 10;
	int b = 15;

	switch (a) {
		case 10:
			std::cout << "Switch outputted the 10 case" << std::endl; // This will be the case that executes becuase a == 10 is True
			break;
		case 15:
			std::cout << "Switch outputted the 15 case" << std::endl; 
			break;
		default:
			break; // The default functionality is ignored because one of the cases was true
	}
		
	// Conditionals are the foundation of a different control flow practice called Loops. A loop does as its name implies and performs an action until a condition is satisfied. There two main types of loops: For and While. Both of these have their own variations that we will discuss. Some important keywords to note are the "continue" and "break" keywords. "continue is used when the program should skip any remaining operations within the loop and move on to the next iteration. "break" is used when the program shoudl exit the loop entirely and move on to the rest of the code.
	
	// The while loop operates under a framework that can be described as "perform WHILE such condition is True". This is an effective loop when individual instances of the loop don't need to be accessed and an evaluatuation just needs to be performed until a condition is met. Its normal synatax is as follows:

	/*
		while (<CONDITIONAL STATEMENT TO BE EVALUATED>){
			<STATEMENT TO BE EXECUTED WHILE CONDITIONAL IS TRUE
		} 
	*/

	// The While loop has a special variant that allows for the loop's code block to be executed once before evaluating the condition. This is referred to as the do-while and is as follows:
	
	/*
		do{
			<STATEMENT TO BE EXECUTED WHILE CONDITIONAL IS TRUE AND ONCE PRIOR TO CONDITIONAL EVALUATION>
		} while (<CONDITIONAL STATEMENT TO BE EVALUATED>);
	*/
	
	// The do-while is especially helpful when the condition to be evaluated requires a variable that must have the same operation performed on it before the initial evaluation by the conditional. Rather than having to write the operation code twice (once outside the loop to establish initial evaluation conditions and once inside the loop as the evaluation operation) the code can be written once. This can be thought of as "DO this and DO it again WHILE certain condition is true" 

	// Example 2d
	std::cout << "EXAMPLE 2d (Lines 152 to 160)" << std::endl;
	int DoWhileCounter = 0;
	int Data = 1;
	const int BinaryPower = 2;
	do {
		// Perform this operation once and then again as long the condition is met. The 
		Data*= BinaryPower; // Raise the value within data by a power of two
		DoWhileCounter++; // Iterate the counter by 1 to represent the number of times multiplied (addition operation is used to prevent exponential growth and perform what is essentially algebraic multiplcation. Formula: log(base2) of USHRT_MAX-15 = x where x = DoWhileCounter. DoWhileCounter will only be known at completion)
	} while (Data < (USHRT_MAX/2) + 1); // Repeat the process until Data is equal to 65520. NOTE: 15 is subtracted from the short's maximum because the maximum is not an even multiple of 16. This is the case with all extreme boundary values for any numerically based type as described in Lesson 01 
	std::cout << "16 can be multiplied " << DoWhileCounter << " times within the signed short's maximum positive value + 1" << std::endl; 
	//The above example should produce the number 4095 because 65520/16 = 4095

	// The for loop is probably one of the more common loops used in programming because it uses a 3 statement structure combining the unqiue features of all the prior control flow statements. The for loop is written as follows:
	/*
		for (<INITIALIZATION STATEMENT TO BE EXECUTED ONCE BEFORE THE CODE BLOCK>; <CONDITIONAL EVALUATION>; <STATEMENT TO BE EXECUTED AFTER EACH COMPLETION OF THE CODE BLOCK>;){
			<CODE BLOCK TO BE EXECUTED>
		}

		Another version of the for loop is the for-each loop. This version of the for loop is primarily for data structure operations and is meant for operations to be done on every element of the structure. The for each doesn't use an initializtion or increment/decrements common in the regular for loop. A for each is written as follows:

		for (<DATATYPE> <VAR NAME> : <DATA STRUCTURE>){
			<CODE BLOCK TO BE EXECUTED>
		}

		The for loop is primarily used on data structures of some kind or when a procedural iteration is necessary. In the above templates, an element variable is used. The initialization statment in the traditional for loop establishes the initial index value (like the count variables used in previous examples). The for each loop doesn't use an index value, but instead references the element of a data structure directly. (There will be more about data structures in the next lesson).
	*/

	// Example 2e 
	std::cout << "EXAMPLE 2e ()" << std::endl;
	// Declare array of 10 integers with populated values
	int MyArrayOfInts[10] = { 0,1,2,3,4,5,6,7,8,9 };

	// Create index variable and initialize to 0 (beginning of the array). Set the condition to ensure the index value is less than the size of the array (sizes are measured as rational so indexing is always size -1). Increment the index by 1
	for (int i = 0; i < 10; i++) {
		// NOTE: The syntax for accessing elements of arrays and some other data structures is <ARRAY NAME>[<INDEX NUMBER>]. Element access for data strcutures will be covered in detail in future lessons.
		if (i % 2 == 0 /* && i != 8 */) { // Check if index is even. Try including the commented out part of the if statement and see what changes
			MyArrayOfInts[i] += 7; // Add 7 to each element accessed
		}
		else if (i == 8) { // Check if at end of array
			break; // Exit the loop if true

			// The break will end the loop early despite the initial condition in the for loop statement
		}
		else {
			continue; // Continue to next iteration of loop if no conditions are met

			// The continue will instruct the code to skip over this iteration logically because the index is an odd number 
		}
	}

	// For Each int x in the array, print it followed by a space
	for (int x : MyArrayOfInts) {
		std::cout << x << " ";
	}
	std::cout << std::endl; // Carraige returns after completion of example
	// The traditional for loop doesn't need to operate in a forward direction all the time. Operation on the index variable can increment, decrement, or procedurally hop around the structure if the programmer finds that to be necessary. Notice the change when the array is printed if the commented portion of line 183 is included. Observe the difference in output. The 8th element will be 8 instead of 15. The intended behavior of the loop is implied by the logical conditions present, but even though the i == 8 condition IS TRUE, it is out of sequence. The condition i %2 =0 evaluates true first so it takes precedance and thus the condition skips the latter options. There are two remedies for this logical problem: Adding an extra condition to the initial case OR reorganizing the sequence of conditions. Both options work, but the former is unique only to the present problem and can lead to overcomplications. The latter will make your code easier to read and understand to other programmers as well as the compiler. Writing a conditional in a linear fashion using a scheme that operates in descending order of liklihood will produce expected behavior more often. With C++ operating as a sequential language, writing code that works effectively top->down is best.   

	// NOTE: It is VERY IMPORTANT to ensure that your index variable DOES NOT exceed the boundaries of the structure or the compiler will throw a Runtime OutOfBounds Exception. 

	return 0;
}

