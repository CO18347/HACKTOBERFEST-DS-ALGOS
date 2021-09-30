#include<bits/stdc++.h>
using namespace std;
int main()
{
	ifstream input;
	string file;
	cout<<"Enter file name"<<endl;
	cin>>file;
	input.open(file.c_str(), std::ifstream::in);
	char ch;
	int multi = 0;
	int single = 0;
	vector<string> comments; 
	string line;
	while(getline(input,line))
	{
		for(int i = 0; i< line.length(); i++)
		{
			if(line[i]== '/' && line[i+1] == '/')
			{
				string s;
				single ++;
				i= i + 2;
				while(i!=line.length())
				{
					s += line[i];
					i++;
				}
			comments.push_back(s);
			break;
            }
            if(line[i] == '/' && line[i+1]=='*')
			{
				i = i + 2;
				multi++;
				string s,
				temp;
				while(i!=line.length())
				{
					s += line[i];
					i++;
				}
				int flag = 0; 
				while(getline(input,temp))
				{
					for (int j= 0; j< temp.length(); j++)
					{
						if (temp [j]== '*' && temp [j+1]== '/')
						{
							comments.push_back(s);
							flag= 1;
							break;
						}
					s += temp[j];
					}
					if(flag)
					{
					break;
					}
				}
			}
		}
	}
    cout<<"Multiline comments "<<multi<<endl<<"Singleline comments "<<single<<endl;
	for(int i = 0; i < comments.size(); i ++)
	{
		cout<<i+1<<" "<<comments[i]<<endl;
	}
return 0;
}
