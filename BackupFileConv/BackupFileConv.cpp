// BackupFileConv.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>


using namespace std;



int findLast(char *str)
{
	int ret = 0;
	int i = 0;
	while(str[i])
	{
		if(str[i] == '/')
			ret = i;
		i++;
	}
	return ret;
}


void instead(char *str,size_t size)
{
	int index = findLast(str);

	if(0 == index)
	{
		char t;
		for(int i = size;i>=0;i--)
		{
			str[i+2] = str[i];		
		}
		str[0] = '/';
		str[1] = ',';
	}
	else
	{
		str[index] = ',';
	}

}


int _tmain(int argc, _TCHAR* argv[])
{
	if(argc != 2)
	{
		cout<<"Parameter error!"<<endl;
		exit(1);
	}

	fstream file;
	file.open(argv[1],ios::in);

	if(!file)
	{
		cout<<"File "<<argv[0]<<"open fail!"<<endl;
		exit(1);
	}

	fstream outFile("temp.ini",ios::trunc|ios::out);	
	char readBuf[1024] = {'\0'};
	while( file.getline(readBuf,1024) )
    { 
		instead(readBuf,strlen(readBuf));
		readBuf[strlen(readBuf)] = '\n';
		outFile.write(readBuf,strlen(readBuf));
		memset(readBuf,0,sizeof(readBuf));
	}
	file.close();
	outFile.close();

	system("pause");
	return 0;
}