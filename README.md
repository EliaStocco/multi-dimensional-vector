# Multi-dimensional-vector
A single include c++ template class for multi dimensional dynamical vectors.

## Jupyter Notebooks
Some jupyter notebooks for Cling kernel are also provided. 

If you do not have Cling or Xeus-Cling kernel installed (https://github.com/jupyter-xeus/xeus-cling.git) you can open it online with Binder (https://mybinder.org/v2/gh/jupyter-xeus/xeus-cling/stable?filepath=notebooks/xcpp.ipynb).

The provided jupyter notebooks are for demonstration only:
- dynamical-vector.ipynb is my "working file", here I modify the code and save it automatically to all the header files
- test.ipynb is a notebook where I test if the code works correctly, you can open it with with Binder (https://mybinder.org/v2/gh/jupyter-xeus/xeus-cling/stable?filepath=notebooks/xcpp.ipynb) or with github (a bit slow but it works) in order to see how to use the template class, copy line of code as example, etc.

## Header files
The only file to be included in your project is "dynamics-vector.h", but you alse need to have "header/" directory in the same directory of "dynamics-vector.h".

## How to use the class
In order to use the provided class, add the following lines of code before ```int main ()```
```cpp
#include "dynamic-vector.h"
using namespace eliastocco :: container :: dynamic;
```
For allocating multi dimensional array of (for example) ```double``` or ```float``` add the following line of code
```cpp
//allocating a 1D array of double of length 2
dynamic_vector < 1 , double > matrix1D = {{ 2 }};

//allocating a 2D array of float of 2 rows and 3 colums
dynamic_vector < 2 , double > matrix2D = {{ 2 , 3 }};
```
So you just need to provide the dimension of the array ad the type of the "contained variables" as template parameters, and the length(s) as constructor parameters.

For access of modify element of an array you can allocate ```std::array``` as follows
```cpp
typedef eliastocco :: container :: dynamic :: t_dim index_t; //long unsigned int
// 1D index
std::array<index_t,1> i1 = {0};
// 2D index
std::array<index_t,2> i2 = {1,0};
```
and then you have different equivalent ways to specify the element to get or to set:
- 1D array
```cpp
//The following are equivalent (1D matrix)
i1={1}; //array of length 1
//
matrix1D[1] = 5.0;
std::cout << matrix1D[1] << std :: endl; //print 5.0
//
matrix1D[i1] = 6.0;
std::cout << matrix1D[i1] << std :: endl; //print 6.0
```
- 2D array
```cpp
//The following are equivalent (2D matrix)
i2={1,0}; //array of length 1
//
matrix2D[1][0] = 7.0;
std::cout << matrix2D[1][0] << std :: endl; //print 7.0
//
matrix2D[i2] = 8.0;
std::cout << matrix2D[i2] << std :: endl; //print 8.0
```
- for higher dimension nothing changes

## How does the class works?
The provided class inherit (by default) from the STL template ```std::vector``` class in order to exploit it as container.

Pay attention that you can inherit also from another similar class, like ```std::deque``` or ```std::queue``` , simply adding the class name as third template parameter
```cpp
#include <queue>
#include <deque>
//2D array of double of length 2,3 using std :: vector as contained
//std :: vector is the default value
dynamic_vector < 2 , double /*, std :: vector*/ > matrix2D_Double = {{ 2 , 3 }};       
//3D array of double of length 2,3,5 using std :: deque as contained
dynamic_vector < 3 , double , std :: deque > matrix2D_Queue = {{ 2 , 3 , 5 }};
//4D array of double of length 2,3,5,9 using std :: queue as contained
dynamic_vector < 4 , double , std :: queue > matrix2D_Deque = {{ 2 , 3 , 5 , 9 }};
```

The provided class is simply an "automatic iteration over the contained variable". 
The logic behind is the same as standard C where a (static) multidimensional array has to be defined as follow
```cpp
// 1D array of double of length 3
double a[3];
// 2D array (matrix) of float of length 3,4
float  b[3][4];
// 3D array of int of length 3,4,2
int    c[3][4][2];
```
The provided class works as follows:
- 1D array is a primitive class, it inherits from ```std::vector<***>``` (by default, or from another class if specified) where ```***``` is the type of the contained variable (```double``` in the previus examples)
- 2D array is a 1D array of 1D array, something like ```std::vector<std::vector<***>>```
- 2D array is a 1D array of 2D array, something like ```std::vector<std::vector<std::vector<***>>>```
- etc

For this reason, if you allocate the following variables
```cpp
dynamic_vector < 1 , double > matrix1D = {{ 3 }};
dynamic_vector < 2 , double > matrix2D = {{ 2 , 3 }};
```
the variable ```matrix2D[0]``` has the same type of the ```matrix1D```, in fact you can do the following
```cpp
matrix1D[0] = 2.0;
matrix1D[1] = 4.0;
matrix1D[2] = 5.0;

matrix2D[1] =  matrix1D
```

### Iterator
Working progess...