#include <bits/stdc++.h>
using namespace std;

int main()
{
	string any;
	int pos=0;
	cin>>any;

	for(char c: any)
	{
		if(pos==0)
		{
			switch(c)
			{
				case '1':
				pos=2;
				break;
				case '0':
				pos=1;
				break;

				default:
				cout<<"reject";
				return false;
			}

		}

		else if(pos==1)
		{
			switch(c)
			{
				case '1':
				pos=2;
				break;
				case '0':
				pos=5;
				break;

				default:
				cout<<"reject";
				return false;
			}

		}

		else if(pos==2)
		{
			switch(c)
			{
				case '1':
				pos=2;
				break;
				case '0':
				pos=3;
				break;

				default:
				cout<<"reject";
				return false;
			}

		}

		else if(pos==3)
		{
			switch(c)
			{
				case '1':
				pos=1;
				break;
				case '0':
				pos=0;
				break;

				default:
				cout<<"reject";
				return false;
			}

		}

		else if(pos==4)
		{
			switch(c)
			{
				case '1':
				pos=3;
				break;
				case '0':
				pos=5;
				break;

				default:
				cout<<"reject";
				return false;
			}

		}

		else if(pos==5)
		{
			switch(c)
			{
				case '1':
				pos=5;
				break;
				case '0':
				pos=5;
				break;

				default:
				cout<<"reject";
				return false;
			}

		}	
	}

	if(pos == 3 || pos==4)
	{
		cout<<"accept";
	}
	else cout<<"reject";
	return 0;

}