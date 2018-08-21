#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int test1(int argc, char *argv[])
{
	string filepath	="G:/F/MTCNN/mtcnn-master2/vehicle-车辆训练样本/images/0.txt";
	ofstream finSave;
	finSave.open("G:/F/MTCNN/mtcnn-master2/vehicle-车辆训练样本/label-1per1.txt");
	ifstream finRead;	
	finRead.open(filepath);
		
	string nameJPG;
	while(getline(finRead,nameJPG))
	{	  
		string temp=nameJPG;

		temp.erase(0, temp.find_first_not_of(" \t"));
		temp.erase(temp.find_last_not_of(" \t") + 1);

		  nameJPG=temp;

		temp.replace(temp.find_last_of("."), 4,".txt");
		ifstream fin1;
		
		fin1.open(temp);
		
		string car; int x1;int y1;int width;int height;
		 fin1>>car>>x1>>y1>>width>>height;
		  
		 int x2=x1+width-1;
		 int y2=y1+height-1;

		   height=height*1.0*8/9;
			y1=y2-height+1;

		 finSave<<nameJPG<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
	}
	finRead.close();
	finSave.close();
	return 0;
}