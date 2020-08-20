#include<iostream>
#include<cmath>
#include<string>
#include<fstream>
#include<stdlib.h>
#include"entry.h"

using namespace std;

entry::entry()
{
	word[0]='\0';
	meaning[0]='\0';
}

entry::entry(string w, string m)
{
	word=w;
	meaning=m;
}


void entry::getword(string w)
{
	word=w;
}


void entry::getmeaning(string m)
{
	meaning=m;
}

string entry::getword()
{
	return word;
}

string entry::getmeaning()
{
	return meaning;
	
}

