#include "resultSearchWidget.h"
#include "mainwindow.h"
#include "calculator.h"
#include <buttonswidget.h>


void ResultSearchWidget::paintEvent(QPaintEvent* event) {
	QColor color1(30, 30, 30);
	QColor color2(34, 34, 34);
	QColor color3(209, 222, 240);

	QStyleOption opt;
	opt.initFrom(this);

	QPainter painter(this);
	QPen pen(color1);
	pen.setWidth(2);
	painter.setPen(pen);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setBrush(color1);

	painter.drawRoundedRect(opt.rect, 5, 5);



	painter.setBrush(color2);
	painter.setPen(Qt::NoPen);




}

void ResultSearchWidget::setGraph(int swithSize, bool first) {
	//graph
	Vla1 = new QVBoxLayout;
	Hla22 = new QHBoxLayout;

	double maxVec = 0;
	set = new QBarSet("CO2 в воздухе");





	if (!first) {
		for (int i = 0; i < 10; i++) {
			*set << allco2vec[i];
			if (allco2vec[i] > maxVec) maxVec = allco2vec[i];
		}
	}

	series = new QBarSeries();
	series->append(set);


	QColor color1(242, 243, 244);
	set->setBrush(color1);

	for (int i = 0; i < 10; i++) {
		double tmp1 = set->at(i);


		if (tmp1 == real_co2) {
			set->setBarSelected(i, true);
		}
	}
	set->setSelectedColor(color1);





	QBarCategoryAxis* axisX = new QBarCategoryAxis();
	QValueAxis* axisY = new QValueAxis();
	axisY->setTickCount(1);
	axisY->setRange(0, maxVec);
	

	QStringList categories;
	categories << "январь" << "февраль" << "март" << "апрель" << "май" << "июнь" << "сентябрь" << "октябрь" << "ноябрь" << "декабрь";
	axisX->append(categories);



	QChart* chart = new QChart();
	chart->addSeries(series);
	chart->setAxisX(axisX, series);
	chart->setAxisY(axisY);
	chart->setTheme(QChart::ChartThemeDark);
	chart->setBackgroundBrush(QBrush(QColor(43, 43, 43)));


	//кастомизация
	QColor color(123, 132, 137);
	set->setBrush(color);



	QChartView* chartView = new QChartView(chart);
	chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	chartView->setMinimumSize(1, 450);
	if (swithSize == 1) {
		chartView->setMaximumSize(800, 1980);
	}
	if (swithSize == 2) {
		chartView->setMaximumSize(1500, 1980);
	}
	chartView->setStyleSheet("background-color: rgb(44, 44, 44); ;border-radius: 5px;");


	



	Hla22->addWidget(chartView);

	Hla22->setAlignment(Qt::AlignCenter);
}


