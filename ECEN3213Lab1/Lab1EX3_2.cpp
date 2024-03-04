// compile the code using:
// g++ -E Lab1EX3_2.cpp -o Lab1EX3_2.i, pre-processing (.i or .ii file)
// g++ -S Lab1EX3_2.i, generate the assembly code (.s file)
// g++ -c Lab1EX3_2.s, generate machine code from assembly code (.o file)
// g++ Lab1EX3_2.o -o Lab1EX3_2, link to generate exe file.

#include <iostream>
using namespace std;
int main(){
	
	/* Complete Code: set a variable  int a to be 30 */
	int a =30;
 	/* Complete Code:set a variable  int b to be 40 */
	int b =40;
    /* Complete Code: assign the sum of a and b to b */
	b = a+b;
    /* Complete Code: print out b */
	cout << b;
    return 0;
}

