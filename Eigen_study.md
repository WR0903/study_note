# Eigen study
**eigen是个纯头文件编写的线性代数库，和matlab相似** 
* `Eigen::Matrix<数据类型, 行（Eigen::Dynamic）, 列（Eigen::Dynamic）> 数组名称`//新建一个数组Eigen::Dynamic表示动态大小
* `Eigen::Vector3d 向量名称`//新建向量，double 3×1
* `matrix_23.cast<新的类型>()`//强制数据类型转换
* `matrix_33.transpose()`//矩阵转置
* `matrix_33.sum() `//矩阵元素求和
* `matrix_33.trace()`//矩阵的迹，特征值的和
* `matrix_33.inverse()`//矩阵的逆
* `matrix_33.determinant()`//求行列式


* eigenMatrix.cpp
```
#include<iostream>
#include<ctime>
using namespace std;
#include<Eigen/Core>
#include<Eigen/Dense>

#define MATRIX_SIZE 50

int main()
{
    Eigen::Matrix<float, 2, 3> matrix_23;//定义一个float2x3矩阵
    Eigen::Vector3d v_3d;//定义一个3x1矩阵,double类型的
    Eigen::Matrix3d matrix_33=Eigen::Matrix3d::Zero();//初始化为0
    Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic > matrix_dynamic;//定义一个动态矩阵
    Eigen::MatrixXd matrix_x;
    matrix_23 << 1, 2, 3, 4, 5, 6;
    cout <<matrix_23 <<endl;
    for (int i=0; i<1; i++)
       for(int j=0; j<2; j++)
          cout <<matrix_23(i,j)<<endl;
    v_3d <<3, 2, 1;
    Eigen::Matrix<double, 2, 1> result =matrix_23.cast<double>() * v_3d;//cast强制类型转换将float转换成double的
    matrix_33=Eigen::Matrix3d::Random();//随机赋值
    cout <<matrix_33 <<endl <<endl;
    cout <<matrix_33.transpose() <<endl;//转置
    cout <<matrix_33.sum() <<endl;      //各个元素的求和
    cout <<matrix_33.trace() <<endl;    //矩阵的迹，主对角线元素的和，特征值的和
    cout <<matrix_33.inverse() <<endl;  //矩阵的逆
    cout <<10*matrix_33 <<endl;         //数乘
    cout <<matrix_33.determinant() <<endl;//行列式
    Eigen::SelfAdjointEigenSolver<Eigen::Matrix3d> eigen_solver(matrix_33.transpose()*matrix_33);//求特征值特征向量
    cout <<"Eigen values =" << eigen_solver.eigenvalues() <<endl;
    cout <<"Eigen vectors =" << eigen_solver.eigenvectors() <<endl;
    Eigen::Matrix< double, MATRIX_SIZE, MATRIX_SIZE> matrix_NN;
    matrix_NN =Eigen::MatrixXd::Random(MATRIX_SIZE,MATRIX_SIZE);
    Eigen::Matrix< double, MATRIX_SIZE, 1> v_Nd;
    v_Nd =Eigen::MatrixXd::Random( MATRIX_SIZE,1 );
    clock_t time_stt=clock();
    Eigen::Matrix<double,MATRIX_SIZE,1> x=matrix_NN.inverse()*v_Nd;
    cout<<"time use in normal inverse is" <<1000*(clock()-time_stt)/(double)CLOCKS_PER_SEC <<"ms"<<endl;
    time_stt = clock();
    x=matrix_NN.colPivHouseholderQr().solve(v_Nd);
    cout <<"time use in Qr composition is " <<1000*(clock()-time_stt)/(double)CLOCKS_PER_SEC <<"ms"<<endl;
    return 0;
}
```
* CMakeLists.txt编写
```
cmake_minimum_required(VERSION 2.8)     #声明要求的camke最低版本
project(EigenSlam)                      #声明一cmake工程
include_directories("/usr/include/eigen3")
add_executable(EigenSlam eigenMatrix.cpp) #添加一个可执行文件
```
* 运行
```
cmake .
make
```
