#include "QWidget"
#include "QPainter"
#include "QLabel"
#include "QWidget"
#include "QStyleOption"
#include "qlayout.h"
#include "QPushButton"
#include<QHboxLayout>
#include<QApplication>

class MainWindow;

class SettingsWidget : public QWidget {
public:
	SettingsWidget(QWidget* parent, MainWindow* mainwindow);
	~SettingsWidget();

public:
	QVBoxLayout* main_layout = new QVBoxLayout;
	QHBoxLayout* layout_label = new QHBoxLayout;
	QPushButton* autumn_btn = new QPushButton("Осенний семестр");
	QPushButton* spring_btn = new QPushButton("Весенний семестр");
	QSlider* slider = new QSlider(Qt::Horizontal);
	QString labelStyle = ("QLabel{ color: #ffffff;  padding: 6px;  font-weight:bold; }");

	QLabel* label1 = new QLabel("Сентябрь");

	QLabel* label2 = new QLabel("Октябрь");
	QLabel* label3 = new QLabel("Ноябрь");
	QLabel* label4 = new QLabel("Декабрь");
	QLabel* label5 = new QLabel("Январь");

	bool fl = true;
	int c = 0;

	QString autumn_style_off = "QPushButton {background-color: rgb(66, 66, 66); border-radius: 10px;padding: 10px 20px; font-size: 14px;font-weight: 400;font-family: Arial; font-weight: bold;  font-size: 13px; padding: 5px;}"
		"QPushButton:hover {background-color: rgb(117, 117, 117); outline: 0; }";

	QString autumn_style_on = "QPushButton {background-color:rgb(117, 117, 117); border-radius: 10px; padding: 10px 20px; font-size: 14px; font-weight: 400;;font-family: Arial; font-weight: bold;  font-size: 13px; padding: 5px;}"
		"QPushButton:hover {background-color:rgb(117, 117, 117); outline: 0;}";

	QString spring_style_off = "QPushButton {background-color: rgb(66, 66, 66); border-radius: 10px;padding: 10px 20px; font-size: 14px;font-weight: 400;font-family: Arial; font-weight: bold;  font-size: 13px; padding: 5px;}"
		"QPushButton:hover {background-color: rgb(117, 117, 117); outline: 0;}";

	QString spring_style_on = "QPushButton {background-color: rgb(117, 117, 117); border-radius: 10px;padding: 10px 20px; font-size: 14px;font-weight: 400;;font-family: Arial; font-weight: bold;  font-size: 13px; padding: 5px;}"
		"QPushButton:hover {background-color: rgb(117, 117, 117); outline: 0;}";

public:


private:
	void paintEvent(QPaintEvent* event);
	void setSpringSlider();
	void setAutumnSlider();
};