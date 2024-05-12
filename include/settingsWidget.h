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
	Q_OBJECT
public:
	SettingsWidget(QWidget* parent, MainWindow* mainwindow);
	~SettingsWidget();

public:
	QVBoxLayout* main_layout = new QVBoxLayout;
	QHBoxLayout* layout_label = new QHBoxLayout;
	QPushButton* autumn_btn = new QPushButton("Осенний семестр");
	QPushButton* spring_btn = new QPushButton("Весенний семестр");
	QString labelStyle = ("QPushButton {background-color: rgb(34, 34, 34); border-radius: 5px;padding: 10px 20px; font-size: 12px;font-weight: 400;font-family: Arial; font-weight: bold;  font-size: 13px; padding: 5px;} QPushButton:hover {background-color: rgb(117, 117, 117); outline: 0; }");

	QPushButton* label1 = new QPushButton("Сентябрь");
	QPushButton* label2 = new QPushButton("Октябрь");
	QPushButton* label3 = new QPushButton("Ноябрь");
	QPushButton* label4 = new QPushButton("Декабрь");
	QPushButton* label5 = new QPushButton("Январь");

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

signals:
	void buttonClicked(int index);

private slots:


private:
	void paintEvent(QPaintEvent* event);
	void setSpringSlider();
	void setAutumnSlider();
};