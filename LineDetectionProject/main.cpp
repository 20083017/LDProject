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
#include "lsd.h"
#include "pgm.h"
#include "lsd_cmd.cpp"

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
	houghLineTransform("C:\\Users\\vpopov\\Desktop\\lena1.jpg");

	/*Mat img = imread("C:\\Users\\vpopov\\Desktop\\lena1.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	namedWindow("ok");
	imshow("ok",img);*/

	int X = 512;
	int Y = 512;
	int i,j,n;
	
	double* out;
	double* image = read_pgm_image_double(&X, &Y,"C:\\Users\\vpopov\\Desktop\\lena1.pgm");

	if(image == NULL) {
		fprintf(stderr,"error: not enough memory\n");
	}
	out = lsd(&n,image,X,Y);

	Mat baseImg = imread("C:\\Users\\vpopov\\Desktop\\lena1.pgm", CV_LOAD_IMAGE_GRAYSCALE);

	/* print output */
    printf("%d line segments found:\n",n);
    for(i = 0; i < n - 2; i++) {
      for( j = 0; j < 7; j++){

		  printf("%f ",out[7*i+j]);

		  if((i + j) % 2 == 0) {
			
			  int x1 = out[7*i+j];
		      int y1 = out[7*i+j + 1];

			  int x2 = out[7*i+j + 2];
			  int y2 = out[7*i+j + 3];

			  line(baseImg, Point(x1,y1), Point(x2,y2), Scalar(0,200,0),1,4);

		  }
          printf("\n");
	  }
    }

	namedWindow("drawing", CV_WINDOW_AUTOSIZE|CV_WINDOW_FREERATIO);
    imshow("drawing", baseImg);

    /* free memory */
    free( (void *) image );
    free( (void *) out );

	waitKey();


    return 0;
}