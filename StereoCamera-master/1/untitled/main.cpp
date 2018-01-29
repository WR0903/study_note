#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
    Mat srcimage,left,right;

    string rgbExt=".png";
    string rgbDir_l="left_";
    string rgbDir_r="right_";
    string filename;
    string filename_l;
    string filename_r;
    for(int imageCount = 20;imageCount<=39;imageCount++)
    {
        stringstream ss;
        stringstream ss_l;
        stringstream ss_r;
        ss<<imageCount<<rgbExt;
        ss>>filename;
        srcimage=imread(filename);
        ss<<rgbExt;
        ss>>filename;
        left=srcimage(Range(0,720),Range(0,1281));
        right=srcimage(Range(0,720),Range(1281,2560));
        ss_l<<rgbDir_l<<imageCount<<rgbExt;
        ss_l>>filename_l;
        imwrite(filename_l,left);
        ss_r<<rgbDir_r<<imageCount<<rgbExt;
        ss_r>>filename_r;
        imwrite(filename_r,right);
       // imageCount++;
     }
    cout << "Hello World!" << endl;
    return 0;
}
