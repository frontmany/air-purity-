#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QList>
#include <vector>
#include "qpainter.h"
#include <QpaintEvent>
#include <QStyleOption>

class MainWindow;

class RatingWidget : public QWidget {
	Q_OBJECT
private:
	const double matfakCo2 = 523;

	const double shoCo2 = 530;

	const double gymnastCo2 = 582;

	const double trenCo2 = 833;

	const double grouppCo2 = 871;


	double length = 0;
	double cwidth = 0;
	double height = 0;
	const double Acurrent = 0;
	double currentCo2 = 0;



	QString style1 = "QPushButton {color:rgb(248, 249, 249); background-color:rgb(36, 36, 36); border-radius: 5px; border:rgb(26, 26, 26); font-family: Arial; font-size: 18px; font-weight: bold; padding: 5px;}"
		"QPushButton:hover {background-color: rgb(117, 117, 117);border: 1px solid rgb(117, 117, 117); outline: 0;}";
	QString style2 = "QPushButton {color:rgb(248, 249, 249); background-color:rgb(66, 66, 66); border-radius: 5px; border:rgb(26, 26, 26); font-family: Arial; font-size: 18px; font-weight: bold; padding: 5px;}"
		"QPushButton:hover {background-color: rgb(117, 117, 117);border: 1px solid rgb(117, 117, 117); outline: 0;}";



	QString menuSheet = "QComboBox { border-radius: 5px; padding: 2px;background: transparent;font-family: Arial; font-weight: bold;  font-size: 13px; padding: 5px;}"
		"QComboBox{border:none;background-color:rgb(66, 66, 66);color:rgb(255, 255, 255);font-weight:bold;padding:15px}"
		"QComboBox::drop-down{border:none;background-color:rgb(66, 66, 66);color:rgb(255, 255, 255);font-weight:bold;padding:0px;border-top-right-radius: 10px; border-bottom-right-radius: 10px;}"
		"QComboBox QAbstractItemView::item {color: rgb(255, 255, 255);font - weight: bold;padding: 5px;background-color:rgb(36, 36, 36);}";


private:
	void calcRating();
	void show();
	void onSortMenuChanged(int index);
	void paintEvent(QPaintEvent* event);

public:
	RatingWidget(QWidget* parent, MainWindow* mainw);
	QVBoxLayout* rate_layout;
	QHBoxLayout* adjustment_layout;
};