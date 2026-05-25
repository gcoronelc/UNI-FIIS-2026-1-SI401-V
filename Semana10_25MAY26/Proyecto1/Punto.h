#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Punto {

private:	
	int x;
	int y;
	
public:

	Punto(){
		this->x = 0;
		this->y = 0;
	}
	
	Punto(int x, int y){
		this->x = x;
		this->y = y;
	}
	
	string getCuadrante(){
		if(this->x>0 && this->y>0){
			return "I";	
		}
		if(this->x<0 && this->y>0){
			return "II";	
		}
		if(this->x<0 && this->y<0){
			return "III";	
		}
		if(this->x>0 && this->y<0){
			return "IV";	
		}
		if(this->x==0 && this->y!=0){
			return "Eje Y";	
		}
		if(this->x!=0 && this->y==0){
			return "Eje X";	
		}
		return "Origen del plano";
	}
	
	float distancia(){
		float d = pow(this->x,2) + pow(this->y,2);
		d = sqrt(d);
		return d;
	}
	
	string getPunto(){
		string s = "(" + to_string(this->x) + "," 
			+ to_string(this->y) + ")";
		return s;
	}
};