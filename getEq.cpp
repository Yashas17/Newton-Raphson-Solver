#include<iostream>
#include<vector>

void getEq(&nt,&x0,&tol,&miter,&eq)
{
    int i;
    std::cout<<"Enter the number of terms in the polynomial equation : ";
    std::cin>>nt;
    for(i=1;i<=nt;i++)
    {
        std::cout<<"Enter power of term "<<i<<" : ";
        std::cin>>eq[1][i];
        std::cout<<"Enter coefficient of term "<<i<<" : ";
        std::cin>>eq[2][i];
    }
    std::cout<<"The polynomial is "
    for(i=1;i<=nt;i++)
    {
        std::cout<<eq[2][i]<<"x^"<<eq[1][i];
        if(i<n)
        {
            std::cout<<"+";
        }
    }
    

}