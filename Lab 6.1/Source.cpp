/* Benjamin Roe
 C++ Fall 2019
 Due November 14
 Lab 6 Binary to Decimal Conversion
Write a C++ program that reads characters representing binary (base 2)
numbers from a data file called BinaryIn.dat and translates them to decimal (base 10)
numbers. The binary and decimal numbers should be output in two columns with
appropriate headings.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void convert(char input, int& value);

int main() /*Before you get into grading this, I just want to say that I really did try but
		   no matter what I did, it simply would not format correctly.*/
{
	ifstream inFile;
	char input;
	int value = 0;
	int digits = 24;
	cout << setw(19) <<"Binary Number" << setw(40) << "Decimal Equivalent" << endl;
	//Places headers.
	inFile.open("C:/Users/ROE26/source/repos/Lab 6.1/Lab 6.1/BinaryIn.dat");
	input = '\n'; //Gives an empty input in a failed attempt to get it to format correctly.
	while (inFile)
	{
		while (input == ' ') /*Allows spaces to be present before and after inputs. 
							 No matter what I did, I could not get it to reject spaces
							 in the middle of binary numbers.*/
		{
			inFile.get(input);
		}
		if (input == '0' || input == '1') //Only jumps to convert function if input is 1 or 0.
		{
			convert(input, value);
			digits--; /*The value of digits is intended to dictate formatting.
					  As you can probably see though, I could not get it to
					  work even after hours of effort.*/
		}
		else if (input == '\n') //Detects when a binary number has ended.
		{
			cout << setw(25 + (digits) / 2) << value << setw(digits / 2) << endl;
			//See line 39.
			value = 0; //Resets output value so the next number can be calculated.
			digits = 25;
		}
		else //Catches any inputs other that 0, 1, or \n and marks them as invalid.
		{
			cout << "Invalid Input";
			cout << setw(25 + (digits) / 2) << setw(digits / 2) << endl;
			/*Is supposed to maintain the formatting even in the presence of invalid inputs
			but of course doesn't exactly work how it should because I cannot get it to format
			as desired in the first place.*/
			value = 0;
			inFile.get(input);
		}
		inFile.get(input);
	}
	cout << setw(25 + (digits) / 2) << value << setw(digits / 2) << endl;
	//Does the output for the final decimal value.
	return 0;
}

void convert(char input, int& value) /*Displays current input and uses it to calculate how
									 much to increase the variable value by and then doing so.*/
{
	cout << input;
	value = (value * 2) + int(input) - 48;
}