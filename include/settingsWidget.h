#include "QWidget"
#include "QPainter"
#include "QLabel"
#include "QWidget"
#include "QStyleOption"
#include "qlayout.h"
#include "QPushButton"
#include<QHboxLayout>
#include<QApplication>

class SettingsWidget : public QWidget {
public:
	SettingsWidget(QWidget* parent);
	~SettingsWidget();

public:
	QVBoxLayout* main_layout = new QVBoxLayout;
	QHBoxLayout* layout_label = new QHBoxLayout;
	QPushButton* autumn_btn = new QPushButton("Осенний семестр");
	QPushButton* spring_btn = new QPushButton("Весенний семестр");
	QSlider* slider = new QSlider(Qt::Horizontal);
	QString labelStyle = ("QLabel{ color: #ffffff;  padding: 6px;  font-weight:bold;}");

	QLabel* label1 = new QLabel("Сентябрь");

	QLabel* label2 = new QLabel("Октябрь");
	QLabel* label3 = new QLabel("Ноябрь");
	QLabel* label4 = new QLabel("Декабрь");
	QLabel* label5 = new QLabel("Январь");

	bool fl = true;
	int c = 0;

	QString autumn_style_off = "QPushButton {background-color: #A7BCC7; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 400;}"
		"QPushButton:hover {background-color: #D3BCAA;border: 1px solid #D3BCAA; outline: 0;}";

	QString autumn_style_on = "QPushButton {background-color: #D3BCAA; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 400;}"
		"QPushButton:hover {background-color: #D3BCAA;border: 1px solid #D3BCAA; outline: 0;}";

	QString spring_style_off = "QPushButton {background-color: #A7BCC7; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 400;}"
		"QPushButton:hover {background-color: #B0C7A7;border: 1px solid #B0C7A7; outline: 0;}";

	QString spring_style_on = "QPushButton {background-color: #B0C7A7; border-radius: 2px;padding: 10px 20px; font-size: 14px;font-weight: 400;}"
		"QPushButton:hover {background-color: #B0C7A7;border: 1px solid #B0C7A7; outline: 0;}";

public:
	int slider_data = slider->value();
	QString season = "autumn";

private:
	void paintEvent(QPaintEvent* event);
	void setSpringSlider();
	void setAutumnSlider();
};