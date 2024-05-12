#include "settingsWidget.h"
#include "mainwindow.h"

void SettingsWidget::setSpringSlider() {


	label1->setText("Февраль");



	label2->setText("Март");



	label3->setText("Апрель");



	label4->setText("Май");



	label5->setText("Июнь");


	



	spring_btn->setStyleSheet(spring_style_on);
	autumn_btn->setStyleSheet(autumn_style_off);
	
	
}



void SettingsWidget::setAutumnSlider() {




	
	label1->setText("Сентябрь");
	


	label2->setText("Октябрь");


	label3->setText("Ноябрь");


	label4->setText("Декабрь");


	label5->setText("Январь");






	spring_btn->setStyleSheet(spring_style_off);
	autumn_btn->setStyleSheet(autumn_style_on);


}


SettingsWidget::SettingsWidget(QWidget* parent, MainWindow* mainwindow) : QWidget(parent) {
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMaximumSize(5000, 330);
	label1 = new QPushButton("Сентябрь");
	label2 = new QPushButton("Октябрь");
	label3 = new QPushButton("Ноябрь");
	label4 = new QPushButton("Декабрь");
	label5 = new QPushButton("Январь");
	label1->setStyleSheet(labelStyle);
	label2->setStyleSheet(labelStyle);
	label3->setStyleSheet(labelStyle);
	label4->setStyleSheet(labelStyle);
	label5->setStyleSheet(labelStyle);

	
	

	


	layout_label->addWidget(label1);
	layout_label->addWidget(label2);
	layout_label->addWidget(label3);
	layout_label->addWidget(label4);
	layout_label->addWidget(label5);
	
	


	//new 
	QHBoxLayout* layout2 = new QHBoxLayout;
	autumn_btn->setStyleSheet(autumn_style_on);
	autumn_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	autumn_btn->setMinimumSize(160, 80);
	autumn_btn->setMaximumSize(350, 120);



	layout2->addWidget(autumn_btn);
	layout2->addSpacing(20);
	layout2->addWidget(spring_btn);


	main_layout->addSpacing(50);
	main_layout->addLayout(layout2);
	main_layout->addSpacing(10);
	main_layout->addLayout(layout_label);

}



void SettingsWidget::paintEvent(QPaintEvent * event) {
	QColor color1(34, 34, 34);

	QStyleOption opt;
	opt.initFrom(this);
	QPainter painter(this);
	QPen pen(color1);
	pen.setWidth(2);
	painter.setPen(pen);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setBrush(color1);
	painter.drawRoundedRect(opt.rect, 15, 15);



}

SettingsWidget::~SettingsWidget() {

}

