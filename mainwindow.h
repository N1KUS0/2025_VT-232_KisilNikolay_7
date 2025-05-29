#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "chair.h"
#include "table.h"
#include "smartptr.h"
#include <vector>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addChair();
    void addTable();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    std::vector<smart_ptr<Furniture>> furnitureList;
    void saveToFile(const QString& filename);
    void loadFromFile(const QString& filename);

};

#endif // MAINWINDOW_H
