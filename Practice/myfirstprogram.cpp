#include <iostream>
#include <cmath>
using namespace std;
// supposedly need to include the string library 
// strings seem to work without it
// inclusion would be : #include <string>

// int a, b, c;
// int x = 1, y = 3;
// int myAge = 22;
// int sum = x + y;
// const int PI = 3.14;
// int input1, input2;

// float f1 = 35e3;
// double d1 = 12E4;

// string a = "50", b = "77", c = "34";

// string s = "cat", ss = "atonic";
// int x = 1;

// string hello = "hello";

// string firstName = "Ryan ", lastName = "Tunkel";
// string fullName = firstName.append(lastName);

// string txt = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// string myString = "AYO";

// string ascii1 = "  0  \n";
// string ascii2 = " /|\\ \n";
// string ascii3 = " / \\ \n";
// string fullAscii = ascii1 + ascii2 + ascii3;

// string iceCreamSize, iceCreamFlavor, iceCreamOrder;

// int power1, power2;
// string message;

// int day;
// string message;

// string message, added;

// int myNumbers[10] = {1, 1, 2, 3, 5, 8, 13, 21, 34, 55};

// string numbers[5] = ("Zero", "One", "Two", "Three", "Four");

int main() {
    // a = b = c = 20;
    // cout << "Hello World!" << endl;

    /* \t = horizontal tab
       \\ = \ 
        \" = " */
    // int, double, char, string, bool

    // cout << "I am learning C++ \n";
    // cout << "I am " << myAge << " years old." << endl;

    // cout << sum;
    // cout << a + b + c;
    // cout << PI;

    // cout << "Type a number: " << endl;
    // cin >> input;
    // cout << "Your number is: " << input << endl;

    // cout << "Input your first number: " << endl;
    // cin >> input1;
    // cout << "Input your second number: "<< endl;
    // cin >> input2;
    // sum = input1 + input2;
    // cout << "Sum: " << sum << endl;

    /*  bool = 1 byte, T/F
        char = 1 byte, single char/letter/number, ASCII val
        int = 2 or 4 bytes, whole nums w/out decs
        float = 4 bytes, fractional nums 1-6/7 decimal digits
        double = 8 bytes, fractional nums 1-15 decimal digits
    */

    // cout << f1 << endl;
    // cout << d1 << endl;

    // cout << a + b + c << endl;

    // cout << s + ss << endl;
    // x |= 0;
    // cout << x << endl;

    /*  &&, ||, ? :, !, <, >, = combos
        "," comma does sequential assignment
        ex: a = (b = 3, b + 2)
        This would first make b = 3 and then make a = b + 2 which = 5)
    */

    // cout << hello << endl;

    // cout << fullName << endl;

    // You can't use the + operator to add a number to a string.

    // cout << "The length of the txt string is: " << txt.length() << endl;
    // can also use size() for the same function;

    // cout << myString[0] << endl;
    // myString[2] = 'Y';
    // cout << myString << endl;

    // \' = '
    // \" = "
    // \\ = "\" (without the quotes)
    // \n = newline
    // \t = tab
    // cout << fullAscii;

    /*  getline() reads a line of text through the input given by the 
        first paramater and assigns it to the second parameter
    */
    // cout << "Type your ice cream size: " << endl;
    // getline(cin, iceCreamSize);
    // cout << "Type your ice cream flavor: "<< endl;
    // getline(cin, iceCreamFlavor);
    // iceCreamOrder = iceCreamSize + " " + iceCreamFlavor;
    // cout << "Your ice cream order is: " << iceCreamOrder << endl;

    // You can omit the "using namespace std" at the top if you put
    // "std::" in front of all string and cout objects

    // Math
    //  max(), min(), etc.
    // If include the cmath header file then get 
    // stuff like sqrt(), round(), and log()
    // there's tons more: https://www.w3schools.com/cpp/cpp_math.asp

    // if-else statements look like this:
    /*  
        if (this) {
            this;
        }
        else {
            that;
        }
    */
    // if: if a condition is true
    // else: if the same condition is false
    // else if: new condition to test if first condition is false
    // switch: specifies many alternative blocks of code to be executed

    // power1 = 50;
    // power2 = power1 * 2;
    // message = power1 > power2 ? "Player 1 is stronger" : "Player 2 is stronger";
    // message = power1 != power2 ? message : "Tie";
    // cout << message << endl;

    // Switch Statements

    // day = 8;

    // switch (day) {
    //     case 1:
    //         message = "Sunday";
    //         break;
    //     case 2:
    //         message = "Monday";
    //         break;
    //     case 3:
    //         message = "Tuesday";
    //         break;
    //     case 4:
    //         message = "Wednesday";
    //         break;
    //     case 5:
    //         message = "Thursday";
    //         break;
    //     case 6:
    //         message = "Friday";
    //         break;
    //     case 7:
    //         message = "Saturday";
    //         break;
    //     default:
    //         message = "End of Days";
    // }
    // cout << message << endl;

    // while() loop
    // do {} while() loop

    // for (stmt1; stmt2; stmt3)
    // stmt1 is executed once before execution of code block
    // stmt2 defines the condition for executing the block
    // stmt3 is executed every time after the block has been executed

    // for (int i = 1; i <= 10; i++) {
    //     cout << i << endl;
    // }

    // // ascii lightning strike
    // added = " ";

    // for (int i = 0; i < 4; i++) {
    //     for (int j = 0; j < 4; j++) {
    //         message = "\\ \\ \n";
    //         added += " ";
    //         cout << added + message;
    //     }
    //     message = "/ / \n";
    //     cout << added + message;
    //     cout << added + "\\ \\ \n";
    // }

    // Faked Avogadro's? Numbers
    // for (int i : myNumbers) {
    //     cout << i << endl;
    // }

    // printing even numbers by skipping odds with continues
    // for (int i = 1; i <= 20; i++) {
    //     if (i % 2 == 1) {
    //         continue;
    //     }
    //     cout << i << endl;
    // }

    // for (string s : numbers) {
    //     cout << s << endl;
    // }

    // you can make arrarys with int array[5] or int array[]

    // sizeof() for arrays gives the size of the array in bytes
    // to get the number of elements, do:
    // int getArrayLength = sizeof(myNumbers) / sizeof(int);
    // can also do a for-each loop

    // multi-dimensional arrays
    // string letters[2][4];
    // can do more too:
    // string letters[2][2][2];

    // int i = 1;
    // cout << "Hi Number " << i << ", how are you?";
    
    // string food = "Pizza";  // Variable declaration
    // string* ptr = &food;    // Pointer declaration

    // // Reference: Output the memory address of food with the pointer (0x6dfed4)
    // cout << ptr << "\n";

    // // Dereference: Output the value of food with the pointer (Pizza)
    // cout << *ptr << "\n";

    return 0;
}