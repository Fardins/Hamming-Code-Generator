#include<stdio.h>
#include<math.h>

int main()
{
    FILE *input,*output;
    char INPUT[255];
    int length,temp[8],binary[40],copy[50],i,j,k=7,l=0,counter=0,tmp,lnt=0;
    //take input from file
    input=fopen("C:Users\ROW TECH BD\Desktop\Network Project\input_output.text","r");
    fscanf(input,"%s",INPUT);
    printf("Given Input: %s\n",INPUT);
    fclose(input);

    length=strlen(INPUT);
    //convert character to binary bit
    for(i=0; i<length; i++)
    {
        for(j=0; j<8; j++)
        {
            if(INPUT[i]!=0)
            {
                temp[j]=INPUT[i]%2;
                INPUT[i]=INPUT[i]/2;
            }
            else
            {
                temp[j]=0;
            }
        }
        for(j=counter; j<length*8; j++)
        {
            if(k>=0)
            {
                binary[j]=temp[k];
                k--;
                counter++;
            }
        }
        k=7;

    }
    length=length*8;
    printf("\nInput Binary Form Is:");
    for(i=0; i<length; i++)
    {
        printf(" %d",binary[i]);
    }



    //store -1 in hamming position
    i=j=counter=0;
    while(i<=length)
    {
        i = pow(2,j);
        if(i<=length)
        {
            counter++;
            copy[i]=-1;
        }
        j++;
    }
    printf("\n\nHamming Position Number: %d",counter);





    j=0;
    for(i=1; i<=length+counter; i++)
    {
        if(copy[i]!=-1)
        {
            copy[i]=binary[j];
            j++;
        }
        else
            continue;
    }
    printf("\n\n 1st step Output:");
    for(i=1; i<=length+counter; i++)
    {
        printf("%d\t",copy[i]);
    }





    //get parity bits value
    for(i=1; i<=length+counter; i++)
    {
        tmp=0;
        if(copy[i]==-1)
        {
            lnt++;
            if(lnt==1)
            {
                for(j=i; j<=length+counter; j=j+2)
                {
                    if(copy[j]==1)
                    {
                        tmp++;
                    }
                }
            }
            else if(lnt==2)
            {
                for(j=i; j<=length+counter; j=j+3)
                {
                    if(copy[j]==1)
                    {
                        tmp++;
                    }
                    j=j+1;
                    if(copy[j]==1)
                    {
                        tmp++;
                    }
                }
            }
            else if(lnt==3)
            {
                for(j=i; j<=length+counter; j=j+4)
                {
                    for(l=0;l<4;l++)
                    {
                        if(copy[j]==1)
                        {
                            tmp++;
                        }
                        j=j+1;
                    }

                }
            }
            else if(lnt==4)
            {
                for(j=i; j<=length+counter; j=j+8)
                {
                    for(l=0;l<8;l++)
                    {
                        if(copy[j]==1)
                        {
                            tmp++;
                        }
                        j=j+1;
                    }
                }
            }
            else if(lnt==5)
            {
                for(j=i; j<=length+counter; j=j+16)
                {
                    for(l=0;l<16;l++)
                    {
                        if(copy[j]==1)
                        {
                            tmp++;
                        }
                        j=j+1;
                    }
                }
            }
            else if(lnt==6)
            {
                for(j=i; j<=length+counter; j=j+32)
                {
                    for(l=0;l<32;l++)
                    {
                        if(i+l<=length+counter&&copy[j]==1)
                        {
                            tmp++;
                        }
                        j=j+1;
                    }
                }
            }


            if(tmp%2==0)
                copy[i]=0;
            else
                copy[i]=1;

        }
    }
    printf("\n\nYour Hamming Code: ");

    //print hamming code in text file
    output=fopen("C:Users\ROW TECH BD\Desktop\Network Project\hamming_output.text","w");
    for(i=1; i<=length+counter; i++)
    {
        printf("%d\t",copy[i]);
        fprintf(input,"%d",copy[i]);
    }
    fclose(output);




    return 0;
}
