#include "block.h"

#define BLOCK_WIDTH 400
#define BLOCK_HEIGHT 70

#include <QMouseEvent>
#include <QLabel>
#include <QLayout>

#include "additionqt.h"


const QString fontFormat = "<font color=#8D96A7 size=40 face=Arial>";

Block::Block(QWidget *parent)
    : QGroupBox(parent)
{
    //Инициализируем переменные
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    titleLabel = new QLabel(this);
    settingsButton = new QPushButton(this);
    closeButton = new QPushButton(this);

    //qDebug() << algo << endl;

    //Настраиваем элементы
    setFixedSize(BLOCK_WIDTH, BLOCK_HEIGHT);

    settingsButton->setText("Settings..");
    closeButton->setText("Close");

    //Красим фон

    //Заполняем блок элементами
    hLayout->addWidget(titleLabel);
    hLayout->addWidget(settingsButton);
    hLayout->addWidget(closeButton);
    setLayout(hLayout);

    //Соединяем сигналы и слоты
    connect(settingsButton, SIGNAL(clicked()), this, SLOT(onSettingsButtonClicked()));
    connect(closeButton, SIGNAL(clicked()), this, SLOT(onBlockClose()));

}

void Block::setAlgorithm(Algorithm *_algo)
{
    algo = _algo;
    setTitle(algo->getName());
}

Block::~Block()
{
    delete algo;
}

void Block::doAlgorithm()
{
    if(algo == NULL){
        qDebug() << "Block::doAlgo: algo == NULL";
        return;
    }
    algo->mainAlgorithm();
}

void Block::onSettingsButtonClicked()
{
    if(settingsDialog == NULL){
        qDebug() << "onSettingsButtonClicked: settingsDialog == NULL";
        return;
    }
    settingsDialog->show();
}

void Block::onBlockClose()
{
    emit closeMeManager(this);
}

void Block::setTitle(QString title)
{
    titleLabel->setText(fontFormat + title);
}

void Block::setSettingsDialog(QDialog *_settingsDialog)
{
    settingsDialog = _settingsDialog;
}
