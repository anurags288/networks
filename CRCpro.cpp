#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
void check(int deg,int &c,int temp[],int ndw[],int bin[]);
void check2(int deg,int &c,int temp[],int ndw[],int bin[]);

void inpoly(int deg,int pol[])
{
    for(int i=0;i<=deg;i++)
    {
            cout<<"enter coefficent of x^"<<(deg-i)<<" :";
            cin>>pol[i];
    }
}
void outpoly(int deg,int pol[])
{
    cout<<"the entered polynomial is :";
    for(int i=deg;i>=0;i--)
    {
        if(i==0)
        cout<<pol[deg-i];
        else
        cout<<pol[deg-i]<<"x^"<<i<<"+";
    }
}
void binpoly(int deg,int pol[],int bin[])
{
    for(int i=0;i<=deg;i++)
    {
        if(pol[i]>0)
        {
            bin[i]=1;
        }
        else
            bin[i]=0;
    }
    cout<<endl<<"polynomial in binary stream(divisor) is :";
    for(int i=0;i<=deg;i++)
    {
        cout<<bin[i];
    }
}
void indw(int dw[],int s)
{
    cout<<endl<<"enter the dataword in binary stream :";
    for(int i=0;i<s;i++)
    cin>>dw[i];
}
void outdw(int dw[],int s)
{
    cout<<endl<<"the entered dataword is :";
    for(int i=0;i<s;i++)
    cout<<dw[i];
}
void outndw(int s,int deg,int s1,int ndw[],int dw[])
{
    for(int i=0;i<s;i++)
    {
        ndw[i]=dw[i];
    }
    for(int i=0;i<deg;i++)
    {
        ndw[i+s]=0;
    }
    cout<<endl<<"the appended dataword(dividend) is :";
    for(int i=0;i<s1;i++)
    cout<<ndw[i];
}
void div(int deg,int s1,int cd[],int bin[],int ndw[],int temp[])
{
    int i,k=0,c=0;
    for(int i=0;i<=deg;i++)
    {
        temp[i]=bin[i]^ndw[i];
        c++;
}
    while(c<s1)
    {

    if(temp[1]==0)
    check(deg,c,temp,ndw,bin);
    else
    check2(deg,c,temp,ndw,bin);

    for(int i=0;i<=deg;i++)
    {
        temp[i]=bin[i]^temp[i];
    }
}
cout<<endl<<"the CRC bit are : ";

    for(int i=1;i<=deg;i++)
{
        cout<<temp[i];
}

for(int i=0;i<(s1-deg);i++)
{
    cd[k]=ndw[i];
    k++;
}
for(int i=1;i<=deg;i++)
{
    cd[k++]=temp[i];
}
cout<<endl<<"the codeword is : ";
for(int i=0;i<s1;i++)
{
    cout<<cd[i];
}
}
void check(int deg,int &c,int temp[],int ndw[],int bin[])
{
        for(int i=0;i<deg;i++)
        temp[i]=temp[i+1];
        temp[deg]=ndw[c++];
        for(int i=0;i<deg;i++)
        temp[i]=temp[i+1];
        temp[deg]=ndw[c++];
}
void check2(int deg,int &c,int temp[],int ndw[],int bin[])
{
    for(int i=0;i<deg;i++)
        temp[i]=temp[i+1];
        temp[deg]=ndw[c++];
}

void func(int s1,int r,int cd[],int ndw1[])
{
    if(r==0)
    {
        return;
    }
    else
    ndw1[r-1]=cd[r-1]^1;
}
void routdw(int s1,int ndw1[])
{
    cout<<endl<<"the received codeword is : ";
    for(int i=0;i<s1;i++)
    cout<<ndw1[i];
}
void div2(int deg,int s1,int bin[],int ndw1[],int temp[])
{
    int i,k=0,c=0;
    for(int i=0;i<=deg;i++)
    {
        temp[i]=bin[i]^ndw1[i];
        c++;
}
    while(c<s1-1)
    {

    if(temp[1]==0)
    check(deg,c,temp,ndw1,bin);
    else
    check2(deg,c,temp,ndw1,bin);

    for(int i=0;i<=deg;i++)
    {
        temp[i]=bin[i]^temp[i];
    }
}
    while(c<s1)
    {

    check(deg,c,temp,ndw1,bin);
    for(int i=0;i<=deg;i++)
    {
        temp[i]=bin[i]^temp[i];
    }
    }

cout<<endl<<"the CRC bit are : ";

    for(int i=0;i<=deg;i++)
{
        cout<<temp[i];
}
int flag=1;
for(int i=0;i<=deg;i++)
{
if(temp[i]!=0)
{

    flag=0;
    break;
}

}
if(flag==0)
cout<<endl<<"there is error in the received codeword!!!!!"<<endl;
else
cout<<endl<<"the received codeword is correct"<<endl;
}
int main()
{
    int deg,s,s1,n;
    int *pol,*bin,*dw,*ndw,*ndw1,*temp,*cd;
    cout<<"SENDER END :"<<endl;
    cout<<"enter the degree of the polynomial"<<endl;
    cin>>deg;
    pol=new int[deg+1];
    bin=new int[deg+1];

    inpoly(deg,pol);
    outpoly(deg,pol);
    binpoly(deg,pol,bin);
    cout<<endl<<"enter the size of dataword"<<endl;
    cin>>s;
    dw=new int[s];
    indw(dw,s);
    outdw(dw,s);
    s1=deg+s;
    ndw=new int[s1];
    outndw(s,deg,s1,ndw,dw);
    temp=new int[deg+1];
    cd=new int[s1];
    div(deg,s1,cd,bin,ndw,temp);

    ndw1=new int[s1];
    ndw1=cd;
    cout<<endl;
    cout<<endl<<"RECEIVER END :"<<endl;
    n=rand()%s1;
    func(s1,n,cd,ndw1);
    routdw(s1,ndw1);
    div2(deg,s1,bin,ndw1,temp);
    return 0;
}

