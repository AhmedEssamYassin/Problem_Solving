#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//------+--------------+ C-Style strings ------+--------------+

	// Declaration:
	// We can declare a c-style string EXACTLY in the same way we declare an array of characters!
	char arr[256]; // Size MUST be known at compile-time

	// Initialization:
	char name[6] = {'A', 'h', 'm', 'e', 'd', '\0'};
	// To hold the NULL character at the end of the array, the size of the character array containing the string is one more than the number of characters in the actual word
	/*
	You can also assign a string literal (it's type is const char *) to a character array
	You do NOT need to actually place the null character at the end of a string literal.
	The C++ compiler automatically places the '\0' at the end of the string when it initializes the character array
	*/

	char Password[] = "AEY0144436102#";
	/*
	- One important point to note is that strings follow ALL the same rules as arrays.
	  This means you can initialize the string upon creation, but you can NOT assign values to it using the assignment operator after that!
	- However, you can still modify single elements (also same as arrays)
	*/
	// Password = "1234"; // Yields an error
	Password[2] = 'E'; // It works fine, and now it's "AEE0144436102#"

	/*
	Why did we declare the C-Style string arr to be 255 characters long?
	The answer is that we don’t know how many characters the user is going to enter, so we are using this array of 255 characters as a buffer.
	A buffer is memory set aside temporarily to hold data.
	If the user were to enter more characters than our array could hold, we would get a buffer overflow.
	A buffer overflow occurs when the program tries to store more data in a buffer than the buffer can hold.
	Buffer overflow results in other memory being overwritten, which usually causes a program crash, but can cause any number of other issues
	---------------
	We use
	cin.getline(char * arr, size_t n) and cin.getline(char * arr, size_t n, char C) to handle this problem:
	arr: A character array in which data is stored
	n: Maximum number of character to extract
	C: delimiter character
	cin extracts characters from input stream until either:
	- Fills the whole size (n) of the character buffer
	- Hits the delimiter
	*/
	cin.getline(arr, 25, '\\'); // Extracts characters of the input stream until it fills 25 characters or hits the '\\' character

	//------+--------------+ C-Style strings VS char pointers ------+--------------+
	char str[] = "c-Style string";
	/*
	- str[i] is modifiable
	- str is NOT modifiable, i.e., str CANNOT point to any other character other than the first character of this string literal
	  However, we STILL can perform other pointer arithmetic on this pointer as long as they does NOT modify it
	  i.e., *(str + i) is allowed but *(str++), str-- or *(++str) are NOT allowed
	- str is char* const, i.e., it CANNOT point to any other string (str = "Other" is NOT allowed)
	- sizeof(str) evaluates to the length of that string (because each character is one byte)
	*/
	str[0] = 'C';		// It works fine, now it's "C-Style string"
	cout << *(str + 2); // Same as str[2]
	// cout << *(str++); // Yields an error
	// cout << *(++str); // Yields an error
	// str++; // Yields an error
	// str = "1234";// Yields an error

	char *ch_ptr = "character pointer";
	/*
	- ch_ptr[i] is NOT modifiable, because ch_ptr now holds the address of the const char* "character pointer" which is stored in a "read-only" data segment
	- The pointer ch_ptr is NOT const, i.e., it can point to any other string literal
	- sizeof(ch_ptr) evaluates to the 4 or 8 bytes (depending on the architecture) because it's just a pointer
	*/
	// ch_ptr[0] = 'C'; // Yields a segmentation fault
	ch_ptr++;			   // Works fine
	cout << *(--ch_ptr);   // Works fine
	cout << *(ch_ptr + 2); // Same as ch_ptr[2]

	//------+--------------+ C-Style strings functions ------+--------------+

	/*
	strcpy(S1, S2):
	To avoid overflows, the size of the destination string shall be long enough to contain the source string (including the terminating null character), and should NOT overlap in memory with the source.
	--------------
	strcat(S1, S2)
	To avoid overflows, the size of the destination string shall be long enough to contain the source string (including the terminating null character), and should NOT overlap in memory with the source.
	--------------
	strlen(S):
	It returns the length of the string NOT the size of the buffer and NOT including the null terminating character.
	---------------
	strcmp(S1, S2):
	Compares the two strings lexicographically (the same way used to sort words alphabetically in dictionaries),
	meaning that it starts comparison character by character, starting from the first character.
	If first character in both strings is equal, then this function will check the second character, if this is also equal then it will check the third and so on.
	This process continues until either:
	- A mismatch between the two strings is encountered
	- A character in either string is NULL. (A string ends)
	When S1 and S2 are NOT the same, the value returned by strcmp() function is the difference between the ASCII values of the first unmatched characters in S1 and S2
	---------------------------------
	memset(char *ptr, char, size_t n)
	Fills a block of memory
	- Sets the first num bytes of the block of memory pointed to by ptr to the specified val (val  is interpreted as an unsigned char)
	- returns ptr
	----------------------------------------
	strtok(char *str, const char *delimiters)
	Splits string into tokens.
	- A sequence of calls to this function split str into tokens,
	  which are sequences of contiguous characters separated by any of the characters that are part of delimiters literal
	- On the first call, the function expects a C string as argument for str, whose first character is used as the starting location to scan for tokens.
	- In subsequent calls, the function expects a null pointer and uses the position right after the end of the last token as the new starting location for scanning.

	- To determine the beginning and the end of a token,
	  the function first scans from the starting location for the first character NOT contained in delimiters (which becomes the beginning of the token).
	  And then scans starting from this beginning of the token for the first character contained in delimiters, which becomes the end of the token.
	- The scan also stops if the terminating null character is found.

	- This end of the token is automatically replaced by a null-character, and the beginning of the token is returned by the function.
	- Once the terminating null character of str is found in a call to strtok, all subsequent calls to this function (with a null pointer as the first argument) return a null pointer.

	Return value:
	If a token is found, a pointer to the beginning of the token. Otherwise, a null pointer.
	A null pointer is always returned when the end of the string (i.e., a null character) is reached in the string being scanned.

	*/
	{
		char S1[] = "A character Array";
		char S2[] = " is a C-style string";
		strcat(S1, S2); // Now, S1[] = "A character Array is a C-style string";

		// strcpy(S1, S2); // Yields buffer overflow because the length of S1 is less then the length of S2
		strcpy(S2, S1); // Works fine! Now, S2 = "A character Array"

		strlen(S1); // returns the length of the string NOT the size of the buffer and NOT including the null terminating character.

		strcmp(S1, S2); // returns 'A' - ' '

		char Line[] = "This is A sentence, or a Line, just to show how strtok() works! Amazing ha? I know:)";
		char *token = strtok(Line, " ,!?"); // First call
		while (token)
		{
			cout << token << endl;
			token = strtok(nullptr, " ,!?"); // Subsequent calls
		}

		memset(S1, 'X', strlen(S1)); // Fills ALL S1 with X's
	}
	cout << "---------------------------------------------------------------------------------" << endl;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//------+--------------+ Class strings ------+--------------+
	// Declaration:
	string T;

	// Initialization and constructors
	string S = "A class string";
	{
		string S2("Full string");

		string S3("Full string", 3); //"Ful"

		string S4(S2, 2); // A string starting from index 2 to the end --> "ll string"

		string S5(S2, 2, 6); // A string of length 6 starting from index 2 --> "ll str"

		string S6(5, 'X'); // A string of 5 X's --> "XXXXX"

		string S7({'X', 'Y', 'Z'}); //"XYZ"
	}
	// Unlike C-style strings, we can re-assign the class string to any value at any time after initialization
	S = "Another class string"; // Works fine!
	/*
	You do NOT need to actually place the null character at the end of a string literal.
	The C++ compiler automatically places the '\0' at the end of the string when it initializes the class string
	That’s why, the size of a class string will be more in bytes than the size of the actual string literal
	You can actually get the size of that character array using the sizeof( ) operator

	NOTE:
	- The size of a class string is NOT allocated like the C-style string because of structure padding

	Structure Padding:
	------------------
	It's a padding added to satisfy alignment constraints. Data structure alignment impacts both performance and correctness of programs:
	- Mis-aligned access might be a hard error (often SIGBUS).
	- Mis-aligned access might be a soft error.
	  - Either corrected in hardware, for a modest performance-degradation.
	  - Or corrected by emulation in software, for a severe performance-degradation.
	In addition, atomicity and other concurrency-guarantees might be broken, leading to subtle errors.
	*/
	cout << sizeof(S); // Will probably print more than 21

	getline(cin, T); // reads a line (string with spaces) as an input
	cout << T << endl;

	T = ""; // Assigns T to an empty string

	getline(cin, T, '!'); // reads a line (string with spaces) as an input until the delimiter '!'
	cout << T << endl;

	//------+--------------+ Class strings functions ------+--------------+

	string Word = "An example sentence!";

	/*
	member constants:
	-----------------
	static const size_t npos = -1;

	Maximum value for size_t
	npos is a static member constant value with the greatest possible value for an element of type size_t.

	This value, when used as the value for a len (or sub_len) parameter in string's member functions, means "until the end of the string".

	As a return value, it is usually used to indicate NO matches.

	This constant is defined with a value of -1, which because size_t is an unsigned integral type, it is the largest possible representable value for this type.

	Member functions:
	-----------------
	front(): returns the first character
	back() : returns the last character
	at(idx): returns the character at idx
	begin(): returns an iterator to the first character
	end(): returns an iterator to the end (after the last character)
	rbegin(): returns reverse iterator to reverse beginning (iterator to the end (the last character) and increments towards beginning)
	rend():	returns reverse iterator to reverse end (iterator to the beginning (before the last character))
	size() : returns the length of the string (number of characters)
	length() : returns the length of the string (number of characters)
	empty(): returns true if the string is empty and false otherwise
	clear(): Deletes the whole string (Makes it empty)
	pop_back(): Deletes the last character
	append	Appends to string (public member function)
	push_back(char): Appends a character to the end of the string
	assign(): Assigns content to string

	insert(pos, str): Inserts str right before the character at insertion point pos
	insert(pos, str, idx, len): Inserts substring of str starting from idx and of length len right before the character at insertion point pos
	insert(pos, const char*, N): Inserts the first N character of the string literal right before the character at insertion point pos
	insert(pos, const char*): Inserts the string literal right before the character at insertion point pos
	insert(pos, len, char): Inserts a string(len, char) right before the character at insertion point pos
	insert(itr, char): Inserts a character right before the character at the iterator
	insert(itr, len, char): Inserts a string(len, char) right before the character at the iterator itr
	insert(itr, first, last): Inserts a range of [first, last) right before the character at the iterator itr

	replace(pos, len, str): Replaces the substring of length len starting from pos with str
	replace(pos, len, str, pos2, N): Replaces the substring of length len starting from pos with substring of length N starting from pos2 of str
	replace(pos, len, const char*): Replaces the substring of length len starting from pos with the string literal
	replace(pos, len, const char*, N): Replaces the substring of length len starting from pos with the first N characters of the string literal
	replace(pos, len, N, char): Replaces the substring of length len starting from pos with the string(N, char)
	replace(first, last, str): Replaces the range [first, last) with the string str
	replace(first, last, const char*): Replaces the range [first, last) with the string literal
	replace(first, last, const char*, N): Replaces the range [first, last) with the first N characters of the string literal
	replace(first, last, N, char): Replaces the range [first, last) with the first N characters of the string literal
	replace(first1, last1, first2, last2): Replaces the range [first1, last2) with the range [first2, last2)

	substr(pos, len): construct a substring of length len starting from pos
	substr(pos): construct a substring starting from pos to the end of the string

	erase(pos, len): removes the substring of length len starting from pos
	erase(pos): removes the substring starting from pos to the end of the string
	erase(itr): removes the character
	erase(first, last): removes the substring in range [first, last)

	swap(S2): Swaps string values

	find(str, pos = 0): Finds the position of the first character of the first occurrence of str
	find(const char*, pos = 0): Finds the position of the first character of the first occurrence of the string literal
	find(char, pos = 0): Finds the position of the first occurrence of the character
	find(const char*, pos, N): Finds the position of the first character of the first occurrence of the first N characters of the string literal
	pos:
	Position of the first character in the string to be considered in the search.
	If this is greater than the string length, the function never finds matches.
	Note: The first character is denoted by a value of 0 (NOT 1): A value of 0 means that the entire string is searched.

	rfind(str, pos = -1): Finds the position of the first character of the last occurrence of str
	rfind(const char*, pos = -1): Finds the position of the first character of the last occurrence of the string literal
	rfind(char, pos = -1): Finds the position of the last occurrence of the character
	rfind(const char*, pos, N): Finds the position of the first character of the last occurrence of the first N characters of the string literal

	If the searched arg is NOT found, it returns string::npos which is -1

	find_first_of	Find character in string (public member function)
	find_last_of	Find character in string from the end (public member function)
	find_first_not_of	Find absence of character in string (public member function)
	find_last_not_of	Find non-matching character in string from the end (public member function)

	Concatenation and comparison can be easily done using the overloaded operators =, > and <
	*/
	cout << S + " Ahmed" + " " + "Essam" << endl; // we can add several strings using the operator +

	S += "New string";
	if (!S.empty())
		cout << "string is not empty, it is: " << S << endl;
	S = ""; // deletes the whole string
	S += "Another new string";
	cout << S << endl;
	{
		string str1 = "to be question";
		string str2 = "the ";
		string str3 = "or not to be";
		string::iterator it;

		// used in the same order as described above:
		str1.insert(6, str2);								 // to be (the )question
		str1.insert(6, str3, 3, 4);							 // to be (not )the question
		str1.insert(10, "that is cool", 8);					 // to be not (that is )the question
		str1.insert(10, "to be ");							 // to be not (to be )that is the question
		str1.insert(15, 1, ':');							 // to be not to be(:) that is the question
		it = str1.insert(str1.begin() + 5, ',');			 // to be(,) not to be: that is the question
		str1.insert(str1.end(), 3, '.');					 // to be, not to be: that is the question(...)
		str1.insert(it + 2, str3.begin(), str3.begin() + 3); // (or )

		std::cout << str1 << '\n';
	}
	cout << "---------------------------------------------------------------------------------" << endl;
	{
		string base = "this is a test string.";
		string str2 = "n example";
		string str3 = "sample phrase";
		string str4 = "useful.";

		// Using positions:
		string str = base;				  // "this is a test string."
		str.replace(9, 5, str2);		  // "this is an example string." (1)
		str.replace(19, 6, str3, 7, 6);	  // "this is an example phrase." (2)
		str.replace(8, 10, "just a");	  // "this is just a phrase."     (3)
		str.replace(8, 6, "a shorty", 7); // "this is a short phrase."    (4)
		str.replace(22, 1, 3, '!');		  // "this is a short phrase!!!"  (5)

		// Using iterators:
		str.replace(str.begin(), str.end() - 3, str3);						// "sample phrase!!!"      (1)
		str.replace(str.begin(), str.begin() + 6, "replace");				// "replace phrase!!!"     (3)
		str.replace(str.begin() + 8, str.begin() + 14, "is coolness", 7);	// "replace is cool!!!"    (4)
		str.replace(str.begin() + 12, str.end() - 4, 4, 'o');				// "replace is cooool!!!"  (5)
		str.replace(str.begin() + 11, str.end(), str4.begin(), str4.end()); // "replace is useful."    (6)
		cout << str << '\n';
	}
	cout << "---------------------------------------------------------------------------------" << endl;
	{
		string str("The sixth sick sheik's sixth sheep's sick.");
		string key("sixth");

		size_t found = str.rfind(key);
		if (found != string::npos)
			str.replace(found, key.length(), "seventh");

		cout << str << '\n';
	}
	return 0;
}