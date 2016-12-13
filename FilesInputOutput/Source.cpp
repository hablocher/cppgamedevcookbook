#include <conio.h>
#include "File.h"

int main() {
	CFile file;


	file.WriteNewFile("Example.txt");
	file.WriteNewFile("Example.txt", "Logging text1");
	file.AppendFile("Example.txt", "Logging text2");
	file.ReadFile("Example.txt");

	_getch();

	return 0;
}