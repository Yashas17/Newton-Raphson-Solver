#include<iostream>
#include<vector>
#include<cmath>

void getEq(int &nt,double &x0,double &tol,int &miter,std::vector<std::vector<double>> &eq)
{
/*
>   This function gets the equation to be solved from the user. 
>   It also gets the solver parameters from the user.
*/
    
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
/*
>   This function evaluates the equation a given value of x.
*/
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
/*
>   The function takes in two 2D vectors: eq and eq1, representing original and differentiated equations respectively.
>   It differentiates eq and stores it in eq1.
*/
    eq1=eq;
    for(auto i=0;i<eq1.size();i++)
    {
        eq1[i][1]*=eq1[i][0];
        eq1[i][0]-=1;
    }
}

double polySolve(int nt, double x0, double tol, int miter, std::vector<std::vector<double>> eq)
{

/*
>   The function polySolve() computes the solution of the given equation.
>   The function calls function polyDiff() to get differentiated equation of input equation and 
    function f() to evalute the value of equation at given point.
*/
    std::vector<std::vector<double>> eq1;
    polyDiff(eq,eq1);
    double res;             //Residual to check for convergence
    auto ctr=0;             //Counter for number of iterations
    do
    {   
        double x,g,g1;
        g=f(x0,eq);         //Value of equation at x0
        g1=f(x0,eq1);       //Value of differentiated equation at x0
        x=x0-g/g1;
        res=fabs(x-x0);     //Absolute difference between solution of previous and current iteration 
        x0=x;               //Updating solution
        ctr++;
        if(ctr>miter)       //Check if maximum number of iterations have been reached
        {
            std::cout<<"\n Maximum number of iterations reached!\n"<<"x="<<x0<<"\nResidual="<<res<<std::endl;
            break;
        }
    }while(res>tol);        //Iterate till the solution converges

    if(ctr<=miter)std::cout<<"\nThe solution is:"<<x0<<"\nThe number of iterations is:"<<ctr<<"\nResidual is:"<<res<<std::endl;

    return x0;
}

bool polySolve_test()
{   
/*
>   We test the working of the polySolve() function by solving an equation with known analytical solution 
    and comparing the numerical solution of polySolve() with it.
>   We solve the equation: x^2-x-1 using polySolve(). 
>   It's positive root is a well known number known as 'Golden Ratio':(1+sqrt(5))/2 which is 
    approximately equal to 1.61803. The negative root is approximately equal to -0.61803.
>   We set the guess solution to 1.6, which is closer to the positive root to ensure the solution converges to positive root.
>   We use a tolerance of 1e-3 for the solver and also for comparing the analytical and numerical solution.
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

    std::cout<<"\nRunning Unit Test.\n";

    x0=polySolve(nt,x0,tol,miter,eq);

    if(fabs(x0-1.61803)>1e-3) 
    {
        std::cout<<"The code is not working as expected.\n";
        return false;
    }

    return true;
}