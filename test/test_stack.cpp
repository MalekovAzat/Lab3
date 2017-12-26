// ����� ��� �����

#include "../include/stack.h"
#include "../gtest/gtest.h"

TEST(Stack,can_create_stack_with_pisitive_size)
{
    ASSERT_NO_THROW(Stack<int > obj(10));
}

TEST(Stack,Cant_create_stack_with_negative_size)
{
    ASSERT_ANY_THROW(Stack<int > obj(-10));
}

TEST(Stack,can_create_copied_stack)
{
    Stack<int > obj_1(5);

    for(int i=0;i<3;i++)
        obj_1.push(i);
    Stack<int> obj_2(obj_1);
    
    EXPECT_EQ(true,obj_1==obj_2);
}

TEST(Stack,can_push_and_pop)
{
    Stack<int> obj_1(10);

    ASSERT_NO_THROW(obj_1.push(100));
    ASSERT_NO_THROW(obj_1.pop());    
}

TEST(Stack,can_peek)
{
    Stack<int > obj_1(10);
    obj_1.push(100);

    EXPECT_EQ(100,obj_1.pop());
}

TEST(Stack,can_use_empty)
{
    Stack<int > obj_1(10);
    EXPECT_EQ(true,obj_1.is_empty());
    
    obj_1.push(1);

    EXPECT_EQ(false,obj_1.is_empty());
}

TEST(Stack,can_use_full)
{
    Stack<int> obj_1(4);
    for(int i=0;i<4;i++)
        obj_1.push(i);
    EXPECT_EQ(true,obj_1.is_full());
    obj_1.pop();
    EXPECT_EQ(false,obj_1.is_full());

}

TEST(Stack,can_return_count_elements)
{
    Stack<int> obj_1(4);
    EXPECT_EQ(0,obj_1.GetStackSize());
    obj_1.push(10);
    EXPECT_EQ(1,obj_1.GetStackSize());
}

TEST(Stack,can_cleaning_stack)
{
    Stack<int> obj_1(5);
    for(int i=0;i<5;i++)
    {
        obj_1.push(i);
    }
    obj_1.clear_stack();
    EXPECT_EQ(0,obj_1.GetStackSize());
}
TEST(Stack, can_compare_of_neq_size)
{
    Stack <int> obj_1(10),obj_2(5);
    for(int i=0;i<5;i++)
    {
        obj_1.push(i);
        obj_2.push(i);
    }
    EXPECT_EQ(false,obj_1==obj_2);
}

TEST(Stack,can_compare_of_eq_size)
{
    Stack <int> obj_1(10),obj_2(10);
    for(int i=0;i<5;i++)
    {
        obj_1.push(i);
        obj_2.push(i);
    }
    EXPECT_EQ(true,obj_1==obj_2);
}
#ifdef Azz
#endif