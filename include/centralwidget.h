#include <QWidget>
#include <qlayout.h>
#include "qmenu.h"
#include "qpainter.h"
#include <QpaintEvent>
#include <QStyleOption>
#include <Qlabel>
#include <QVboxLayout>
#include <QHboxLayout>
#include <QPushbutton>
#include <QMenu>
#include <QScrollArea>
#include <QStyledItemDelegate>
#include <QStringLiteral>
#include <QPixmap>

class CentralWidget : public QWidget {
public:
	CentralWidget();
	~CentralWidget();
	
public:
	int body_count;
	QString building;

private:
	void paintEvent(QPaintEvent* event);
};