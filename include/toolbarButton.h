#include <qpushbutton.h>
#include <QStyleOption>
#include "qpainter.h"


class MainWindow;

class ToolbarButton : public QPushButton {

public:
	ToolbarButton(QWidget* parent,  MainWindow* window);
	~ToolbarButton();
	


private:
	MainWindow* m_mwd;
	

};