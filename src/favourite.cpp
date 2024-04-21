#include "favourite.h"
#include "resultsearchwidget.h"
#include "mainwindow.h"




void FavouriteListWidget::onButtonClicked() {
	QPushButton* senderButton = qobject_cast<QPushButton*>(sender());
	if (senderButton) {
		int index = storage_layout->indexOf(senderButton);
		emit buttonClicked(index); // Отправка сигнала с индексом нажатой кнопки
	}
}


void FavouriteListWidget::paintEvent(QPaintEvent* event) {
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


	int rectWidth = width()-20;
	int rectHeight = 60;
	int rectX = 10;
	int rectY = 20;

	QRect Rect1(rectX, rectY, rectWidth, rectHeight);
	painter.drawRoundedRect(Rect1, 5,5);
	painter.setPen(color3);




	QFont font = QFont("Arial", 18);
	font.setBold(true);
	painter.setFont(font);
	QRect textRect(rectX, rectY, rectWidth, rectHeight);
	painter.drawText(textRect, Qt::AlignVCenter, "  Избранное");

}



void FavouriteListWidget::showFavWidgets() {

		
	
	for (int j = 0; j < main_window->fav_wid_count; j++) {

		
		Hla1 = new QHBoxLayout;
		QPushButton* btn = new QPushButton("" + (main_window->storage_list[j])[1] + "      |      " + (main_window->storage_list[j])[0] + "      |      " + (main_window->storage_list[j])[5] + " человек    ");
		btn->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
		btn->setMinimumSize(350, 80);
		btn->setMaximumSize(1400, 80);

		btn->setStyleSheet("QPushButton {"
			"color:rgb(255, 255, 255);"
			"background-color:rgb(246, 93, 69 );"
			"font-family: Arial;"
			"font-size: 18px;"
			"font-weight: bold;"
			"padding: 5px;"
			"border-radius: 5px;"
			"}"
			"QPushButton:hover {background-color:rgb(255, 110, 74;)}");





		Hla1->addWidget(btn);



		connect(btn, &QPushButton::clicked, this, &FavouriteListWidget::onButtonClicked);
		connect(this, &FavouriteListWidget::buttonClicked, main_window, &MainWindow::handleButtonClicked);
		connect(btn, &QPushButton::clicked, main_window, &MainWindow::onFavBtnClicked);

		storage_layout->addWidget(btn);

		fav_layout->addLayout(Hla1);



	}
	
	
	

}


FavouriteListWidget::FavouriteListWidget(QWidget* parent, MainWindow* mainwindow)
	: QWidget(parent)
{
	main_window = mainwindow;
	fav_layout = new QVBoxLayout;
	storage_layout = new QVBoxLayout;
	storage_layout2ex = new QVBoxLayout;
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMinimumSize(350, 300);
	setMaximumSize(1000, 1080);


	this->setLayout(fav_layout);
}


FavouriteListWidget::~FavouriteListWidget() {

}