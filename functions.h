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

void polySolve(int nt, double x0, double tol, int miter, std::vector<std::vector<double>> eq)
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
        res=x-x0;
        if(res<0)res=-res;
        x0=x;
        ctr++;
        if(ctr>miter)
        {
            std::cout<<"\n Maximum number of iterations reached!\n"<<"x="<<x0<<"\nResidual="<<res<<std::endl;
            break;
        }
    }while(res>tol);
    if(ctr<=miter)std::cout<<"\nThe solution is:"<<x0<<"\nThe number of iterations is:"<<ctr<<"\nResidual is:"<<res<<std::endl;
}