ResultSearchWidget::ResultSearchWidget(QWidget* parent, MainWindow* mainwindow, bool first) : QWidget(parent){
	QVBoxLayout* layout = new QVBoxLayout;
	layout->setAlignment(Qt::AlignCenter);
	mainWindow = mainwindow;

	setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
	setMinimumSize(1000, 300);
	setMaximumSize(1000, 1080);

	Calculator* calc = new Calculator(mainwindow->month, mainwindow->body_count, mainwindow->building);
	mark = calc->getMark();
	body_count = calc->getBodyCount();
	building = calc->getBuilding();
	month = calc->getMonth();
	dust_value = calc->getDustValue();
	allco2vec = calc->getAllYearCo2();
	alldustvec = calc->getAllYearDust();
	real_co2 = calc->getCo2();



	
	//grf

	setGraph(1, first);




	//dust


	QString styleSheet1 = "QLabel {color:rgb(202, 207, 210); background-color:rgb(30, 30, 30); font-family: Arial; font-size: 18px;font-weight: bold;padding: 5px;border-radius: 5px;}";
	QLabel* suplabel2 = new QLabel;
	if (!first) {
		suplabel2 = new QLabel(QString::number(round(dust_value)) + " / 100  (points)");
	}
	if (first) {
		suplabel2 = new QLabel(QString::number(0) + " / 100  (points)");
	}
	suplabel2->setFixedSize(190, 40);
	QLabel* dustlabel = new QLabel(" Запыленность ");
	QLabel* dustlabel2 = new QLabel("");
	dustlabel->setFixedSize(162, 40);
	dustlabel->setStyleSheet(styleSheet1);
	suplabel2->setStyleSheet(labelStyle2);
	dustlabel2->setStyleSheet(styleSheet1);

	QHBoxLayout* Hla3 = new QHBoxLayout;


	co_2_value = real_co2;
	QString styleSheet2 = "QLabel {color:rgb(202, 207, 210); background-color:rgb(30, 30, 30); font-family: Arial; font-size: 18px;font-weight: bold;padding: 5px;border-radius: 5px;}";
	QLabel* suplabel = new QLabel;
	if (mainwindow->first == false) {
		suplabel = new QLabel(QString::number(round(co_2_value)) + " / 1000  (ppm)");
	}
	if (mainwindow->first == true) {
		suplabel = new QLabel(QString::number(0) + " / 1000  (ppm)");
	}
	suplabel->setFixedSize(190, 40);
	QLabel* airlabel = new QLabel(" CO2 в воздухе ");
	QLabel* airlabel2 = new QLabel("");
	airlabel->setFixedSize(162, 40);
	airlabel->setStyleSheet(styleSheet2);
	suplabel->setStyleSheet(labelStyle);
	airlabel2->setStyleSheet(styleSheet2);

	QHBoxLayout* Hla4 = new QHBoxLayout;
	Hla4->addSpacing(80);
	Hla4->setAlignment(Qt::AlignLeft);
	Hla4->addWidget(airlabel);
	Hla4->addWidget(suplabel);
	Hla4->addSpacing(-10);
	Hla4->addWidget(airlabel2);



	Hla3->addSpacing(-30);
	Hla3->addLayout(Hla4);


	Hla3->setAlignment(Qt::AlignCenter);
	Hla3->addWidget(dustlabel);
	Hla3->addWidget(suplabel2);
	Hla3->addSpacing(-10);
	Hla3->addWidget(dustlabel2);

	


	ButtonWidget = new Buttons(this, mainwindow, this, mainwindow->fav_widget, 1);

	Vla1->addSpacing(10);
	Vla1->addLayout(Hla22);
	Vla1->addLayout(Hla3);
	Vla1->addSpacing(15);
	Vla1->setAlignment(Qt::AlignCenter);

	QVBoxLayout* Vlatmp = new QVBoxLayout;
	Vlatmp->addWidget(ButtonWidget);
	Vlatmp->setAlignment(Qt::AlignTop);

	QHBoxLayout* Hla44 = new QHBoxLayout;
	Hla44->addLayout(Vla1);
	Hla44->addSpacing(-90);
	Hla44->addLayout(Vlatmp);
	
	Hla44->setAlignment(Qt::AlignRight);

	setLayout(Hla44);
	
}




