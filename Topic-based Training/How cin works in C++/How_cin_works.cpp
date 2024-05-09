#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define OO 2e18
#define MaxSize 1000000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    /*
    The 'c' in the name refers to "character",i.e. cin means "character input" and wcin means "wide character input".

    std::cin extracts inputs from the input stream buffer as long as it's NOT empty, otherwise, the program waits for more inputs.

    Once std::cin is constructed, std::cin.tie() returns &std::cout.
    This means that any formatted input operation on std::cin forces a call to std::cout.flush() if any characters are pending for output.

    The std::cin extracts input until it hits a space or a newline, i.e. it distinguishes between inputs by either a space or a newline (enter key)

    cin.ignore(N, Delimiter);
    N: Maximum number of characters to extract (and ignore).
    Delimiter: The function stops extracting characters as soon as an extracted character compares equal to this.
    Note that the delimiting character is extracted, and thus the next input operation will continue on the character that follows it (if any).
    It extracts and ignores either exactly N characters or until an extracted character compares equal to the Delimiter (whichever occurs first).

    cin.ignore(); without any parameters
    Extracts and ignores JUST one character from the input buffer

    Let's Discuss some cases:

    1. When std::cin is reading input of some data type from the input stream buffer,
    it extracts input until it either fills the memory specified for that data type or it hits a disallowed character for that data type:
    - A floating-point is disallowed for integers.
    - A space and a newline are disallowed for all data types.
    Example:
    int number;
    char c;
    cin >> number;// If the input stream buffer has "13.245", std::cin will extract 13 as input and .245 remains in the input stream buffer
    cin >> c;//If the input stream buffer has "H33", std::cin will extract 'H' as input and 33 remains in the input stream buffer

    2. When inputting any data before inputting a string (either a C-style or a class string) and we hit the enter key (newline),
    this newline remains in the input stream buffer and thus, the next string gets filled with that newline character '\n' without waiting for inputting anything
    (which is of course NOT intended)
    - The solution to this problem is to use std::cin.ignore(256, '\n'); in order to extract that newline from the input buffer and ignore it then wait for more inputs

    3. What happens if cin fails to place a value in a variable due to incompatible datatype?
    Example:
    Trying to place a character in a variable of a numerical datatype such as int, float, double, ...etc.
    - If cin fails, it places a 0 in that variable and its error state is set accordingly.(cin itself becomes false)
    (So, future I/O operations will NOT work correctly unless we use cin.clear())
    - If cin successfully places the value in that variable, it returns true.
    We can make use of this to read undetermined number of inputs of some numerical datatype as follows:
    int number;
    while(cin>>number)
    {
        //Some logic
    }
    This loop will continue to take inputs from the input stream buffer until it's either empty or it hits an incompatible datatype
    */

    cout << "----------------------------------------------------Examples on 1st case:----------------------------------------------------\n";
    int X;
    float Y;
    char ch1, ch2;
    cout << "If input is: 13 24.6 A B and the variables are in this order: cin >> X >> Y >> ch1 >> ch2;\n";
    cin >> X >> Y >> ch1 >> ch2;
    cout << "std::cin extracts inputs as follows: \n";
    cout << "X : " << X << endl
         << "Y : " << Y << endl
         << "ch1 : " << ch1 << endl
         << "ch2 : " << ch2 << endl;
    cin.ignore(256, '\n');
    cout << "----------------------------------------------\n";
    cout << "If input is: 13 24.6 A B and the variables are in this order: cin >> Y >> X >> ch1 >> ch2;\n";
    cin >> Y >> X >> ch1 >> ch2;
    cout << "std::cin extracts inputs as follows: \n";
    cout << "X : " << X << endl
         << "Y : " << Y << endl
         << "ch1 : " << ch1 << endl
         << "ch2 : " << ch2 << endl;
    cin.ignore(256, '\n');
    cout << "----------------------------------------------\n";
    cout << "If input is: 13 24.6 A B and the variables are in this order: cin >> X >> ch1 >> ch2 >> Y;\n";
    cin >> X >> ch1 >> ch2 >> Y;
    cout << "std::cin extracts inputs as follows: \n";
    cout << "X : " << X << endl
         << "Y : " << Y << endl
         << "ch1 : " << ch1 << endl
         << "ch2 : " << ch2 << endl;
    cin.ignore(256, '\n');
    cout << "----------------------------------------------\n";
    cout << "If input is: 13 24.6 A B and the variables are in this order: cin >> Y >> ch1 >> X >> ch2;\n";
    cin >> Y >> ch1 >> X >> ch2;
    cout << "std::cin extracts inputs as follows: \n";
    cout << "X : " << X << endl
         << "Y : " << Y << endl
         << "ch1 : " << ch1 << endl
         << "ch2 : " << ch2 << endl;
    cin.ignore(256, '\n');
    cout << "----------------------------------------------------Examples on 2nd case:----------------------------------------------------\n";
    cout << "In case we do NOT use std::cin.ignore(256,'\\n'); The first string will consume the '\\n' in the input stream buffer so it will appear empty!\n";
    int N;
    cout << "How many users would you like to insert?\n";
    cin >> N; // The newline (enter key) after this input would cause the problem
    string *arr = new string[N];
    // cin.ignore(256, '\n');
    for (int i{}; i < N; i++)
        getline(cin, arr[i]);

    for (int i{}; i < N; i++)
        cout << "User's Name #" << i + 1 << ": " << arr[i] << endl;
    cout << "-----------------------------------------------------------------\n";
    cin.ignore(256, '\n'); // We also should use this here to extract the third string that wasn't consumed previously and ignore it before the next input
    cout << "In case we USE std::cin.ignore(256,'\\n'); The first string will be filled normally\n";
    cout << "How many users would you like to insert?\n";
    cin >> N; // The newline (enter key) after this input would cause the problem
    cin.ignore(256, '\n');
    delete[] arr;
    arr = new string[N];
    for (int i{}; i < N; i++)
        getline(cin, arr[i]);

    for (int i{}; i < N; i++)
        cout << "User's Name #" << i + 1 << ": " << arr[i] << endl;
    cout << "----------------------------------------------------Examples on 3rd case:----------------------------------------------------\n";
    // cin.ignore(256, '\n'); // This is NOT needed now because the previous case has consumed all inputs properly
    int number;
    cin >> number;
    while (!cin) // while cin is in a false state
    {
        cout << "You have input incorrect data, please re-enter your input in a correct way: \n";
        // Now we CANNOT use cin because it's in a false state
        cin.clear(); // So that future I/O operations will work correctly
        // But the line caused the cin to fail is still in the input buffer
        cin.ignore(256, '\n'); // To ignore the wrong input line that caused the cin to fail
        cin >> number;
    }
    // After this loop, it's guaranteed that cin has placed a correct value in the variable
    if (number & 1)
        cout << "ODD\n";
    else
        cout << "EVEN\n";
    // and we can read correct inputs until either the buffer is empty or an incorrect line is hit again!
    while (cin >> number)
    {
        if (number & 1)
            cout << "ODD\n";
        else
            cout << "EVEN\n";
    }
    return 0;
}