显示图片
```c++
Mat img = imread("1.jpg");
imshow("Before", img);
```
腐蚀操作
```c++
Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
Mat dstImage;
erode(img, dstImage, element);
```
图像模糊
```
	blur(img, dstImage, Size(7, 7));
```
边缘检测
```c++
	/*检测边缘*/
	Mat edge, grayImage;
	cvtColor(img, grayImage, CV_BGR2GRAY);//将原图转换为灰度图
	blur(grayImage, edge, Size(3, 3));//使用3x3内核降噪
	Canny(edge, edge, 3,9,3);//运行Canny算子
```
![边缘检测](https://github.com/Joki-memeda/MyLearning/blob/master/opencv/part1/%E8%BE%B9%E7%BC%98%E6%A3%80%E6%B5%8B.png)
