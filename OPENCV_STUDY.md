# opencv_study

* 腐蚀操作，效果局部变黑
```
Mat element=getStructuringElement(MORPH_RECT,Size(15,15));//获得结构元素内核矩阵
erode(I,D,element);
```

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
* 方框滤波，内核矩阵越大图像越模糊


![](picture/1.jpg)










