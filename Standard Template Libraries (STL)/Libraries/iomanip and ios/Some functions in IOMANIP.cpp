/*
A : Strip its decimal (i.e., truncate it) and print its hexadecimal representation (including the 0x  prefix) in lower case letters.
B : Print it to a scale of 2 decimal places, preceded by a + or - sign (indicating if it's positive or negative), right justified, and left-padded with underscores so that the printed result is exactly 15 characters wide.
C : Print it to a scale of exactly nine decimal places, expressed in scientific notation using upper case.
*/
/*

input test:
5
28473348240.706573486328 25255936.905333388597 561062869105.690063476562
193407077285.911254882812 29579676.652467213571 128199936410.734954833984
396111231594.237182617188 2114281.323031922337 20207841881.095516204834
406421152336.609313964844 67153516.350574523211 47361108519.905632019043
238025850337.944885253906 82871058.783060148358 156778009269.216827392578

*/
#include <iostream>
#include <iomanip> 
using namespace std;
#define ll long long

void trunc_Hexa(double x)
{
  cout << left << hex << showbase << nouppercase;
    cout << (long long) x << endl;
}

void  Two_decimal(double x)
{
   cout.precision(2);
    cout << showpos << fixed << setfill('_') << setw(15) << right;
    cout << x << endl;
}

void exp_notation(double x)
{
  cout<<noshowpos<<fixed<<setprecision(9)<<uppercase<<scientific<<x<<"\n"; 
}
int main()
{
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  int Q;
  cin>>Q;
  double A,B,C;
  while(Q--)
  {
    cin>>A>>B>>C;
    trunc_Hexa(A);
    Two_decimal(B);
    exp_notation(C);
  }
    return 0;
}

/*
**Another Solution**
#include <iostream>
#include <iomanip>
#include <ios>
#include <cmath>
#define ll long long
#define endl "\n"
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin>>t;
    double A,B,C;
    while(t--)
    {
    	cin>>A>>B>>C;
    	cout<<hex<<nouppercase<<showbase<<(long long)trunc(A)<<endl;
    	cout<<showpos<<setfill('_')<<setw(15)<<fixed<<setprecision(2)<<B<<endl;
    	cout<<noshowpos<<setprecision(9)<<uppercase<<scientific<<C<<endl;
    }
    return 0;
}
*/