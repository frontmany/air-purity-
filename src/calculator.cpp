#include "calculator.h"

double Calculator::getCo2() {
	return co2;
}
int Calculator::getBodyCount() {
	return co2;
}
int Calculator::getMark() {
	return mark;
}
QString Calculator::getMonth() {
	return month;
}
QString Calculator::getDescription() {
	return description;
}
QString Calculator::getBuilding() {
	return build;
}


Calculator::Calculator(int sliderPos, int bodyCount, QString season, QString building) {
	build = building;
	if (season == "spring") {
		switch (sliderPos) {
		case 1:
			month = "Февраль";
			break;
		case 2:
			month = "Март";
			break;
		case 3:
			month = "Апрель";
			break;
		case 4:
			month = "Май";
			break;
		case 5:
			month = "Июнь";
			break;
		}

	}


	if (season == "autumn") {
		switch (sliderPos) {
		case 1:
			month = "Сентябрь";
			break;
		case 2:
			month = "Октябрь";
			break;
		case 3:
			month = "Ноябрь";
			break;
		case 4:
			month = "Декабрь";
			break;
		case 5:
			month = "Январь";
			break;
		}

	}

	if (building == "Школа Компьютерных Наук") {
		if (month == "Сентябрь") {
			co2 = ((75 * 0.017 * bodyCount) / (7 * Vmatfak)) * Vmatfak * 90;
		}
		if (month == "Октябрь") {
			co2 = ((75 * 0.017 * bodyCount) / (4.5 * Vmatfak)) * Vmatfak * 90;
		}
		if (month == "Ноябрь") {
			co2 = ((75 * 0.017 * bodyCount) / (3.5 * Vmatfak)) * Vmatfak * 90;
		}
		if (month == "Декабрь" || month == "Январь" || month == "Февраль") {
			co2 = ((75 * 0.017 * bodyCount) / (2.5 * Vmatfak)) * Vmatfak * 90;
		}
		if (month == "Март") {
			co2 = ((75 * 0.017 * bodyCount) / (3.5 * Vmatfak)) * Vmatfak * 90;
		}
		if (month == "Апрель") {
			co2 = ((75 * 0.017 * bodyCount) / (4.5 * Vmatfak)) * Vmatfak * 90;
		}
		if (month == "Май") {
			co2 = ((75 * 0.017 * bodyCount) / (5.5 * Vmatfak)) * Vmatfak * 90;
		}
		if (month == "Июнь") {
			co2 = ((75 * 0.017 * bodyCount) / (7 * Vmatfak)) * Vmatfak * 90;
		}
	}
	
	else {
		if (month == "Сентябрь") {
			co2 = ((75 * 0.017 * bodyCount) / (5.5 * Vmatfak)) * Vmatfak * 90;
		}
		if (month == "Октябрь") {
			co2 = ((75 * 0.017 * bodyCount) / (3.5 * Vmatfak)) * Vmatfak * 90;
		}
		if (month == "Ноябрь") {
			co2 = ((75 * 0.017 * bodyCount) / (2.5 * Vmatfak)) * Vmatfak * 90;
		}
		if (month == "Декабрь" || month == "Январь" || month == "Февраль") {
			co2 = ((75 * 0.017 * bodyCount) / (1.5 * Vmatfak)) * Vmatfak * 90;
		}
		if (month == "Март") {
			co2 = ((75 * 0.017 * bodyCount) / (2.5 * Vmatfak)) * Vmatfak * 90;
		}
		if (month == "Апрель") {
			co2 = ((75 * 0.017 * bodyCount) / (3.5 * Vmatfak)) * Vmatfak * 90;
		}
		if (month == "Май") {
			co2 = ((75 * 0.017 * bodyCount) / (4.5 * Vmatfak)) * Vmatfak * 90;
		}
		if (month == "Июнь") {
			co2 = ((75 * 0.017 * bodyCount) / (6 * Vmatfak)) * Vmatfak * 90;
		}
	}
	
	if (co2 < 800) {
		mark = 5;
		description = "Воздух чистый и свежий, с низким уровнем CO2. Дышать легко и приятно.";
	}
	if (co2 >= 800 && co2 <=1000) {
		mark = 4;
		description = "Воздух в целом чистый, но уровень CO2 начинает повышаться. Воздух может казаться немного затхлым, особенно в конце пары.";
	}
	if (co2 > 1000 && co2 < 1200) {
		mark = 3;
		description = "Воздух становится затхлым, и уровень CO2 заметно повышен. Воздух может вызывать дискомфорт при дыхании, особенно у людей с респираторными заболеваниями.";
	}
	if (co2 >= 1200 && co2 <= 1500) {
		mark = 2;
		description = "Воздух становится некомфортным для дыхания, и уровень CO2 значительно повышен. Воздух может вызывать головные боли, головокружение и другие симптомы.";
	}
	if (co2 > 1500) {
		mark = 1;
		description = "Воздух опасен для здоровья, и уровень CO2 чрезвычайно высок. Воздух может вызвать серьезные проблемы со здоровьем, включая потерю сознания.";
	}



}



Calculator::~Calculator() {

}