#include<iostream>
#include<thread>
#include<time.h>
#include<conio.h>
#include<cstring>
#include<fstream>
#include<stdlib.h>
using namespace std;

// exception classes
class fileNotFoundException
{
	public:
		string fileName;
		fileNotFoundException(string F):fileName(F){}
};

class filesNotMatchedException{};

// file functions
inline void checkFile(string fileName)
{
	if(ifstream(fileName)==NULL)
		throw fileNotFoundException(fileName);
}

inline void removeFile(string fileName)
{
	if(ifstream(fileName))
		system(("del "+fileName).c_str());
}

void compareFiles(string file1,string file2)
{
	removeFile("log.txt");
	ofstream log("log.txt");
	bool matched=true;
	int lineNumber=1;
	ifstream f1(file1);	
	ifstream f2(file2);

	while(f1&&f2)
	{
		char f1Buffer[10000];
		char f2Buffer[10000];
		f1.getline(f1Buffer,sizeof(f1Buffer));
		f2.getline(f2Buffer,sizeof(f2Buffer));
		
		if(strcmp(f1Buffer,f2Buffer)!=0)
		{
			
			matched=false;
			cout<<endl;
			cout<<"Line #"<<lineNumber<<endl;	
			log<<"Line #"<<lineNumber<<endl;	
	
			cout<<"Out1 Result: "<<f1Buffer<<endl;
			log<<"Out1 Result: "<<f1Buffer<<endl;
	
			cout<<"Out2 Result: "<<f2Buffer<<endl;
			log<<"Out2 Result: "<<f2Buffer<<endl;
		}
		lineNumber++;
	}
	if(f1&&!f2)
	{
		cout<<"Extra data in the end of Program1 output"<<endl;
		log<<"Extra data in the end of Program1 output"<<endl;
		matched=false;
	}
	if(f1&&!f2)
	{
		cout<<"Extra data in the end of Program2 output"<<endl;
		log<<"Extra data in the end of Program2 output"<<endl;
		matched=false;
	}
	log.close();	
	
	if(!matched)
		throw filesNotMatchedException();	
	else
		removeFile("log.txt");	
}
string program1,program2,testFile;

int main(int argc,char *argv[])
{
	cout<<"******************************************************************************"<<endl;
	cout<<"                        dragonSlayerv2 Program Verification Module            "<<endl;
	cout<<"******************************************************************************"<<endl<<endl;
	
	if(argc==4)
	{
		program1=argv[1];
		program2=argv[2];
		testFile=argv[3];
	}
	else
	{
		cout<<"Enter the program1 path"<<endl;
		cin>>program1;
		cout<<"Enter the program2 path"<<endl;
		cin>>program2;
		cout<<"Enter the testFile Generator path"<<endl;
		cin>>testFile;
	}
	
		try
		{
			cout<<"Checking input files: "<<endl;
			cout<<"1. "<<program1+".cpp"<<"\t: ";	checkFile(program1+".cpp");	cout<<"OK"<<endl;
			cout<<"2. "<<program2+".cpp"<<"\t: ";	checkFile(program2+".cpp");	cout<<"OK"<<endl;
			cout<<"3. "<<testFile+".cpp"<<"\t: ";	checkFile(testFile+".cpp");	cout<<"OK"<<endl;
			cout<<endl;
		
			removeFile(program1+".exe");
			removeFile(program2+".exe");
			removeFile(testFile+".exe");
			cout<<"Compiling Files: "<<endl;
			
			thread threadP1		([](){	system(("g++ "+program1+".cpp -o"+program1+".exe -std=c++11").c_str());});
			thread threadP2		([](){	system(("g++ "+program2+".cpp -o"+program2+".exe -std=c++11").c_str());});
			thread threadtest	([](){	system(("g++ "+testFile+".cpp -o"+testFile+".exe -std=c++11").c_str());});
			
			cout<<"1. "<<program1<<"\t: ";	if(threadP1.joinable())		threadP1.join();	checkFile(program1+".exe");cout<<"OK"<<endl;
			cout<<"2. "<<program2<<"\t: ";	if(threadP2.joinable())		threadP2.join();	checkFile(program2+".exe");cout<<"OK"<<endl;
			cout<<"3. "<<testFile<<"\t: ";	if(threadtest.joinable())	threadtest.join();	checkFile(testFile+".exe");cout<<"OK"<<endl;
			cout<<endl;
			
			cout<<"Verification Phase Started: "<<endl<<endl;
			
			int round=0;
			while(1)
			{
				round++;
				cout<<endl<<endl;
				cout<<"Round #"<<round<<endl;
			
				removeFile("in.txt");
				removeFile("out1.txt");
				removeFile("out2.txt");
				
				cout<<"Generating Test File\t: ";system((testFile+" >in.txt").c_str());checkFile("in.txt");cout<<"DONE"<<endl;
					
				clock_t start,end;
				start=clock();
				cout<<"Executiong "<<program1<<"\t: ";	system((program1+".exe <in.txt >out1.txt").c_str());	checkFile("out1.txt");	cout<<"DONE"<<endl;
				end=clock();
				cout<<"Time Elapsed\t: "<<((double)(end-start))/(CLK_TCK)<<" secs"<<endl;
				
				start=clock();
				cout<<"Executiong "<<program2<<"\t: ";	system((program2+".exe <in.txt >out2.txt").c_str());	checkFile("out2.txt");cout<<"DONE"<<endl;
				end=clock();
				cout<<"Time Elapsed\t: "<<((double)(end-start))/(CLK_TCK)<<" secs"<<endl;
				
				cout<<"Match Result\t: ";compareFiles("out1.txt","out2.txt");cout<<"Matched!!!";
			}
		}
		catch(fileNotFoundException F)
		{
			perror(("\aError "+F.fileName).c_str());
		}
		catch(filesNotMatchedException F)
		{
			cout<<"Files not matched"<<endl;
			cout<<"Press O to open input, output and log files.";
			if(getch()=='o')
			{
				thread in([]()	{		system("notepad in.txt");});
				thread o1([]()	{		system("notepad out1.txt");});
				thread o2([]()	{		system("notepad out2.txt");});
				thread log([]()	{		system("notepad log.txt");});
			
				in.join();
				o1.join();
				o2.join();
				log.join();
			}
		}
}