ResultSearchWidget::ResultSearchWidget(std::vector<QString> calculatorData, std::vector<QString> calculatorData2, MainWindow* mainwindow) {
	calculator_data = calculatorData;
	month = calculatorData[0];
	building = calculatorData[1];
	co_2_value = calculatorData[2].toDouble();
	dust_value = calculatorData[3].toDouble();
	mark = calculatorData[4].toInt();
	body_count = calculatorData[5].toInt();
	real_co2 = calculatorData[6].toDouble();

	for (int i = 7; i < 17; i++) {
		allco2vec.push_back(calculatorData[i].toDouble());
	}
	
	for (int i = 0; i < 10; i++) {
		alldustvec.push_back(calculatorData2[i].toDouble());
	}

	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumSize(1000, 300);
	setMaximumSize(1680, 1000);



	QLabel* datalabel = new QLabel("" + building + ",   " + month + ",  " + QString::number(body_count) + " человек");
	datalabel->setAlignment(Qt::AlignLeft);
	datalabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	datalabel->setMaximumSize(1500, 60);
	datalabel->setStyleSheet("QLabel {"
		"color:rgb(209,222,240);"
		"background-color: rgb(30, 30, 30);"
		"font-family: Arial;"
		"font-size: 20px;"
		"font-weight: bold;"
		"padding: 5px;"
		"border-radius: 2px;"
		"}");







	QHBoxLayout* Hla1 = new QHBoxLayout;
	Hla1->setAlignment(Qt::AlignLeft);
	Hla1->addSpacing(80);
	Hla1->addWidget(datalabel);



	QString progressBarStyle1 =
		"QProgressBar {"
		"border: 2px solid rgb(30, 30, 30);"
		"border-radius: 0px;"
		"background-color:rgb(30, 30, 30);"
		"}"
		"QProgressBar::chunk {"
		"background-color:rgb(171, 178, 185);"
		"width: 30px;"
		"margin: 1px;"
		"border-radius: 2px;"
		"}";


	//dust


	QString styleSheet1 = "QLabel {color:rgb(202, 207, 210); background-color:rgb(30, 30, 30); font-family: Arial; font-size: 18px;font-weight: bold;padding: 5px;border-radius: 5px;}";
	QLabel* suplabel2 = new QLabel(QString::number(round(dust_value)) + " / 100  (points)");
	suplabel2->setFixedSize(190, 40);
	QLabel* dustlabel = new QLabel(" Запыленность");
	QLabel* dustlabel2 = new QLabel("");
	dustlabel->setFixedSize(162, 40);
	dustlabel->setStyleSheet(styleSheet1);
	suplabel2->setStyleSheet(labelStyle2);
	dustlabel2->setStyleSheet(styleSheet1);

	QHBoxLayout* Hla3 = new QHBoxLayout;
	Hla3->addSpacing(80);
	Hla3->setAlignment(Qt::AlignLeft);
	Hla3->addWidget(dustlabel);
	Hla3->addWidget(suplabel2);
	Hla3->addSpacing(-10);
	Hla3->addWidget(dustlabel2);




	//air
	QString progressBarStyle2 =
		"QProgressBar {"
		"border: 2px solid rgb(30, 30, 30);"
		"border-radius: 5px;"
		"background-color:rgb(30, 30, 30);"
		"}"
		"QProgressBar::chunk {"
		"background-color:rgb(171, 178, 185);"
		"width: 30px;"
		"margin: 1px;"
		"border-radius: 2px;"
		"}";

	co_2_value = real_co2;
	QString styleSheet2 = "QLabel {color:rgb(202, 207, 210); background-color:rgb(30, 30, 30); font-family: Arial; font-size: 18px;font-weight: bold;padding: 5px;border-radius: 5px;}";
	QLabel* suplabel = new QLabel(QString::number(round(co_2_value)) + " / 1000  (ppm)");
	suplabel->setFixedSize(190, 40);
	QLabel* airlabel = new QLabel(" CO2 в воздухе");
	QLabel* airlabel2 = new QLabel("");
	airlabel->setFixedSize(162, 40);
	airlabel->setStyleSheet(styleSheet2);
	suplabel->setStyleSheet(labelStyle);
	airlabel2->setStyleSheet(styleSheet2);

	QHBoxLayout* Hla4 = new QHBoxLayout;
	Hla4->addSpacing(80);
	Hla4->setAlignment(Qt::AlignLeft);
	Hla4->addWidget(airlabel);
	Hla4->addWidget(suplabel);
	Hla4->addSpacing(-10);
	Hla4->addWidget(airlabel2);










	//graph
	QVBoxLayout* Vla1 = new QVBoxLayout;
	QHBoxLayout* Hla22 = new QHBoxLayout;

	double maxVec = 0;
	set = new QBarSet("Углекислый газ");


	if (mainwindow->first == false){
		for (int i = 0; i < 10; i++) {
			*set << allco2vec[i];
			if (allco2vec[i] > maxVec) maxVec = allco2vec[i];
		}
	}
	


	QBarSeries* series = new QBarSeries();
	series->append(set);


	QColor color1(242, 243, 244);
	set->setBrush(color1);

	for (int i = 0; i < 10; i++) {
		double tmp1 = set->at(i);


		if (tmp1 == real_co2) {
			set->setBarSelected(i, true);
		}
	}
	set->setSelectedColor(color1);





	QBarCategoryAxis* axisX = new QBarCategoryAxis();
	QValueAxis* axisY = new QValueAxis();
	axisY->setTickCount(1);
	axisY->setRange(0, maxVec);
	

	QStringList categories;
	categories << "январь" << "февраль" << "март" << "апрель" << "май" << "июнь" << "сентябрь" << "октябрь" << "ноябрь" << "декабрь";
	axisX->append(categories);



	QChart* chart = new QChart();
	chart->addSeries(series);
	chart->setAxisX(axisX, series);
	chart->setAxisY(axisY);
	chart->setTheme(QChart::ChartThemeDark);
	chart->setBackgroundBrush(QBrush(QColor(43, 43, 43)));


	//кастомизация
	QColor color(123, 132, 137);
	set->setBrush(color);



	QChartView* chartView = new QChartView(chart);
	chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	chartView->setMinimumSize(1, 450);
	chartView->setMaximumSize(1500, 1080);
	chartView->setStyleSheet("background-color: rgb(44, 44, 44); ;border-radius: 5px;");


	//graph2





	Hla22->addWidget(chartView);

	Hla22->setAlignment(Qt::AlignCenter);



	ButtonWidget = new Buttons(this, mainwindow, this, mainwindow->fav_widget, 2);


	QHBoxLayout* Hla41 = new QHBoxLayout;
	Hla41->addLayout(Hla4);
	Hla41->addLayout(Hla3);
	Hla41->setAlignment(Qt::AlignCenter);


	Vla1->addLayout(Hla22);
	Vla1->addLayout(Hla41);
	Vla1->addSpacing(35);



	QVBoxLayout* Vlatmp = new QVBoxLayout;
	Vlatmp->addSpacing(-42);
	Vlatmp->addWidget(ButtonWidget);
	Vlatmp->addSpacing(35);
	Vlatmp->setAlignment(Qt::AlignTop);

	QHBoxLayout* Hla44 = new QHBoxLayout;
	Hla44->addLayout(Vlatmp);
	Hla44->addSpacing(-90);
	Hla44->addLayout(Vla1);
	Hla44->setAlignment(Qt::AlignRight);

	setLayout(Hla44);
}


