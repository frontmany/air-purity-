#include <toolbarButton.h>
#include <mainwindow.h>


ToolbarButton::ToolbarButton(QWidget* parent , MainWindow* window) : QPushButton(parent), m_mwd(window){
	setIcon(QIcon(":/fullscrBtn2.png"));
	setIconSize(QSize(14, 14));
}



ToolbarButton::~ToolbarButton() {

}



