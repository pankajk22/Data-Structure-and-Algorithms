#pragma once
#ifndef EDGE_H
#define EDGE_H

using namespace std;

class edge
{
	float distance;
	int cappos1;
	int cappos2;
	public:
	float getdist();
	int getcappos1();
	int getcappos2();
	void addinfo(float,int,int);
	void showdata();
	int getbin();
}; 

#endif
