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
