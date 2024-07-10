/*
Most of the time, in competitive programming, there is a need to assign the maximum or minimum value that a data type can hold to a variable , but remembering such a large and precise number comes out to be a difficult job. Therefore, C++ has certain macros to represent these numbers, so that these can be directly assigned to the variable without actually typing the whole number.

**Values of INT_MAX and INT_MIN may vary from compiler to compiler. Following are typical values in a compiler where integers are stored using 32 bits.**

Don't get confused
** "int and unsigned int" are equivalent to "long int and unsigned long int" but "long long int and unsigned long long int" are larger **


CHAR_BIT	Number of bits in a char object (byte)								8 or greater*
SCHAR_MIN	Minimum value for an object of type signed char						-127 (-2^7+1) or less*
SCHAR_MAX	Maximum value for an object of type signed char						127 (2^7-1) or greater*
UCHAR_MAX	Maximum value for an object of type unsigned char					255 (2^8-1) or greater*
CHAR_MIN	Minimum value for an object of type char							either SCHAR_MIN (-128) or 0
CHAR_MAX	Maximum value for an object of type char							either SCHAR_MAX (127) or UCHAR_MAX
MB_LEN_MAX	Maximum number of bytes in a multibyte character, for any locale 1 or greater*
SHRT_MIN	Minimum value for an object of type short int						-32767 (-2^15+1) or less*
SHRT_MAX	Maximum value for an object of type short int						32767 (2^15-1) or greater*
USHRT_MAX	Maximum value for an object of type unsigned short int				65535 (2^16-1) or greater*
INT_MIN		Minimum value for an object of type int								-2147483647 (-2^31+1) or less*
INT_MAX		Maximum value for an object of type int								2147483647 (2^31-1) or greater*
UINT_MAX	Maximum value for an object of type unsigned int					4294967295 (2^32-1) or greater*
LONG_MIN	Minimum value for an object of type long int						-2147483647 (-2^31+1) or less*
LONG_MAX	Maximum value for an object of type long int						2147483647 (2^31-1) or greater*
ULONG_MAX	Maximum value for an object of type unsigned long int				4294967295 (2^32-1) or greater*
LLONG_MIN	Minimum value for an object of type long long int					-9223372036854775807 (-2^63+1) or less*
LLONG_MAX	Maximum value for an object of type long long int					9223372036854775807 (2^63-1) or greater*
ULLONG_MAX	Maximum value for an object of type unsigned long long int			18446744073709551615 (2^64-1) or greater*



*/
#include <iostream>
#include <climits>

#define ll long long
#define endl "\n"
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cout<<CHAR_BIT<<endl;
    cout<<SCHAR_MIN<<endl;
    cout<<SCHAR_MAX<<endl;
    cout<<UCHAR_MAX<<endl;
    cout<<CHAR_MIN<<endl;
    cout<<CHAR_MAX<<endl;
    cout<<MB_LEN_MAX<<endl;
    cout<<SHRT_MIN<<endl;
    cout<<SHRT_MAX<<endl;
    cout<<USHRT_MAX<<endl;
    cout<<INT_MIN<<endl;
    cout<<INT_MAX<<endl;
    cout<<UINT_MAX<<endl;
    cout<<LONG_MIN<<endl;
    cout<<LONG_MAX<<endl;
    cout<<ULONG_MAX<<endl;
    cout<<LLONG_MIN<<endl;
    cout<<LLONG_MAX<<endl;
    cout<<ULLONG_MAX<<endl;
    
    return 0;
}
