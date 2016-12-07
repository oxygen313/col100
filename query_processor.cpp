#include<iostream>
#include<string.h>
#include <stdio.h>
#include<fstream>
using namespace std;
int main()
{
	// Example: The first two lines of file contain name and address of a person.
	char name[5][20],entry[5][20];
	int ent=0;
	ifstream filename;
	filename.open("input.txt", ios::in);
	if(!filename.good())
	cerr << "File opening error" << endl;// â€˜coutâ€™ is used for normal output,
	else
	{
		while(!filename.eof())
		{
			filename.getline(name[ent], 20, '\n');// Reads 20 chars from a line
			filename.getline(entry[ent], 20, '\n');
		//	cout<<name[i]<<endl<<entry[i]<<endl;
			ent++;
		}

		filename.close();//to output error messages use â€˜cerrâ€™
	}
	int ch, i, count;char dp[6];char yr[4];
	cin>>ch;
	switch(ch)
	{
	case 1: char br[2]; count=0;
		//cout<<"Enter branch"<<endl;
		cin>>br;
	    for(i=0;i<ent;i++)
		{if(entry[i][4]==br[0]&&entry[i][5]==br[1])
			count++;
		}
		cout<<count;
		break;

	case 2:   count=0;

			cin>>dp;
			for(i=0;i<ent;i++)
			{
				if((entry[i][6]=='5'||entry[i][6]=='7')&&(strcmp(dp,"Dual")==0))
			count++;
			else if ((entry[i][6]=='1'||entry[i][6]=='2'||entry[i][6]=='3'||entry[i][6]=='4')&&strcmp(dp,"BTech")==0)
				count++;
			else if ((entry[1][6]=='Z'&&(strcmp(dp,"Phd")==0)))

				count++;
			}
			cout<<count;
	break;

	case 3:  count=0;
		cin>>yr;
		for(i=0;i<ent;i++)
		{ if((entry[i][2]==yr[2])&&(entry[i][3]==yr[3]))
		count++;

	}
	cout<<count;
	break;

	case 4:
		cin>>br>>dp;
		for(i=0;i<ent;i++)
	{if((entry[i][4]==br[0]&&entry[i][5]==br[1]))
		if((entry[i][6]=='5'||entry[i][6]=='7')&&(strcmp(dp,"Dual")==0))
			cout<<name[i]<<endl;
			else if ((entry[i][6]=='1'||entry[i][6]=='2'||entry[i][6]=='3'||entry[i][6]=='4')&&strcmp(dp,"BTech")==0)
				cout<<name[i]<<endl;
			else if ((entry[1][6]=='Z'&&(strcmp(dp,"Phd")==0)))
					cout<<name[i]<<endl;

	}
		break;
	case 5: cin>>br>>yr;
	for(i=0;i<ent;i++)
	{if (((entry[i][4]==br[0])&&(entry[i][5]==br[1]))&&((entry[i][2]==yr[2])&&(entry[i][3]==yr[3])))
		cout<<name[i]<<endl;
	}
break;

	case 6: cin>>dp>>yr;
	for(i=0;i<ent;i++)
	{if ((entry[i][2]==yr[2])&&(entry[i][3]==yr[3]))
		if((entry[i][6]=='5'||entry[i][6]=='7')&&(strcmp(dp,"Dual")==0))
					cout<<name[i]<<endl;
					else if ((entry[i][6]=='1'||entry[i][6]=='2'||entry[i][6]=='3'||entry[i][6]=='4')&&strcmp(dp,"BTech")==0)
						cout<<name[i]<<endl;
					else if ((entry[1][6]=='Z'&&(strcmp(dp,"Phd")==0)))
							cout<<name[i]<<endl;
}


}
	return 0;
}
