#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    int n,cpct,i,j;
    cout << "\n no. of values: ";
    cin>>n;
    int job[n],prof[n],d[n],a,b,c;
    for(i=0;i<n;i++)
    {
        cout<<"\n obj "<<i+1<<": ";
        cin>>job[i];
        cin>>d[i];
        cin>>prof[i];
    }
    //max=r[0];
    for (i = 1; i < n; i++)
    {
        a=job[i];
        b=prof[i];
        c=d[i];
        j = i - 1;
        while (j>=0 && prof[j]<=b)
        {
            prof[j+1]=prof[j];
            job[j+1]=job[j];
            d[j+1]=d[j];
            j=j-1;
        }
        job[j+1]=a;
        prof[j+1]=b;
        d[j+1]=c;
    }
    int m=d[0];
    for(i=0;i<n;i++)
    {
        if(d[i]>m)
            m=d[i];
    }
    for(i=0;i<n;i++)
    {
        cout<<"\n J"<<job[i]<<" | "<<d[i]<<" | "<<prof[i];
    }
    cout<<"\n max deadline: "<<m;
    int t[m],x,s=0;
    for(i=0;i<n;i++)
    {
        x=d[i]-1;
        t[x]=d[i];
        s+=prof[i];
    }
    return 0;
}
