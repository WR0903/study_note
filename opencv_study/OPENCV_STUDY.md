# opencv_study


* qt使用opencv的工程配置

**2.4.9版本**  

```

INCLUDEPATH += /usr/local/include \
                        /usr/local/include/opencv2 \
                        /usr/local/include/opencv

LIBS +=  /usr/local/lib/libopencv_core.so.2.4.9 \
                /usr/local/lib/libopencv_highgui.so.2.4.9 \
                /usr/local/lib/libopencv_imgproc.so.2.4.9
```
**3.1版本**
```
INCLUDEPATH += /usr/local/include
LIBS += /usr/local/lib/libopencv_*.so
```

* 腐蚀操作，效果局部变黑，原理是领域内找最小值  
```
Mat element=getStructuringElement(MORPH_RECT,Size(15,15));//获得结构元素内核矩阵
erode(I,D,element);
```  
![](erode.png)   
其中getStructuringElement会返回指定形状和大小的结构内核矩阵，它有三个元素，第一个元素是内核矩阵的形状，第二个参数是内核矩阵的大小，第三个参数是内核矩阵的瞄点位置（默认是中点）  
```
矩形MORPH_RECT  
交叉形MORPH_CROSS  
椭圆形MORPH_ELLIPSE  
```
* 膨胀操作，效果局部变亮，原理是领域内找最大值  
![](dilate.png)   
`dilate(I,D,element);`
* 模糊操作，效果局部变淡
```
blur(I,E,Size(7,7));
```
* 边缘检测
首先转成灰度图像  
`cvtColor(I,F,CV_BGR2GRAY);`  
然后模糊处理,我的理解是边缘以内的进行模糊，以更好的找到边缘  
`blur(F,G,Size(7,7));`  
边缘检测  
`Canny(G,G,3,9,3);`  

* 打开一个新的窗口，添加插件用的比较多（比如滑动条，鼠标操作）
`namedWindow("haha");`

* `saturate_cast()`就是防止数据溢出，具体的原理可以大致描述如下：
```
if(data<0)
        data=0;
if(data>255)
data=255
```

* 对一张图片的每个像素乘以一个常数，照片的对比度改变，这个常数<1,对比度减小，这个常数>1，对比度增大;
对一张图片的每个像素加上一个常数，照片的亮度改变，这个常数<0,亮度减小，这个常数>0，亮度增大;
```
for(int i=0;i<image.rows;i++)
    {
        for(int j=0;j<image.cols;j++)
        {
            for(int c=0;c<3;c++)
            {
                image.at<Vec3b>(i,j)[c]=saturate_cast<uchar>(0.5×image.at<Vec3b>(i,j)[c]+100);
            }
        }
    }
```
* 方框滤波，内核矩阵越大图像越模糊,以下是我用10*10的内核矩阵,均值滤波的效果和方框滤波相似（差别在于是否有归一化），效果都是如下  
![](srcImage.jpg)  
![](boxFilter.png)  
高斯滤波，内核矩阵不能太大，所以模糊的比较小，效果如下  
![](gaussianBlue.png)  
```
boxFilter(image,out,-1,Size(10,10));
blur(image,out1,Size(10,10));
GaussianBlur(image,out2,Size(5,5),0,0);
```
* 中值滤波，孔径越大，图像越模糊，孔径大小只能选择奇数`medianBlur(image,out3,9);`
![](median.png)
* 双边滤波器，能滤掉噪点并保存边缘信息，但高频噪点不能很好的滤掉`bilateralFilter(image,out4,25,25*2,25/2);`  
![](bf.png)

* 掩码拷贝，掩码图像就是一个矩阵数据。里面有Width*Height个数据。像素值为0表示这点像素不处理，为1表示要处理。 `image.copyTo(out,dstImage);`  

![](canny.png)  
图1为image，图2为dstImage，图3为out，dstImage为掩码图，掩码图中像素为0，即黑色部分不处理。
* `int cvRound (double value)`
对一个`double`型的数进行四舍五入，并返回一个整型数！  
函数 `cvRound, cvFloor, cvCeil` 用一种舍入方法将输入浮点数转换成整数。 `cvRound `返回和参数最接近的整数值。 `cvFloor`返回不大于参数的最大整数值。  
`cvCeil` 返回不小于参数的最小整数值。在某些体系结构中该函数 工作起来比标准 C 操作起来还要快。
* `convertScaleAbs`先缩放元素再取绝对值，最后转换格式为8bit型
* getAffineTransform函数  
函数作用：主要用于生成仿射变换矩阵  
一个任意的仿射变换都能表示为乘以一个矩阵(线性变换)接着再加上一个向量 (平移).  
综上所述, 我们能够用仿射变换来表示:  
`旋转 (线性变换)`  
`平移 (向量加)`  
`缩放操作 (线性变换)`  
我们通常使用2x3矩阵来表示仿射变换.

   







