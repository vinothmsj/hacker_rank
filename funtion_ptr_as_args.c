#include<stdio.h>
#include<stdlib.h>
/* this is a simple program to demostrate the function pointer. 
   */
void int_arg(int a)
{
    printf("%d \n" , a);
}

void char_args(char *str)
{
    printf("%s \n" , str);
}
void func_ptr_as_arg(void (*func)(int) , void (*func_1)(char *))
{
    func(20);
    func_1("target");
}
void (*int_fn_ptr)(int) = &int_arg;
void (*char_fn_ptr)(char *) = &char_args;
void (*fun)(void (*func)(int) , void (*func_1)(char *)) = &func_ptr_as_arg;
void main()
{

    int_fn_ptr(10);
    char_fn_ptr("vinoth");
    fun(&int_arg , &char_args );

}
