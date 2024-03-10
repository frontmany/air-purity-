#include <QMenu>
#include <QWidget>
#include <qlayout.h>
#include "qmenu.h"
#include "qpainter.h"
#include <QpaintEvent>
#include <QComboBox>
#include <QStyleOption>
#include <QScrollArea>
#include <vector>

class Menu : public QComboBox {
public:
	Menu(int a);
	~Menu();

private:
	void paintEvent(QPaintEvent* event) override;

};