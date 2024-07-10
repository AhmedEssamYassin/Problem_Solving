/*
Header <cmath> declares a set of functions to compute common mathematical operations and transformations

**Trigonometric functions**

cos(X)		Compute cosine (function)
sin(X)		Compute sine (function)
tan(X)		Compute tangent (function)
acos(X)		Compute arc cosine (function)
asin(X)		Compute arc sine (function)
atan(X)		Compute arc tangent (function)
atan2(X)	Compute arc tangent with two parameters (function)
-------------------------------------------------------------------------------------------------------------------------------
**Hyperbolic functions**

cosh(X)		Compute hyperbolic cosine (function)
sinh(X)		Compute hyperbolic sine (function)
tanh(X)		Compute hyperbolic tangent (function)
acosh(X)	Compute area hyperbolic cosine (function)
asinh(X)	Compute area hyperbolic sine (function)
atanh(X)	Compute area hyperbolic tangent (function)
-------------------------------------------------------------------------------------------------------------------------------
**Exponential and logarithmic functions**

exp(X)		Compute exponential function "e^x" (function)
exp2(X)		Compute binary exponential function "2^x" (function)
expm1(X)	Compute exponential minus one "e^x - 1" (function)
frexp(X)	Get significand and exponent (function)
ldexp(X)	Generate value from significand and exponent (function)
log(X)		Compute natural logarithm "ln()" (function)
log10(X)	Compute common logarithm (function)
log2(X)		Compute binary logarithm (function)
log1p(X)	Compute logarithm plus one (function)
logb(X)		Compute floating-point base logarithm (function)
modf(X)		Break into fractional and integral parts (function)
ilogb(X)	Integer binary logarithm (function)
scalbn(X)	Scale significand using floating-point base exponent (function)
scalbln(X)	Scale significand using floating-point base exponent (long) (function)
-------------------------------------------------------------------------------------------------------------------------------
**Power functions**

pow(X,Y)	Raise X to power Y (function)
sqrt(X)		Compute square root (function)
cbrt(X)		Compute cubic root (function)
hypot(X,Y)	Compute hypotenuse --> sqrt(X*X + Y*Y) (function)
-------------------------------------------------------------------------------------------------------------------------------
**Error and gamma functions**

erf		Compute error function (function)
erfc		Compute complementary error function (function)
tgamma		Compute gamma function (function)
lgamma		Compute log-gamma function (function)
-------------------------------------------------------------------------------------------------------------------------------
**Rounding and remainder functions**

ceil(X)			Round up value (function)
floor(X)		Round down value (function)
fmod(X,Y)		Compute remainder of division --> X % Y (function)
trunc(X)		Truncate value --> removes decimals after the floating-point (function)
round(X)		Round to nearest (function)
lround(X)		Round to nearest and cast to long integer (function)
llround(X)		Round to nearest and cast to long long integer (function)
rint(X)			Round to integral value (function)
lrint(X)		Round and cast to long integer (function)
llrint(X)		Round and cast to long long integer (function)
nearbyint(X)		Round to nearby integral value (function)
remainder(X)		Compute remainder (IEC 60559) (function)
remquo(X,Y,&Z)		Compute remainder and quotient (prints remainder and stores quotient in Z)--> Z must be of data type int (function)
-------------------------------------------------------------------------------------------------------------------------------
**Minimum, maximum, difference functions**

fdim(X,Y)	Positive difference --> X - Y (returns 0 is X <= Y)   (function)
fmax(X,Y)	Maximum value "Accepts float parameters" (function)
fmin(X,Y)	Minimum value "Accepts float parameters" (function)
max(X,Y)	Maximum value "Accepts ONLY integers" (function)
min(X,Y)	Minimum value "Accepts ONLY integers" (function)
-------------------------------------------------------------------------------------------------------------------------------
**Other functions**

fabs(X)			Compute absolute value (function)
abs(X)			Compute absolute value (function)
fma(X,Y,Z)		Multiply and add --> X * Y + Z (function)
-------------------------------------------------------------------------------------------------------------------------------
**Comparison macro / functions** returns boolean value (either 1 if true or 0 if false)
isgreater(X,Y)			Is X greater than Y (macro)
isgreaterequal(X,Y)		Is X greater than or equal Y (macro)
isless(X,Y)			Is X less than Y (macro)
islessequal(X,Y)		Is X less than or equal Y (macro)
islessgreater(X,Y)		Is X less or greater than Y (macro)
isunordered(X,Y)		Is X or Y equal NAN (macro)
-------------------------------------------------------------------------------------------------------------------------------
**Macro constants**

INFINITY	Infinity (constant)
NAN		Not-A-Number (constant)
HUGE_VAL	Huge value (constant)
HUGE_VALF	Huge float value
HUGE_VALL	Huge long double value (constant)
-------------------------------------------------------------------------------------------------------------------------------
**Important**
Pay attention to the data type of both arguments and returned values especially if you are dealing with the modular arithmetic operator or if the format of output matters
(It may be converted to the exponential representation with large float values)
*/
#include <iostream>
#include <cmath>

