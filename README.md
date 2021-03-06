# 计算力

> 这个repo是GP课程大作业微积分计算部分，单独列出一个repo便于使用

单独计算各个力的实现：[GP-ODE](<https://github.com/199ChenNuo/GP-ODE>)

## 1. node需要的数据结构

### 1.1 node所在折痕的另一个node

> （需要的是彼此的三维空间中的位置），也可以记住node所在的所有折痕

axial constraints:
$$
\vec F_{axial} = - k_{axial} (l - l_0) \frac {\partial l} { \partial \vec p} \\
其中  \\
\frac {\partial l} { \partial \vec p} = 
\begin {cases}
- \vec I_{12} & node1 \\
\vec I_{12} & node2 \\
\end {cases} \\

\vec I_{12}是从node1的位置指向node2的位置的单位向量， \\所以对于每个node来说， \frac {\partial l} { \partial \vec p}直接取 \\ 到所在折痕的另一个node的单位向量的负值即可
$$

### 1.2 node所在的所有面

即使是对边（如图中标注）对p2也有力的作用
$$
\frac{\partial \theta}{\partial \vec p_1} = \frac{\vec n_1}{h_1}, \\\
\frac{\partial \theta}{\partial \vec p_2} = \frac{\vec n_2}{h_2}, \\\
\frac{\partial \theta}{\partial \vec p_3} = \frac{-cot \alpha_{4,31}}{cot \alpha_{3,14}+cot \alpha_{4,31}}\frac{\vec n_1}{h_1} + \frac{-cot \alpha_{4,23}}{cot \alpha_{3,42}+cot \alpha_{4,23}}\frac{\vec n_2}{h_2}, \\\
\frac{\partial \theta}{\partial \vec p_4} = \frac{-cot \alpha_{3,14}}{cot \alpha_{3,14}+cot \alpha_{4,31}}\frac{\vec n_1}{h_1} + \frac{-cot \alpha_{3,42}}{cot \alpha_{3,42}+cot \alpha_{4,23}}\frac{\vec n_2}{h_2} \\\
\alpha_{1, 23}：以p_1为顶点，p_2, p_3分别在两边的角 \\\
h_1,h_2: 以p_1, p_2为顶点的高
$$
![1559112188107](D:/github/GameProgramming/%E4%B8%AD%E6%9C%9F/assets/1559112188107.png)



### 1.3 node需要有自己的id

> 除了全局的之外，最好也能在面内和另外两个node区分开

因为在本文2.1中要计算Crease constraints的时候，是针对面来计算的，但是最后的力又是要施加到node上，所以需要能够根据面找到对应的node。



## 2. 面需要的数据结构

### 2.1 和邻接面的夹角

> 这里也可以直接记住邻接的面，或者通过node来得到邻接的面

crease constraints:
$$
\vec F_{crease} = - k_{crease} (\theta - \theta_{target}) \frac {\partial \theta}{\partial \vec p} \\
这里的\frac {\partial \theta}{\partial \vec p}即1.2节中的求导结果 \\
k_{crease}是常数，不用在数据结构中定义。 \\ 
k_{crease} = 
\begin{cases}
{l_0 k_{flod}} & \text{moutain or valley crease} \\
{l_0 k_{facet}} & \text{facet crease} \\
{0} & \text {boundary edge or undriven crease}
\end{cases}
$$
![1559112188107](D:/github/GameProgramming/%E4%B8%AD%E6%9C%9F/assets/1559112188107.png)

复用了这张图。

这里的theta是指图中两个面的夹角的补角，target theta即最终期望的折叠角（这里大概就是和flod percentage）有关了。

这里计算完之后需要再把力添加到node受的外力上。



### 2.2 面的法向量，面的3个node

> 面的法向量可以通过node计算得出，但是可以空间换时间，直接记住（但是这样也需要经常更新(T ^ T) ）面的3个node是一定要有的

face constraints:
$$
\vec F_{face} = - k_{face} (\alpha - \alpha_0) \frac{\partial \alpha} {\partial \vec p} \\
\frac{\partial \vec p_1}{\partial \alpha_{2,31}} = \frac{\vec n \times (\vec p_1-\vec p_2)}{\parallel \vec p_1-\vec p_2 \parallel ^2} \\
\frac{\partial \vec p_2}{\partial \alpha_{2,31}} = - \frac{\vec n \times (\vec p_1-\vec p_2)}{\parallel \vec p_1-\vec p_2 \parallel ^2} + \frac{\vec n \times (\vec p_3-\vec p_2)}{\parallel \vec p_3-\vec p_2 \parallel ^2}\\
\frac{\partial \vec p_3}{\partial \alpha_{2,31}} = - \frac{\vec n \times (\vec p_3-\vec p_2)}{\parallel \vec p_3-\vec p_2 \parallel ^2} \\
$$
alpha和p的相对位置规定如图。

![1559113226698](D:/github/GameProgramming/%E4%B8%AD%E6%9C%9F/assets/1559113226698.png)

## 3. 折痕需要的数据结构

> crease和beam的区别，目前猜测是beam是梁，在计算力的时候是有意义的。boundary facet、facet crease等都是crease（然而不是beam）

### 3.1 原长 & 当前长度

这是因为胡克系数和原长有关。（也许以后可以再加入横截面积等，来计算更精确的胡克系数）
$$
k_{axial} = \frac{EA}{l_0} \\
EA = 20
$$

### 3.2 两端的node