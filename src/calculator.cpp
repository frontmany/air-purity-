#include "calculator.h"


double Calculator::getCo2() {
	return co2;
}
std::vector<double> Calculator::getAllYearCo2() {
	return allco2;
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

std::vector<double> Calculator::getAllYearDust(){
	std::vector<double> alldust;
	
	if (build == "Школа Компьютерных Наук") {
		for (auto j : k) {
			double monthdustvalue = idd[0] * j;
			alldust.push_back(monthdustvalue);
		}
	}
	if (build == "Школа Образования") {
		for (auto j : k) {
			double monthdustvalue = idd[1] * j;
			alldust.push_back(monthdustvalue);
		}
	}
	if (build == "Олимпия: Гимнастический Зал") {
		for (auto j : k) {
			double monthdustvalue = idd[2] * j;
			alldust.push_back(monthdustvalue);
		}
	}
	if (build == "Олимпия: Тренажерный Зал") {
		for (auto j : k) {
			double monthdustvalue = idd[3] * j;
			alldust.push_back(monthdustvalue);
		}
	}
	if (build == "Олимпия: Зал Групповых Программ") {
		for (auto j : k) {
			double monthdustvalue = idd[4] * j;
			alldust.push_back(monthdustvalue);
		}
	}
	return alldust;
}

void Calculator::calcAllYearCo2() {
	if (build == "Школа Компьютерных Наук") {
		for (int i = 0; i < 10; i++) {
			double monthco2value = 350 + (body_count * MCO2 * t / Vmatfak * Avec_matfak[i]);
			allco2.push_back(monthco2value);
		}
	}
	if (build == "Школа Образования") {
		for (int i = 0; i < 10; i++) {
			double monthco2value = 350 + (body_count * MCO2 * t / Vsho * Avec_sho[i]);
			allco2.push_back(monthco2value);
		}
	}
	if (build == "Олимпия: Гимнастический Зал") {
		for (int i = 0; i < 10; i++) {
			double monthco2value = 350 + (body_count * MCO2 * t / Vgymnast * Avec_gymnast[i]);
			allco2.push_back(monthco2value);
		}
	}
	if (build == "Олимпия: Тренажерный Зал") {
		for (int i = 0; i < 10; i++) {
			double monthco2value = 350 + (body_count * MCO2 * t / Vtren * Avec_tren[i]);
			allco2.push_back(monthco2value);
		}
	}
	if (build == "Олимпия: Зал Групповых Программ") {
		for (int i = 0; i < 10; i++) {
			double monthco2value = 350 + (body_count * MCO2 * t / Vgroupp * Avec_groupp[i]);
			allco2.push_back(monthco2value);
		}
	}
	
}

double Calculator::calcCo2() {
	if (build == "Школа Компьютерных Наук") {
		if (month == "Январь") return 350 + (body_count * MCO2 * t / Vmatfak * Avec_matfak[0]);
		if (month == "Февраль") return 350 + (body_count * MCO2 * t / Vmatfak * Avec_matfak[1]);
		if (month == "Март") return 350 + (body_count * MCO2 * t / Vmatfak * Avec_matfak[2]);
		if (month == "Апрель") return 350 + (body_count * MCO2 * t / Vmatfak * Avec_matfak[3]);
		if (month == "Май") return 350 + (body_count * MCO2 * t / Vmatfak * Avec_matfak[4]);
		if (month == "Июнь") return 350 + (body_count * MCO2 * t / Vmatfak * Avec_matfak[5]);
		if (month == "Сентябрь") return 350 + (body_count * MCO2 * t / Vmatfak * Avec_matfak[6]);
		if (month == "Октябрь") return 350 + (body_count * MCO2 * t / Vmatfak * Avec_matfak[7]);
		if (month == "Ноябрь") return 350 + (body_count * MCO2 * t / Vmatfak * Avec_matfak[8]);
		if (month == "Декабрь") return 350 + (body_count * MCO2 * t / Vmatfak * Avec_matfak[9]);
	}
	if (build == "Школа Образования") {
		if (month == "Январь") return 350 + (body_count * MCO2 * t / Vsho * Avec_sho[0]);
		if (month == "Февраль") return 350 + (body_count * MCO2 * t / Vsho * Avec_sho[1]);
		if (month == "Март") return 350 + (body_count * MCO2 * t / Vsho * Avec_sho[2]);
		if (month == "Апрель") return 350 + (body_count * MCO2 * t / Vsho * Avec_sho[3]);
		if (month == "Май") return 350 + (body_count * MCO2 * t / Vsho * Avec_sho[4]);
		if (month == "Июнь") return 350 + (body_count * MCO2 * t / Vsho * Avec_sho[5]);
		if (month == "Сентябрь") return 350 + (body_count * MCO2 * t / Vsho * Avec_sho[6]);
		if (month == "Октябрь") return 350 + (body_count * MCO2 * t / Vsho * Avec_sho[7]);
		if (month == "Ноябрь") return 350 + (body_count * MCO2 * t / Vsho * Avec_sho[8]);
		if (month == "Декабрь") return 350 + (body_count * MCO2 * t / Vsho * Avec_sho[9]);
	}
	if (build == "Олимпия: Гимнастический Зал") {
		if (month == "Январь") return 350 + (body_count * MCO2 * t / Vgymnast * Avec_gymnast[0]);
		if (month == "Февраль") return 350 + (body_count * MCO2 * t / Vgymnast * Avec_gymnast[1]);
		if (month == "Март") return 350 + (body_count * MCO2 * t / Vgymnast * Avec_gymnast[2]);
		if (month == "Апрель") return 350 + (body_count * MCO2 * t / Vgymnast * Avec_gymnast[3]);
		if (month == "Май") return 350 + (body_count * MCO2 * t / Vgymnast * Avec_gymnast[4]);
		if (month == "Июнь") return 350 + (body_count * MCO2 * t / Vgymnast * Avec_gymnast[5]);
		if (month == "Сентябрь") return 350 + (body_count * MCO2 * t / Vgymnast * Avec_gymnast[6]);
		if (month == "Октябрь") return 350 + (body_count * MCO2 * t / Vgymnast * Avec_gymnast[7]);
		if (month == "Ноябрь") return 350 + (body_count * MCO2 * t / Vgymnast * Avec_gymnast[8]);
		if (month == "Декабрь") return 350 + (body_count * MCO2 * t / Vgymnast * Avec_gymnast[9]);
	}
	if (build == "Олимпия: Тренажерный Зал") {
		if (month == "Январь") return 350 + (body_count * MCO2 * t / Vtren * Avec_tren[0]);
		if (month == "Февраль") return 350 + (body_count * MCO2 * t / Vtren * Avec_tren[1]);
		if (month == "Март") return 350 + (body_count * MCO2 * t / Vtren * Avec_tren[2]);
		if (month == "Апрель") return 350 + (body_count * MCO2 * t / Vtren * Avec_tren[3]);
		if (month == "Май") return 350 + (body_count * MCO2 * t / Vtren * Avec_tren[4]);
		if (month == "Июнь") return 350 + (body_count * MCO2 * t / Vtren * Avec_tren[5]);
		if (month == "Сентябрь") return 350 + (body_count * MCO2 * t / Vtren * Avec_tren[6]);
		if (month == "Октябрь") return 350 + (body_count * MCO2 * t / Vtren * Avec_tren[7]);
		if (month == "Ноябрь") return 350 + (body_count * MCO2 * t / Vtren * Avec_tren[8]);
		if (month == "Декабрь") return 350 + (body_count * MCO2 * t / Vtren * Avec_tren[9]);
	}
	if (build == "Олимпия: Зал Групповых Программ") {
		if (month == "Январь") return 350 + (body_count * MCO2 * t / Vgroupp * Avec_groupp[0]);
		if (month == "Февраль") return 350 + (body_count * MCO2 * t / Vgroupp * Avec_groupp[1]);
		if (month == "Март") return 350 + (body_count * MCO2 * t / Vgroupp * Avec_groupp[2]);
		if (month == "Апрель") return 350 + (body_count * MCO2 * t / Vgroupp * Avec_groupp[3]);
		if (month == "Май") return 350 + (body_count * MCO2 * t / Vgroupp * Avec_groupp[4]);
		if (month == "Июнь") return 350 + (body_count * MCO2 * t / Vgroupp * Avec_groupp[5]);
		if (month == "Сентябрь") return 350 + (body_count * MCO2 * t / Vgroupp * Avec_groupp[6]);
		if (month == "Октябрь") return 350 + (body_count * MCO2 * t / Vgroupp * Avec_groupp[7]);
		if (month == "Ноябрь") return 350 + (body_count * MCO2 * t / Vgroupp * Avec_groupp[8]);
		if (month == "Декабрь") return 350 + (body_count * MCO2 * t / Vgroupp * Avec_groupp[9]);
	}
}

double Calculator::calcDust() {
	if (build == "Школа Компьютерных Наук") {
		if (month == "Январь") return k[0] * idd[0];
		if (month == "Февраль") return k[1] * idd[0];
		if (month == "Март") return k[2] * idd[0];
		if (month == "Апрель") return k[3] * idd[0];
		if (month == "Май") return k[4] * idd[0];
		if (month == "Июнь") return k[5] * idd[0];
		if (month == "Сентябрь") return k[6] * idd[0];
		if (month == "Октябрь") return k[7] * idd[0];
		if (month == "Ноябрь") return k[8] * idd[0];
		if (month == "Декабрь") return k[9] * idd[0];
	}
	if (build == "Школа Образования") {
		if (month == "Январь") return k[0] * idd[1];
		if (month == "Февраль") return k[1] * idd[1];
		if (month == "Март") return k[2] * idd[1];
		if (month == "Апрель") return k[3] * idd[1];
		if (month == "Май") return k[4] * idd[1];
		if (month == "Июнь") return k[5] * idd[1];
		if (month == "Сентябрь") return k[6] * idd[1];
		if (month == "Октябрь") return k[7] * idd[1];
		if (month == "Ноябрь") return k[8] * idd[1];
		if (month == "Декабрь") return k[9] * idd[1];
	}
	if (build == "Олимпия: Гимнастический Зал") {
		if (month == "Январь") return k[0] * idd[2];
		if (month == "Февраль") return k[1] * idd[2];
		if (month == "Март") return k[2] * idd[2];
		if (month == "Апрель") return k[3] * idd[2];
		if (month == "Май") return k[4] * idd[2];
		if (month == "Июнь") return k[5] * idd[2];
		if (month == "Сентябрь") return k[6] * idd[2];
		if (month == "Октябрь") return k[7] * idd[2];
		if (month == "Ноябрь") return k[8] * idd[2];
		if (month == "Декабрь") return k[9] * idd[2];
	}
	if (build == "Олимпия: Тренажерный Зал") {
		if (month == "Январь") return k[0] * idd[3];
		if (month == "Февраль") return k[1] * idd[3];
		if (month == "Март") return k[2] * idd[3];
		if (month == "Апрель") return k[3] * idd[3];
		if (month == "Май") return k[4] * idd[4];
		if (month == "Июнь") return k[5] * idd[5];
		if (month == "Сентябрь") return k[6] * idd[3];
		if (month == "Октябрь") return k[7] * idd[3];
		if (month == "Ноябрь") return k[8] * idd[3];
		if (month == "Декабрь") return k[9] * idd[3];
	}
	if (build == "Олимпия: Зал Групповых Программ") {
		if (month == "Январь") return k[0] * idd[4];
		if (month == "Февраль") return k[1] * idd[4];
		if (month == "Март") return k[2] * idd[4];
		if (month == "Апрель") return k[3] * idd[4];
		if (month == "Май") return k[4] * idd[4];
		if (month == "Июнь") return k[5] * idd[4];
		if (month == "Сентябрь") return k[6] * idd[4];
		if (month == "Октябрь") return k[7] * idd[4];
		if (month == "Ноябрь") return k[8] * idd[4];
		if (month == "Декабрь") return k[9] * idd[4];
	}

}

Calculator::Calculator(QString month, int bodyCount, QString building) {
	build = building;
	body_count = bodyCount;
	this->month = month;
	
	
	
	calcAllYearCo2();
	co2 = calcCo2();
	dust_value = calcDust();
}



Calculator::~Calculator() {

}