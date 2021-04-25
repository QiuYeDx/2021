//手写简单的栈
    int stack[MAXN];    //开辟栈需要的数组空间，其中MAXN是栈的最大支持的大小
    int p=0;    //栈顶指针，指向下一个待插入的数组位置
    void push(int x){   //压栈，需要判断栈是否溢出
        if(p >= MAXN)
            printf("Stack overflow.");
        else{
            stack[p] = x;
            p+=1;
        }
    }
    void pop(){ //弹出栈顶元素，需要判断是否栈为空
        if(p == 0)
            printf("Stack is empty.");
        else
            p -= 1;
    }
    int top(){  //查询栈顶元素，需要判断是否栈为空
        if(p == 0){
            printf("Stack is empty.");
            return -1;
        }
        else
            return stack[p-1];  //注意按照定义方式，p-1才是栈顶
    }