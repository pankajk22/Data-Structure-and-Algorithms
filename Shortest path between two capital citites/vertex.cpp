#include<iostream>
#include<cstdio>
#include<math.h>
#include<cstring>
#include"vertex.h"

using namespace std;
int vertex::getpos()
{
	return pos;		
}

string vertex::getcap()
{
	return capital;
}

void vertex::addinfo(string a,int b)
{
	capital=a;
	pos=b;
}

void vertex::showdata()
{
	//cout<<"lol"<<endl;
	cout<<capital<<"\t"<<pos<<endl;
}