#define ll long long
#define endl "\n"
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cout<<exp(1)<<endl;
    cout<<exp2(7)<<endl;
    cout<<expm1(1)<<" "<<exp(1)-1<<endl;
    cout<<log(2)<<endl;
    cout<<log10(2)<<endl;
    cout<<log2(2)<<endl;
    cout<<log1p(2)<<endl;
    cout<<"-----------------------------------------------------------------------\n";
    cout<<pow(5,2)<<endl;
    cout<<pow(25,0.5)<<endl;
    cout<<pow(25,1/2)<<endl;// 1/2 is evaluated as 0 because the data type of the expression is int so it ignores the fractional part
    cout<<pow(25,1/2.0)<<endl;//Make one of the operands float using data type casting to make the evaluated expression be of data type float and keep the fractional part 
    cout<<8/pow(2,3)<<endl;
    cout<<8%int(pow(2,3))<<endl;//pow() function returns a value of data type double
    //and most functions in cmath STL returns a value of data type float or double, so be careful when using them
    cout<<sqrt(25)<<endl;
    cout<<cbrt(64)<<endl;
    cout<<hypot(5,12)<<endl;
    cout<<"-----------------------------------------------------------------------\n";
    cout<<ceil(2.33)<<" "<<int(2.33)+(2.33>int(2.33))<<endl;//Another method using type casting to perform the same functionality as ceil() function
    //They both output the same result but unlike the type casting method, ceil() function returns a value of data type float
    cout<<ceil(2)<<endl;
    cout<<floor(2.5)<<endl;
    cout<<5/2<<endl;//Integer division is the same as floor() function but unlike Integer division, floor() function returns a value of data type float  
    cout<<round(3.4)<<" "<<int(3.4+0.5)<<endl;//This is a method used to round numbers without using round() function
    //They both output the same result but unlike the type casting method, round() function returns a value of data type float
    cout<<round(3.6)<<" "<<int(3.6+0.5)<<endl;
    cout<<"-----------------------------------------------------------------------\n";
    cout<<max(2,5)<<endl;
    cout<<min(3,8)<<endl;
    cout<<fmax(2.5,1.3)<<endl;
    cout<<fmin(2,2.7)<<endl;
    cout<<trunc(3.1234543)<<endl;
    cout<<abs(-5)<<endl;
    cout<<fabs(-5.32)<<endl;
    cout<<abs(-5.32)<<endl;
    cout<<fma(2,3,4)<<endl;
    cout<<"-----------------------------------------------------------------------\n";
    cout<<isgreater(5,4)<<endl;
    cout<<isgreaterequal(5,5)<<endl;
    cout<<isless(4,8)<<endl;
    cout<<islessequal(4,3)<<endl;
    cout<<islessgreater(4,5)<<" "<<islessgreater(5,4)<<endl;
    
    return 0;
}
