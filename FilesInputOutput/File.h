#ifndef _FILE_H
#define _FILE_H

#include <iostream>
#include <string.h>

using namespace std;

class CFile
{
public:
	CFile();
	~CFile();

	void WriteNewFile(string Filename) const;
	void WriteNewFile(string Filename, string Text) const;
	void AppendFile(string Filename, string Text) const;
	void ReadFile(string Filename) const;

private:

	string Text;
};

#endif // !_FILE_h

