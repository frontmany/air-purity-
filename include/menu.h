#include <QMenu>
#include <string>
#include <QWidget>
#include <qlayout.h>
#include "qmenu.h"
#include "qpainter.h"
#include <QpaintEvent>
#include <QComboBox>
#include <QStyleOption>
#include <QScrollArea>
#include <vector>
#include<QLineEdit>

class Menu : public QComboBox {
public:
	void mousePressEvent(QMouseEvent* event);
	void onCurrentIndexChanged(int index);

	Menu(QWidget * parent, int a);
	~Menu();



private:
	int a_a;
	bool fl = true;
	QString tmp_state;
	int tmp_state_ind;

private:
	void paintEvent(QPaintEvent* event) override;

};