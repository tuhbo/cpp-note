### 第7章 类

类的基本思想是数据抽象和封装。数据抽象是一种依赖于接口和实现分离的编程技术。

**1.成员函数**：在类内声明，可以定义在类外或者类之内。(定义在类之内的函数是隐式的inline函数)。

**2.this指针**

​	(1) 成员函数可以通过一个this的隐式参数来访问到调用它的那个对象。this是指向非常量类类型的一个常量指针。

​	(2) const成员函数使得this指针指向常量对象。并且常量成员函数不能改变调用它的对象的内容。(常量对象，以及常量对象的引用和指针都只能调用常量成员函数)

**3.构造函数**

​	初始化对象的数据成员

(1) **构造函数不能被声明成const**

(2) 如果一个类没有定义任何构造函数，那么编译器会隐式地定义一个默认构造函数。它将按下列规则初始化数据成员

* 如果存在类内初始值，则用它来初始化成员。
* 否则，默认初始化该成员。

下列情况会生成的默认构造函数是可靠的：

* 只有当类没有声明任何构造函数
* 只有类包含有内置类型或者复合类型的成员都有类内初始值
* 类类型成员定义了默认构造函数。

(3) 如果需要显示定义构造函数具有默认行为，可以在构造函数后面添加 = default。

**4.友元**

​	类允许其他类或者函数访问它的非公有成员，令其他类和函数成为它的友元(加friend关键字)

​	(1) 友元声明只能出现在类内部，具体位置不限。

​	(2) 为了使友元对类的用户可见，通常把友元在类外再次声明。

​	(3) 类可以把其他的类定义成友元，也可以把其他类的成员函数定义成友元。

​	(4) 友元函数可以定义在类的内部，这样就变成了隐式内联函数。

​	(5) 相同类的对象互为友元。

​	(6) 友元关系不存在传递性。(每个类负责控制自己的友元类或友元函数)。

**5 构造函数初始值列表**

​	(1) 如果没在构造函数初始值列表中显式地初始化成员，则该成员将在构造函数之前执行默认初始化。

​	(2) 如果数据成员是:

* const
* 引用
* 未提供默认构造函数的类类型

必须使用构造函数初始值列表初始化。

```c++
class ConstRef
{
	public:
		ConstRef (int ii) ;
	private:
		int i;
		const int ci;
		int &ri;
};

//错误:ci和ri必须被初始化
ConstRef::ConstRef (int ii)
{//赋值:
	i = ii;//正确
	ci = ii;//错误:不能给const赋值
	ri = i ;//错误:ri没被初始化
}
//正确:显式地初始化引用和const成贝
ConstRef::ConstRef(int ii):i(ii),ci(ii), ri(i){ }
```

​	(3) 构造函数初始值列表中的初始值的前后位置关系不会影响实际的初始化顺序，成员的初始化顺序由它们在类中的定义顺序决定

6. **隐式的类类型转换**

   如果构造函数只接受一个参数，则定义了一个转换此类的隐式的规则(转换构造函数)

   ```c++
   string null_book = "9-999-99999-99";
   //item为Sales_data类型，而Sales_data有一个
   //Sales_data(const string &)构造函数
   //combine的形参类型为const Sales_data &
   item.combine(null_book);
   ```

   上述代码中null_book自动转换成Sales_data类型(相当于一个临时变量)

   (2) 隐式转换的规则中只允许一部类类型转换。

   ```c++
   //错误:需要用户定义的两种转换:
   // (1)把“9-999-99999-9”转换成string
   // (2)再把这个（临时的) string转换成Sales_data
   item .combine( "9-999-99999-9");
   ```

   (2) 抑制构造函数定义的隐式转换

   在只有一个参数的构造函数的前面加explicit关键字。(只对一个实参的构造函数有效，并且只能用于类内声明构造函数时使用，类外不能重复定义)

   ```c++
   class Sales_data {
   	public:
   		Sales_data() = default;
   		sales_data (const std: :string &s,unsigned n,double p):
   		bookNo (s) , units_sold(n) , revenue (p*n){ }
   		explicit Sales_data (const std : :string &s) : bookNo(s) {}
   		explicit csales_data(std: :istream& ) ;
   	//其他成员与之前的版本一致
   };
   
   item.combine (null_book) ;
   //错误:string构造函数是explicit的
   item. combine (cin) ;
   //错误:istream构造函数是explicit的
   
   //错误:explicit关键字只允许出现在类内的构造函数声明处
   explicit sales_data::Sales_data(istream& is)
   {
   	read (is,*this) ;
   }
   ```

