#include "mainwindow.h"
#include <QApplication>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



      QPixmap pixmap("1.png");
      QSplashScreen splash(pixmap);
      splash.show();
      for(long index=0;index<=900000000;index++)
      {
         //for(int j=0;j<=9000000;j++);
//         {
//             for(int z=0;z<=9000000;z++);
//         }
      }
      MainWindow w;
      w.show();
      splash.finish(&w);


    return a.exec();
}
