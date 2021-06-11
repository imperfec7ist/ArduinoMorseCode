#include<stdio.h>
#include<string.h>

char alpha[26][5]=    
    {
    ".-",   //A
    "-...", //B
    "-.-.", //C
    "-..",  //D
    ".",    //E
    "..-.", //F
    "--.",  //G
    "....", //H
    "..",   //I
    ".---", //J
    "-.-",  //K
    ".-..", //L
    "--",   //M
    "-.",   //N
    "---",  //O
    ".--.", //P
    "--.-", //Q
    ".-.",  //R
    "...",  //S
    "-",    //T
    "..-",  //U
    "...-", //V
    ".--",  //W
    "-..-", //X
    "-.--", //Y
    "--.." //Z
    };

char num[10][6] = 
    {
    "-----", //0
    ".----", //1
    "..---", //2
    "...--", //3
    "....-", //4
    ".....", //5
    "-....", //6
    "--...", //7
    "---..", //8
    "----." //9
    };

int main()
{
    int i,j=0,k=0, x,y;
    char str[25], morse[100], morlet[25][10];
    printf("\nEnter Morse:\n");
    gets(morse);

    for(int i=0;morse[i]!='\0';i++)
    { 

        if(morse[i]==' ')
        {
        ++j;
        k=0;
        continue;
        }
        else
        {
        morlet[j][k]=(morse[i]);
        morlet[j][k+1]='\0';        
        //printf("\n%d,%d\n",j,k);//check valve
        ++k;
        }
    }
/*for(int a=0;a<=j;a++)
{
    printf("\n\t%s\n", morlet[a]);
}
*///check valve for input
char message[j];

for(x=0;x<=j;x++)
{
    if(strcmp(morlet[x],"/")==0)
    message[x]=' ';
    for (y=0;y<=26;y++)
    {
        //printf("\t%d",y);//check valve
        if (strcmp(morlet[x],alpha[y])==0)
        {
        message[x]=65+y;
        //printf("\n%s,%s\n",morlet[x],alpha[y]);//checkvalve
        break;
        }
    }

    for (y=0;y<=10;y++)
    {
        if (strcmp(morlet[x],num[y])==0)
        message[x]=48+y;
    }
}
message[j+1]='\0';
printf("\nDecoded: %s", message);

return 0;
}
