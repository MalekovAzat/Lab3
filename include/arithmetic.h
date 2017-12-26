#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include"stack.h"

enum type_r {l_br,r_br,val,add,sub,div_,mul,exp_,num};

class Sub
{
private:
    double value; 
    type_r type; 
    int priority;
    string str;// имя переменной 

public:
    Sub(string s,type_r type_);// переменная
    Sub(double z);//  значение 
    Sub(char s);//  оператор 
    int get_type(){return type;};
    int get_priority(){return priority;};
    string get_main_str(){return str;};
    double get_value(){return value;};
    void modif_value(double z){value=z;};
    void modif_str(string str_0){str=str_0;}
};

// Sub::Sub(char s)
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
// }

// Sub::Sub(string s,type_r type_):str(s),type(type_)
// {
//     if (type==num)
//         value=atof(s.c_str());
// }

// Sub::Sub(double z):type(num),value(z)
// {
// }

class Polish_entry
{
private:
    string main_str,polish_str;// исходная строка
    double solution;
public:
    Polish_entry(string s);
    
    string get_polish_notes(Queue<Sub*> queue);// получение строки с польской записью 
    double get_solution(){return solution;};
    Queue<Sub*> trans_string_to_queue();// возврат строки в виде очереди 
    double calculation_polish_notes(Queue<Sub*> queue);// главный алгоритм 
    string return_pol_str(){return polish_str;};
};
// #ifdef INC
// #define INC
// Polish_entry::Polish_entry(string s):main_str(s)
// {
//     Queue<Sub*> sig(10);
//     sig=trans_string_to_queue();
//     solution=calculation_polish_notes(sig);

// }

// Queue<Sub*> Polish_entry::trans_string_to_queue()
// {   
//     string loc_str="";
//     Queue<Sub*> queue(30);
//     int flag=0;
//     if (main_str[0]==45)
//         main_str=string("0")+main_str;
//     for(int i=1;i<=main_str.size();i++)
//     {
//         if((main_str[i]==45)&&(i<main_str.size()))
//         {
//             if(((main_str[i+1]>=97)&&(main_str[i+1]<=122))||((main_str[i+1]>47)&&(main_str[i+1]<=57)))
//                 if((main_str[i-1]==40)||(main_str[i-1]==41))
//                 {
//                     main_str=main_str.substr(0,i)+"0"+main_str.substr(i,main_str.size()-i);
//                     i++;
//                 }
//             if((main_str[i]==43) ||(main_str[i]==45)||
//             (main_str[i]==47)||(main_str[i]==42)||(main_str[i]==94))
//                 if((main_str[i+1]==43) ||(main_str[i+1]==45)||
//             (main_str[i+1]==47)||(main_str[i+1]==42)||(main_str[i+1]==94))
//                 throw "Two operators in a row.";
//         }
//     }
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
//             if (main_str[i]==40)
//                 flag++;
//             else
//                 flag--;
//             if (loc_str.size()!=0)
//             {
//                 if((loc_str[0]>=97) && (loc_str[0]<=122))
//                     queue.push(new Sub(loc_str,val));
//                 else 
//                     queue.push(new Sub(loc_str,num));
//             }
//             loc_str="";
//             queue.push(new Sub(main_str[i]));
//         }
//         else
//         if((main_str[i]==43) ||(main_str[i]==45)||
//         (main_str[i]==47)||(main_str[i]==42)||(main_str[i]==94)||(main_str[i]==0))// если +- 
//         {
//             if (loc_str.size()!=0)
//             {
//                 if((loc_str[0]>=97) && (loc_str[0]<=122))
//                     queue.push(new Sub(loc_str,val));
//                 else 
//                     queue.push(new Sub(loc_str,num));
//             }
//             loc_str="";
//             queue.push(new Sub(main_str[i]));
//         }
//         else
//         {
//             //cout<<"исключение!"<<endl;
//             throw 0;
//         }
//     }
//     if(flag!=0)
//     {
//         throw 0;
//         //cout<<"исключение!"<<endl;
//     }
//     return queue;
// }

// string Polish_entry::get_polish_notes(Queue<Sub* > queue)
// {
//     string loc_str="";
//     while(queue.get_len()>0)
//     {
//         Sub* obj=queue.pop();
//         if(obj->get_type()==num)
//             loc_str+=to_string(obj->get_value());
//         else if (obj->get_type()==val)
//             loc_str+=obj->get_main_str();
//         else
//         {
//             switch(obj->get_type())
//             {
//                 case add:loc_str+="+";break;
//                 case sub:loc_str+="-";break;
//                 case div_:loc_str+="/";break;
//                 case mul:loc_str+="*";break;
//                 case exp_:loc_str+="^";break;
//             }
//         }
//     }
//     return loc_str;
// }

// double Polish_entry::calculation_polish_notes(Queue<Sub* > queue)
// {
//     Stack <Sub *> stack_0(queue.get_len()+10);// стек с временными значениями
//     Queue <Sub *> queue_0(queue.get_len()+10);// выходная строка
//     while (queue.get_len()>0)
//     {   
//         Sub* arg=queue.pop();
//         if (arg->get_type()==num)//число 
//             queue_0.push(arg);
//         else if( arg->get_type()==val)//переменная 
//             queue_0.push(arg);
//         else if (arg->get_type() == l_br)// левая скобка  
//             stack_0.push(arg);
//         else if (arg->get_type() ==r_br)// правая скобка
//         {
//             while((stack_0.GetStackSize()>0)&&(stack_0.peek()->get_type()!= l_br))
//                 queue_0.push(stack_0.pop());
//             stack_0.pop();// мега ВАЖНА!
//         }
//         else if ((arg->get_type()>val) && (arg->get_type()<num)) // оператор 
//         {
//             while((stack_0.GetStackSize()>0)&&(arg->get_priority()<=stack_0.peek()->get_priority()))
//             {
//                 queue_0.push(stack_0.pop());
//             }
//             stack_0.push(arg);
//         }
//     }
//     int size=stack_0.GetStackSize();
//     for(int i=0;i<size;i++)
//         queue_0.push(stack_0.pop());
//     polish_str=get_polish_notes(queue_0);
//     Stack <Sub *> stack_1(100);
//     while (queue_0.get_len()>0)
//     {
//         Sub* arg=queue_0.pop();
//         if(arg->get_type()==val)
//         {
//             cout<<"Введите значение "<<arg->get_main_str()<<" : ";
//             double val;
//             cin>>val;
//             arg->modif_value(val);
//             stack_1.push(arg);
//         }
//         else if(arg->get_type()==num)
//         {
//             stack_1.push(arg);
//         }
//         else if ((arg->get_type()>val) && (arg->get_type()<num))
//         {
//             double arg_1=stack_1.pop()->get_value();
//             double arg_2=stack_1.pop()->get_value();
//             switch(arg->get_type())
//             {
//                 case add:stack_1.push(new Sub(arg_1+arg_2)); break;
//                 case sub:stack_1.push(new Sub(arg_2-arg_1)); break;
//                 case div_:stack_1.push(new Sub(arg_2/arg_1)); break;
//                 case mul:stack_1.push(new Sub(arg_1*arg_2)); break;
//                 case exp_:stack_1.push(new Sub(pow(arg_2,arg_1))); break;
//             }
//         }   
//     }
//     return stack_1.pop()->get_value();
// }
// #endif
#endif