#include<vector>
#include<iostream>
#include<string>
#include<cctype>
#define N_OPTR 9
using namespace std;

enum Operator {ADD,SUB,MUL,DIV,POW,FAC,L_P,R_P,EOE};

const char pri[N_OPTR][N_OPTR]=
{ // +   -   *   /   ^   !    (  )   \0
    '>','>','<','<','<','<','<','>','>',  //  +
    '>','>','<','<','<','<','<','>','>',  //  -
    '>','>','>','>','<','<','<','>','>',  //  *
    '>','>','>','>','<','<','<','>','>',  //  /
    '>','>','>','>','>','<','<','>','>',  //  ^
    '>','>','>','>','>','>',' ','>','>',  //  !
    '<','<','<','<','<','<','<','=',' ',  //  (
    ' ',' ',' ',' ',' ',' ',' ',' ',' ',  //  )
    '<','<','<','<','<','<','<',' ','='   //  \0
};


template<typename T>
class Stack:public vector<T>
{
public:
    void push(T const & e){this->push_back(e);}
    T& top(){return this->back();}
    T pop(){T tmp=this->back();this->pop_back();return tmp;}
};

void readNumber(char c,Stack<float> & opnd,bool flag)
{
    if(flag==false)
    {

    }
}

float evaluate(string & str,string & RPN)
{
    Stack<float> opnd;
    Stack<char> optr;
    optr.push('\0');
    int i=0;
    bool flag=false;
    while(!optr.empty())
    {
        if(isdigit(str[i]))
        {
            flag=true;
            readNumber(str[i],opnd,flag);
            RPN.append(opdn.top());
        }
        else
        {
            switch(orderBetween(optr.top(),str[i]))
            {
                case '<':optr.push(str[i]);i++;break;
                case '=':optr.pop();i++;break;
                case '>':
                {
                    char op=optr.pop;
                    append(RPN.op);
                    if('!'==op)
                    {
                        float pOpnd=opdn.pop();
                        opnd.push(calcu(op,pOpnd));                        
                    }
                    else
                    {
                        float pOpnd2=opnd.pop();
                        float pOpnd1=opnd.pop();
                        opnd.push(calcu(pOpnd1,op,pOpnd2));
                    }
                    break;
                }
            }
            default:exit(-1);
        }
        i++;
    }

    return opnd.pop();
}

int main()
{
    string str;
    srting RPN;
    cin>>str;
    cout<<evaluate(string &str,string &RPN)<<endl;
    cout<<str<<endl<<RPN<<endl;
    return 0;
}
