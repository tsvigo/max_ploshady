#include "dialog.h"
#include "ui_dialog.h"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::Dialog
/// \param parent
///.
/// 
#include <fstream>
#include <iostream>
#include <QFile>
#include <QTextStream>
//#include <TextArray>


#include <QList>
#include <QDebug>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// . 
Dialog::Dialog(QWidget *parent)
     : QDialog(parent)
     , ui(new Ui::Dialog)
     {
          ui->setupUi(this);
////////////////////////////////////////////// загрузка нейронов и сигнала из файла в вектор ///////////////////////////////////////////////////////////////////////////////////////
    std::ifstream is(
        
 "/home/viktor/высоты.txt"

        );
    std::istream_iterator<unsigned long long> start(is), end;
    std::vector<int> list_of_visot(start, end); 
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////  
////////////////////////////////////////////// загрузка нейронов и сигнала из файла в вектор ///////////////////////////////////////////////////////////////////////////////////////
    std::ifstream is2(
        
 "/home/viktor/ширины.txt"

        );
    std::istream_iterator<unsigned long long> start2(is2), end2;
    std::vector<int> list_of_shirin(start2, end2); 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
/// 


//int main() {
    QFile file("/home/viktor/my_projects_qt_2/kartinki_iz_shriftov/papka-fonts-sort/obrez_snizu/polniy_obrez/black-white/ploshdi.txt");
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        for (int i = 0; i < 1422; ++i) {
            out <<list_of_shirin[i]*list_of_visot[i] << "\n";
        }
        file.flush();
        file.close();
//    }
//    return 0;
}

/// 
/// 
//QFile file("out.txt");
//if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
//    return;
// QVector<QString> TextArray;
//QTextStream out(&file);
//for (const QString& str : TextArray)
//    out << list_of_visot[] << "\n";
    
//    for (int x=0;x<1422 ;x++ )
//     {
              
//         }        
     }

Dialog::~Dialog()
     {
          delete ui;
     }


void Dialog::on_pushButton_clicked()
{    QFile file("/home/viktor/my_projects_qt_2/kartinki_iz_shriftov/papka-fonts-sort/obrez_snizu/polniy_obrez/black-white/ploshdi.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        QList<int> numbers;
        int num;
        while (!in.atEnd()) {
            in >> num;
            if (in.status() == QTextStream::Ok) {
                numbers.append(num);
            }
        }
        file.close();
        int max = numbers.first();
        for (int i = 1; i < numbers.size(); i++) {
            if (numbers[i] > max) {
                max = numbers[i];
            }
        }
        qDebug() << "The largest number is:" << max;
    } else {
        qDebug() << "Could not open file.";
    }
}


void Dialog::on_pushButton_2_clicked()
{
     QFile file("/home/viktor/my_projects_qt_2/kartinki_iz_shriftov/papka-fonts-sort/obrez_snizu/polniy_obrez/black-white/ploshdi.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        QList<int> numbers;
        int num;
        while (!in.atEnd()) {
            in >> num;
            if (num > 201) {
              //  numbers.append(num);
                   numbers.append(num);
            }
        }
        file.close();

        qDebug() << "Numbers greater than 201:";
        for (int i = 0; i < numbers.size(); i++) {
           qDebug() << numbers[i];
           // qDebug() << i;
        }
    } else {
        qDebug() << "Could not open file.";
    }
}


void Dialog::on_pushButton_3_clicked()
{

QList<int> indices={};
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
          /// \brief file
          ///.
    QFile file("/home/viktor/my_projects_qt_2/kartinki_iz_shriftov/papka-fonts-sort/obrez_snizu/polniy_obrez/black-white/ploshdi.txt");
    if (file.open(QIODevice::ReadOnly)) {
        QTextStream in(&file);
        QList<int> numbers;
      //  QList<int> indices;
        int num;
        int index = 0;
        while (!in.atEnd()) {
            in >> num;
            if (num > 201) {
                numbers.append(num);
                indices.append(index);
            }
            index++;
        }
        file.close();

        qDebug() << "Numbers greater than 201 and their indices:";
        for (int i = 0; i < numbers.size(); i++) {
            qDebug() << "Index:" << indices[i] << " Number:" << numbers[i];
        }
    } else {
        qDebug() << "Could not open file.";
    }

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
   int size = sizeof(indices);// / sizeof(indices[0]);

    QFile file2("/home/viktor/my_projects_qt_2/kartinki_iz_shriftov/papka-fonts-sort/obrez_snizu/polniy_obrez/black-white/список индексов площадей больше 201.txt");
    if (file2.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file2);
        
        for (int i = 0; i < size; i++) {
            out << indices[i] << "\n";
        }

        file2.close();
        qDebug() << "Array saved to file.";
    } else {
        qDebug() << "Could not open file for writing.";
    }  
///  
}

