### malloc

<u>头文件</u>：stdlib

<u>原型</u>：void* malloc(size_t size)

由于返回类型是void型指针，所以对所以数据类型都适用，但是为了防止后续程序出现错误需要根据实际需要的数据类型对其进行强制类型转换。

<u>返回值</u>：

成功时，返回新分配内存的指针（也就是这部分内存的地址），后续为避免内存泄露必须用free或realloc解分配返回的指针（释放分配的内存）。

失败时，返回空指针（NULL）

<u>参数</u>：size—要分配的字节数，一般用sizeof（DataType）获取

<u>定义</u>：

分配 size 字节的未初始化内存。
若分配成功，则返回为任何拥有基础对齐的对象类型对齐的指针。

/* 对齐是指根据对象数据类型的不同，单个数据类型对象占有的固定size有差异，这种固定的size值就叫做对齐，比如对于int型指针p=10006，p+1=10010（地址值），而对于void型指针vp=10006，vp+1=10007。可以理解为当指针+1时其实是移动了一个size值的距离，也就是移动了一个对齐。因此p=malloc（sizeof（int））和p=（int*）malloc(sizeof(int))是对齐不同的指针，前者为malloc的默认返回值void型指针，对齐为1；后者为int型指针，对齐为4。

测试代码：

```
int main(){
    int n;
    int* p;
    void* pv;
    printf("%d\n",sizeof(p));
    printf("%d\n",sizeof(pv));
    printf("%d   %d\n",p,p+1);
    printf("%d   %d",pv,pv+1);
}
```



### free

<u>头文件</u>：stdlib

原型：void free(void* ptr);

参数：指向待解分配的内存的指针

返回值：无

malloc失败的指针(空指针)也可以给free处理。



注意1：确保free的指针和malloc的指针是同一个指针，如果malloc的指针改变过（如p++），再free(p)就会导致程序错误。

注意2：free后的指针是野指针

