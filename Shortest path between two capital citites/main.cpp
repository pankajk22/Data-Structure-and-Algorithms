#include<iostream>
#include<cstdio>
#include<math.h>
#include<cstring>
#include"vertex.h"
#include"edge.h"
#include<vector>
#include<algorithm>
#include<limits.h>

vector<vertex*> vec;
vector<edge*> ivec;

void dijkstra(edge* graph,int src);

using namespace std;
int main()
{
	
	
	
	int i,j,k;
	char temp[20];
	char temp2[20];
	char garbage[150];
	float distance;
	FILE *fp1;
	fp1=fopen("capitals.txt","r");
	while(fscanf(fp1,"%s ",temp)>0)
	{
		vertex *obj=new vertex();
		if(vec.size()==0)
		{
			int index=(vec.size());
			obj->addinfo(temp,index);
			vec.push_back(obj);
			cout<<"Pushback-1"<<endl;
			//cout<<"1"<<endl;
		}
		else
		{
			int ind=(vec.size());
			
			int flag =0;
			for(int l=0;l<ind;l++)
			{
				if(vec[l]->getcap()==temp)
				{
					flag=1;
					//cout<<"Flag="<<flag<<endl;
					break;
				}
				
			}
			if(flag==0)
			{	
				int index=(vec.size());
				obj->addinfo(temp,index);
				vec.push_back(obj);
				//obj->showdata();
				//cout<<"vector"<<endl;
				//vec[index]->showdata();
				//cout<<"Pushback-"<<index<<endl;
				//cout<<"2"<<endl;
			}
		}
		fgets(garbage,150,fp1);
	}
	
	fseek(fp1, 0, SEEK_SET); 
	
				
	while(fscanf(fp1,"%s %s %f",temp,temp2,&distance)>0)
	{
		int a,b;
		edge *obj1=new edge();
		int ind=vec.size();
		for(int c=0;c<ind;c++)
		{
			if(temp==vec[c]->getcap())
			{
				a=vec[c]->getpos();
			}
			
			if(temp2==vec[c]->getcap())
			{
				b=vec[c]->getpos();
			}
		}
		
		obj1->addinfo(distance,a,b);
		ivec.push_back(obj1);
	}
	/*cout<<"vector size="<<vec.size();
	for(int c=0;c<vec.size();c++)
	{
		vec[c]->showdata();
	}
	
	cout<<"EDGES"<<endl;
	
	for(int c=0;c<ivec.size();c++)
	{
		ivec[c]->showdata();
	}*/
	int p=vec.size();
	edge* matrix[p][p];
	for(int q=0;q<p;q++)
	{
		for(int r=0;r<p;r++)
		{	
			edge *obj1=new edge();
			obj1->addinfo(0,0,0);
			matrix[q][r]=obj1;
		}
	}
	for(int c=0;c<ivec.size();c++)
	{
		int a=ivec[c]->getcappos1();
		int b=ivec[c]->getcappos2();
		float dist=ivec[c]->getdist();
		matrix[a][b]->addinfo(dist,a,b);
		
	}
	/*for(int q=0;q<p;q++)
	{	
		cout<<endl;
		for(int r=0;r<p;r++)
		{	
			
			matrix[q][r]->showdata();
			cout<<"\t";
		}
	}*/
	vector<int>myvector;
	for(int q=0;q<p;q++)
	{	
		int one=0;
		for(int r=0;r<p;r++)
		{			
			if(matrix[q][r]->getbin()==1)
			{
				one++;
			}
		}
		myvector.push_back(one);
	}
	int max=0;
	int pos;
	int c;
	for(int c=0;c<myvector.size();c++)
	{
		if(myvector[c]>max)
		{
			max=myvector[c];
			pos=c;
		}
	}
	cout<<"max="<<max<<"\t"<<"pos"<<pos<<endl;
	vec[pos]->showdata();
	int source=0;
	
	dijkstra(matrix[p][p],source);
	
	
	return 0;
	

}

void dijkstra(edge* graph,int src)
{	

	int ver=vec.size();	
	int dis[ver];
	bool inc[ver];
	//cout<<"ver="<<ver<<endl;
	for(int i=0;i<ver;i++)
	{
		inc[i]=0;
		dis[i]=INT_MAX;
		//cout<<"dis"<<dis[i]<<endl;
	}
	dis[src]=0;
	
	
	for(int cnt=0;cnt<ver;cnt++)
	{
		int min=INT_MAX;
		int min_index;
		for(int j=0;j<ver;j++)
		{
			if(inc[j]==false&&dis[j]<min)
			{
				min=dis[j];
				min_index=j;
			}
		}
		
		inc[min_index]=true;
		for(int v=0;v<ver;v++)
		{
			if(!inc[ver]&&(graph[min_index][v]->getbin()!=0)&&(dis[min_index]!=INT_MAX)&&(dis[min_index]+(graph[min_index][v]->getbin())<dis[v]))
			{
				dis[v]=dis[min_index]+graph[min_index][v]->getbin();
			}
		}
	}
	
}


