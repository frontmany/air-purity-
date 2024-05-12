#include <QWidget>
#include <qlayout.h>
#include "qmenu.h"
#include "qpainter.h"
#include <QpaintEvent>
#include <QStyleOption>
#include <Qlabel>
#include <QVboxLayout>
#include <QHboxLayout>
#include <QPushbutton>
#include <QMenu>
#include <QScrollArea>
#include <QStyledItemDelegate>
#include <QStringLiteral>
#include <QPixmap>

class MainWindow;

class CentralWidget : public QWidget {
public:
	CentralWidget(QWidget* parent,  MainWindow* mainwindow);
	~CentralWidget();

	void comboBoxChanged(const QString&);
	
public:
	QString labelStyle = ("QLabel{ color:rgb(93, 145, 201);  background-color:rgb(34, 34, 34); font-family: Arial; font-size: 20px;font-weight: bold;padding: 5px;border-radius: 5px;}");


private:
	void paintEvent(QPaintEvent* event);
};