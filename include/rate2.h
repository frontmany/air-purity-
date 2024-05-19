#pragma once
#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QList>
#include <QDialog>
#include <vector>
#include "qpainter.h"
#include <QpaintEvent>
#include <QStyleOption>
#include <QMenu>
#include <QTextEdit>

class MainWindow;
class RatingWidget;

class RatingWidget2 : public QWidget {

public:
	void paintEvent(QPaintEvent* event);
	RatingWidget2(QWidget* parent, MainWindow* mainw, RatingWidget* wid);
	~RatingWidget2();
	void errGymCheck();
	void addGym();
	void errclear();


private:
	MainWindow* mainWindow;
	RatingWidget* rate_widget;

	QVBoxLayout* rate_layout2;
	QLineEdit* edit1;
	QLineEdit* edit2;
	QLineEdit* edit3;
	bool check1;
	bool check2;
	bool check3;
private:

	QString style1 = "QPushButton {color:rgb(248, 249, 249); background-color:rgb(36, 36, 36); border-radius: 5px; border:rgb(26, 26, 26); font-family: Arial; font-size: 18px; font-weight: bold; padding: 5px;}"
		"QPushButton:hover {background-color: rgb(117, 117, 117);border: 1px solid rgb(117, 117, 117); outline: 0;}";
	QString style2 = "QPushButton {color:rgb(248, 249, 249); background-color:rgb(66, 66, 66); border-radius: 5px; border:rgb(26, 26, 26); font-family: Arial; font-size: 18px; font-weight: bold; padding: 5px;}"
		"QPushButton:hover {background-color: rgb(117, 117, 117);border: 1px solid rgb(117, 117, 117); outline: 0;}";

	QString menuSheet = "QComboBox { border-radius: 5px; padding: 2px;background: transparent;font-family: Arial; font-weight: bold;  font-size: 13px; padding: 5px;}"
		"QComboBox{border:none;background-color:rgb(66, 66, 66);color:rgb(255, 255, 255);font-weight:bold;padding:15px}"
		"QComboBox::drop-down{border:none;background-color:rgb(66, 66, 66);color:rgb(255, 255, 255);font-weight:bold;padding:0px;border-top-right-radius: 10px; border-bottom-right-radius: 10px;}"
		"QComboBox QAbstractItemView::item {color: rgb(255, 255, 255);font - weight: bold;padding: 5px;background-color:rgb(36, 36, 36);}";

	QString labelStyle = ("QLabel{ color:rgb(209, 222, 240);  background-color:rgb(40, 40, 40); font-family: Arial; font-size: 18px;font-weight: bold;padding: 5px;border-radius: 5px;}");
	QString labelStyle2 = ("QLabel{ color:rgb(202, 207, 210);  background-color:rgb(40, 40, 40); font-family: Arial; font-size: 13px;font-weight: bold;padding: 5px;border-radius: 5px;}");

	QString lineEdStyle = ("QLineEdit {"
		"color: white;"
		"font-family: Arial; "
		"font-weight: bold;"
		"font-size: 18px;"
		"background-color:rgb(36, 36, 36);"
		"border: 2px solid gray;"
		"border-radius: 5px;"
		"padding: 0 8px;"
		"selection-background-color: darkgray;"
		"selection-color:rgb(36, 36, 36);"
		"}");

	QString errlineEdStyle = ("QLineEdit {"
		"color: white;"
		"font-family: Arial; "
		"font-weight: bold;"
		"font-size: 18px;"
		"background-color:rgb(36, 36, 36);"
		"border: 2px solid red;"
		"border-radius: 5px;"
		"padding: 0 8px;"
		"selection-background-color: darkgray;"
		"selection-color:rgb(36, 36, 36);"
		"}");

	QString lineEdStyle2 = ("QLineEdit {"
		"color: white;"
		"font-family: Arial; "
		"font-weight: bold;"
		"font-size: 20px;"
		"background-color:rgb(36, 36, 36);"
		"border: 2px solid gray;"
		"border-radius: 5px;"
		"padding: 0 8px;"
		"selection-background-color: darkgray;"
		"selection-color:rgb(36, 36, 36);"
		"}");

	QString errlineEdStyle2 = ("QLineEdit {"
		"color: white;"
		"font-family: Arial; "
		"font-weight: bold;"
		"font-size: 20px;"
		"background-color:rgb(36, 36, 36);"
		"border: 2px solid red;"
		"border-radius: 5px;"
		"padding: 0 8px;"
		"selection-background-color: darkgray;"
		"selection-color:rgb(36, 36, 36);"
		"}");

};