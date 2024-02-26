#include<stdio.h>
#include<math.h>


int main()
{
    FILE *input;
    char INPUT[255],check[255],copy1[255],final[255];
    int length,i=0,j=1,k=0,l=0,lnt=0,n=0,tmp,copy[100],flag,sum=0;
    //get input from text box.
    input=fopen("C:Users\ROW TECH BD\Desktop\Network Project\hamming_output.text","r");
    fscanf(input,"%s",INPUT);
    printf("Given Input: %s",INPUT);
    fclose(input);

    length=strlen(INPUT);
    printf("\n\nInput Length: %d\n",length);




    //count number of 1 in input according to parity bits
    i=k=0;
    while(i<=length)
    {
        flag=0;
        tmp=0;
        i=pow(2,k);
        k++;
        if(i<=length)
        {

            lnt++;

            if(lnt==1)
            {
                flag=1;
                for(j=i-1; j<length; j=j+2)
                {
                    if(INPUT[j]=='1')
                    {
                        tmp++;
                    }
                }
            }

            else if(lnt==2)
            {
                flag=1;
                for(j=i-1; j<length; j=j+3)
                {
                    if(INPUT[j]=='1')
                    {
                        tmp++;
                    }
                    j=j+1;
                    if(INPUT[j]=='1')
                    {
                        tmp++;
                    }
                }
            }
            else if(lnt==3)
            {
                flag=1;
                for(j=i-1; j<length; j=j+4)
                {
                    for(n=0; n<4; n++)
                    {
                        if(INPUT[j]=='1')
                        {
                            tmp++;
                        }
                        j=j+1;
                    }
                }
            }

            else if(lnt==4)
            {
                flag=1;
                for(j=i-1; j<length; j=j+8)
                {
                    for(n=0; n<8; n++)
                    {
                        if(INPUT[j]=='1')
                        {
                            tmp++;
                        }
                        j=j+1;
                    }
                }
            }
            else if(lnt==5)
            {
                flag=1;
                for(j=i-1; j<length; j=j+16)
                {
                    for(n=0; n<16; n++)
                    {
                        if(INPUT[j]=='1')
                        {
                            tmp++;
                        }
                        j=j+1;
                    }
                }
            }
            else if(lnt==6)
            {
                flag=1;
                for(j=i-1; j<length; j=j+32)
                {
                    for(n=0; n<32; n++)
                    {
                        if(INPUT[j]=='1')
                        {
                            tmp++;
                        }
                        j=j+1;
                    }
                }
            }

        }
        if(flag!=0)
        {
            if(tmp%2==0)
                check[l]='0';
            else
                check[l]='1';
        }


        l++;




    }

    check[l]='\0';
    //error bit position in decimal
    length=strlen(check);
    for(i=length-1; i>=0; i--)
    {
        if(i==5&&check[i]=='1')
        {
            sum=sum+32;
        }
        else if(i==4&&check[i]=='1')
        {
            sum=sum+16;
        }
        else if(i==3&&check[i]=='1')
        {
            sum=sum+8;
        }
        else if(i==2&&check[i]=='1')
        {
            sum=sum+4;
        }
        else if(i==1&&check[i]=='1')
        {
            sum=sum+2;
        }
        else if(i==0&&check[i]=='1')
        {
            sum=sum+1;
        }
    }
    //check error or not
    if(sum==0)
        printf("\n\nThe Code Has No Error\n\n");
    else
    {
        printf("\nError Bit Position Is:%d",sum);
        if(INPUT[sum-1]=='1')
            INPUT[sum-1]='0';
        else
            INPUT[sum-1]='1';

        length=strlen(INPUT);
            //store 9 in parity position
            if(length>=32)
            {
                INPUT[31]='9';
                INPUT[15]='9';
                INPUT[7]='9';
                INPUT[3]='9';
                INPUT[1]='9';
                INPUT[0]='9';
            }
            else if(length>=16)
            {
                INPUT[15]='9';
                INPUT[7]='9';
                INPUT[3]='9';
                INPUT[1]='9';
                INPUT[0]='9';
            }
            else if(length>=8)
            {
                INPUT[7]='9';
                INPUT[3]='9';
                INPUT[1]='9';
                INPUT[0]='9';
            }
            j=0;
            //copy input in another array without parity
            for(i=0;i<length;i++)
            {
                if(INPUT[i]=='9')
                    continue;
                else
                {
                    copy1[j]=INPUT[i];
                }
                j++;
            }
            copy1[j]='\0';
            length=strlen(copy1);
            flag=length/8;

            k=sum=0;
            //convert binary to character
            for(i=0;i<flag;i++)
            {
                if(i==0)
                {
                    for(j=7;j>=0;j--)
                    {
                        if(copy1[k]=='1')
                           {
                               sum=sum+pow(2,j);
                           }
                           k++;
                    }
                    final[i]=sum;
                    sum=0;
                }
                else if(i==1)
                {
                    for(j=7;j>=0;j--)
                    {
                        if(copy1[k]=='1')
                           {
                               sum=sum+pow(2,j);
                           }
                           k++;
                    }
                    final[i]=sum;
                    sum=0;
                }
                else if(i==2)
                {
                    for(j=7;j>=0;j--)
                    {
                        if(copy1[k]=='1')
                           {
                               sum=sum+pow(2,j);
                           }
                           k++;
                    }
                    final[i]=sum;
                    sum=0;
                }
                else if(i==3)
                {
                    for(j=7;j>=0;j--)
                    {
                        if(copy1[k]=='1')
                           {
                               sum=sum+pow(2,j);
                           }
                           k++;
                    }
                    final[i]=sum;
                    sum=0;
                }
                else if(i==4)
                {
                    for(j=7;j>=0;j--)
                    {
                        if(copy1[k]=='1')
                           {
                               sum=sum+pow(2,j);
                           }
                           k++;
                    }
                    final[i]=sum;
                }

            }
            final[i]='\0';
            //print final output

            printf("\n\nFinal Correct Output Is: %s\n",final);

    }






    return 0;
}
