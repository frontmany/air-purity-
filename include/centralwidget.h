#include <QWidget>
#include <qlayout.h>
#include "qmenu.h"
#include "qpainter.h"
#include <QpaintEvent>

class CentralWidget : public QWidget {
public:
	CentralWidget();
	~CentralWidget();
	
private:
	void paintEvent(QPaintEvent* event);
};