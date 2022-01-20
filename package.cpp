#include<iostream>
#include<stdlib.h>
#include<windows.h>

using namespace std;

void setConsoleColor(WORD c)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int main()
{
	int a[8][8];
	int i,j,ch=1;
	char tut;
	//The X & Y coordinates
	for(j=0;j<8;j++)
	{
		a[0][j]=j;
	}
	for(i=0;i<8;i++)
	{
        a[i][0]=i;
	}
	setConsoleColor(5);
	cout<<"\n\n\t\t\t\t\t\t\t\t\t\t----------------------";
	cout<<"\n\t\t\t\t\t\t\t\t\t\t THE PEG SOLITAIRE";
	cout<<"\n\t\t\t\t\t\t\t\t\t\t----------------------\n\n";
	setConsoleColor(8);
	cout << "\tPeg solitaire is an old single person board game . It involves moving marbles from one position to another position on the board according to certain rules . A game board with 33 holes in cross form is \tgiven , 32 pegs are in. The centre hole is empty. You have to remove the pegs one after the other by jumping horizontally or vertically over one. In the end one peg should be left in the centre hole.The \tobjective is to have as few marbles as possible at the end of the game. Make sure that all the inputs are integers, any other character would lead to crash of the game !!\n\n";
    setConsoleColor(5);
    cout<<"\n\n\t\t\t\t\t\t\t\t\t\t----------------------";
	cout<<"\n\t\t\t\t\t\t\t\t\t\t       RULES";
	cout<<"\n\t\t\t\t\t\t\t\t\t\t----------------------\n\n";
	setConsoleColor(8);
	cout << "\n\t\t\t\t --> The presence of marbles is marked as '1' and the absence is '0'\n";
	cout << "\n\t\t\t\t --> Movements are defined for four directions => UP(NORTH) DOWN(SOUTH) LEFT(EAST) RIGHT(WEST)\n";
	cout << "\n\t\t\t\t --> A valid move is defined by :-\n";
	cout << "\n\t			        (a) A marble present source cell\n";
	cout << "\n\t 				(b) A marble absent destination cell alternate in any valid direction to the first cell\n";
	cout << "\n\t 				(c) The adjacent cell between the source and the destination must have the marble\n";
	setConsoleColor(5);
	cout << "\n\t\t\t\t\t\t\t\t  <<<< START THE GAME >>>> (1 for YES and 0 for NO)"<<"\t";
	cin >> ch;
	if(ch==1)
		goto Play;
	else
    {
        cout << "\n\t\t\t\t\t\t\t ((: THANK YOU :))";
		return 0;
	}
	Play:;
	setConsoleColor(8);
	cout<<"\n\t\t\t\t\t\t\t Do you want us to give a tutorial ! ( 'Y' for Yes and 'N' for No )\t";
	cin>>tut;
	setConsoleColor(5);
	if(tut=='Y')
    {
        cout << "\n\t\t\t\t\t ---->> For example\n\n";
        for(j=0;j<8;j++)
        {
            a[0][j]=j;
        }
        for(i=0;i<8;i++)
        {
            a[i][0]=i;
        }
        for(i=1;i<=7;i++)
        {
            for(j=1;j<=7;j++)
            {
                if((i<3 && j<3) || (i<3 && j>5) || (i>5 && j<3) || (i>5 && j>5))
                {
                    a[i][j]='/0';
                }
                else
                    a[i][j]=1;
            }
        }
        a[4][4]=0;
        a[6][4]=1;
        a[5][4]=1;
        setConsoleColor(3);
      for(i=0;i<=7;i++)
        {
            cout<<"\t\t\t\t\t\t\t\t";
            for(j=0;j<=7;j++)
            {
                    if((i==1 || i==2 || i==6 || i==7) && (j==1 || j==2 || j==6 || j==7))
                    {
                        cout<<"     ";
                    }
                    else
                        //printf("  %d  ",a[i][j]);
                        cout<<"  "<<a[i][j]<<"  ";
            }
            cout<<"\n\n\n";
        }
        setConsoleColor(5);
        cout << "\n\t\t	a)Enter the row of first cell = 6";
        cout << "\n\n\t\t	b)Enter the column of first cell = 4";
        cout << "\n\n\t\t	c)Enter the row of second cell(alternate to the first cell) = 4";
        cout << "\n\n\t\t\td)Enter the column of second cell = 4\n\n";
        a[6][4]=0;
        a[4][4]=1;
        a[5][4]=0;
        setConsoleColor(3);
        for(i=0;i<=7;i++)
        {
            cout<<"\t\t\t\t\t\t\t\t";
            for(j=0;j<=7;j++)
            {
                    if((i==1 || i==2 || i==6 || i==7) && (j==1 || j==2 || j==6 || j==7))
                    {
                        cout<<"     ";
                    }
                    else
                        //printf("  %d  ",a[i][j]);
                        cout<<"  "<<a[i][j]<<"  ";
            }
            cout<<"\n\n\n";
        }
        setConsoleColor(5);
        cout << "\n\t\t\t So the marble from source cell(4,2) is transferred to the destination cell(4,4) removing the marble of the adjacent cell(4,3)  \n\t\t\t Similarly, you have to remove as many marbles as possible  I hope You have understood the game logic, lets start\n\n";
    }

    //Starting Game
    setConsoleColor(4);
    cout<<"\n\n\t\t\t\t\t\t\t\t\t   ----------------------";
	cout<<"\n\t\t\t\t\t\t\t\t\t        THE MAIN GAME ";
	cout<<"\n\t\t\t\t\t\t\t\t\t   ----------------------\n\n";
	setConsoleColor(8);
    for(i=1;i<=7;i++)
    {
        for(j=1;j<=7;j++)
        {
            if((i<3 && j<3) || (i<3 && j>5) || (i>5 && j<3) || (i>5 && j>5))
            {
                a[i][j]='\0';
            }
            else
                a[i][j]=1;
        }
    }
    a[4][4]=0;
	int count=0;
	cout<<"\n\n\n";
	setConsoleColor(3);
	for(i=0;i<=7;i++)
    {
        cout<<" \t\t\t\t\t\t\t\t";
			for(j=0;j<=7;j++)
			{
				if((i==1 || i==2 || i==6 || i==7) && (j==1 || j==2 || j==6 || j==7))
				{
					cout<<"     ";
				}
				else
                    cout<<"  "<<a[i][j]<<"  ";
			}
			cout<<"\n\n\n";
    }

    //Backtracking Algorithm
	while(count!=31)
	{
        int row_1,row_2,column_1,column_2;
        setConsoleColor(5);
		cout<< "\n\t\t\tEnter the start index row and column =\t";
		cin>> row_1 >> column_1;
		cout<< "\n\n\t\t\tEnter the end index row and column   =\t";
		cin >> row_2 >> column_2;

		if((((row_1==1 || row_1==2 || row_1==6 || row_1==7) &&(column_1>2 || column_1<6)) || (row_1>2 && row_1<6 && column_1>0 && column_1<8))
          && (((row_2==1 || row_2==2 || row_2==6 || row_2==7) && (column_2>2 || column_2<6))|| (row_2>2 && row_2<6 && column_2>0 && column_2<8)))
        {
            //To check if position is empty or not
            if(a[row_2][column_2]==0)
			{
			    //LEFT or WEST
				if(row_1==row_2 && column_2==column_1-2)
                {
                    a[row_2][column_2]=1;
                    a[row_1][column_1]=0;
                    a[row_1][column_1-1]=0;
                    ++count;
                }
                //RIGHT or EAST
				else if(row_1==row_2 && column_2==column_1+2)
                {
                    a[row_2][column_2]=1;
                    a[row_1][column_1]=0;
                    a[row_1][column_1+1]=0;
                    ++count;
                }
                //UP or NORTH
				else if(column_1==column_2 && row_2==row_1-2)
                {
                    a[row_2][column_2]=1;
                    a[row_1][column_1]=0;
                    a[row_1-1][column_1]=0;
                    ++count;
                }
                //DOWN or SOUTH
				else if(column_1==column_2 && row_2==row_1+2)
                {
                    a[row_2][column_2]=1;
                    a[row_1][column_1]=0;
                    a[row_1+1][column_1]=0;
                    ++count;
                }
                //JUMP NOT POSSIBLE
				else

                    cout << "\n\t\t\tInvalid move\n\n";
			}
			else

                cout << "\n\t\t\tDestination not empty\n\n";
		}
		else

            cout<<"\n\t\t\tInvalid Indices\n\n";

        //Solution Board
        cout << endl << endl <<endl;
        setConsoleColor(3);
        for(i=0;i<=7;i++)
        {
            cout<<" \t\t\t\t\t\t\t\t";
			for(j=0;j<=7;j++)
			{
				if((i==1 || i==2 || i==6 || i==7) && (j==1 || j==2 || j==6 || j==7))
				{
					cout<<"     ";
				}
				else
                    cout<<"  "<<a[i][j]<<"  ";
			}
			cout<<"\n\n\n";
        }
        setConsoleColor(4);
        cout << "\n\t\t\tThe numbers of Marbles remaining is\t" << 32-count;
        cout<<"\n\n\t\t\tYour Next move -->> \n\n";

    }
        //End Game
        setConsoleColor(5);
        if(a[4][4]==1)
        {
            cout<<"\n\n\t\t\t\t\t\t-----------------------------------------";
            setConsoleColor(5);
            cout<<"\n\n\t\t\t\t\t\t!! Congratulations you won the game !!";
            cout<<"\n\n\t\t\t\t\t\t<<<  GAME OVER >>>";
            setConsoleColor(3);
            cout<<"\n\n\t\t\t\t\t\t-----------------------------------------";
        }

}
