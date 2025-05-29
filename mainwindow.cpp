#include <QGraphicsTextItem>
#include <QJsonArray>
#include <QJsonObject>
#include <QFile>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    connect(ui->btnAddChair, &QPushButton::clicked, this, &MainWindow::addChair);
    connect(ui->btnAddChair_2, &QPushButton::clicked, this, &MainWindow::addTable);
    connect(ui->btnSave, &QPushButton::clicked, this, [this]() {
        saveToFile("furniture.json");
    });
    connect(ui->btnLoad, &QPushButton::clicked, this, [this]() {
        loadFromFile("furniture.json");
    });

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::addChair() {
    auto chair = new Chair(QPoint(50, 50), QSize(60, 60));
    scene->addRect(QRect(chair->getPosition(), chair->getSize()));
    scene->addText("Chair")->setPos(chair->getPosition() + QPoint(5, 5));
    furnitureList.push_back(smart_ptr<Furniture>(chair));
}

void MainWindow::addTable() {
    auto table = new Table(QPoint(100, 100), QSize(80, 80));
    scene->addRect(QRect(table->getPosition(), table->getSize()), QPen(Qt::blue));
    scene->addText("Table")->setPos(table->getPosition() + QPoint(5,5));
    furnitureList.push_back(smart_ptr<Furniture>(table));
}


void MainWindow::saveToFile(const QString& filename) {
    QJsonArray array;
    for (const auto& item : furnitureList) {
        QJsonObject obj;
        obj["type"] = "Chair"; // Пока только стулья
        obj["x"] = item->getPosition().x();
        obj["y"] = item->getPosition().y();
        obj["width"] = item->getSize().width();
        obj["height"] = item->getSize().height();
        array.append(obj);
    }

    QJsonDocument doc(array);
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
    }
}

void MainWindow::loadFromFile(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) return;

    QByteArray data = file.readAll();
    file.close();

    QJsonDocument doc = QJsonDocument::fromJson(data);
    if (!doc.isArray()) return;

    scene->clear();
    furnitureList.clear();

    QJsonArray array = doc.array();
    for (const QJsonValue& value : array) {
        QJsonObject obj = value.toObject();
        QString type = obj["type"].toString();
        QPoint pos(obj["x"].toInt(), obj["y"].toInt());
        QSize size(obj["width"].toInt(), obj["height"].toInt());

        if (type == "Chair") {
            auto* chair = new Chair(pos, size);
            scene->addRect(QRect(pos, size));
            scene->addText("Chair")->setPos(pos + QPoint(5, 5));
            furnitureList.push_back(smart_ptr<Furniture>(chair));
        } else if (type == "Table") {
            auto* table = new Table(pos, size);
            scene->addRect(QRect(pos, size), QPen(Qt::blue));
            scene->addText("Table")->setPos(pos + QPoint(5, 5));
            furnitureList.push_back(smart_ptr<Furniture>(table));
        }

    }
}

