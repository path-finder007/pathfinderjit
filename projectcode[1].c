#include<stdio.h>
//#include<conio.h>
int main()
{
	int n,count,i,j,k,l,arr[10][10],A=0,B=0,C=0,D=0,E=0,F=0,G=0,H=0;
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
				if(arr[i][j]==1)
					  putchar(node1[i][j]);
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
                       printf("%c%c\t",node1[i][j],node1[j][i]);
					  if(node1[i][j]=='a'||node1[j][i]=='a')
						  A++;
					  if(node1[i][j]=='b'||node1[j][i]=='b')
						 B++;
					  if(node1[i][j]=='c'||node1[j][i]=='c')
						C++;
					  if(node1[i][j]=='d'||node1[j][i]=='d')
						  D++;
					  if(node1[i][j]=='e'||node1[j][i]=='e')
						 E++;
					  if(node1[i][j]=='f'||node1[j][i]=='f')
						F++;
				  if(node1[i][j]=='g'||node1[j][i]=='g')
						 G++;
					  if(node1[i][j]=='h'||node1[j][i]=='h')
						H++;
          }
				}
       }
	printf("\n\nA=%d\tB=%d\tC=%d\tD=%d\tE=%d\tF=%d\tG=%d\tH=%d",A,B,C,D,E,F,G,H);
printf("\n");
printf("\n");

if((A==1 && (3>=B>=2||3>=C>=2||3>=D>=2||3>=E>=2||3>=F>=2||3>=G>=2||3>=H>=2))||
   (B==1 && (3>=A>=2||3>=C>=2||3>=D>=2||3>=E>=2||3>=F>=2||3>=G>=2||3>=H>=2))||
   (C==1 && (3>=B>=2||3>=A>=2||3>=D>=2||3>=E>=2||3>=F>=2||3>=G>=2||3>=H>=2))||
   (D==1 && (3>=B>=2||3>=C>=2||3>=A>=2||3>=E>=2||3>=F>=2||3>=G>=2||3>=H>=2))||
   (E==1 && (3>=B>=2||3>=C>=2||3>=D>=2||3>=A>=2||3>=F>=2||3>=G>=2||3>=H>=2))||
   (F==1 && (3>=B>=2||3>=C>=2||3>=D>=2||3>=E>=2||3>=A>=2||3>=G>=2||3>=H>=2))||
   (G==1 && (3>=B>=2||3>=C>=2||3>=D>=2||3>=E>=2||3>=F>=2||3>=A>=2||3>=H>=2))||
   (H==1 && (3>=B>=2||3>=C>=2||3>=D>=2||3>=E>=2||3>=F>=2||3>=G>=2||3>=A>=2)))
        {printf("BUS TOPOLOGY\n");}

        else if((A==2 && B==2 && C==2 && D==2 && E==2 && F==2)||(G==2 && H==2))
                      {printf("RING TOPOLOGY\n");}

             else if((A>=3 && B>=3 && C>=3 && D>=3 && E>=3 && F>=3) || (G>=3 && H>=3))
                     {printf("MESH TOPOLOGY\n");}

                  else if(((A<=2 || B<=2 || C<=2 || D<=2 || E<=2 || F<=2) || (G<=2 || H<=2)) && ((A>=3 || B>=3 || C>=3 || D>=3 || E>=3 || F>=3) || (G>=3 || H>=3)))
                       {printf("STAR TOPOLOGY\n");}
                       else
                           printf("Cannot form a Standard topology");

return 0;
}