7. **聚合类**

   (1) 满足下列条件的类:

   * 所有成员是public。
   * 没有定义任何构造函数
   * 没有类内初始值
   * 没有基类，也没有virtual函数

   (2) 可以提供花括号来初始化聚合类的数据成员。花括号中的初始值的顺序必须与声明的顺序一一致。

   (3) 初始值列表中元素的数量不能超过类的成员数量。小于的话，靠后的成员执行值初始化。

8. **字面值常量类**

   字面值常量类可能含有constexpr成员函数，它们是隐式const的。
   
   (1) 数据成员都是字面值类型的聚合类是字面值常量类
   
   (2) 如果不是聚合类，符合下述要求，则也是字面值常量类:
   
   * 数据成员都必须是字面值类型。
   * 至少有一个constexpr构造函数。
   * 数据成员有类内初始值，则内置类型成员初始值必须是一条常量表达式。类类型的初始值必须使用constexpr构造函数。
   * 类必须使用析构函数的默认定义。

9. **类的静态成员**

   类的静态成员与类本省直接相关，而不是与类的各个对象保持关联。

   (1) 类的静态成员存在于任何对象之外，对象不包含任何静态数据成员有关的数据

   (2) 静态成员函数也不与任何对象绑定在一起，不包含this指针。不能声明成const

   (3) static关键字只能出现在类内部的声明语句中。

   (4) 静态数据成员只能定义一次，一旦被定义，就将存在程序的整个生命周期。

   (5) 即使一个常量静态数据成员在类内初始化，通常情况下也应该在类外部定义下该成员。

   (6) 静态数据成员特殊应用场景：

   * 静态数据成员的类型可以是它所属的类类型。而非静态数据成员只能声明它所属类的指针或引用。

   ```c++
   class Bar {
   public:
   / / ...
   private:
   	static Bar meml ;//正确:静态成员可以是不完全类型
   	Bar *mem2 ;//正确:指针成员可以是不完全类型
   	Bar mem3 ;//错误:数据成员必须是完全类型
   };
   
   ```

   

   * 静态成员可以作为默认实参。



### 第10章

**1.介绍lambda**

​	lambda表达式是一个未命名的可调用对象。和函数一样，具有一个返回类型、参数列表、函数体。

它可以定义在函数的内部。

```c++
[ capture list ] (parameter list) -> return type { function body}
```

* capture list 是lambda表达式所在函数中定义的局部变量的列表
* parameter list是参数列表，return type为返回类型。
* lambda必须使用尾置返回类型。
* 必须包含捕获列表和函数体
* 如果lambda的函数体包含任何单一return语句之外的内容，且未指定返回类型，则返回void。

(1) 传递参数

* 调用lambda时给定的实参被用来初始化lambda的形参。
* lambda不能有默认实参。

(2) 捕获列表

* 捕获列表只用于局部非静态变量，lambda可以直接使用局部静态变量和它所在函数之外声明的名字。

* 值捕获：采用值捕获的前提是变量能被拷贝。

  * 被捕获的变量的值是在lambda创建时拷贝，而不是调用的时候拷贝。
  * 因为是在创建时被拷贝，所以随后对其修改不会影响lambda内对应的值

  ```c++
  void fcn1 ()
  {
  	size_t v1 =42;//局部变量
  	//将v1拷贝到名为f的可调用对象
  	auto f = [v1] { return vl; };
  	v1 = 0;
  	auto j = f();//j为42;f保存了我们创建它时v1的拷贝
  )
  
  ```

* 引用捕获：当以引用方式捕获一个变量时，必须保证在lambda执行时变量是存在的

  ```c++
  void fcn2 ()
  {
  	size_t v1 = 42;//局部变量
  	//对象f2包含v1的引用
  	auto f2 =[ &v1] { return vl; };
  	vl = 0;
  	auto j = f2();// j为0;f2保存v1的引用，而非拷贝
  }
  
  ```

(3) 可变lambda

