## 第2章 变量和基本类型

1. 当一个表达式中既含有无符号数又有int值时，那个int值就会被转换为无符号数。

```c++
unsignd u = 10;
int i = -42;
std::cout << i +i << std::endl; //输出-84
std::cout<<u +i<< std::endl;//如果int 占32位，输出4294967264

```

2. 内层作用域可以重新定义外层作用域已有的名字。

3. 引用

​	(1)  引用一旦初始化，必须和它的初始值对象一直绑定，无法再重新绑定到另外一个对象，因此引用必须初始化。

​	(2) 引用只能绑定在对象上，而不能与字面值或某个表达式的计算结果绑定在一起。

​	(3)  引用的类型必须和它所绑定的对象的类型严格匹配。

4. const限定符

​	(1) const对象一旦创建后其值不能再改变，const对象必须初始化。

​	(2) 默认状态下，const对象仅在文件内有效，如果想在多个文件之间共享const对象，必须在变量定义之前添加extern关键字。

```c++
// file_1.cc定义并初始化了一个常量，该常量能被其他文件访问
extern const int bufSize = fcn ( ) ;
// file_1.h头文件
extern const int bufSize; //与file_1.cc中定义的bufsize是同一个

```

​	(3) 顶层const常量可以拷贝给任意变量，但是底层const常量只能拷贝给具有相同底层const的对象。

​	(4) **常量表达式**是指值不会改变并且在编译过程时就能得到结果的表达式。可以将一个变量声明为constexpr类型由编译器来验证变量的值是否是一个常量表达式

```c++
constexpr int mf = 20;// 20是常量表达式
constexpr int limit = mf + 1; //mf + 1是常量表达式
constexpr int sz = size ();//只有当size是一个constexpr函数时
						   //才是一条正确的声明语句

```

​	(5) constexpr指针的初始值必须是nullptr或者0，或者是存储于某个固定地址中的对象。constexpr声明中如果定义了一个指针，限定符仅对指针有效，与所指向的对象无关。(相当于是顶层const)

```c++
constexpr int *np = nullptr; //np是一个指向整数的常量指针，其值为空
int j= 0;
constexpr int i = 42; //i的类型是整型常量
//l i和j都必须定义在函数体之外
constexpr const int *p = &i; // p是指向常量的常量指针，指向整型常量i
constexpr int *p1 =&j;// p1是常量指针，指向整数j

```

5. decltype可以从表达式的类型推断出要定义的变量的类型。(由编译器分析完成，但不实际计算表达式的值)

   (1) decltype使用的表达式是一个变量，则decltype返回该变量的类型(包括顶层const和引用在内)。

   ```c++
   const int ci = 0, &cj = ci;
   decltype(ci) x= 0;// x的类型是const int
   decltype(cj）y = X;// y的类型是const int&，y绑定到变量x
   decltype(cj) z; //错误:z是一个引用，必须初始化
   
   ```

   (2) decltype使用的表达式不是一个变量，则decltype返回表达式结果对应的类型。(**如果表达式的结果对象能作为一条赋值语句的左值，则返回引用类型**)

   ```c++
   // decltype的结果可以是引用类型
   int i = 42,*p = &i, &r = i;
   decltype(r + 0) b;//正确:加法的结果是int，因此b是一个(未初始化的)
   intdecltype (*p) c;//错误:c是int&，必须初始化
   ```

   (3) 如果给变量加上一个括号，decltype返回引用类型

   ```c++
   //decltype的表达式如果是加上了括号的变量，结果将是引用
   decltype((i)) d;//错误:d是int&，必须初始化
   decltype(i) e;//(正确:e是一个（未初始化的) int
   ```

6. c中的struct和c++中的struct的区别

   (1) c中的struct没有函数成员，只有数据成员。c++中都有

   (2) c中的struct不可以继承。c++中的可以

   (3) c中的struct没有访问权限的设定，不能对外隐藏数据。c++ 中的struct有三种权限设定。

### 第四章 表达式

1. 左值和右值

   (1) **当一个对象被用作右值的时候，用的是对象的值(内容)；当一个对象被用作左值的时候，用的是对象的身份(在内存中的位置)。**

   (2) 在需要右值的地方可以用左值来代替，但是不能把右值当成左值(也就是位置)使用。当一个左值被当作右值来使用时，实际上用的是它的内容(值)。

