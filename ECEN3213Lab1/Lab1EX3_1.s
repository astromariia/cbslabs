/*
To compile the code, run:
as -g -o Lab1EX3_1.o Lab1EX3_1.s
gcc -o Lab1EX3_1 Lab1EX3_1.o

*/

.global main
main: 
    // Complete Code: set the register R3 to be 30
    MOV r3, #30
                
    // Complete Code: set the register R4 to be 40
    MOV r4,#40
    // Complete Code:add R4 and R3 and assign the result to R3
    ADD r3,r3,r4

    // print the result
    MOV R1, R3 
    LDR R0, =string
    BL printf
    B exit


    //exit the program
    MOV     R7, #1
    SVC     0


.data
string:
        .asciz "%d\n"
