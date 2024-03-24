#include "settingsWidget.h"

SettingsWidget::SettingsWidget(QWidget* parent) : QWidget(parent) {
	setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	setMaximumSize(800, 400);
	
}

void SettingsWidget::paintEvent(QPaintEvent* event) {
	QColor color1(26, 26, 26);

	QStyleOption opt;
	opt.initFrom(this);

	QPainter painter(this);
	QPen pen(color1);
	pen.setWidth(2);
	painter.setPen(pen);
	painter.setRenderHint(QPainter::Antialiasing);
	painter.setBrush(color1);
	painter.drawRoundedRect(opt.rect, 15, 15);

	
}

SettingsWidget::~SettingsWidget() {

}