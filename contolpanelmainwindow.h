//
// Created by Elena on 23.07.2022.
//

#ifndef CONTROLPANEL_CONTOLPANELMAINWINDOW_H
#define CONTROLPANEL_CONTOLPANELMAINWINDOW_H

#include "QMainWindow"
#include <QtWidgets/QLabel>
#include <QPushButton>
#include <QTime>
#include <QDate>

class ControlPanelMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    ControlPanelMainWindow(QWidget* parent = nullptr): QMainWindow(parent) {}
    QLabel* label = nullptr;

    double setVolume(double& volumeTmp)
    {
        if(volumeTmp < 0) return volumeTmp = 0;
        else return volumeTmp;
    }

private:
    QPushButton* button = nullptr;
    QString str, date, currentTime;
    double num, volume = 0;
    bool pressedDateTime = true;

public slots:

    void pushButton_0()
    {
        label->setText("00 channel");
        button = (QPushButton*) sender();
        num = (button->text().toDouble());
        pressedDateTime = true;
    };

    void pushButton_1()
    {
        label->setText("01 channel");
        button = (QPushButton*) sender();
        num = (button->text().toDouble());
        pressedDateTime = true;
    };

    void pushButton_2()
    {
        label->setText("02 channel");
        button = (QPushButton*) sender();
        num = (button->text().toDouble());
        pressedDateTime = true;
    };

    void pushButton_3()
    {
        label->setText("03 channel");
        button = (QPushButton*) sender();
        num = (button->text().toDouble());
        pressedDateTime = true;
    };

    void pushButton_4()
    {
        label->setText("04 channel");
        button = (QPushButton*) sender();
        num = (button->text().toDouble());
        pressedDateTime = true;
    };

    void pushButton_5()
    {
        label->setText("05 channel");
        button = (QPushButton*) sender();
        num = (button->text().toDouble());
        pressedDateTime = true;
    };

    void pushButton_6()
    {
        label->setText("06 channel");
        button = (QPushButton*) sender();
        num = (button->text().toDouble());
        pressedDateTime = true;
    };

    void pushButton_7()
    {
        label->setText("07 channel");
        button = (QPushButton*) sender();
        num = (button->text().toDouble());
        pressedDateTime = true;
    };

    void pushButton_8()
    {
        label->setText("08 channel");
        button = (QPushButton*) sender();
        num = (button->text().toDouble());
        pressedDateTime = true;
    };

    void pushButton_9()
    {
        label->setText("09 channel");
        button = (QPushButton*) sender();
        num = (button->text().toDouble());
        pressedDateTime = true;
    };

    void pushButton_plus()
    {
        volume += 0.1;

        if (volume >= 2)
        {
            label->setText("*** maximum\nvolume ***");
        }
        else {
            //преобразует значение громкости из типа double в тип string, и сохраняет его в str
            str = QString::number(setVolume(volume));
            label->setText(str + " volume");
        }
    };

    void pushButton_minus()
    {
        volume -= 0.1;

        if (volume <= 0)
        {
            label->setText("*** volume down ***");
        }
        else
        {
            str = QString::number(setVolume(volume));
            label->setText(str + " volume");
        }
    };

    void pushButton_time()
    {
        if (pressedDateTime)
        {
            QDate cd = QDate::currentDate();
            QTime ct = QTime::currentTime();
            date = cd.toString();
            currentTime = ct.toString();
            label->setText(label->text() + '\n' + date + '\n' +  currentTime);
            pressedDateTime = false;
        }
    };

    void pushButton_next()
    {
        if (num == 9) num = -1;
        label->setText(label->text());
        str = QString::number(++num, 'g', 13);
        label->setText("0" + str + " channel");
        pressedDateTime = true;
    };

    void pushButton_previous()
    {
        if (num == 0) num = 10;
        label->setText(label->text());
        str = QString::number(--num, 'g', 13);
        label->setText("0" + str + " channel");
        pressedDateTime = true;
    };

    void pushButton_power()
    {
        close();
    };
};
#endif //CONTROLPANEL_CONTOLPANELMAINWINDOW_H
