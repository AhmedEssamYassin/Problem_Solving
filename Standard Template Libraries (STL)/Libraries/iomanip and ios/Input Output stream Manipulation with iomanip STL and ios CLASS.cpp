/*
double X,Y;
int A,B;
char C;
-------------------------------------------------------------------------------------------------------------------------------
IO Manipulators --> "iomanip"
Header providing parametric manipulators
-------------------------------------------------------------------------------------------------------------------------------
setiosflags(ios::flag1|ios::flag2|...)		Set format flags (function)
resetiosflags(ios::flag1|ios::flag2|...)	Reset format flags (function)
setbase(base)								Set basefield flag (function)--> 8 is oct // 16 is hex // 10 is dec
setfill(C)									Set fill character (function) --> fills a field width
setw(A)										Set field width (function)
setprecision(A)								Set decimal precision (function)
--> use fixed before it to represent the value with exactly as many digits as in the decimal part as specified by the precision field (setprecision() function) and with no exponent part.
get_money()									Get monetary value (function)
put_money()									Put monetary value (function)
get_time()									Get date and time (function)
put_time()									Put date and time (function)

-------------------------------------------------------------------------------------------------------------------------------
Input/Output Stream --> "ios"
Header providing base classes and types for the IOStream hierarchy of classes
-------------------------------------------------------------------------------------------------------------------------------
Format flag manipulators (functions)
------------------------------------
Independent flags (switch on):
------------------------------------
boolalpha				Alphanumerical bool values --> takes a boolean parameter --> returns true instead of 1 and false instead of 0 (function)
showbase				Show numerical base prefixes (function)
showpoint				Show decimal point (function)
showpos					Show positive signs --> Negative signs are written by default (function)
skipws					Skip whitespaces (function)
unitbuf					Flush buffer after insertions (function)
uppercase				Generate upper-case letters (function)
-------------------------------------------------------------------------------------------------------------------------------
Independent flags (switch off): --> they MAY be switched off by default
------------------------------------
noboolalpha				No alphanumerical bool values (function)
noshowbase				Do not show numerical base prefixes (function)
noshowpoint				Do not show decimal point (function)
noshowpos				Do not show positive signs (function)
noskipws				Do not skip whitespaces (function)
nounitbuf				Do not force flushes after insertions (function)
nouppercase				Do not generate upper case letters (function)
-------------------------------------------------------------------------------------------------------------------------------
----------+--------Important----------+--------

cout.setf(ios::flag1| ios::flag2|.....); --> Sets the format flags selected
cout.unsetf(ios::flag1| ios::flag2|...); --> Clears the format flags selected in mask.

Or use switch-off flags if found
-------------------------------------------------------------------------------------------------------------------------------
Numerical base format flags ("basefield" flags): **ONLY work for values or variables of data type int**
-------------------------------------------------
dec						Use decimal base (function)
hex						Use hexadecimal base (function)
oct						Use octal base (function)
-------------------------------------------------------------------------------------------------------------------------------
Floating-point format flags ("floatfield" flags):
-------------------------------------------------
fixed					Use fixed floating-point notation (function)
scientific				Use scientific floating-point notation --> exponentiation notation (e or E) (function)
hexfloat                write floating-point values in hexadecimal format.
                        The value of this is the same as (fixed|scientific)
defaultfloat            write floating-point values in default floating-point notation. This is the value by default (same as none, before any other floatfield bit is set).
-------------------------------------------------------------------------------------------------------------------------------
Adjustment format flags ("adjustfield" flags):
-------------------------------------------------
internal				The output is padded to the field width by inserting fill characters at a specified internal point.
left					The output is padded to the field width inserting fill characters at the beginning.
right					The output is padded to the field width by appending fill characters at the end.
-------------------------------------------------------------------------------------------------------------------------------
When output manipulators are used, their effect remains in the output stream until further change or reset
*/
#include <iostream>
#include <iomanip>
#include <ios>

#define ll long long
#define endl "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << showbase << uppercase << setbase(16) << 100 << endl; // Now base is set to hexadecimal until a further change
    cout << "-------------------------------------------------\n";
    cout << setbase(10) << setfill('0') << setw(10) << 70 << endl; // Now base is set to decimal until a further change
    cout << "-------------------------------------------------\n";
    cout << fixed << setprecision(6) << 3.5 / 5.256 << endl; // sets the precision to 6 decimals after the floating-point until further change
    cout << 12.325 / 16.3 << endl;
    cout << 30 << endl;   // Will be displayed as 30 because it's of data type int
    cout << 30.0 << endl; // Once it's float, the precision will be applied
    cout << "-------------------------------------------------\n";
    bool test = 15;                    // 15 is a NON-ZERO value and is equivalent to true and is stored as 1 in memory
    cout << boolalpha << test << endl; // Alphanumerical boolean values are displayed until further change
    bool check = 0;                    // 0 is equivalent to false and is stored as 0 in memory
    cout << check << endl;
    cout << "-------------------------------------------------\n";
    cout << showpos << 15 << endl; // Now Positive (and of course Negative) sign will be shown until a further change
    cout << 12 << endl;
    cout << "-------------------------------------------------\n";
    cout.unsetf(ios::fixed | ios::showpos); // Deactivates the precision field and showpos
    cout << 12.0 << endl;
    cout << "-------------------------------------------------\n";
    cout << hex << 100 << endl; // base 16
    cout << dec << 100 << endl; // base 10
    cout << oct << 100 << endl; // base 8
    cout << 8 << endl;
    cout.unsetf(ios::oct);
    cout << 8 << endl;
    cout << "-------------------------------------------------\n";
    cout << uppercase << scientific << 1543.032154321 << endl;
    cout << 21324.322456421 << endl;
    cout.unsetf(ios::uppercase | ios::scientific | ios::oct | ios::showpos);
    cout << 21324.322456421 << endl;
    return 0;
}
