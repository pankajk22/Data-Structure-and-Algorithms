#pragma once
#ifndef VERTEX_H
#define VERTEX_H

using namespace std;

class vertex
{
	int pos;
	string capital;
	public:
	int getpos();
	string getcap();
	void addinfo(string ,int);
	void showdata();
}; 

#endif
