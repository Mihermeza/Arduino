#define roj_1 2
#define ama_1 3
#define ver_1 4
#define roj_2 5
#define ama_2 6
#define ver_2 7

boolean A,B,C,D;
boolean Q,R,S,T,U,V;

void semaforo(boolean A, boolean B, boolean C, boolean D){
    Q = (!A&(!B|!C)); ///Verde 1
    R = ((!A&B&C&!D)|(A&B&C&D)|(A&!B&!C&!D)); ///Amarillo 1
    S = (A&((B&!C)|(!B&D)|(C&!D)));///Rojo 1
    T = ((A&B&!C&!D)|((A&!B)&(C|D))); ///Verde 2
    V = (!A|(!B&!C&!D)); ///Rojo 2
    U = ((A&B&D));///Amarillo 2
    if (A == 1 && B == 1 && C == 1 && D == 1){
      digitalWrite(roj_1, 0);
      digitalWrite(roj_2, 0);
      digitalWrite(ama_1, 1);
      digitalWrite(ama_2, 1);  
      delay(1000);  
      digitalWrite(ama_1, 0);
      digitalWrite(ama_2, 0);  
      delay(1000);  
      digitalWrite(ama_1, 1);
      digitalWrite(ama_2, 1);  
      delay(1000);  
      digitalWrite(ama_1, 0);
      digitalWrite(ama_2, 0);  
      delay(1000);  
      digitalWrite(ama_1, 1);
      digitalWrite(ama_2, 1);  
      delay(1000);  
    }else{
      digitalWrite(roj_1, S);
      digitalWrite(roj_2, V); 
      digitalWrite(ama_1, R);
      digitalWrite(ama_2, U); 
      digitalWrite(ver_1, Q);
      digitalWrite(ver_2, T); 
      delay(1000);  
    }
}
void setup() {
  pinMode(roj_1, OUTPUT);
  pinMode(roj_2, OUTPUT);
  pinMode(ama_1, OUTPUT);
  pinMode(ama_2, OUTPUT);
  pinMode(ver_1, OUTPUT);
  pinMode(ver_2, OUTPUT);
}

void loop() {
  semaforo(0,0,0,0);
  semaforo(0,0,0,1);
  semaforo(0,0,1,0);
  semaforo(0,0,1,1);
  semaforo(0,1,0,0);
  semaforo(0,1,0,1);
  semaforo(0,1,1,0);
  semaforo(0,1,1,1);
  semaforo(1,0,0,0);
  semaforo(1,0,0,1);
  semaforo(1,0,1,0);
  semaforo(1,0,1,1);
  semaforo(1,1,0,0);
  semaforo(1,1,0,1);
  semaforo(1,1,1,0);
  semaforo(1,1,1,1);
}
