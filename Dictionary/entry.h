#include<iostream>
#include<cmath>
#include<cstring>
#include<string>
#include<stdlib.h>

using namespace std;

class entry{

	private:
		
		string word;
		string meaning;

	public:
		
		entry();
		entry(string, string);
		
		void getword(string);
		void getmeaning(string);
		
		string getword();
		string getmeaning(); 

};
