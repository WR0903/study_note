#include "mainwindow.h"
#include "ui_mainwindow.h"

QString str;
static int m_read;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    time1 = new QTimer(this);
    connect(time1, SIGNAL(timeout()), this, SLOT(uplable()));
    time1->start(10);
    //ui->label->setText(str);
    this->duqu();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void* thread1(void *ptr)
{

    QFile file("/home/wr/桌面/ss.txt");
    int m_h=0;//
    while(1)
    {
        if(!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            qDebug()<<"Can't open the file!"<<endl;
        }

        while(!file.atEnd())
        {
            QByteArray line = file.readLine();
            m_h++;
            if(m_h==m_read)
            {
                str=QString(line);
                qDebug()<< str;

                m_read++;

            }
        }
        m_h=0;
        file.close();
    }


    return 0;
}

void MainWindow::duqu()
{

    m_read=1;



    pthread_t id;
    int ret;
    ret = pthread_create(&id, NULL, thread1, NULL);
    if(ret) {
        cout << "Create pthread error!" << endl;
        return ;
    }
    //pthread_join(id, NULL);//等待线程结束
}
void MainWindow::uplable()
{
    ui->label->setText(str);
    const char* msg="qeqe";
    QFile file1("/home/wr/桌面/ss.txt");
    if(!file1.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }
    file1.write(msg, qstrlen(msg));
    file1.close();
}
