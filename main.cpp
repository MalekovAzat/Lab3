#include"include/arithmetic.h"

int main()
{   
    string str="";
    while(str!="Stop")
    {
        cout<<"Введите строку: ";
        cin>>str;
        try
        {
            Polish_entry a(str);
            cout<<"Ответ - "<<a.get_solution()<<endl;
        }
        catch(...)
        {
            cout<<"Проверьте строку на наличие ошибок"<<endl;
        }
    }
    return 0;
}