ResultSearchWidget::ResultSearchWidget(QWidget* parent, MainWindow* mainwindow, int a) {
	QVBoxLayout* layout = new QVBoxLayout;
	layout->setAlignment(Qt::AlignCenter);

	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumSize(1000, 300);
	setMaximumSize(1680, 1000);

	Calculator* calc = new Calculator(mainwindow->month, mainwindow->body_count, mainwindow->building);
	mark = calc->getMark();
	body_count = calc->getBodyCount();
	building = calc->getBuilding();
	month = calc->getMonth();
	dust_value = calc->getDustValue();
	allco2vec = calc->getAllYearCo2();
	alldustvec = calc->getAllYearDust();
	real_co2 = calc->getCo2();




	//grf


	setGraph(2, mainwindow->first);
	


	//dust


	QString styleSheet1 = "QLabel {color:rgb(202, 207, 210); background-color:rgb(30, 30, 30); font-family: Arial; font-size: 18px;font-weight: bold;padding: 5px;border-radius: 5px;}";
	QLabel* suplabel2 = new QLabel;
	if (mainwindow->first == false) {
		suplabel2 = new QLabel(QString::number(round(dust_value)) + " / 100  (points)");
	}
	if (mainwindow->first == true) {
		suplabel2 = new QLabel(QString::number(0) + " / 100  (points)");
	}
	suplabel2->setFixedSize(190, 40);
	QLabel* dustlabel = new QLabel(" Запыленность ");
	QLabel* dustlabel2 = new QLabel("");
	dustlabel->setFixedSize(162, 40);
	dustlabel->setStyleSheet(styleSheet1);
	suplabel2->setStyleSheet(labelStyle2);
	dustlabel2->setStyleSheet(styleSheet1);

	QHBoxLayout* Hla3 = new QHBoxLayout;


	co_2_value = real_co2;
	QString styleSheet2 = "QLabel {color:rgb(202, 207, 210); background-color:rgb(30, 30, 30); font-family: Arial; font-size: 18px;font-weight: bold;padding: 5px;border-radius: 5px;}";
	QLabel* suplabel = new QLabel;
	if (mainwindow->first == false) {
		suplabel = new QLabel(QString::number(round(co_2_value)) + " / 1000  (ppm)");
	}
	if (mainwindow->first == true) {
		suplabel = new QLabel(QString::number(0) + " / 1000  (ppm)");
	}
	suplabel->setFixedSize(190, 40);
	QLabel* airlabel = new QLabel(" CO2 в воздухе ");
	QLabel* airlabel2 = new QLabel("");
	airlabel->setFixedSize(162, 40);
	airlabel->setStyleSheet(styleSheet2);
	suplabel->setStyleSheet(labelStyle);
	airlabel2->setStyleSheet(styleSheet2);

	QHBoxLayout* Hla4 = new QHBoxLayout;
	Hla4->addSpacing(80);
	Hla4->setAlignment(Qt::AlignLeft);
	Hla4->addWidget(airlabel);
	Hla4->addWidget(suplabel);
	Hla4->addSpacing(-10);
	Hla4->addWidget(airlabel2);



	Hla3->addSpacing(-30);
	Hla3->addLayout(Hla4);


	Hla3->setAlignment(Qt::AlignCenter);
	Hla3->addWidget(dustlabel);
	Hla3->addWidget(suplabel2);
	Hla3->addSpacing(-10);
	Hla3->addWidget(dustlabel2);




	ButtonWidget = new Buttons(this, mainwindow, this, mainwindow->fav_widget, 3);

	Vla1->addSpacing(10);
	Vla1->addLayout(Hla22);
	Vla1->addLayout(Hla3);
	Vla1->addSpacing(35);
	Vla1->setAlignment(Qt::AlignCenter);

	QVBoxLayout* Vlatmp = new QVBoxLayout;
	Vlatmp->addWidget(ButtonWidget);
	Vlatmp->setAlignment(Qt::AlignTop);

	QHBoxLayout* Hla44 = new QHBoxLayout;
	Hla44->addLayout(Vlatmp);
	Hla44->addSpacing(-80);
	Hla44->addLayout(Vla1);
	Hla44->setAlignment(Qt::AlignRight);

	setLayout(Hla44);
}





ResultSearchWidget::~ResultSearchWidget() {


}