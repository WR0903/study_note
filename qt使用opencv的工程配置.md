#qt使用opencv的工程配置

* 2.4.9版本
```

INCLUDEPATH += /usr/local/include \
                        /usr/local/include/opencv2 \
                        /usr/local/include/opencv

LIBS +=  /usr/local/lib/libopencv_core.so.2.4.9 \
                /usr/local/lib/libopencv_highgui.so.2.4.9 \
                /usr/local/lib/libopencv_imgproc.so.2.4.9
```
* 3.1版本
```
INCLUDEPATH += /usr/local/include
LIBS += /usr/local/lib/libopencv_*.so
```