* 默认情况下，值捕获的变量，lambda不会改变其值，如果希望能改变一个被捕获变量的值，在参数列表后加上关键字mutable。

  ```c++
  void fcn3 ()
  {
      size_t v1 = 42;//局部变量
      //f可以改变它所捕获的变量的值
      auto f = [v1]( ) mutable { return ++vl; };v1 = 0;
      auto j= f(); //j为43
  }
  
  ```

* 一个引用变量是否可以改变依赖于它是const还是非const

  ```c++
  void fcn4 ()
  {
  	size_t vl = 42;//局部变量
  	// v1是一个非const变量的引用
  	//可以通过f2中的引用来改变它
  	auto f2 =[&v1] { return++vl;};vl = 0;
  	auto j = f2();//j为1
  }
  
  ```



### 第12章 智能指针

新标准提供了三种指针：

* shared_ptr: 允许多个指针指向同一个对象。
* unique_ptr: 则“独占”所指向的对象。
* weak_ptr，它是一种弱引用，指向shared_ptr所指向的对象。

(1) 支持的操作

* share_ptr 和 unique_ptr共同支持的操作

  ![share_ptr和unique_ptr共同支持的操作](D:\study\Specialty\note\c ++\image\share_ptr和unique_ptr共同支持的操作.png)

* share_ptr独有的操作

  ![share_ptr独有的操作](D:\study\Specialty\note\c ++\image\share_ptr独有的操作.png)

1. **share_ptr**

* shared_ptr有一个与它指向对象关联的计数器(引用计数)。拷贝一个shared_ptr,用shared_ptr初始化另一个shared_ptr，将它作为参数传递给函数，作为函数的返回值，引用计数都会递增。

* 给shared_ptr赋予一个新值，shared_ptr被销毁，计数器会递减。
* 但计数器减为0时， 会自动释放自己管理的对象。

(1) **和new结合使用**

接受指针参数的智能指针构造函数是explicit的，不能将一个内置指针隐式转换成shared_ptr,必须使用直接初始化。

* 默认情况下，用来初始化智能指针的普通指针必须指向动态内存
* 智能指针默认使用delete释放它所关联的对象。
* 可以将智能指针绑定到一个指向其他类型的资源的指针上，但必须定义自己的操作来替代delete

![QQ截图20210303145355](D:\study\Specialty\note\c ++\image\QQ截图20210303145355.png)

![QQ截图20210303145437](D:\study\Specialty\note\c ++\image\QQ截图20210303145437.png)

(2) 不要使用get初始化另一个智能指针或为智能指针赋值

```c++
shared_ptr<int> p (new int (42));//引用计数为1
int *q = p.get(); //正确:但使用q时要注意，不要让它管理的指针被释放
{//新程序块
//未定义:两个独立的shared_ptr指向相同的内存
	shared ptr<int>(q);
}//程序块结束，q被销毁，它指向的内存被释放
int foo = *p; //未定义:p指向的内存已经被释放了

```

p, q虽然指向相同的内存，但它们是相互独立创建的，因此各自的引用计数都是1。(**因为引用计数是创建在堆内存上的**)

**(3) 智能指针使用规范**

* 不使用想用的内置指针值初始化(或reset)多个智能指针
* 不delete get()返回的指针
* 如果使用get()返回的指针，最后一个对应的智能指针销毁后，指针就变为无效了
* 如果使用智能指针管理的资源不是new分配的内存，要传递一个删除**器。**

2. **unique_ptr**

   unique_ptr与shared_ptr不同，某时刻只能有一个unique_ptr指向一个给定的对象

   ![QQ截图20210303152052](D:\study\Specialty\note\c ++\image\QQ截图20210303152052.png)

* unique_ptr不能拷贝和赋值，只能直接初始化

```c++
unique_ptr<string> pl(new string ("Stegosaurus" ) );
unique_ptr<string> p2(p1);//错误: unique_ptr不支持拷贝unique_ptr<string> p3;
p3 = p2;
//错误:unique_ptr不支持赋值

```

**(4) weak_ptr**

weak_ptr指向由shared_ptr管理的对象，将一个weak_ptr绑定到一个shared_ptr不会改变shared_ptr的引用计数。

![QQ截图20210303155046](D:\study\Specialty\note\c ++\image\QQ截图20210303155046.png)