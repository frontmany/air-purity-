#include "resultSearchWidget.h"
#include "mainwindow.h"
#include "calculator.h"
#include <buttonswidget.h>


void ResultSearchWidget::paintEvent(QPaintEvent* event) {
	QColor color1(34, 34, 34);
	QColor color2(220, 130, 48);
	QColor color3(226, 227, 138);
	QColor color4(199, 221, 198);
	QColor color5(153, 201, 162);
	QColor color6(255, 255, 255);
	QColor color7(131, 141, 149);


	QStyleOption opt;
	opt.initFrom(this);

	QPen pen(color1);
	pen.setWidth(2);

	QPainter painter(this);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setBrush(color1);
	painter.setPen(pen);


	painter.drawRoundedRect(opt.rect, 15, 15);

	

}


ResultSearchWidget::ResultSearchWidget(QWidget* parent, MainWindow* mainwindow) : QWidget(parent){
	QVBoxLayout* layout = new QVBoxLayout;
	layout->setAlignment(Qt::AlignCenter);
	
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumSize(350, 300);
	setMaximumSize(1600, 1080);

	Calculator* calc = new Calculator(mainwindow->slider_data, mainwindow->body_count, mainwindow->season, mainwindow->building);
	co_2_value = calc->getCo2Value();
	mark = calc->getMark();
	body_count = calc->getBodyCount();
	building = calc->getBuilding();
	month = calc->getMonth();
	dust_value = calc->getDustValue();
	allco2vec = calc->getAllYearCo2();
	alldustvec = calc->getAllYearDust();
	real_co2 = calc->getCo2();


	QLabel* datalabel = new QLabel("" + building + "        |        " + month + "        |        " + QString::number(body_count) + " человек");
	datalabel->setAlignment(Qt::AlignCenter);
	datalabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	datalabel->setMaximumSize(1500, 60);
	datalabel->setStyleSheet("QLabel {"
		"color:rgb(209,222,240);"  
		"background-color: rgb(34, 34, 34);" 
		"font-family: Arial;" 
		"font-size: 20px;"  
		"font-weight: bold;" 
		"padding: 5px;" 
		"border-radius: 2px;"  
		"}");







	QHBoxLayout* Hla1 = new QHBoxLayout;
	Hla1->setAlignment(Qt::AlignCenter);
	Hla1->addSpacing(0);
	Hla1->addWidget(datalabel);
	


	QString progressBarStyle1 =
		"QProgressBar {"
		"border: 2px solid rgb(34, 34, 34);"
		"border-radius: 0px;"
		"background-color:rgb(34, 34, 34);"
		"}"
		"QProgressBar::chunk {"
		"background-color:rgb(171, 178, 185);"
		"width: 30px;" 
		"margin: 1px;" 
		"border-radius: 2px;"
		"}";


	//dust
	QProgressBar* progressdustBar = new QProgressBar();
	progressdustBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	progressdustBar->setMaximumSize(1010, 40);
	progressdustBar->setRange(1, 100);
	progressdustBar->setValue(dust_value);
	progressdustBar->setStyleSheet(progressBarStyle1);
	progressdustBar->setTextVisible(false);

	QString styleSheet1 = "QLabel {color:rgb(202, 207, 210); background-color:rgb(34, 34, 34); font-family: Arial; font-size: 14px;font-weight: bold;padding: 5px;border-radius: 5px;}";
	QLabel* suplabel2 = new QLabel(QString::number(round(dust_value)) + " / 100  (points)");
	suplabel2->setFixedSize(150, 40);
	QLabel* dustlabel = new QLabel(" Запыленность ");
	QLabel* dustlabel2 = new QLabel("|");
	dustlabel->setFixedSize(122, 40);
	dustlabel->setStyleSheet(styleSheet1);
	suplabel2->setStyleSheet(labelStyle);
	dustlabel2->setStyleSheet(styleSheet1);

	QHBoxLayout* Hla3 = new QHBoxLayout;
	Hla3->setAlignment(Qt::AlignLeft);
	Hla3->addWidget(dustlabel);
	Hla3->addWidget(suplabel2);
	Hla3->addSpacing(-10);
	Hla3->addWidget(progressdustBar);
	Hla3->addWidget(dustlabel2);




	//air
	QString progressBarStyle2 =
		"QProgressBar {"
		"border: 2px solid rgb(34, 34, 34);"
		"border-radius: 5px;"
		"background-color:rgb(34, 34, 34);"
		"}"
		"QProgressBar::chunk {"
		"background-color:rgb(171, 178, 185);"
		"width: 30px;"
		"margin: 1px;"
		"border-radius: 2px;"
		"}";

	QProgressBar* progressairBar = new QProgressBar();
	progressairBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	progressairBar->setMaximumSize(800, 40);
	progressairBar->setRange(1, 100);
	progressairBar->setValue(co_2_value);
	progressairBar->setStyleSheet(progressBarStyle2);
	progressairBar->setTextVisible(false);

	QString styleSheet2 = "QLabel {color:rgb(202, 207, 210); background-color:rgb(34, 34, 34); font-family: Arial; font-size: 14px;font-weight: bold;padding: 5px;border-radius: 5px;}";
	QLabel* suplabel = new QLabel(QString::number(round(real_co2)) + " / 2500  (ppm)");
	suplabel->setFixedSize(150,40);
	QLabel* airlabel = new QLabel(" CO2 в воздухе " );
	QLabel* airlabel2 = new QLabel("|");
	airlabel->setFixedSize(122, 40);
	airlabel->setStyleSheet(styleSheet2);
	suplabel->setStyleSheet(labelStyle);
	airlabel2->setStyleSheet(styleSheet2);

	QHBoxLayout* Hla4 = new QHBoxLayout;
	Hla4->setAlignment(Qt::AlignLeft);
	Hla4->addWidget(airlabel);
	Hla4->addWidget(suplabel);
	Hla4->addSpacing(-10);
	Hla4->addWidget(progressairBar);
	Hla4->addWidget(airlabel2);





	




	//graph
	QVBoxLayout* Vla1 = new QVBoxLayout;
	QHBoxLayout* Hla22 = new QHBoxLayout;

	double maxVec = 0;
	set = new QBarSet("Углекислый газ");



	for (int i = 0; i < 10; i++) {
		*set << allco2vec[i];
		if (allco2vec[i] > maxVec) maxVec = allco2vec[i];
	}
	

	QBarSeries* series = new QBarSeries();
	series->append(set);


	QColor color1(242, 243, 244);
	set->setBrush(color1);
	
	for (int i = 0; i < 10; i++) {
		double tmp1 = set->at(i);
		

		if (tmp1 == real_co2) {
			set->setBarSelected(i, true);
			if (mark == 5) {
				
			}
		}
	}
	set->setSelectedColor(color1);





	QBarCategoryAxis* axisX = new QBarCategoryAxis();
	QValueAxis* axisY = new QValueAxis();
	axisY->setTickCount(5); 
	axisY->setRange(0, maxVec);
	axisY->setTitleText("CO2 (ppm) при   " + QString::number(body_count) + " человек");
	
	QStringList categories;
	categories << "сентябрь" << "октябрь" << "ноябрь" << "декабрь" << "январь" << "февраль" << "март" << "апрель" << "май" << "июнь";
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
	chartView->setMinimumSize(1, 350);
	chartView->setMaximumSize(1500, 1080);
	chartView->setStyleSheet("background-color: rgb(44, 44, 44); ;border-radius: 5px;");
	

	//graph2


	double maxVec1 = 0;
	set2 = new QBarSet("Запыленность");



	for (int i = 0; i < 10; i++) {
		*set2 << alldustvec[i];
		if (alldustvec[i] > maxVec1) maxVec1 = alldustvec[i];
	}


	QBarSeries* series1 = new QBarSeries();
	series1->append(set2);


	QColor color11(242, 243, 244);
	set2->setBrush(color1);

	for (int i = 0; i < 10; i++) {
		double tmp1 = set2->at(i);


		if (tmp1 == dust_value) {
			set2->setBarSelected(i, true);

		}
	}
	set2->setSelectedColor(color11);





	QBarCategoryAxis* axisX1 = new QBarCategoryAxis();
	QValueAxis* axisY1 = new QValueAxis();
	axisY1->setTickCount(5);
	axisY1->setRange(0, maxVec1);
	axisY1->setTitleText("dust (points) при   " + QString::number(body_count) + " человек");

	QStringList categories1;
	categories1 << "сентябрь" << "октябрь" << "ноябрь" << "декабрь" << "январь" << "февраль" << "март" << "апрель" << "май" << "июнь";
	axisX1->append(categories1);



	QChart* chart2 = new QChart();
	chart2->addSeries(series1);
	chart2->setAxisX(axisX1, series1);
	chart2->setAxisY(axisY1);
	chart2->setTheme(QChart::ChartThemeDark);
	chart2->setBackgroundBrush(QBrush(QColor(43, 43, 43)));


	//кастомизация
	QColor color12(123, 132, 137);
	set2->setBrush(color12);



	QChartView* chartView2 = new QChartView(chart2);
	chartView2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	chartView2->setMinimumSize(1, 350);
	chartView2->setMaximumSize(1500, 1080);
	chartView2->setStyleSheet("background-color: rgb(44, 44, 44); ;border-radius: 5px;");




	Hla22->addWidget(chartView);
	Hla22->addWidget(chartView2);
	Hla22->setAlignment(Qt::AlignCenter);



	ButtonWidget = new Buttons(this, mainwindow, this, mainwindow->fav_widget, 1);
	
	QHBoxLayout* Hla33 = new QHBoxLayout;
	Hla33->addLayout(Hla4);
	Hla33->addLayout(Hla3);


	QHBoxLayout* Hla44 = new QHBoxLayout;
	Hla44->addWidget(ButtonWidget);


	Vla1->addSpacing(25);
	Vla1->addLayout(Hla1);
	Vla1->addSpacing(25);
	Vla1->addLayout(Hla22);
	Vla1->addLayout(Hla33);
	Vla1->addSpacing(25);
	Vla1->addLayout(Hla44);
	Vla1->addSpacing(25);
	Vla1->setAlignment(Qt::AlignCenter);

	setLayout(Vla1);
	
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
	setMinimumSize(350, 300);
	setMaximumSize(1600, 1080);



	QLabel* datalabel = new QLabel("" + building + "        |        " + month + "        |        " + QString::number(body_count) + " человек");
	datalabel->setAlignment(Qt::AlignCenter);
	datalabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	datalabel->setMaximumSize(1500, 60);
	datalabel->setStyleSheet("QLabel {"
		"color:rgb(209,222,240);"
		"background-color: rgb(34, 34, 34);"
		"font-family: Arial;"
		"font-size: 20px;"
		"font-weight: bold;"
		"padding: 5px;"
		"border-radius: 2px;"
		"}");







	QHBoxLayout* Hla1 = new QHBoxLayout;
	Hla1->setAlignment(Qt::AlignCenter);
	Hla1->addSpacing(0);
	Hla1->addWidget(datalabel);



	QString progressBarStyle1 =
		"QProgressBar {"
		"border: 2px solid rgb(34, 34, 34);"
		"border-radius: 0px;"
		"background-color:rgb(34, 34, 34);"
		"}"
		"QProgressBar::chunk {"
		"background-color:rgb(171, 178, 185);"
		"width: 30px;"
		"margin: 1px;"
		"border-radius: 2px;"
		"}";


	//dust
	QProgressBar* progressdustBar = new QProgressBar();
	progressdustBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	progressdustBar->setMaximumSize(1010, 40);
	progressdustBar->setRange(1, 100);
	progressdustBar->setValue(dust_value);
	progressdustBar->setStyleSheet(progressBarStyle1);
	progressdustBar->setTextVisible(false);

	QString styleSheet1 = "QLabel {color:rgb(202, 207, 210); background-color:rgb(34, 34, 34); font-family: Arial; font-size: 14px;font-weight: bold;padding: 5px;border-radius: 5px;}";
	QLabel* suplabel2 = new QLabel(QString::number(round(dust_value)) + " / 100  (points)");
	suplabel2->setFixedSize(150, 40);
	QLabel* dustlabel = new QLabel(" Запыленность ");
	QLabel* dustlabel2 = new QLabel("|");
	dustlabel->setFixedSize(122, 40);
	dustlabel->setStyleSheet(styleSheet1);
	suplabel2->setStyleSheet(labelStyle);
	dustlabel2->setStyleSheet(styleSheet1);

	QHBoxLayout* Hla3 = new QHBoxLayout;
	Hla3->setAlignment(Qt::AlignLeft);
	Hla3->addWidget(dustlabel);
	Hla3->addWidget(suplabel2);
	Hla3->addSpacing(-10);
	Hla3->addWidget(progressdustBar);
	Hla3->addWidget(dustlabel2);




	//air
	QString progressBarStyle2 =
		"QProgressBar {"
		"border: 2px solid rgb(34, 34, 34);"
		"border-radius: 5px;"
		"background-color:rgb(34, 34, 34);"
		"}"
		"QProgressBar::chunk {"
		"background-color:rgb(171, 178, 185);"
		"width: 30px;"
		"margin: 1px;"
		"border-radius: 2px;"
		"}";

	QProgressBar* progressairBar = new QProgressBar();
	progressairBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	progressairBar->setMaximumSize(800, 40);
	progressairBar->setRange(1, 100);
	progressairBar->setValue(co_2_value);
	progressairBar->setStyleSheet(progressBarStyle2);
	progressairBar->setTextVisible(false);

	QString styleSheet2 = "QLabel {color:rgb(202, 207, 210); background-color:rgb(34, 34, 34); font-family: Arial; font-size: 14px;font-weight: bold;padding: 5px;border-radius: 5px;}";
	QLabel* suplabel = new QLabel(QString::number(round(real_co2)) + " / 2500  (ppm)");
	suplabel->setFixedSize(150, 40);
	QLabel* airlabel = new QLabel(" CO2 в воздухе ");
	QLabel* airlabel2 = new QLabel("|");
	airlabel->setFixedSize(122, 40);
	airlabel->setStyleSheet(styleSheet2);
	suplabel->setStyleSheet(labelStyle);
	airlabel2->setStyleSheet(styleSheet2);

	QHBoxLayout* Hla4 = new QHBoxLayout;
	Hla4->setAlignment(Qt::AlignLeft);
	Hla4->addWidget(airlabel);
	Hla4->addWidget(suplabel);
	Hla4->addSpacing(-10);
	Hla4->addWidget(progressairBar);
	Hla4->addWidget(airlabel2);










	//graph
	QVBoxLayout* Vla1 = new QVBoxLayout;
	QHBoxLayout* Hla22 = new QHBoxLayout;

	double maxVec = 0;
	set = new QBarSet("Углекислый газ");



	for (int i = 0; i < 10; i++) {
		*set << allco2vec[i];
		if (allco2vec[i] > maxVec) maxVec = allco2vec[i];
	}


	QBarSeries* series = new QBarSeries();
	series->append(set);


	QColor color1(242, 243, 244);
	set->setBrush(color1);

	for (int i = 0; i < 10; i++) {
		double tmp1 = set->at(i);


		if (tmp1 == real_co2) {
			set->setBarSelected(i, true);
			if (mark == 5) {

			}
		}
	}
	set->setSelectedColor(color1);





	QBarCategoryAxis* axisX = new QBarCategoryAxis();
	QValueAxis* axisY = new QValueAxis();
	axisY->setTickCount(5);
	axisY->setRange(0, maxVec);
	axisY->setTitleText("CO2 (ppm) при   " + QString::number(body_count) + " человек");

	QStringList categories;
	categories << "сентябрь" << "октябрь" << "ноябрь" << "декабрь" << "январь" << "февраль" << "март" << "апрель" << "май" << "июнь";
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
	chartView->setMinimumSize(1, 350);
	chartView->setMaximumSize(1500, 1080);
	chartView->setStyleSheet("background-color: rgb(44, 44, 44); ;border-radius: 5px;");


	//graph2


	double maxVec1 = 0;
	set2 = new QBarSet("Запыленность");



	for (int i = 0; i < 10; i++) {
		*set2 << alldustvec[i];
		if (alldustvec[i] > maxVec1) maxVec1 = alldustvec[i];
	}


	QBarSeries* series1 = new QBarSeries();
	series1->append(set2);


	QColor color11(242, 243, 244);
	set2->setBrush(color1);

	for (int i = 0; i < 10; i++) {
		double tmp1 = set2->at(i);


		if (tmp1 == dust_value) {
			set2->setBarSelected(i, true);

		}
	}
	set2->setSelectedColor(color11);





	QBarCategoryAxis* axisX1 = new QBarCategoryAxis();
	QValueAxis* axisY1 = new QValueAxis();
	axisY1->setTickCount(5);
	axisY1->setRange(0, maxVec1);
	axisY1->setTitleText("dust (points) при   " + QString::number(body_count) + " человек");

	QStringList categories1;
	categories1 << "сентябрь" << "октябрь" << "ноябрь" << "декабрь" << "январь" << "февраль" << "март" << "апрель" << "май" << "июнь";
	axisX1->append(categories1);



	QChart* chart2 = new QChart();
	chart2->addSeries(series1);
	chart2->setAxisX(axisX1, series1);
	chart2->setAxisY(axisY1);
	chart2->setTheme(QChart::ChartThemeDark);
	chart2->setBackgroundBrush(QBrush(QColor(43, 43, 43)));


	//кастомизация
	QColor color12(123, 132, 137);
	set2->setBrush(color12);



	QChartView* chartView2 = new QChartView(chart2);
	chartView2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	chartView2->setMinimumSize(1, 350);
	chartView2->setMaximumSize(1500, 1080);
	chartView2->setStyleSheet("background-color: rgb(44, 44, 44); ;border-radius: 5px;");




	Hla22->addWidget(chartView);
	Hla22->addWidget(chartView2);
	Hla22->setAlignment(Qt::AlignCenter);



	ButtonWidget = new Buttons(this, mainwindow, this, mainwindow->fav_widget, 2);

	QHBoxLayout* Hla33 = new QHBoxLayout;
	Hla33->addLayout(Hla4);
	Hla33->addLayout(Hla3);


	QHBoxLayout* Hla44 = new QHBoxLayout;
	Hla44->addWidget(ButtonWidget);


	Vla1->addSpacing(25);
	Vla1->addLayout(Hla1);
	Vla1->addSpacing(25);
	Vla1->addLayout(Hla22);
	Vla1->addLayout(Hla33);
	Vla1->addSpacing(25);
	Vla1->addLayout(Hla44);
	Vla1->addSpacing(25);
	Vla1->setAlignment(Qt::AlignCenter);

	setLayout(Vla1);
}






ResultSearchWidget::~ResultSearchWidget() {


}