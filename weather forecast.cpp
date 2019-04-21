/* In this program object oriented approach has been followed .
This is Weekly weather program in which firstly data is entered manually 
by the user
then output arranged data is shown after reading from file
*/






                    /* program starts from here*/

 
#include <iostream> 
#include <fstream>
using namespace std;
class Weather
{
 char name[10];
int htemp;
int ltemp;
float rainfall;
public:

void readdata();
void writedata();
void avgdata();
 };
 void Weather ::readdata()
 {
 	
	 cout<<"Week name: "; cin>>name;
 	cout<<"High Temp: "; cin>>htemp;
 	cout<<"Low Temp: "; cin>>ltemp;
 	cout<<"Rainfall: "; cin>>rainfall;
 }
void Weather ::writedata()

{    

    cout<<name;
	cout<<"\t\t\t"<<htemp;
     cout<<"\t\t\t"<<ltemp;
     cout<<"\t\t\t"<<rainfall<<endl;
}

int main()
{
	Weather week[7];
	ofstream file;
	
	file.open("DATA.txt");
         cout<<"Enter data accordingly \n";
	for(int i=0;i<7;i++)
	{
		week[i].readdata();
		file.write((char*) &week[i],sizeof (week[i]));
	}
	file.close();
	ifstream filee;
	filee.open("DATA.txt");
	cout<<"\t\t\t\t\tWEATHER REPORT\n\n";
	cout<<" WEEK name           HIGH TEMP(C)        LOW TEMP(C)         RAIN FALL(%)\n";
	for (int i=0;i<7;i++)
	{
	filee.read((char*) &week[i],sizeof (week[i]));
		
	week[i].writedata();
	}
	
	
	
	filee.close();
      
	
}

