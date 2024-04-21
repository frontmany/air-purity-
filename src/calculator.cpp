#include "calculator.h"

double Calculator::getCo2Value() {
	int co2_value = co2 / 25;
	if (co2_value < 10) return 2;
	return  co2_value;

}
double Calculator::getCo2() {
	return co2;
}

int Calculator::getBodyCount() {
	return body_count;
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
double Calculator::getDustValue() {
	return dust_value;
}
std::vector<double> Calculator::getAllYearCo2(){
	std::vector<double> allco2;
	
	if (build == "Школа Компьютерных Наук") {
		double list[10] = { 7, 4.59, 3.6, 2.7, 2.5, 2.9, 3.7, 4.5, 5.5, 7.7 };
		for (auto i : list) {
			double monthco2value = ((75 * 0.017 * body_count) / (i * Vmatfak)) * Vmatfak * 90;
			allco2.push_back(monthco2value);
		}
	}
	else {
		double list[10] = { 5.5, 3.6, 2.6, 2.7, 2.5, 2.9, 2.8, 3.5, 4.5, 6 };
		for (auto i : list) {
			double monthco2value  = ((75 * 0.017 * body_count) / (i * Vmatfak)) * Vmatfak * 90;
			allco2.push_back(monthco2value);
		}
	}
	return allco2;
}

std::vector<double> Calculator::getAllYearDust() {
	std::vector<double> alldust;
	if (build == "Школа Компьютерных Наук") {
		double list[10] = { 1.41, 1.31, 1.21, 1.11, 1.12, 1.1, 1.2, 1.3, 1.4, 1.5 };
		for (auto i : list) {
			double monthdustvalue = (body_count * Vmatfak * pollution * i) / 1200;
			alldust.push_back(monthdustvalue);
		}
	}
	else {
		double list[10] = { 1.41, 1.31, 1.21, 1.11, 1.12, 1.1, 1.2, 1.3, 1.4, 1.5};
		for (auto i : list) {
			double monthdustvalue = (body_count * Vmatfak * pollution * i) / 1200;
			alldust.push_back(monthdustvalue);
		}
	}
	return alldust;
}

Calculator::Calculator(int sliderPos, int bodyCount, QString season, QString building) {
	build = building;
	body_count = bodyCount;

	int realPos = std::floor(sliderPos / 60);
	

	if (season == "spring") {
		switch (realPos) {
		case 0:
			month = "Февраль";
			break;
		case 1:
			month = "Март";
			break;
		case 2:
			month = "Апрель";
			break;
		case 3:
			month = "Май";
			break;
		case 4:
			month = "Июнь";
			break;
		}

	}


	if (season == "autumn") {
		switch (realPos) {
		case 0:
			month = "Сентябрь";
			break;
		case 1:
			month = "Октябрь";
			break;
		case 2:
			month = "Ноябрь";
			break;
		case 3:
			month = "Декабрь";
			break;
		case 4:
			month = "Январь";
			break;
		}

	}

	if (building == "Школа Компьютерных Наук") {
		if (month == "Сентябрь") {
			co2 = ((75 * 0.017 * bodyCount) / (7 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.41) / 1200;
		}
		if (month == "Октябрь") {
			co2 = ((75 * 0.017 * bodyCount) / (4.59 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.31) / 1200;
		}
		if (month == "Ноябрь") {
			co2 = ((75 * 0.017 * bodyCount) / (3.6 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.21) / 1200;
		}
		if (month == "Декабрь") {
			co2 = ((75 * 0.017 * bodyCount) / (2.7 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.11) / 1200;
		}
		if (month == "Январь") {
			co2 = ((75 * 0.017 * bodyCount) / (2.5 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.12) / 1200;
		}
		if (month == "Февраль") {
			co2 = ((75 * 0.017 * bodyCount) / (2.9 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.1) / 1200;
		}
		if (month == "Март") {
			co2 = ((75 * 0.017 * bodyCount) / (3.7 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.2) / 1200;
		}
		if (month == "Апрель") {
			co2 = ((75 * 0.017 * bodyCount) / (4.5 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.3) / 1200;
		}
		if (month == "Май") {
			co2 = ((75 * 0.017 * bodyCount) / (5.5 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.4) / 1200;
		}
		if (month == "Июнь") {
			co2 = ((75 * 0.017 * bodyCount) / (7.7 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.5) / 1200;
		}


	}
	
	else {
		if (month == "Сентябрь") {
			co2 = ((75 * 0.017 * bodyCount) / (5.5 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.41) / 1200;
		}
		if (month == "Октябрь") {
			co2 = ((75 * 0.017 * bodyCount) / (3.6 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.31) / 1200;
		}
		if (month == "Ноябрь") {
			co2 = ((75 * 0.017 * bodyCount) / (2.6 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.21) / 1200;
		}
		if (month == "Декабрь") {
			co2 = ((75 * 0.017 * bodyCount) / (2.7 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.11) / 1200;
		}
		if (month == "Январь") {
			co2 = ((75 * 0.017 * bodyCount) / (2.5 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.12) / 1200;
		}
		if (month == "Февраль") {
			co2 = ((75 * 0.017 * bodyCount) / (2.9 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.1) / 1200;
		}
		if (month == "Март") {
			co2 = ((75 * 0.017 * bodyCount) / (2.8 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.2) / 1200;
		}
		if (month == "Апрель") {
			co2 = ((75 * 0.017 * bodyCount) / (3.5 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.3) / 1200;
		}
		if (month == "Май") {
			co2 = ((75 * 0.017 * bodyCount) / (4.5 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.4) / 1200;
		}
		if (month == "Июнь") {
			co2 = ((75 * 0.017 * bodyCount) / (6 * Vmatfak)) * Vmatfak * 90;
			dust_value = (bodyCount * Vmatfak * pollution * 1.5) / 1200;
		}


	}
	
	if (co2 < 800) {
		mark = 5;
		description = "Воздух чистый и свежий, с низким уровнем CO2.\nДышать легко и приятно.";
	}
	if (co2 >= 800 && co2 <=1000) {
		mark = 4;
		description = "Воздух в целом чистый,\nно уровень CO2 начинает повышаться.\nВоздух может казаться немного затхлым,\nособенно в конце пары.";
	}
	if (co2 > 1000 && co2 < 1200) {
		mark = 3;
		description = "Воздух становится затхлым,\nуровень CO2 заметно повышен.\nВоздух может вызывать дискомфорт при дыхании,\nособенно у людей с респираторными заболеваниями.";
	}
	if (co2 >= 1200 && co2 <= 1500) {
		mark = 2;
		description = "Воздух становится некомфортным для дыхания,\nуровень CO2 значительно повышен.\nВоздух может вызывать головные боли,\nголовокружение и другие симптомы.";
	}
	if (co2 > 1500) {
		mark = 1;
		description = "Воздух опасен для здоровья,\nуровень CO2 чрезвычайно высок.\nВоздух вызвает серьезные проблемы со здоровьем,\nвключая потерю сознания.";
	}



}



Calculator::~Calculator() {

}