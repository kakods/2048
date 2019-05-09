#include<iostream>
#include<time.h>
#include<cstdlib>
using namespace std;
class game
{
	int a[4][4],b[4][4];
	int count,score,flag;
public:
	game()
	{
		count=1;
		score=0;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
				b[i][j]=0;
		}
		randmove();
		randmove();
	}
	bool same()
	{
		int c=0;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(a[i][j]==b[i][j])
					c++;
			}
		}
		if(c==16)
			return true;
		return false;
	}
	void undo();
	void save();
	void cleft();
	void cright();
	void cup();
	void cdown();
	void left();
	void right();
	void up();
	void down();
	void play();
	void show();
	bool over();
	bool win()
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(b[i][j]==2048)
					return true;
			}
		}
		return false;
	}
	void randmove()
	{
		srand(time(NULL));
		while(true)
		{
			int r=rand()%4;
			int s=rand()%4;
			if(b[r][s]==0)
			{
				int c=rand()%2;
				if((c==0)&&(count!=5))
				{
					b[r][s]=2;
					count++;
					return;
				}
				else if(count==5)
				{
					count=1;
					b[r][s]=4;
					return;
				}
			}
		}
	}
};
bool game::over()
{
	int c=0;
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(b[i][j]!=0)
				c++;
		}
	}
	if(c==16)
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(b[i][j]==b[i][j+1])
				{
					return false;
				}
			}
		}
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(b[j][i]==b[j+1][i])
				{
					return false;
				}
			}
		}
		return true;			
	}
	else
		return false;
}

void game::left()
{
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<4;j++)
		{
			if(b[i][j]!=0)
			{
				int k=j;
				while(k>0)
				{
					if(b[i][k-1]==0)
					{
						b[i][k-1]=b[i][k];
						b[i][k]=0;
					}
					k--;
				}
			}
		}
	}
}
void game::save()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			a[i][j]=b[i][j];
	}
}
void game::undo()
{
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
			b[i][j]=a[i][j];
	}
}
void game::cup()
{
	save();
	up();
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<4;j++)
		{
			if((b[j][i]==b[j-1][i])&&(b[j][i]!=0))
			{
				b[j-1][i]=b[j-1][i]+b[j][i];
				score+=b[j-1][i];
				b[j][i]=0;
			}
		}
	}
	up();
}
void game::cleft()
{
	save();
	left();
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<4;j++)
		{
			if((b[i][j]==b[i][j-1])&&(b[i][j]!=0))
			{
				b[i][j-1]=b[i][j-1]+b[i][j];
				score+=b[i][j-1];
				b[i][j]=0;
			}
		}
	}
	left();
}
void game::cright()
{
	save();
	right();
	for(int i=0;i<4;i++)
	{
		for(int j=2;j>=0;j--)
		{
			if((b[i][j]==b[i][j+1])&&(b[i][j]!=0))
			{
				b[i][j]=2*b[i][j+1];
				score+=b[i][j];
				b[i][j+1]=0;
			}
		}
	}
	right();
	
}
void game::cdown()
{
	save();
	down();
	for(int i=0;i<4;i++)
	{
		for(int j=2;j>=0;j--)
		{
			if((b[j][i]==b[j+1][i])&&(b[j][i]!=0))
			{
				b[j+1][i]=2*b[j+1][i];
				score+=b[j+1][i];
				b[j][i]=0;
			}
		}
	}
	down();
}
void game::right()
{
	for(int i=0;i<4;i++)
	{
		for(int j=2;j>=0;j--)
		{
			if(b[i][j]!=0)
			{
				int k=j;
				while(k<3)
				{
					if(b[i][k+1]==0)
					{
						b[i][k+1]=b[i][k];
						b[i][k]=0;
					}
					k++;
				}
			}
		}
	}
}
void game::down()
{
	for(int i=0;i<4;i++)
	{
		for(int j=2;j>=0;j--)
		{
			if(b[j][i]!=0)
			{
				int k=j;
				while(k<3)
				{
					if(b[k+1][i]==0)
					{
						b[k+1][i]=b[k][i];
						b[k][i]=0;
					}
					k++;
				}
			}
		}
	}
}
void game::up()
{
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<4;j++)
		{
			if(b[j][i]!=0)
			{
				int k=j;
				while(k>0)
				{
					if(b[k-1][i]==0)
					{
						b[k-1][i]=b[k][i];
						b[k][i]=0;
					}
					k--;
				}
			}			
		}
	}
}
void game::show()
{
	system("clear");
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			if(j==3)
			{
				if(b[i][j]==0)
					cout<<"_"<<"\t";
				else
					cout<<b[i][j]<<"\t";
			}
			else
			{
				if(b[i][j]==0)
					cout<<"_"<<"\t"<<"|";
				else
					cout<<b[i][j]<<"\t"<<"|";
			}
		}
		cout<<"\n";		
	}
}
void game::play()
{
	while(true)
	{
		show();
		cout<<"Enter your move\n";
		char c;
		cin>>c;
		if(c=='w')
			cup();
		else if(c=='a')
			cleft();
		else if(c=='s')
			cdown();
		else if(c=='d')
			cright();
		else if(c=='u')
			undo();
		else
			break;
		if(!same())
			randmove();
		if(win())
		{
			cout<<"YOU WIN!!!\n";
			show();
			break;
		}
		if(over())
		{
		  	cout<<"GAME OVER\n"<<"Score="<<score<<"\n";
		  	show();
		  	break;
	    }
	}
}
int main()
{
	char g;
	do
	{
		class game gg;
	    gg.play();
	    cout<<"Press g to play again n to quit\n";
	    cin>>g;
	}while(g!='n');
	return 0;
}