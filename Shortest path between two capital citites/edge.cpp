#include<iostream>
#include<cstdio>
#include<math.h>
#include<cstring>
#include"edge.h"
#include"vertex.h"

using namespace std;
float edge::getdist()
{
	return distance;		
}

int edge::getcappos1()
{
	return cappos1;		
}

int edge::getcappos2()
{
	return cappos2;		
}
void edge::addinfo(float x,int y,int z)
{
	distance=x;
	cappos1=y;
	cappos2=z;
}
void edge::showdata()
{
	//cout<<"lol"<<endl;
	if(distance==0&&cappos1==0&&cappos2==0){
	cout<<"0";
	}
	else cout<<"1";
	 /*cout<<"("<<distance<<","<<cappos1<<","<<cappos2<<")";*/
}
int edge::getbin()
{
	if(distance==0&&cappos1==0&&cappos2==0)
	{
		return 0;
	}
	else return 1;
}
