#include<iostream>
#include<fstream>
#include <math.h>
using namespace std;

int image[512][512];
char tp[3];
int w,h,p;
float c=0.1;

void read()
	{
	
	
	ifstream pic;
	char pj[20];
	cin>>pj;
	pic.open(pj, ios::in);
	if(!pic.good())
	cerr << "File opening error" << endl;
	else
		
	{
		pic.getline(tp,3,'\n');
		pic>>w>>h;
		pic>>p;
		for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
		pic>>image[i][j];
		
		
		}
		pic.close();
			//	cout<<tp<<w<<h<<p;
	}
	
	
		


void average()
{
ofstream avg;
avg.open("average.pgm",ios::out);
	if(!avg.good())
	cerr << "File opening error" << endl;// â€˜coutâ€™ is used for normal output,
	else
		{
				
					avg<<tp<<endl<<w<<endl<<h<<endl<<p<<endl;
					for(int i=0;i<h;i++)
					for(int j=0;j<w;j++)
						{
							if(i==0||j==0||i==h-1||j==w-1)
							avg<<image[i][j]<<endl;
							else
							avg<<(image[i-1][j-1]+image[i-1][j]+image[i-1][j+1]+image[i][j-1]+image[i][j]+image[i][j+1]+image[i+1][j-1]+image[i+1][j]+image[i+1][j+1])/9<<endl;
						}
				
			avg.close();
		}
}

void edge()
{
 	float hdif,vdif,grad[512][512], mgrad=0 ;
 	int i , j;
 	
 	for(i=1;i<h-1;i++)
 	for(j=1;j<w-1;j++)
 	 {
 	 	hdif = (image[i-1][j-1]-image[i-1][j+1]) + 2*(image[i][j-1]-image[i][j+1]) + (image[i+1][j-1]-image[i+1][j+1]);
		vdif = (image[i-1][j-1]-image[i+1][j-1]) + 2*(image[i-1][j]-image[i+1][j]) + (image[i-1][j+1]-image[i+1][j+1]);
 			grad[i][j]= sqrt(pow(hdif,2)+pow(vdif,2));
 			if(grad[i][j]>mgrad)
 			mgrad=grad[i][j];
 	}
 		
 		
 		ofstream edge;
		edge.open("edge.pgm",ios::out);
			if(!edge.good())
				cerr << "File opening error" << endl;// â€˜coutâ€™ is used for normal output,
			else
			{
					edge<<tp<<endl<<w<<endl<<h<<endl<<p<<endl;	
						for(int i=0;i<h;i++)
						for(int j=0;j<w;j++)
						{
							if(i==0||j==0||i==h-1||j==w-1)
							edge<<image[i][j]<<endl;
							else
						{
							if(grad[i][j]>(0.1* mgrad))
							edge<<image[i][j]<<endl;
							else
							edge<<0<<endl;
						}
	  
                    }
                    
     	}
     	edge.close();
     	
	}
	int main()
	{
		read();
		average();
		edge();
		return 0;
	}
