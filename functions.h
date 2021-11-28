#include<iostream>
#include<vector>
#include<cmath>

void getEq(int &nt,double &x0,double &tol,int &miter,std::vector<std::vector<double>> &eq)
{
    
    std::cout<<"Enter the tolerance:";
    std::cin>>tol;

    std::cout<<"Enter maximum number of iterations:";
    std::cin>>miter;

    std::cout<<"Enter guess solution:";
    std::cin>>x0;
    
    std::cout<<"Enter the number of terms in the polynomial equation: ";
    std::cin>>nt;

    eq.resize(nt,std::vector<double>(2,0));

    for(auto i=0;i<nt;i++)
    {
        std::cout<<"Enter the power of term "<<i+1<<":\t";
        std::cin>>eq[i][0];
        std::cout<<"Enter coefficient of term "<<i+1<<":\t";
        std::cin>>eq[i][1];
    }

    std::cout<<"\nThe polynomial is:";
    for(auto i=0;i<nt;i++)
    {
        std::cout<<" "<<eq[i][1]<<"x^"<<eq[i][0]<<" ";
        if(i<nt-1)
        {
            std::cout<<"+";
        }
    }
    std::cout<<std::endl;
}

double f(double x,const std::vector<std::vector<double>>& eq)
{
    double sum=0;
    for(auto i=0;i<eq.size();i++)
    {   
        if(eq[i][1]!=0) sum+=eq[i][1]*pow(x,eq[i][0]);
    }
    auto y=sum;
    if(y<0)y=-y;
    if(y<1e-14) std::cout<<"\nWARNING!\nThe value of the differentiated function is close or equal to zero which can lead to large errors!\n";
    return sum;
}

void polyDiff(const std::vector<std::vector<double>>& eq, std::vector<std::vector<double>>& eq1)
{
    eq1=eq;
    for(auto i=0;i<eq1.size();i++)
    {
        eq1[i][1]*=eq1[i][0];
        eq1[i][0]-=1;
    }
}

double polySolve(int nt, double x0, double tol, int miter, std::vector<std::vector<double>> eq)
{
    std::vector<std::vector<double>> eq1;
    polyDiff(eq,eq1);
    double res; //residual
    auto ctr=0;
    do
    {   
        double x,g,g1;
        g=f(x0,eq);
        g1=f(x0,eq1);
        x=x0-g/g1;
        res=fabs(x-x0);
        x0=x;
        ctr++;
        if(ctr>miter)
        {
            std::cout<<"\n Maximum number of iterations reached!\n"<<"x="<<x0<<"\nResidual="<<res<<std::endl;
            break;
        }
    }while(res>tol);
    if(ctr<=miter)std::cout<<"\nThe solution is:"<<x0<<"\nThe number of iterations is:"<<ctr<<"\nResidual is:"<<res<<std::endl;

    return x0;
}

bool polySolve_test()
{   
/*
We test the working of function polySolve by comparing its solution for the equation x^2-x-1=0 with the analytical solution.
The test equation has two roots: 1.61803 and -061803. We enter the guess solution close to 1.61803 to make the solver converge to that root.
If the numerical solution is equal to the analytical solution, we conclude the solver works as expected. 
We use tolerance of 1e-3 compare analytical and numerical solutions.
*/
    int nt=3;
    double x0=1.6;
    double tol=1e-3;
    int miter=10;
    std::vector<std::vector<double>> eq;

    eq.resize(nt,std::vector<double>(2,0));

    eq[0][0]=2;
    eq[0][1]=1;
    eq[1][0]=1;
    eq[1][1]=-1;
    eq[2][0]=0;
    eq[2][1]=-1;

    std::cout<<"Running Unit Test.\n";

    x0=polySolve(nt,x0,tol,miter,eq);

    if(fabs(x0-1.61803)>1e-3) 
    {
        std::cout<<"The code is not working as expected.\n";
        return true;
    }

    return false;
}