// 概要      : 文字伝達実験（カメラ）
// File Name : code.cpp
// Library   : OpenCV 2.0
//---------------------------------------------------------

#include <stdio.h>
#include <highgui.h>
#include <cv.h>

#pragma comment (lib,"cv200d.lib")
#pragma comment (lib,"cxcore200d.lib")
#pragma comment (lib,"highgui200d.lib")


int main( int argc, char** argv ){ 
	int key;					//	キー入力用の変数
	CvCapture *capture;				//	カメラキャプチャ用の構造体
	IplImage *frameImage;				//	キャプチャ画像用IplImage
	char windowNameCapture[] = "Capture";			//キャプチャした画像を表示するウィンドウの名前
	int x, y;
	int m,d,ss;
	uchar b0,g0,r0,b1,g1,r1,b2,g2,r2,b3,g3,r3,s;

	//	カメラを初期化する
	if ( ( capture = cvCreateCameraCapture( 0 ) ) == NULL ) {
		//	カメラが見つからなかった場合
		printf( "カメラが見つかりません\n" );
		key = cvWaitKey( 10 );
	}

	//	ウィンドウを生成する
    cvNamedWindow( windowNameCapture, CV_WINDOW_AUTOSIZE );

	m=0;
	d=0;
	ss=0;
	//	メインループ
	while ( 1 ) {
		//	カメラからの入力画像フレームをframeImageに格納する
		frameImage = cvQueryFrame( capture );

      /* 画素値を直接操作する一例*/   
		x = 160;
		y = 120;

		b0 = frameImage ->imageData[frameImage ->widthStep * y + x * 3];        // B
		g0 = frameImage ->imageData[frameImage ->widthStep * y + x * 3 + 1];    // G      
		r0 = frameImage ->imageData[frameImage ->widthStep * y + x * 3 + 2];    // R

    	     frameImage->imageData[frameImage->widthStep * y+ x * 3] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 1] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 2] = 200;

		x = 161;
		y = 120;
		b1 = frameImage ->imageData[frameImage ->widthStep * y + x * 3];        // B
		g1 = frameImage ->imageData[frameImage ->widthStep * y + x * 3 + 1];    // G      
		r1 = frameImage ->imageData[frameImage ->widthStep * y + x * 3 + 2];    // R

        	    frameImage->imageData[frameImage->widthStep * y+ x * 3] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 1] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 2] = 200;

		x = 160;
		y = 121;

		b2 = frameImage ->imageData[frameImage ->widthStep * y + x * 3];        // B
		g2= frameImage ->imageData[frameImage ->widthStep * y + x * 3 + 1];     // G      
		r2 = frameImage ->imageData[frameImage ->widthStep * y + x * 3 + 2];    // R

       	    frameImage->imageData[frameImage->widthStep * y+ x * 3] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 1] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 2] = 200;


		x = 161;
		y = 121;
		b3 = frameImage ->imageData[frameImage ->widthStep * y + x * 3];        // B
		g3 = frameImage ->imageData[frameImage ->widthStep * y + x * 3 + 1];    // G      
		r3 = frameImage ->imageData[frameImage ->widthStep * y + x * 3 + 2];    // R

        	    frameImage->imageData[frameImage->widthStep * y+ x * 3] = 200;
     	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 1] = 200;
	    frameImage->imageData[frameImage->widthStep * y + x * 3 + 2] = 200;

		s=(b0+g0+r0+b1+g1+r1+b2+g2+r2+b3+g3+r3)/12;

		if (s<200) {
			
			if(m==0)
				ss=1;
		
			if(ss)
				m=m+1;	
			printf("0 m= %d,d=%02X  \n",m,d);
		}
		else {
//			printf("%d \n",m);			
	
			if(ss){
				d=d+(1<<(m-1));
				m=m+1;}
			printf("1 m= %d,d=%02X  \n",m,d);
			
			
		}

		if(m>8){
		printf("コード　d= %c   \n",d);



			m=0;
			d=0;
			ss=0;
		}



		//	画像を表示する
		cvShowImage( windowNameCapture, frameImage );
	
		//	'q'キーが入力されたらループを抜ける
		key = cvWaitKey( 10 );
		if ( key == 'q' ) 
			break;

//		printf ("%d \n",s);

	}
	
	//	キャプチャを解放する
	cvReleaseCapture( &capture );
	//	ウィンドウを破棄する
	cvDestroyWindow( windowNameCapture );

	return 0;
}