2. 类型转换

   (1) 算数转换。运算符中的运算对象将转换成其中的最宽类型。

   (2) 显示转换：将对象强制转换成另一种类型。

   * static_cast: 任何具有明确定义的类型转换，只要不包含底层const，都可以使用。

     ```c++
     //进行强制类型转换以便执行浮点数除法
     double slope = static_cast<double>(j)/ i;
     void* p = &d;//正确:任何非常量对象的地址都能存入 void*
     //正确:将void*转换回初始的指针类型
     double *dp = static_cast<double*>(p);
     ```
     
   * const_cast:用于去掉对象的底层const性质。不能用于改变表达式的类型

     ```c++
     const char *cp;
     //错误:static_cast不能转换掉const性质
     char *q = static_cast<char* > (cp) ;
     static_cast<string>(cp);//正确:字符串字面值转换成string类型
     const_cast<string> (cp) ;//错误:const_cast只改变常量属性
     ```

     

### 第六章 函数

1. 参数传递

   (1) 形参是const时，用实参初始化形参会忽略掉形参的顶层const。

   (2) 可变形参有两种方式:

    * 使用initializer_list (每个实参的类型相同)
    * 使用可变参数模板(实参的类型不同)

2. 返回类型

   (1) 不要返回局部对象的引用或指针。函数完成之后，它所占用的存储空间也被随之释放。

   (2) 返回数组指针

   ```c++
   typedef int arrT[10];// arrT是一个类型别名，它表示的类型是含有10个整数的数组
   using arrT = int [10];// arrT的等价声明
   arrT*func (int i);// func返回一个指向含有10个整数的数组的指针
   ```

   ```c++
   int (*func (int i))[10];
   ```

   ```c++
   auto func ( int i)-> int (* )[10]; //使用尾置返回类型
   ```

   ```c++
   int odd [] = {1，3,5,7,9};
   int even [] = {0,2,4,6,8};
   //返回一个指针，该指针指向含有5个整数的数组
   decltype (odd) *arrPtr (int i)
   {
   	return (i % 2)? &odd : &even;// 返回一个指向数组的指针
   }
   ```

3. 函数重载(同一作用域内，函数名称相同但形参列表不同)

   (1) const形参

   * 如果形参是顶层const，不能用它来区分是否是函数重载。因为形参是const时，用实参初始化形参会忽略掉形参的顶层const。

     ```c++
     Record lookup ( Phone) ;
     Record lookup (const Phone) ;//重复声明了Record lookup (Phone)
     
     Record lookup(Phone*) ;
     Record lookup ( Phone* const);//重复声明了 Record lookup(Phone*)
     ```

   * 如果形参是底层const，则可以用来重载函数。当传入一个非常量对象或者指向非常量的指针时，编译器会优先选用非常量的版本。

   (2) 如果在内层作用域中声明名字，将隐藏外层作用中声明的同名实体。在不同作用域中无法重载函数名。

4. 语言特性

   (1) 默认实参。函数可以声明多次，但是在给定作用域中一个形参只能被赋予一次默认实参。而且默认实参的后面的形参都要有默认值。

   (2) constexpr函数:指能用于常量表达式的函数。
   
   * constexpr函数的返回类型及所有形参的类型都得是字面值类型。
   * 函数体中必须有且只有一条return语句。
   * 不一定返回常量表达式(看传入得实参是否是常量表达式)

5. 函数匹配

   (1) 候选函数:与被调用函数同名，在调用点可见。

   (2) 可行函数:形参与本次调用提供的实参数量相等；每个实参的类型与对应的形参类型相同或者能转化成形参的类型。

   (3) 匹配规则:

   * 每个实参的匹配都不劣于其他可行函数需要的匹配。
   * 至少有一个实参的匹配优于其他可行函数提供的匹配。

   (4) 实参类型转换等级：

   * 精确匹配：
     * 实参类型和形参相同
     * 从数组类型或者函数类型转换成对应的指针类型
     * 向实参添加顶层const和从实参删除顶层const
   * 通过const转换实现的匹配。
   * 通过类型提升。
   * 通过算术类型转换或指针转换。(所有算术类型转换的级别都一样)
   * 通过类类型转换。