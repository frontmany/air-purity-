#include <QToolBar>
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
#include <QDockWidget>

class MainWindow;

class ResultSearchWidget : public QWidget {

public:
	ResultSearchWidget(QWidget* parent, MainWindow* mainwindow);
	~ResultSearchWidget();

public:

	double co_2 = 0;
	int mark = 0;
	QString description;

private:
	void paintEvent(QPaintEvent* event);
};