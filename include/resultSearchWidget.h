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
	ResultSearchWidget(std::vector<QString> calculatorData, std::vector<QString> calculatorData2, MainWindow* mainwindow);
	~ResultSearchWidget();

public:
	QString labelStyle = ("QLabel{ color:rgb(93, 145, 201);  background-color:rgb(30, 30, 30); font-family: Arial; font-size: 14px;font-weight: bold;padding: 5px;border-radius: 5px;}");
	double co_2_value = 0;
	double dust_value = 0;
	int mark = 0;
	int body_count;
	QString month;
	QString building;
	double real_co2;
	std::vector<double> allco2vec;
	std::vector<double> alldustvec;
	std::vector<QString> calculator_data;
	
	std::vector<double> allco2vecn{0,0,0,0,0,0,0,0,0,0};

	QBarSet* set;
	QBarSet* set2;
	Buttons* ButtonWidget;
private:
	void paintEvent(QPaintEvent* event);

};