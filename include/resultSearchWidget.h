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
#include <QProgressBar>
#include <QtCharts/QLineSeries>
#include <QtCharts/QValueAxis>
#include <QAbstractAxis>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <vector>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <vector>




class MainWindow;
class Buttons;

class ResultSearchWidget : public QWidget {

public:
	ResultSearchWidget(QWidget* parent, MainWindow* mainwindow);
	ResultSearchWidget(std::vector<QString> calculatorData, MainWindow* mainwindow);
	~ResultSearchWidget();

public:

	double co_2_value = 0;
	double dust_value = 0;
	int mark = 0;
	int body_count;
	QString month;
	QString building;
	double real_co2;
	std::vector<double> allco2vec;
	std::vector<QString> calculator_data;
	
	QBarSet* set;
	Buttons* ButtonWidget;
private:
	void paintEvent(QPaintEvent* event);

};