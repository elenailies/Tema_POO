#include <iostream>

using namespace std;

class Multime
{
    friend ostream& operator<<(ostream& out, const Multime& x);
    friend istream& operator>>(istream& in,  Multime& x);
    friend Multime operator + (const Multime& a, const Multime& b);
    friend Multime operator - (const Multime& a, const Multime& b);
    friend Multime operator * (const Multime& a, const Multime& b);


    int v[100];
	int n;
public:
    Multime()
	{
		n = 0;
	}
    Multime(Multime &a)
    {
        n = a.n;
        for (int i = 0; i < n; i++)
		{
		    v[i] = a.v[i];
		}
    }
    ~Multime()
	{
		n = 0;
	}

    void vector_in_multime()
    {
        int sortat;
        do
        {
          sortat = 1;
          for(int i = 0 ; i < n - 1 ; i ++)
            if(v[i] > v[i+1])
            {
              int aux = v[i];
              v[i] = v[i+1];
              v[i+1] = aux;
              sortat = 0;
            }
        }while(sortat==0);
       for(int i=0;i<n-1;i++)
        {
            if(v[i]==v[i+1])
            {
                for(int j=i;j<n;j++)
                    v[j]=v[j+1];
                n--;
            }
        }


    }


};


 ostream& operator<<(ostream& out, const Multime& x)
    {
        for(int i=0;i<x.n;i++)
            out << x.v[i]<<" ";
        return out;
    }
 istream& operator>>(istream& in, Multime& x)
    {
     in >> x.n;
    for(int i=0;i<x.n;i++)
        in >>x.v[i];
     return in;
    }
 Multime operator + (const Multime& a, const Multime& b)
{
    Multime c;
    int k=-1,j;

    for(j=0;j<a.n;j++)
            c.v[++k]=a.v[j];

    for(j=0;j<b.n+1;j++)
    {
            c.v[++k]=b.v[j];
    }
    c.n=k;
    c.vector_in_multime();
    return c;
}
 Multime operator - (const Multime& a, const Multime& b)
{
    Multime c;

    int i,j,k=-1,ok;

    for(j=0;j<a.n+1;j++)
    {
        ok=0;
        for(i=0;i<b.n;i++)
            if(a.v[j]==b.v[i])
                ok=1;
        if(ok==0)
            c.v[++k]=a.v[j];
    }

    c.n=k;

    return c;
}
 Multime operator * (const Multime& a, const Multime& b)
{
    Multime c;
    int i,j,k=-1;
    for(j=0;j<a.n;j++)
    {
        for(i=0;i<b.n;i++)
            if(a.v[j]==b.v[i])
                c.v[++k]=a.v[j];
    }

    c.n=k+1;
    return c;
}


int main()
{
    Multime a,b;
    cin>>a;
    cin>>b;
    a.vector_in_multime();
    b.vector_in_multime();
    cout<<endl<<a<<endl<<b<<endl<<endl<<"a+b="<<a+b<<endl<<"a-b="<<a-b<<endl<<"a*b="<<a*b;
    return 0;
}
