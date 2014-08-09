#ifdef WIN32
	#include <windows.h>
	#include <time.h>
#endif

#ifdef linux
	#include <stdio.h>
	#include <sys/time.h>
	#include <time.h>
#endif
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <cmath>
#include "hough.h"

using namespace cv;
using namespace std;



int main( int argc, char** argv )
{
	/*
	�������������� ���� ������������ �� ������������� �������� ������� � ���� ���������������� ���������. 
	��������� ����� ��������� ������������ ������� ������������ (�.�. �������������� ������/������������, ������������ ����). 
	�����, ������ �������� ����������� (��������, ��������� ������ ��������� ������ �����). 
	������������ ��� ����� ������ � �������� �������������, ��� ����� ����������� ����� �������� ������� � �.�. 
	��� ������ ����� ����������� �������������� ������ ��������� � ���������� ����������� ���������, 
	������� ����������� � ������������ ����. ��������� ����� �������� ����� ������������ ���� � ����� ������������ ��������, 
	�� ������� �������������� ������ ����� �������� ��������, ��� � ���� ��������� ��� ��������� �������� �������.
	*/
	houghLineTransform("C:\\Users\\vpopov\\Desktop\\lena.jpg");

	waitKey();

    return 0;
}