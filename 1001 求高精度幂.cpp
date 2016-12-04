/* 
    对一个实数R( 0.0 < R < 99.999 )，要求写程序精确计算 R 的 n 次方(Rn)，其中n 是整数并且 0 < n <= 25。
	Input
T输入包括多组 R 和 n。 R 的值占第 1 到第 6 列，n 的值占第 8 和第 9 列。
Output
对于每组输入，要求输出一行，该行包含精确的 R 的 n 次方。输出需要去掉前导的 0 后不要的 0 。如果输出是整数，不要输出小数点。

	Input:
		95.123 12
		0.4321 20
		5.1234 15
		6.7592  9
		98.999 10
		1.0100 12

	Output:
		548815620517731830194541.899025343415715973535967221869852721
		.00000005148554641076956121994511276767154838481760200726351203835429763013462401
		43992025569.928573701266488041146654993318703707511666295476720493953024
		29448126.764121021618164430206909037173276672
		90429072743629540498.107596019456651774561044010001
		1.126825030131969720661201
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream> 
using namespace std;

void trim_zero(string &str,bool trim_f,bool trim_e);

int main()
{
	const int ARRAY_LENGTH=200;
	signed int arr[ARRAY_LENGTH];

	string bs;
	int bottom,power,dotidx=0;
	while(cin>>bs>>power)
	{
		if(power==0) 
		{
			cout<<'1'<<endl;
			continue;
		}
		trim_zero(bs,true,true);
		if(bs[bs.size()-1]=='.') bs.erase(bs.size()-1,1);
		if(power==1) 
		{
			cout<<bs<<endl;
			continue;
		}

		if((dotidx=bs.find("."))!=string::npos)
		{	
			bs.erase(dotidx,1);
			dotidx=power*(bs.size()- dotidx);
		}
		trim_zero(bs,true,false);
		stringstream ss(bs);
		ss >> bottom; 

		int arridx=0;
		for(string::reverse_iterator i=bs.rbegin() ;i!=bs.rend();i++)
			arr[arridx++]=*i-'0';
		arr[arridx]=-1;

		for(int i=1;i<power;i++)
		{
			long temp=0;
			for(int j=0;j<ARRAY_LENGTH;j++)
			{
				temp+=(arr[j]*bottom);
				arr[j]=temp%10;
				temp/=10;
				if(arr[j+1]==-1 && temp==0) break;
				if(arr[j+1]==-1)
				{
					arr[j+1]=0;
					arr[j+2]=-1;
				}
			}
		}

		int length=0;
		int zero_length=0;
		bool zero_end=false;
		for(int i=0;i<ARRAY_LENGTH;i++)
		{
			if(arr[i]==-1)
			{
				length=i;
				break;
			}
			if(!zero_end && arr[i]!=0) 
			{
				zero_end=true;
				zero_length=i;
			}
		}

		bool dotted=false;
		if(dotidx>length)
		{
			cout<<'.';
			dotted=true;
		}
		while(dotidx-->length) cout<<'0';

		for(int i=length-1;i>=0;i--)
		{
			if(dotidx>=i && i<zero_length)break;
			if(i==dotidx&&!dotted)cout<<'.';
			cout<<arr[i];
		}
		cout<<endl;
	}

	/*int program_end;
	cin>>program_end;*/
	return 0;
}


void trim_zero(string &str,bool trim_f,bool trim_e)
{
	int Begin_idx=0,End_idx=str.size();
	if(trim_f)
	{
		for(int i=0;i<str.size();i++)
		{
			if( str[i]!='0') 
			{
				Begin_idx=i;
				break;
			}
		}
	}
	if(trim_e)
	{
		for(int i=str.size()-1;i>=0;i--)
		{
			if(str[i]!='0') 
			{
				End_idx=i+1;
				break;
			}
		}
	}
	string temp=str.substr(Begin_idx,End_idx-Begin_idx);
	if(temp.size()==0 || temp==".") temp="0";
	str=temp;
}