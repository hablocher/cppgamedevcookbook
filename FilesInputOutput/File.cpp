#include "File.h"
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

CFile::CFile()
{
	Text = "This is the initial data";
}

CFile::~CFile()
{

}

void CFile::WriteNewFile(string Filename) const
{
	ofstream myfile(Filename);
	if (myfile.is_open())
	{
		myfile << Text;
		myfile.close();
	}
	else cout << "Unable to open file";
}

void CFile::WriteNewFile(string Filename, string Text) const
{
	ofstream myfile(Filename);
	if (myfile.is_open())
	{
		myfile << Text;
		myfile.close();
	}
	else cout << "Unable to open file";
}

void CFile::AppendFile(string Filename, string Text) const
{
	ofstream outfile;
	outfile.open(Filename, ios_base::app);
	outfile << Text;
	outfile.close();
}

void CFile::ReadFile(string Filename) const
{
	string line;
	ifstream myfile(Filename);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << endl;
		}
		myfile.close();
	}
	else cout << "Unable to open file";
}