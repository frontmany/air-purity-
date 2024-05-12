#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QLayout>
#include <QList>
#include <vector>

class RatingWidget : public QWidget {

private:
	const double Vmatfak = 3000;
	const double Amatfak = 0.53;

	const double Vsho = 2500;
	const double Asho = 0.461;

	const double Vgymnast = 3200;
	const double Agymnast = 0.761;

	const double Vtren = 1800;
	const double Atren = 0.89;

	const double Vgroupp = 1500;
	const double Agroupp = 0.80;


	double length = 0;
	double width = 0;
	double height = 0;
	const double Acurrent = 0;
private:
	void calcRating();
	void show();

};