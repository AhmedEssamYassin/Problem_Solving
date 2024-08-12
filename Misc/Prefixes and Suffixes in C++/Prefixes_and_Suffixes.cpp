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
    Prefixes and Suffixes for integer literals in C++:
    --------------------------------------------------
    1. Prefixes:
    ------------
    1. Decimal-literal (base 10):- a NON-zero decimal digit followed by zero or more decimal digits from the set {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    For example, 56, 78.

    2. Octal-literal (base 8):- a zero followed by zero or more octal digits from the set {0, 1, 2, 3, 4, 5, 6, 7}
    For example, 045, 076, 06210.

    3. Hex-literal (base 16):- 0x or 0X followed by one or more hexadecimal digits from the set {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, A, b, B, c, C, d, D, e, E, f, F}
    For example, 0x23A, 0Xb4C, 0xFEA.

    4. Binary-literal (base 2):- 0b or 0B followed by one or more binary digits from the set {0, 1}
    For example, 0b101, 0B111.
    ---------------------------------------------------------------------------------------------------------------------------------------------------------------

    2. Suffixes:
    ------------
    For integers:
    int:- No suffix are required because integer constant are by default assigned as int data type.
    unsigned int: character u or U at the end of integer constant.
    long int: character l or L at the end of integer constant.
    unsigned long int: character ul or UL at the end of integer constant.
    long long int: character ll or LL at the end of integer constant.
    unsigned long long int: character ull or ULL at the end of integer constant.

    For floating-point numbers:
    1. (NO suffix): defines double
    2. f or F : defines float
    3. l or L : defines long double

    Comparison of floating-point numbers in C++:
    --------------------------------------------
    The problem is when we assign a floating-point value in a variable of float datatype then compare this variable with a double,

    The values used in an expression are considered as double (double precision floating-point format) unless a ‘f’ is specified at the end.
    So the expression (X == 0.1) has a double on right hand side and a float which is stored in a single precision floating-point format on the left hand side.
    In such situations, float is promoted to double.
    The double precision format uses more bits for precision than single precision format.
    The binary equivalent of 0.1 (base 10) can be written as (0.00011001100110011…) (base 2) which goes up to infinity.
    Since the precision of float is less than the double therefore after a certain point (23 in float and 52 in double) it would truncate the result.
    Hence, after promotion of float into double (at the time of comparison) compiler will pad the remaining bits with zeroes.
    Hence, we get the different result in which decimal equivalent of both would be different. For instance,

    In float
    => (0.1) (base 10) = (0.00011001100110011001100) (base 2)

    In double after promotion of float ...(1)
    => (0.1) (base 10) = (0.00011001100110011001100000000000000000...) (base 2)
                                                   ^ padding zeroes here
    In double without promotion ... (2)
    => (0.1) (base 10) = (0.0001100110011001100110011001100110011001100110011001) (base 2)

    Hence we can see the result of both equations are different

    The solution to this problem is either:
    1. To use the suffix 'f' or 'F' at the end of the floating-point literal at the time of comparison
    (X == 0.1f)
    2. Make the variable of datatype double instead of float in order NOT to force any kind of type promotion at comparison time

    Note:
    The promotion of float to double can only cause mismatch when a value (like 0.1) uses more precision bits than the bits of single precision.
    For example, a value such as (0.5) wouldn't cause any problems!

    Here binary equivalent of 0.5 (base 10) is (0.100000…) (base 2)
    (No precision will be lost in both float and double type).
    Therefore if the compiler pad the extra zeroes at the time of promotion then we would get the same result in the decimal equivalent of both left and right
    side in the comparison(Z == 0.5)
    ---------------------------------------------------------------------------------------------------------------------------------------------------------------

    3. Digit separator: In C++
    --------------------------
    integer literals may contain digit separators to allow digit grouping into more readable forms.
    This is particularly useful for bit fields, and makes it easier to see the size of large numbers (such as a million) at a glance by subitizing rather than counting digits.
    It is also useful for numbers that are typically grouped, such as credit card number or social security numbers.
    [a] Very long numbers can be further grouped by doubling up separators.
    Typically decimal numbers (base-10) are grouped in three digit groups (representing one of 1000 possible values),
    binary numbers (base-2) in four digit groups (one nibble, representing one of 16 possible values),
    and hexadecimal numbers (base-16) in two digit groups (each digit is one nibble, so two digits are one byte, representing one of 256 possible values).
    Numbers from other systems (such as id numbers) are grouped following whatever convention is in use.
    */
    cout << "---------------------------------------------Prefixes---------------------------------------------\n";
    int Decimal_Number = 659;     // Decimal-literal (base 10) --> stores 659
    int Octal_Number = 015;       // Octal-literal (base 8) --> stores (1 * 8 + 5 * 1) = 13
    int Hex_Number = 0x42C;       // Hex-literal (base 16) --> stores (4 * 16^2 + 2 * 16 + 12 * 1) = 1068
    int Binary_Number = 0b111010; // Binary-literal (base 2) --> stores (1 * 2^5 + 1 * 2^4 + 1 * 2^3 + 0 + 1 * 2^1 + 0) = 58
    cout << "The Decimal_Number stored: " << Decimal_Number << endl;
    cout << "The Octal_Number stored: " << Octal_Number << endl;
    cout << "The Hex_Number stored: " << Hex_Number << endl;
    cout << "The Binary_Number stored: " << Binary_Number << endl;
    cout << "---------------------------------------------Suffixes---------------------------------------------\n";
    cout << "-------------------------------------------For integers-------------------------------------------\n";

    cout << "A long long int literal: " << 1234567890123456789LL << endl;

    cout << "An unsigned long long int literal: " << 12345678901234567890ull << endl;

    cout << "Automatic conversion to unsigned long long even without long long prefix: " << 12345678901234567890u << endl;

    cout << "------------------------------------For floating-point numbers------------------------------------\n";

    float X = 3.425;
    cout << "First case:\nX is float and compared to the literal 3.425 which is considered a double, thus, the condition (X == 3.425) evaluates to false\n";
    if (X == 3.425)
        cout << "They are Equal!\n\n";
    else
        cout << "They are NOT Equal!\n\n";

    cout << "Second case:\nX is float and compared to the literal 3.425f which is considered a float, thus, the condition (X == 3.425) evaluates to true\n";

    if (X == 3.425f)
        cout << "They are Equal!\n\n";
    else
        cout << "They are NOT Equal!\n\n";

    cout << "Third case:\nY is double and compared to the literal 3.425 which is considered a double, thus, the condition (Y == 3.425) evaluates to true\n";
    double Y = 3.425;
    if (Y == 3.425)
        cout << "They are Equal!\n\n";
    else
        cout << "They are NOT Equal!\n\n";

    cout << "Fourth case:\nZ is float and compared to the literal 0.5 which is considered a double but its representation is the same as a float or a double";
    cout << ", thus, the condition (Z == 0.5) evaluates to true\n";
    float Z = 0.5;
    if (Z == 0.5)
        cout << "They are Equal!\n";
    else
        cout << "They are NOT Equal!\n";
    return 0;
}