#include "resultSearchWidget.h"
#include "mainwindow.h"
#include "calculator.h"

void ResultSearchWidget::paintEvent(QPaintEvent* event) {
	QColor color1(170, 88, 88);
	QColor color2(220, 130, 48);
	QColor color3(226, 227, 138);
	QColor color4(199, 221, 198);
	QColor color5(153, 201, 162);
	QColor color6(255, 255, 255);
	QColor color7(131, 141, 149);
	QPainter painter(this);

	Qt::AlignCenter;


	painter.setRenderHint(QPainter::Antialiasing);
	painter.drawRoundedRect(QRect(ResultSearchWidget::width() / 4, 25, ResultSearchWidget::width()/2, 120), 5, 5);

	painter.setPen(QPen(color7));
	painter.setBrush(color7);
	painter.drawRoundedRect(QRect(ResultSearchWidget::width() / 4, 142, ResultSearchWidget::width() / 2, 120), 0, 0);


	if (mark == 5) {
		painter.setPen(QPen(color5));
		painter.setBrush(color5);
	}
	if (mark == 4) {
		painter.setPen(QPen(color4));
		painter.setBrush(color4);
	}
	if (mark == 3) {
		painter.setPen(QPen(color3));
		painter.setBrush(color3);
	}
	if (mark == 2) {
		painter.setPen(QPen(color2));
		painter.setBrush(color2);
	}
	if (mark == 1) {
		painter.setPen(QPen(color1));
		painter.setBrush(color1);
	}
	painter.setFont(QFont("Arial", 24, QFont::Bold));
	painter.drawText(QRect(ResultSearchWidget::width() / 2, 65, 100, 50), QString::number(mark));

}


ResultSearchWidget::ResultSearchWidget(QWidget* parent, MainWindow* mainwindow) : QWidget(parent){
	QVBoxLayout* layout = new QVBoxLayout;
	


	QPushButton* backButton = new QPushButton("back");
	backButton->setFixedSize(100, 100);
	connect(backButton, &QPushButton::clicked, mainwindow, &MainWindow::searchWback);
	layout->addSpacing(160);
	layout->addWidget(backButton);

	
	Calculator* calc = new Calculator(mainwindow->slider_data, mainwindow->body_count, mainwindow->season, mainwindow->building);
	co_2 = calc->getCo2();
	mark = calc->getMark();
	description = calc->getDescription();

	QLabel* labelCo2 = new QLabel(QString::number(co_2));
	labelCo2->setFixedSize(100, 100);
	layout->addWidget(labelCo2);



	setLayout(layout);
	
}

ResultSearchWidget::~ResultSearchWidget() {


}