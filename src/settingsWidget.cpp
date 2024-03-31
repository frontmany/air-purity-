#include "settingsWidget.h"

void SettingsWidget::setSpringSlider() {

	slider->setFixedSize(340, 20);

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

	season = "spring";
	spring_btn->setStyleSheet(spring_style_on);
	autumn_btn->setStyleSheet(autumn_style_off);
	
	
}


void SettingsWidget::setAutumnSlider() {

	slider->setFixedSize(360, 20);

	
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

	season = "autumn";
	spring_btn->setStyleSheet(spring_style_off);
	autumn_btn->setStyleSheet(autumn_style_on);


}


SettingsWidget::SettingsWidget(QWidget* parent) : QWidget(parent) {
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMaximumSize(800, 400);

	

	
	slider->setStyleSheet("QSlider {background: #D3D3D3; border: 0px solid #D3D3D3; border-radius: 10px; height: 20px; margin: 0; padding: 0;}"
		"QSlider::groove:horizontal {background: #D3D3D3; height: 10px; margin: 5px 0; border-radius: 5px;}"
		"QSlider::handle:horizontal {background: #708090; border: 0px solid #aaaaaa; width: 50px; height: 20px; margin: -5px 0;border-radius: 10px;}"
		"QSlider::handle:horizontal:hover {background: #4f7ba3;}"
		"QSlider::handle:horizontal:pressed {background: #4f7ba3;}"
	);

	slider->setFixedSize(360, 20);
	slider->setRange(1, 5);
	slider->setSingleStep(1);



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
	autumn_btn->setFixedSize(160, 50);
	autumn_btn->setStyleSheet(autumn_style_on);

	spring_btn->setFixedSize(160, 50);
	spring_btn->setStyleSheet(spring_style_off);

	layout2->addWidget(autumn_btn);
	layout2->addSpacing(15);
	layout2->addWidget(spring_btn);


	main_layout->addSpacing(50);
	main_layout->addLayout(layout2);
	main_layout->addSpacing(20);
	main_layout->addWidget(slider);
	main_layout->addLayout(layout_label);

	connect(spring_btn, &QPushButton::clicked, this, &SettingsWidget::setSpringSlider);
	connect(autumn_btn, &QPushButton::clicked, this, &SettingsWidget::setAutumnSlider);
	main_layout->setAlignment(Qt::AlignCenter);
	setLayout(main_layout);

}



void SettingsWidget::paintEvent(QPaintEvent * event) {
	QColor color1(26, 26, 26);

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

