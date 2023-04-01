#include<opencv2/opencv.hpp>
#include<iostream>
#include<Windows.h>
#include<string>
#include<math.h>

std::string s = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:.\"^`'  ";

int PrintStringGama(cv::Mat img,double dp,double h)
{
	std::string s = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/\\|()1{}[]?-_+~<>i!lI;:.\"^`'  ";
	int Xlength = img.rows;//892
	int Ylength = img.cols;
	cv::Vec3b pixel;
	for (int i = 0; i < Xlength; i += (Xlength / 58))
	{
		for (int j = 0; j < Ylength / 3; j += (int)(Ylength / 3 / 115 * h))
		{
			pixel = img.at<cv::Vec3b>(i, j);
			//std::cout << "\n" << i << " " << j;
			double gama = 255 * pow(pixel[0] / 255.0, dp);
			//int gama = pixel[0] * pow(1, pixel[0] / 255);
			//int gama = pixel[0];
			int value = (int)gama / 3.6;

			std::cout << s[value];
		}
		std::cout << "\n";
	}
	return 1;
}

int SearchEdge(cv::Mat img,int w)
{
	int Xlength = img.rows;
	int Ylength = img.cols;
	cv::Vec3b pixel,pixelLast;
	for (int i = 0; i < Xlength-1; i ++)
	{
		for (int j = 0; j < Ylength/3-1; j ++)
		{
			pixelLast = img.at<cv::Vec3b>(i, j);
			pixel = img.at<cv::Vec3b>(i+1, j+1);
			if (pixel[0]-pixelLast[0]>w)
			{
				pixelLast[0] = 255;
			}
			else
			{
				pixelLast[0] = 0;
			}
		}
		//
	}
	cv::imshow("windwos", img);
	cv::waitKey(0);
	return 1;
}

int main()
{
	//char s[10] = {};
	char str[] = "color F0";    //实现控制台变色，先背景后字，具体值查表
	system(str);
	
	cv::Mat simg = cv::imread("video0000.jpg", 1);
	cv::Mat img;
	cv::cvtColor(simg, img, CV_BGR2GRAY);
	int Xlength = img.rows;//892
	int Ylength = img.cols;
	std::cout <<"分辨率:"<< Xlength << "x" << Ylength<<"\n";
	cv::imshow("windwos", img);
	cv::waitKey(0);
	PrintStringGama(img, 0.3, 1);
	SearchEdge(img, 50);
	cv::Vec3b pixel, pixelLast;
	for (int i = 0; i < Xlength - 1; i++)
	{
		for (int j = 0; j < Ylength/3 - 1; j++)
		{
			//pixelLast = img.at<cv::Vec3b>(i, j);
			//img.at<cv::Vec3b>(i, j)[0] = 0;
			//pixel = img.at<cv::Vec3b>(i + 1, j + 1);
			if (abs(img.at<cv::Vec3b>(i+1, j+1)[0] - img.at<cv::Vec3b>(i, j)[0]) > 10)
			{
				img.at<cv::Vec3b>(i, j)[0] = 0;
				img.at<cv::Vec3b>(i, j)[1] = 255;
				img.at<cv::Vec3b>(i, j)[2] = 255;
			}
			else
			{
				img.at<cv::Vec3b>(i, j)[0] = 255;
				img.at<cv::Vec3b>(i, j)[1] = 255;
				img.at<cv::Vec3b>(i, j)[2] = 255;
				
			}
			//pixelLast[0] = 255;
		}
		//
	}
	cv::namedWindow("输出图像-2", CV_WINDOW_AUTOSIZE);
	cv::imshow("输出图像-2", img);
	
	cv::waitKey(0);











	//cv::Vec3b pixel;
	////(891,1181)
	////for (int i = 0; i < 396; i++)
	////{
	////	pixel = img.at<cv::Vec3b>(0, i);

	////}
	//double dp = 0;//伽马矫正系数
	//int h = 1;
	//while (1) 
	//{
	//	std::cout << "请输入伽马矫正系数:\n";
	//	std::cin >> dp;
	//	std::cout << "输入横向缩放系数:\n";
	//	std::cin >> h;
	//	for (int i = 0; i < Xlength; i += (Xlength / 58))
	//	{
	//		for (int j = 0; j < Ylength / 3; j += (int)(Ylength / 3 / 115*h))
	//		{
	//			pixel = img.at<cv::Vec3b>(i, j);
	//			//std::cout << "\n" << i << " " << j;
	//			double gama = 255 * pow(pixel[0] / 255.0, dp);
	//			//int gama = pixel[0] * pow(1, pixel[0] / 255);
	//			//int gama = pixel[0];
	//			int value = (int)gama / 3.6;

	//			std::cout << s[value];
	//		}
	//		std::cout << "\n";
	//	}
	//	system("pause");
	//}
	return 0;
}