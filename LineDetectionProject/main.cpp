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
	Преобразование Хафа основывается на представлении искомого объекта в виде параметрического уравнения. 
	Параметры этого уравнения представляют фазовое пространство (т.н. аккумуляторный массив/пространство, пространство Хафа). 
	Затем, берётся двоичное изображение (например, результат работы детектора границ Кенни). 
	Перебираются все точки границ и делается предположение, что точка принадлежит линии искомого объекта — т.о. 
	для каждой точки изображения рассчитывается нужное уравнение и получаются необходимые параметры, 
	которые сохраняются в пространстве Хафа. Финальным шагом является обход пространства Хафа и выбор максимальных значений, 
	за которые «проголосовало» больше всего пикселей картинки, что и дает параметры для уравнений искомого объекта.
	*/
	houghLineTransform("C:\\Users\\vpopov\\Desktop\\lena.jpg");

	waitKey();

    return 0;
}