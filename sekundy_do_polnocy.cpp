#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>


struct Zegar{
	int godzina;
	int minuta;
	int sekunda;
	
	Zegar(int godzina, int minuta, int sekunda);
	std::string toString();
	void next_hour();
	void next_minute();
	void next_second();
	std::string time_of_day();
	std::string to_string(std::string time_of_day);
	Zegar dodawanie(const Zegar zeg);
	Zegar odejmowanie(const Zegar zeg);
	bool czy_wiekszy(const Zegar zeg);
	bool czy_mniejszy(const Zegar zeg);
	bool czy_rowne(const Zegar zeg);
	bool czy_nierowne(const Zegar zeg);
	int count_seconds();
	int count_minutes();
	Zegar time_to_midnight();
	
};
Zegar::Zegar(int godz, int min, int sek){
		godzina = godz;
		minuta = min;
		sekunda = sek;
		}

auto main() -> int{
	
	auto zegar = Zegar(20, 51, 59);
	std::cout<<zegar.toString();
	
	
	auto zegar2 = Zegar(21, 55, 00);
	std::cout<<zegar2.toString();
	std::cout << zegar.count_seconds() << "\n";
	std::cout << zegar.count_minutes() << "\n";
	auto zegar3 = zegar2.time_to_midnight();
	
	std::cout<<zegar3.toString();
	
	return 0;
}

std::string Zegar::toString(){
	std::string godzina_string = std::to_string(godzina);
	std::string minuta_string = std::to_string(minuta);
	std::string sekundaa_string = std::to_string(sekunda);
	
	if(godzina == 24)
		godzina = 0;
	
	if(minuta == 60)
		minuta = 0;
	
	if(sekunda == 60)
		minuta = 0;

	
	if(godzina < 10)
		godzina_string = "0" + std::to_string(godzina);
	if(minuta < 10)
		minuta_string = "0" + std::to_string(minuta);
	if(sekunda < 10)
		sekundaa_string = "0" + std::to_string(sekunda);
		
	return godzina_string + ":" + minuta_string + ":" + sekundaa_string + "\n";
}
void Zegar::next_hour(){
		godzina++;
		if(godzina == 24)
			std::cout<<"Nastepna godzina to 0\n";
		else if(godzina > 24)
			std::cout<<"Nastepna godzina to 1\n";
		else
			std::cout<<"Nastepna godzina to " + godzina;
}
void Zegar::next_minute(){
	minuta++;
	if(minuta == 60)
			std::cout<<"Nastepna minuta to 0\n";
		else if(minuta > 60)
			std::cout<<"Nastepna godzina to 1\n";
		else
			std::cout<<"Nastepna godzina to " + minuta;
}
void Zegar::next_second(){
	sekunda++;
	if(sekunda == 60)
			std::cout<<"Nastepna sekunda to 0\n";
		else if(sekunda > 60)
			std::cout<<"Nastepna sekunda to 1\n";
		else
			std::cout<<"Nastepna sekunda to " + sekunda;
}
std::string Zegar::time_of_day(){
	if(godzina >= 22 || godzina < 5)
		return "noc";
	else if(godzina >= 5 && godzina < 12)
		return "rano";
	else if(godzina >= 12 && godzina < 17)
		return "dzien";
	else
		return "wieczor";
}
std::string Zegar::to_string(std::string time_of_day){
	return time_of_day;
}
Zegar Zegar::dodawanie(Zegar zeg){
	int g;
	int m;
	int s;
	
	g = godzina + zeg.godzina;
	m = minuta + zeg.minuta;
	s = sekunda + zeg.sekunda;
	
	if(s >= 60){
		s -= 60;
		m++;
	}
	if(m >= 60){
		m -= 60;
		g++;
	}
	if(g >= 24)
		g -= 24;
		
	Zegar z = Zegar(g,m,s);
	return z;
}
Zegar Zegar::odejmowanie(Zegar zeg){
	int g;
	int m;
	int s;
	
	g = godzina - zeg.godzina;
	m = minuta - zeg.minuta;
	s = sekunda - zeg.sekunda;
	
	if(s < 0){
		s += 60;
		m--;
	}
	if(m < 0){
		m += 60;
		g--;
	}
	if(g < 0)
		g += 24;
		
	Zegar z = Zegar(g,m,s);
	return z;
}
bool Zegar::czy_wiekszy(Zegar zeg){
	if(godzina > zeg.godzina)
		return true;
	else if(godzina == zeg.godzina){
		if(minuta > zeg.minuta)
			return true;
		else if(minuta == zeg.minuta){
			if(sekunda > zeg.sekunda)
				return true;
			else
				return false;
		}else 
			return false;
		return false;
	}else
		return false;
}
bool Zegar::czy_mniejszy(Zegar zeg){
	if(godzina < zeg.godzina){
		return true;
	}else if(godzina == zeg.godzina){
		if(minuta < zeg.minuta){
			return true;
		}else if(minuta == zeg.minuta){
			if(sekunda < zeg.sekunda){
				return true;
			}else
				return false;
		}else 
			return false;
	
	}else
		return false;
	
}
bool Zegar::czy_rowne(Zegar zeg){
	if(godzina != zeg.godzina)
		return false;
	return true;
}
bool Zegar::czy_nierowne(Zegar zeg){
	if(godzina != zeg.godzina)
		return true;
	return false;
}
int Zegar::count_seconds(){
	int min = minuta * 60;
	int g = godzina * 60 * 60;
	
	return sekunda + min + g;
}
int Zegar::count_minutes(){
	int g = godzina * 60;
	
	return g + minuta + 1;
}
Zegar Zegar::time_to_midnight(){
	int g = 23 - godzina;
	int m = 59 - minuta;
	int s = 60 - sekunda;
	
	if(minuta == 0)
		m = 59;
	if(sekunda == 0)
		s = 59;
	if(godzina == 24)
		g = 0;
	return Zegar(g,m,s);
}
