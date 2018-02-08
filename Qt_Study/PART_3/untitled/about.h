#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>
#include <QMovie>
#include <QtDebug>

namespace Ui {
class about;
}

class about : public QDialog
{
    Q_OBJECT

public:
    explicit about(QWidget *parent = 0);
    ~about();

private:
    Ui::about *ui;
    QMovie *Movie;
private slots:
    void startMovieSlot();
    void stopMovieSlot();
};

#endif // ABOUT_H
