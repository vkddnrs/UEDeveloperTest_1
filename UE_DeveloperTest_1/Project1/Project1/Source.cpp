#include <iostream>
#include <string>
#include <conio.h>

char* string_conversion(char* _str);

int main()
{
	char* str = new char;
	char choice = 'n';
	using namespace std;
	
	do	
	{
		cout << "Enter the line and press \"Enter\"" << endl;
		cin.getline(str, 256);
		str[strlen(str) + 1] = '\0';
		cout << "\"" << str << "\" => \"";
		cout << string_conversion(str) << "\"" << endl;

		cout << "Continue? (y(es)/n(o))" << endl;
		choice = _getch();
		
	} while (choice == 'y');

	return 0;
}



char* string_conversion(char* _str)
{
	unsigned int size = strlen(_str);
	_strlwr_s(_str, size + 1); // convert the string to lowercase
	
	// since the input string can contain characters ')' and '(', we use an additional array
	char* t_str = new char[size + 1]();	
	for (int i = 0; i < size; i++) // initial option when there are no repeated characters
		t_str[i] = '(';
	
	bool is_character_repeats = false;

	for (int i = 0; i < size - 1; i++)
	{
		is_character_repeats = false;
		for (int j = i + 1; j < size; j++)
		{
			if (t_str[j] == ')') // everything has already been done for this array element
				continue;

			if (_str[j] == _str[i])
			{
				is_character_repeats = true;
				t_str[j] = ')'; // characters repeating the current character from the beginning of the array
			}
		}
		if (is_character_repeats)
			t_str[i] = ')';		// characters with repetitions in the tail of the array
	}

	for (int i = 0; i < size; i++)
		_str[i] = t_str[i];
	
	delete[] t_str;
	return _str;
}

