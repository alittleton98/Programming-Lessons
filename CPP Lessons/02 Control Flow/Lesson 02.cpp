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

//Function declaration to demonstrate scope execution. Functions as a whole will be covered later.
void UpdateCount();

// Global variable declarations are made outside of functions. This allows them to be accessed from all executable code blocks within this program
int GlobalCount = 0; 
int GlobalMaxCount; // This variable will be compared to the LocalMaxCount defined inside main


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

	// Example 1
	std::cout << "EXAMPLE 1 (Lines 53 to 66)" << std::endl;
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
	std::cout << "EXAMPLE 2 (Lines )" << std::endl;
	int NumberToBeEvaluatedByTernary = 15;
	bool bVarToBeAssignedTo;

	bVarToBeAssignedTo = (NumberToBeEvaluatedByTernary % 5 == 0) ? true : false;
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

	// The switch statement is the equivalent of an if, multiple else if statmments, and and else statement. The "default" keyword within the switch represents "default" functionality and executes on no conditions. The switch statement is helpful when different values or ranges of values need to be evaluated and executed upon

	// Example 3
	std::cout << "EXAMPLE 3" << std::endl;
	int a = 10;
	int b = 15;

	switch (a) {
		case 10:
			std::cout << "Switch outputted the 10 case" << std::endl; // This will be the case that executes becuase a == 10 is True
		case 15:
			std::cout << "Switch outputted the 15 case" << std::endl; 
		default:
			break; // The default functionality is ignored because one of the cases was true
	}
		
	// Conditionals are the foundation of a different control flow practice called Loops. A loop does as its name implies and performs an action until a condition is satisfied. There two main types of loops: For and While. Both of these have their own variations that we will discuss.
	
	// The while loop operates under a framework that can be described as "perform WHILE such condition is True". This is an effective loop when individual instances of the loop don't need to be accessed and an evaluatuation just needs to be performed until a condition is met. Its normal synatax is as follows:

	/*
		while (<CONDITIONAL STATEMENT TO BE EVALUATED>){
			<STATEMENT TO BE EXECUTED WHILE CONDITIONAL IS TRUE
		} 
	*/

	// The While loop has a special variant that allows for the loop's code block to be executed once before evaluating the condition. This is referred to as the do-while and is as follows:
	
	/*
		do{
			<STATEMENT TO BE EXECUTED WHILE CONDITIONAL IS TRUE AND ONCE PRIOR TO EVALUATION
		} while (<CONDITIONAL STATEMENT TO BE EVALUATED>);
	*/
	

	// Variable declarations that are local only to the main function
	int LocalCount = 0;			// The Count variable that is local to the main function
	const int LocalMaxCount = 50;	// The maximum number any of the count variables can reach. This will be compared to the GlobalMaxCount
	bool bIsLocalCount10;		// Boolean variable to be evaluated. Is intended to return True if the LocalCount variable is 10
	bool bIsGlobalCountEven;	// Boolean variable to be evaluated. Is intended to return True if the GlobalCount variable is an even number


	return 0;
}

void UpdateCount() {
	// Variable declarations that are local only to the UpdateCount() function
	int FunctionCountingFactor = 3; // Variable is the addition factor that Count variable will increase by.
	GlobalMaxCount = FunctionCountingFactor * 10; // Programmatically defines the number any of the count variables can reach

	GlobalCount += FunctionCountingFactor;
}