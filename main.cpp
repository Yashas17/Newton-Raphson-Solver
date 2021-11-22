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

    std::cout<<"The polynomial is:";
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
        sum+=eq[i][1]*pow(x,eq[i][0]);
    }
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
        double x=x0-f(x0,eq)/f(x0,eq1);
        res=x-x0;
        if(res<0)res=-res;
        x0=x;
        ctr++;
        if(ctr>miter)
        {
            std::cout<<"Maximum number of iterations reached!\n"<<"x="<<x0<<"\nResidual="<<res<<std::endl;
            break;
        }
    }while(res>tol);
    if(res<tol) std::cout<<"The solution is:"<<x0<<"\nThe number of iterations is:"<<ctr<<"\nResidual is:"<<res<<std::endl;
}

int main()
{
    int nt;    //number of terms in the equation seperated by addition
    double x0;     //guess solution
    double tol;    //tolerance
    int miter;  //maximum iterations
    std::vector<std::vector<double>> eq; //vector to store equation
    getEq(nt,x0,tol,miter,eq);
    polySolve(nt,x0,tol,miter,eq);
}
