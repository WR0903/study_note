# 检测二维码的ros功能包
**功能描述**
该功能包通过订阅/image_raw话题，然后应用ARToolKitPlus库检测图像中的二维码，并通过/PoseStamped_mark话题发布相机相对二维码的位置。
**使用说明**
* 安装uvc camera功能包 `sudo apt-get install ros-kinetic-uvc-camera`
* 安装image相关功能包 `sudo apt-get install ros-kinetic-image-*` `sudo apt-get install ros-kinetic-rqt-image-view`
* 安装ARToolKitPlus
* 运行
```
roscore
rosrun uvc_camera uvc_camera_node
rosrun markerid marker 
rostopic echo /PoseStamped_mark 
```
