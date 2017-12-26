#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<string>
#include<cmath>

using namespace std;

template<class Val>
class Stack
{
private:
    Val *stackPtr;                  //указатель на стек
    int size;                 //размер стека
    int top;                        //вершина стека
public:
    Stack(int size_=10);              // конструктор стека 
    Stack(const Stack<Val> &s);     // конструктор копирования
    ~Stack();

    Val pop();                      //вытащить элемент с вершины 
    void push(const Val &value);    // положить на вершину значение 
    Val peek();     //посмотреть содержимое стека
    int GetStackSize();             //возврат размера стека
    bool operator== (const Stack<Val> &s);
    bool is_empty(){if (top>0)return 0; return 1;};
    bool is_full(){if (top==size) return 1;return 0;};
    void clear_stack(){top=0;};
};

template<class Val>
Stack<Val>::Stack(int size_):size(size_)
{
    if (size>0)
    {
        stackPtr = new Val[size];
        top=0; 
    }
    else 
    throw "we have a problem!";
}

template<class Val>
Stack<Val>:: Stack(const Stack<Val> &s):size(s.size)
{
    top=s.top;
    stackPtr=new Val[size];

    for(int i=0;i<top;i++)
        stackPtr[i]=s.stackPtr[i];
}

template<class Val>
void Stack<Val>::push(const Val& value)
{
    if (top<size)
        stackPtr[top++]=value;
    else
    {
        Stack<Val> tmp(*this);
        size=top+5;
        stackPtr= new Val[size];
        for(int i=0; i<tmp.GetStackSize();i++)
        {
            stackPtr[i]=tmp.stackPtr[i];
        }
        stackPtr[top++]=value;
    }
}

template<class Val>
Val Stack<Val>::pop()
{
    if (top>0)
        return stackPtr[--top];
    else 
        throw "It's a problem!";
}

template <class Val>
int Stack<Val>::GetStackSize()
{
    return top;
}

template <class Val>
Val Stack<Val>::peek()
{
    return stackPtr[top-1];
}

template <class Val>
bool Stack<Val>::operator==(const Stack<Val> &s)
{
    if(size!=s.size)
        return 0;
    else 
    {
        Stack<Val> obj_1(*this);
        Stack<Val> obj_2(s);
        for(int i=0;i<obj_1.GetStackSize();i++)
        {
            if(obj_1.pop()!=obj_2.pop())
                return 0;
        }
        return 1;
    }
}

template <class Val>
Stack<Val>::~Stack()
{
    delete [] stackPtr;
}

template<class Val>
class Queue
{
public:
    int size,head,tail;// голова хвост и размер
    Val* pVal;

    Queue(int size_=10);
    Queue( Queue<Val> &a);
    ~Queue();

    Queue<Val>& operator=(const Queue<Val> &a); 
    void push(const Val a);//добавить в очередь 
    Val pop();// вытащить элемент из очереди 
    int get_len(){return (tail-head);};
};

template<class Val>
Queue<Val>::Queue(int size_):size(size_),head(0),tail(0)
{
    pVal=new Val[size];
    for(int i=0;i<size;i++)
        pVal[i]=0;//  не обязательно
}

template<class Val>
Queue<Val>::~Queue()
{
    delete [] pVal;
}

template<class Val>
void Queue<Val>::push(const Val a)
{
    pVal[tail++]=a;
}

template<class Val>
Val Queue<Val>::pop()
{    
    return pVal[head++];
}

template<class Val>
Queue<Val>::Queue( Queue<Val> &a):size(a.size),head(a.head),tail(a.tail)
{
    pVal=new Val[size];
    for (int i=head;i<tail;i++)
        pVal[i]=a.pVal[i];
}

template<class Val>
Queue<Val>& Queue<Val>::operator=(const Queue<Val> &a)
{
    size=a.size;
    head=a.head;
    tail=a.tail;
    pVal=new Val[size];
    for (int i=head;i<tail;i++)
        pVal[i]=a.pVal[i];
    return *this;
}

// #ifdef zero

// //#define zero
// enum type_r {l_br,r_br,val,add,sub,div_,mul,exp_,num};

// class Sub
// {
// public:
//     double value;
//     type_r type;
// };


// class Operand_0:public Sub // операнд 
// {
// public:
//     //double value;
//     Operand_0(string s);
//     Operand_0(double z){value=z;};
// };

// Operand_0::Operand_0(string s)
// {
//     type=num;
//     value=atof(s.c_str());
// }
// class Operator:public Sub// 
// {
// public:
//     Operator(char s);
//     int priority; 
// };

// Operator::Operator(char s)
// {
//     switch(s)
//     {
//         case 40:type=l_br; priority=0; break;
//         case 41:type= r_br; priority=0; break;
//         case 43:type=add; priority=1; break;
//         case 45:type=sub; priority=1 ;break;
//         case 47:type=div_; priority=2 ; break;
//         case 42:type=mul; priority=2 ;break;
//         case 94:type=exp_; priority=3 ;break;
//     }
// };

