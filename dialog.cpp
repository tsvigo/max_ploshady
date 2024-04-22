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
#include <QDir>



#include <QStringList>

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


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// \brief Dialog::on_pushButton_4_clicked
///.
/// 
void deleteFilesByIndices(const QString &indicesFile, const QString &filesFile) {
    QFile indices(indicesFile);
    if (!indices.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&indices);
    QStringList indicesList = in.readAll().split('\n', QString::SplitBehavior::SkipEmptyParts);
    indicesList.removeDuplicates();

    QFile files(filesFile);
    if (!files.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream filesIn(&files);
    QStringList filesList = filesIn.readAll().split('\n', QString::SplitBehavior::SkipEmptyParts);
    filesList.removeDuplicates();

    for (const QString &index : indicesList) {
        int idx = index.toInt();
        if (idx >= 0 && idx < filesList.size()) {
            QFile::remove(filesList[idx]);
        }
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// . 
/// 
 void getStringsByIndices(const QString &indicesFile, const QString &stringsFile) {
    QFile indices(indicesFile);
    if (!indices.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in(&indices);
    QStringList indicesList = in.readAll().split('\n', QString::SplitBehavior::SkipEmptyParts);

    QFile strings(stringsFile);
    if (!strings.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream stringsIn(&strings);
    QStringList stringsList = stringsIn.readAll().split('\n', QString::SplitBehavior::SkipEmptyParts);

    for (const QString &index : indicesList) {
        int idx = index.toInt();
        QString full_path;
        if (idx >= 0 && idx < stringsList.size()) {
            QString str = stringsList[idx];
            // Do something with the string
            qDebug() << "String with index" << idx << "is" << str;
            full_path="/home/viktor/my_projects_qt_2/kartinki_iz_shriftov/papka-fonts-sort/obrez_snizu/polniy_obrez/black-white/"
            +
            str;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    QFile file(full_path);

    if (file.exists()) {
        if (file.remove()) {
            qDebug() << "File deleted successfully.";
        } else {
            qDebug() << "Failed to delete the file.";
        }
    } else {
        qDebug() << "File does not exist.";
    }
///             
        }
    }
}
///
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// / 
void Dialog::on_pushButton_4_clicked()
{
//#include <QFile>
//#include <QTextStream>
//#include <QStringList>
getStringsByIndices("/home/viktor/my_projects_qt_2/kartinki_iz_shriftov/papka-fonts-sort/obrez_snizu/polniy_obrez/black-white/список индексов площадей больше 201.txt",
 "/home/viktor/my_projects_qt_2/kartinki_iz_shriftov/papka-fonts-sort/obrez_snizu/polniy_obrez/black-white/spisok.txt");


}

