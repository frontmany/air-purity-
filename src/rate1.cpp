#include "rate1.h"
#include "menu.h"

void RatingWidget::show() {
	
}

void RatingWidget::calcRating() {
	currentCo2 = 350 + (31 * 350 * 90 / length * height * cwidth * Acurrent);
}


void RatingWidget::paintEvent(QPaintEvent* event) {
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



	painter.setBrush(color1);
	painter.setPen(Qt::NoPen);



	int rectWidth = width() - 20;
	int rectHeight = 60;
	int rectX = 10;
	int rectY = 20;

	QRect Rect1(rectX, rectY, rectWidth, rectHeight);
	painter.drawRoundedRect(Rect1, 5, 5);
	painter.setPen(color3);




	QFont font = QFont("Arial", 18);
	font.setBold(true);
	painter.setFont(font);
	QRect textRect(rectX, rectY, rectWidth, rectHeight);
	painter.drawText(textRect, Qt::AlignVCenter, "  Рейтинг Залов");

}

void RatingWidget::onSortMenuChanged(int index) {

}

RatingWidget::RatingWidget(QWidget* parent, MainWindow* mainw) : QWidget(parent){
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumSize(350, 300);
	setMaximumSize(1920, 1080);

	rate_layout = new QVBoxLayout();
	adjustment_layout = new QHBoxLayout();
	
	QPushButton* matfakBtn = new QPushButton("Школа Компьютерных наук");
	matfakBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	matfakBtn->setMinimumSize(350, 80);
	matfakBtn->setMaximumSize(1000, 80);
	matfakBtn->setStyleSheet(style1);

	QPushButton* shoBtn = new QPushButton("Школа Образования");
	shoBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	shoBtn->setMinimumSize(350, 80);
	shoBtn->setMaximumSize(1000, 80);
	shoBtn->setStyleSheet(style1);

	QPushButton* gymnastBtn = new QPushButton("Олимпия: Гимнастический Зал");
	gymnastBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	gymnastBtn->setMinimumSize(350, 80);
	gymnastBtn->setMaximumSize(1000, 80);
	gymnastBtn->setStyleSheet(style1);

	QPushButton* trenBtn = new QPushButton("Олимпия: Тренажерный Зал");
	trenBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	trenBtn->setMinimumSize(350, 80);
	trenBtn->setMaximumSize(1000, 80);
	trenBtn->setStyleSheet(style1);

	QPushButton* grouppBtn = new QPushButton("Олимпия: Зал Групповых Программ");
	grouppBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	grouppBtn->setMinimumSize(350, 80);
	grouppBtn->setMaximumSize(1000, 80);
	grouppBtn->setStyleSheet(style1);

	rate_layout->addWidget(matfakBtn);
	rate_layout->addWidget(shoBtn);
	rate_layout->addWidget(gymnastBtn);
	rate_layout->addWidget(trenBtn);
	rate_layout->addWidget(grouppBtn);




	//2

	QVBoxLayout* rate_layout2 = new QVBoxLayout();

	Menu* area_menu = new Menu(this, 4);
	area_menu->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	area_menu->setMinimumSize(350, 80);
	area_menu->setMaximumSize(400, 80);
	connect(area_menu, &QComboBox::currentIndexChanged, this, &RatingWidget::onSortMenuChanged);
	area_menu->setStyleSheet(menuSheet);

	
	QPushButton* ngymBtn = new QPushButton("Добавить Свой Зал");
	ngymBtn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	ngymBtn->setMinimumSize(350, 60);
	ngymBtn->setMaximumSize(400, 60);
	ngymBtn->setStyleSheet(style2);


	rate_layout2->addWidget(area_menu);
	rate_layout2->addSpacing(-80);
	rate_layout2->addWidget(ngymBtn);
	rate_layout2->addSpacing(100);
	
	
	adjustment_layout->setAlignment(Qt::AlignCenter);
	adjustment_layout->addLayout(rate_layout);
	adjustment_layout->addSpacing(80);
	adjustment_layout->addLayout(rate_layout2);
	setLayout(adjustment_layout);
}
