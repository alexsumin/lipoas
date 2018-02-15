#pragma once
#include<iostream>

class CoutModified :public std::ostream {

public:
	CoutModified() :std::ostream(&buf) {}
private:
	class streambuf :public std::streambuf
	{
	public:
		streambuf() :line(0) {}
	private:
		int overflow(int c)
		{
			std::cout.put(c);
			if (c == '\n' && ++line % 21 == 0)
			{
				system("pause");
				system("cls");
				line = 0;
			}
			return c;
		}
		int line;
	};

	streambuf buf;
};

static CoutModified coutMod;
	

