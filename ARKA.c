#include<stdio.h>
//#include<conio.h>
int main()
{
	int n,count,a[100],i,j,k,x,y,l,m,arr[10][10],A=0,B=0,C=0,D=0,E=0,F=0,G=0,H=0,ch,setmesh=0,setring=0,setbus=0;
	char node1[8][8]={	{'a','b','c','d','e','f','g','h'},
	{'a','b','c','d','e','f','g','h'},
	{'a','b','c','d','e','f','g','h'},
	{'a','b','c','d','e','f','g','h'},
	{'a','b','c','d','e','f','g','h'},
	{'a','b','c','d','e','f','g','h'},
	{'a','b','c','d','e','f','g','h'},
	{'a','b','c','d','e','f','g','h'}
};
printf("enter the order of sparse matrix\n");
scanf("%d",&n);

read:{
		printf("\n enter the sparse matrix");
		for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		scanf("%d",&arr[i][j]);
	}

	printf("\nsparse matrix is:\n");

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{

			if((arr[i][j]==0||arr[i][j]==1) && (arr[i][j]==arr[j][i]))
				printf("%d",arr[i][j]);
			else
			{
				printf("error!!!");
				goto read;
			}
		}
		printf("\n");
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				if(arr[i][j]==1)
				putchar(node1[i][j]);
			}
		}
		printf("\n");
	}

	printf("\n");
	printf("\n");

		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				if(arr[i][j]==1 && i!=j)
				{
					printf("%c->%c\t",node1[i][j],node1[j][i]);
					if(node1[i][j]=='a'||node1[j][i]=='a')
						A++;
					a[0] = A;
					if(node1[i][j]=='b'||node1[j][i]=='b')
						B++;
					a[1] = B;
					if(node1[i][j]=='c'||node1[j][i]=='c')
						C++;
					a[2] = C;
					if(node1[i][j]=='d'||node1[j][i]=='d')
						D++;
					a[3] = D;
					if(node1[i][j]=='e'||node1[j][i]=='e')
						E++;
					a[4] = E;
					if(node1[i][j]=='f'||node1[j][i]=='f')
						F++;
					a[5] = F;
					if(node1[i][j]=='g'||node1[j][i]=='g')
						G++;
					a[6] = G;
					if(node1[i][j]=='h'||node1[j][i]=='h')
						H++;
					a[7] = H;
				}
			}
		}
		printf("\n\nA=%d\tB=%d\tC=%d\tD=%d\tE=%d\tF=%d\tG=%d\tH=%d",A,B,C,D,E,F,G,H);
		printf("\n");
		printf("\n");
		for(i=0;i<n;i++)
		{
			if(a[i]>>2)

				setmesh=1;
			else
	        	setmesh=0;
	    }
		if(setmesh==1)
			{
			printf("mesh topology\n");
			goto read1;
			}
        for(i=0;i<n;i++)
		{
			if(a[i]==2)
			{
				setring=1;
			}
		    else
		    {
			setring=0;
		    }
		}
		if(setring==1)
			{
			printf("ring topology\n");
		 	goto read1;
		 	}
        for(i=0;i<n;i++)
		{

			if(a[i]==1 || a[i]==2)
			{
				setbus=1;
			}
			else
		{
			setbus=0;
		}
	if(setbus==1)
	{
		printf("bus topology");
	    goto read1;
	}
		if( (A==7 && B==1 && C==1 && D==1 && E==1 && F==1 && G==1 && H==1)||
       		(A==1 && B==7 && C==1 && D==1 && E==1 && F==1 && G==1 && H==1)||
      	 	(A==1 && B==1 && C==7 && D==1 && E==1 && F==1 && G==1 && H==1)||
	  	 	(A==1 && B==1 && C==1 && D==7 && E==1 && F==1 && G==1 && H==1)||
	  	 	(A==1 && B==1 && C==1 && D==1 && E==7 && F==1 && G==1 && H==1)||
	   		(A==1 && B==1 && C==1 && D==1 && E==1 && F==7 && G==1 && H==1)||
	   		(A==1 && B==1 && C==1 && D==1 && E==1 && F==1 && G==7 && H==1)||
	   		(A==1 && B==1 && C==1 && D==1 && E==1 && F==1 && G==1 && H==7))
				{
					printf("STAR TOPOLOGY\n");
					goto read1;
		    	}
				else
				{
					printf("Cannot form a Standard topology!!");
				}

				goto read1;
	}
        read1:{
       			printf("Enter the node to fail...");
     			printf("\n");
     			printf("Enter the row number(0-7) : ");
     			scanf("%d",&x);
     			printf("Enter the col number(0-7) : ");
     			scanf("%d",&y);

	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++)
            {
                arr[x][y] = 0;
                printf ("%d ", arr[i][j]);

            }
            printf("\n");
	    }
        for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
					if(arr[i][j]==1)
					putchar(node1[i][j]);
			}
		}
			printf("\n");
	}
    for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				if(arr[i][j+1] && arr[i][j-1] && arr[i+1][j] && arr[i-1][j] == 1)
                    {
                        printf("%c->%c\t",node1[i][j],node1[j][i]);
                    }
                    if(node1[x][y]=='a'||node1[y][x]=='a')
						A++;
					a[0] = A;
					if(node1[x][y]=='b'||node1[y][x]=='b')

						B++;
					a[1] = B;
					if(node1[x][y]=='c'||node1[y][x]=='c')
						C++;
					a[2] = C;
					if(node1[x][y]=='d'||node1[y][x]=='d')
						D++;
					a[3] = D;
					if(node1[x][y]=='e'||node1[y][x]=='e')
						E++;
					a[4] = E;
					if(node1[x][y]=='f'||node1[y][x]=='f')
						F++;
					a[5] = F;
					if(node1[x][y]=='g'||node1[y][x]=='g')
						G++;
					a[6] = G;
					if(node1[x][y]=='h'||node1[y][x]=='h')
						H++;
					a[7] = H;
				}
			}
		}
        l1: return 0;
        }


