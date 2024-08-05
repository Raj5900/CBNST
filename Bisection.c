# include<stdio.h>
# include<math.h>

float func(float x)
{
    float fx=(x*x*x)-(2*x)-5;
    return fx;
}

int main()
{
    float x0,x1,e;
    float x2;
    printf("ENTER X0   X1    e\n");
    scanf("%f%f%f",&x0,&x1,&e);
    if((func(x0)*func(x1))>=0);
    {   
        printf(" ");
     }   
     printf("		   x0		         x1		           x2		            f(x2)\n");
while(fabs(x0-x1)>e)
{
    x2=(x0+x1)/2;
    if(func(x0)*func(x2)<0)
    {
        x1=x2;
    }
    else if(func(0)*func(x2)>0)
    {
        x0=x2;
    }
    else
        {break;}
    
    printf("		%f		%f		%f		%f\n",x0,x1,x2,func(x2));
}
printf("ROOT IS %f\n",x2);
return 0;
}
