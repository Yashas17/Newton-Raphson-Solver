#include<iostream>
#include<vector>

void getEq(int& nt,int& x0,int& tol,int& miter,std::vector<std::vector<double>>& eq)
{
    int i;
    std::vector<double> v1;
    std::vector<double> v2;
    double temp;
    std::cout<<"Enter the number of terms in the polynomial equation : ";
    std::cin>>nt;
    for(i=0;i<nt;i++)
    {
        std::cout<<"Enter power of term "<<i+1<<" : ";
        std::cin>>temp;
        v1.push_back(temp);
        std::cout<<"Enter coefficient of term "<<i+1<<" : ";
        std::cin>>temp;
        v2.push_back(temp);
    }
    eq.push_back(v1);
    eq.push_back(v2);
    std::cout<<"The polynomial is ";
    for(i=0;i<nt;i++)
    {
        std::cout<<eq[1][i]<<"x^"<<eq[0][i];
        if(i<nt-1)
        {
            std::cout<<"+";
        }
    }
}
    
int main()
{
    int nt;    //number of terms in the equation seperated by addition
    int x0;     //guess solution
    int tol;    //tolerance
    int miter;  //maximum iterations
    std::vector<std::vector<double>> eq; //vector to store equation
    getEq(nt,x0,tol,miter,eq);
    //polySolve(x0,tol,miter,eq);
    return 0;
}