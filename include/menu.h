#include <QMenu>
#include <QWidget>
#include <qlayout.h>
#include "qmenu.h"
#include "qpainter.h"
#include <QpaintEvent>
#include <QComboBox>

class Menu : public QComboBox {
public:
	Menu(int a);
	~Menu();

private:
	void paintEvent(QPaintEvent* event) override;

};