// class Unknown:public Sub // неизвестное строковое выражение 
// {
// public:
//     string str;
//     //double value;
//     Unknown(string s){type=val;str=s;value=0;}

// };
// //#define zero
// class Polish_entry
// {
// private:
//     string main_str;// исходная строка
//     double solution;
// public:
//     Polish_entry(string s);
//     string get_polish_notes();// получение строки с польской записью 
//     double get_solution(){return solution;};
//     Queue<Sub*> trans_string_to_queue();// возврат строки в виде очереди 
//     double calculation_polish_notes(Queue<Sub*> queue);// главный алгоритм 
// };


// Polish_entry::Polish_entry(string s):main_str(s)
// {
//     Queue<Sub*> sig(10);
//     sig=trans_string_to_queue();
//     solution=calculation_polish_notes(sig);
//     cout<<solution<<endl;
// }

// Queue<Sub*> Polish_entry::trans_string_to_queue()
// {
//     string loc_str="";
//     Queue<Sub*> queue(30);

//     for(int i=0;i<=main_str.size();i++)
//     {   
//         if (((main_str[i]>47)&&(main_str[i]<=57))||(main_str[i]==46))
//         {
//             loc_str+=main_str[i];
//         }
//         else if((main_str[i]>=97) && (main_str[i]<=122))
//         {
//             loc_str+=main_str[i];
//         }
//         else if (main_str[i]==40 ||main_str[i]==41)//если  (  )
//         {
//             if (loc_str.size()!=0)
//             {
//                 if((loc_str[0]>=97) && (loc_str[0]<=122))
//                     queue.push(new Unknown(loc_str));
//                 else 
//                     queue.push(new Operand_0(loc_str));
//             }
//             loc_str="";
//             queue.push(new Operator(main_str[i]));
//         }
//         else // если +-*/
//         {
//             if (loc_str.size()!=0)
//             {
//                 if((loc_str[0]>=97) && (loc_str[0]<=122))
//                     queue.push(new Unknown(loc_str));
//                 else 
//                     queue.push(new Operand_0(loc_str));
//             }
//             loc_str="";
//             queue.push(new Operator(main_str[i]));
//         }
//     }
//     return queue;
// }

// double Polish_entry::calculation_polish_notes(Queue<Sub* > queue)
// {
//     Stack <Sub *> stack_0(queue.get_len());// стек с временными значениями
//     Queue <Sub *> queue_0(queue.get_len());// выходная строка
//     while (queue.get_len()-1>0)
//     {   
//         Sub* arg=queue.pop();
//         if (arg->type==num)//число 
//             queue_0.push(arg);
//         else if( arg->type==val)
//             queue_0.push(arg);
//         else if (arg->type == l_br)// левая скобка  
//             stack_0.push(arg);
//         else if (arg->type ==r_br)// правая скобка
//         {
//             if(stack_0.GetStackSize()>0)
//             {
//                 while(stack_0.peek()->type!= l_br)
//                     queue_0.push(stack_0.pop());
//             }
//             stack_0.pop();// мега ВАЖНА!
//         }
//         else if ((arg->type>val) && (arg->type<num)) // оператор 
//         {
//             if(stack_0.GetStackSize()>0)
//             {
//                 while(((Operator*)arg)->priority<=((Operator*)(stack_0.peek()))->priority)
//                 {
//                     queue_0.push(stack_0.pop());
//                 }
//             }
//             stack_0.push(arg);
//         }
//     }
//     int size=stack_0.GetStackSize();
//     for(int i=0;i<size;i++)
//         queue_0.push(stack_0.pop());
//     Stack <Sub *> stack_1(100);
//     while (queue_0.get_len()>0)
//     {
//         Sub* arg=queue_0.pop();
//         if(arg->type==val)
//         {
//             cout<<"Введите значение :"<<((Unknown*)arg)->str;
//             cin>>arg->value;
//             stack_1.push(arg);
//         }
//         else if(arg->type==num)
//         {
//             stack_1.push(arg);
//         }
//         else if ((arg->type>val) && (arg->type<num))
//         {
//             double arg_1=stack_1.pop()->value;
//             double arg_2=stack_1.pop()->value;
//             switch(arg->type)
//             {
//                 case add:stack_1.push(new Operand_0(arg_1+arg_2)); break;
//                 case sub:stack_1.push(new Operand_0(arg_2-arg_1)); break;
//                 case div_:stack_1.push(new Operand_0(arg_2/arg_1)); break;
//                 case mul:stack_1.push(new Operand_0(arg_1*arg_2)); break;
//                 case exp_:stack_1.push(new Operand_0(pow(arg_2,arg_1))); break;
//             }
//         }   
//     }
//     return stack_1.pop()->value;
// }
// #endif
#endif