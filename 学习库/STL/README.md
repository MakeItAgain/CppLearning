# STL standard template library

## 什么是STL？
参考链接1： https://zhuanlan.zhihu.com/p/130905242
参考链接2：
1. STL（Standard Template Library），即标准模板库，是一个高效的C++程序库，包含了诸多常用的基本数据结构和基本算法。熟练使用STL会让编码事半功倍。

2. 从逻辑层次来看，在STL中体现了泛型化程序设计的思想（generic programming）。在这种思想里，大部分基本算法被抽象，被泛化，独立于与之对应的数据结构，用于以相同或相近的方式处理各种不同情形。

3. 从实现层次看，整个STL是以一种类型参数化（type parameterized）的方式实现的，基于模板（template）。

STL有六大组件，但是主要包含了容器，迭代器，算法三个部分：
* 容器（Containers）：用来管理某类对象的集合（例如string就是一个容器，提供了管理字符和字符串数据的很多方法和逻辑）。每一种容器都有其优点和缺点，所以，为了应付程序中的不同需求，STL 准备了七种基本容器类型。
* 迭代器（Iterators）：用来在一个对象集合的元素上进行遍历动作（类比于指针）。这个对象集合或许是个容器，或许是容器的一部分。每一种容器都提供了自己的迭代器（类比指针也就是不同的容器有自己的容器，不同的数据类型有自己的指针），而这些迭代器了解该种容器的内部结构。
* 算法（Algorithms）：用来处理对象集合中的元素，比如 Sort，Search，Copy，Erase 那些元素。熟练掌握了STL，可以很方便的将algorithm库里的函数通过迭代器的协助，只需撰写一次算法，就可以将它应用于任意容器之上，这是因为所有容器的迭代器都提供一致的接口。

## 容器
容器用来管理某类对象。为了应付程序中的不同需求，STL 准备了两类共七种基本容器类型：
* 序列式容器（Sequence containers），此为可序群集，其中每个元素均有固定位置—取决于插入时机和地点，和元素值无关。如果你以追加方式对一个群集插入六个元素，它们的排列次序将和插入次序一致。STL提供了三个序列式容器：向量（vector）、双端队列（deque）、列表（list），此外你也可以把 string 和 array 当做一种序列式容器。
* 关联式容器（Associative containers），此为已序群集，元素位置取决于特定的排序准则以及元素值，和插入次序无关。如果你将六个元素置入这样的群集中，它们的位置取决于元素值，和插入次序无关。STL提供了四个关联式容器：集合（set）、多重集合（multiset）、映射（map）和多重映射（multimap）
### vector （可变长数组）

### string 字符串



## 迭代器  Iterators

## 算法 Algorithms