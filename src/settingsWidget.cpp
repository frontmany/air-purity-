#include "settingsWidget.h"
#include "mainwindow.h"

void SettingsWidget::setSpringSlider() {
	slider->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	slider->setMinimumSize(350, 20);
	slider->setMaximumSize(1200, 20);

	label1->setText("Февраль");
	label1->setStyleSheet(labelStyle);

	label2->setText("Март");
	label2->setStyleSheet(labelStyle);

	label3->setText("Апрель");
	label3->setStyleSheet(labelStyle);

	label4->setText("Май");
	label4->setStyleSheet(labelStyle);

	label5->setText("Июнь");
	label5->setStyleSheet(labelStyle);
	
	if (c == 0){
		layout_label->insertSpacing(3, 15);
		c++;
		fl = true;
	}


	spring_btn->setStyleSheet(spring_style_on);
	autumn_btn->setStyleSheet(autumn_style_off);
	
	
}


void SettingsWidget::setAutumnSlider() {

	slider->setFixedSize(360, 20);
	slider->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	slider->setMinimumSize(350, 20);
	slider->setMaximumSize(1200, 20);


	label1->setText("Сентябрь");
	label1->setStyleSheet(labelStyle);

	label2->setText("Октябрь");
	label2->setStyleSheet(labelStyle);

	label3->setText("Ноябрь");
	label3->setStyleSheet(labelStyle);

	label4->setText("Декабрь");
	label4->setStyleSheet(labelStyle);

	label5->setText("Январь");
	label5->setStyleSheet(labelStyle);

	if (c > 0 && fl) {
		layout_label->insertSpacing(3, -15);
		fl = false;
		c = 0;
	}


	spring_btn->setStyleSheet(spring_style_off);
	autumn_btn->setStyleSheet(autumn_style_on);


}


SettingsWidget::SettingsWidget(QWidget* parent, MainWindow* mainwindow) : QWidget(parent) {
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMaximumSize(5000, 330);

	

	
	slider->setStyleSheet("QSlider {background: rgb(26, 26, 26); border: 0px solid rgb(26, 26, 26); border-radius: 10px; height: 20px; margin: 0; padding: 0;font-family: Arial; font-weight: bold;  font-size: 13px;}"
		"QSlider::groove:horizontal {background: rgb(26, 26, 26); height: 10px; margin: 5px 0; border-radius: 5px;}"
		"QSlider::handle:horizontal {background: rgb(46, 46, 46); border: 0px solid #aaaaaa; width: 50px; height: 20px; margin: -5px 0;border-radius: 10px;}"
		"QSlider::handle:horizontal:hover {background: rgb(46, 46, 46);}"
		"QSlider::handle:horizontal:pressed {background:rgb(46, 46, 46);}"
	);

	slider->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	slider->setMinimumSize(350, 20);
	slider->setMaximumSize(1200, 20);
	slider->setRange(0, 300);
	slider->setSingleStep(1);
	connect(slider, &QSlider::valueChanged, mainwindow, &MainWindow::onSliderChanged);


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


	spring_btn->setFixedSize(160, 50);
	spring_btn->setStyleSheet(spring_style_off);
	spring_btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	spring_btn->setMinimumSize(160, 80);
	spring_btn->setMaximumSize(350, 120);

	layout2->addWidget(autumn_btn);
	layout2->addSpacing(20);
	layout2->addWidget(spring_btn);


	main_layout->addSpacing(50);
	main_layout->addLayout(layout2);
	main_layout->addSpacing(10);
	main_layout->addWidget(slider);
	main_layout->addLayout(layout_label);

	connect(spring_btn, &QPushButton::clicked, this, &SettingsWidget::setSpringSlider);
	connect(spring_btn, &QPushButton::clicked, mainwindow, &MainWindow::isSpring);

	connect(autumn_btn, &QPushButton::clicked, this, &SettingsWidget::setAutumnSlider);
	connect(autumn_btn, &QPushButton::clicked, mainwindow, &MainWindow::isAutumn);
	main_layout->setAlignment(Qt::AlignCenter);
	setLayout(main_layout);

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

