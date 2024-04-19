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


private:
	void paintEvent(QPaintEvent* event);
};