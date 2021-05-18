#define MOTO1_L 4
#define MOTO1_R 5
#define MOTO2_L 6
#define MOTO2_R 7

#define S1 8
#define S2 9
#define S3 10
#define S4 11
#define S5 12

int sensor[5];
int error = 0;
byte SpMaxL=100;
byte SpMaxR=100;


void setup() {
  Serial.begin(9600);
  pinMode(MOTO1_L, OUTPUT);//Set chân in1 của dc A là output
  pinMode(MOTO1_R, OUTPUT);//Set chân in2 của dc A là output
  pinMode(MOTO2_L, OUTPUT);//Set chân in1 của dc B là output
  pinMode(MOTO3_R, OUTPUT);//Set chân in2 của dc B là output
  pinMode(S1, INPUT);//Set chân cảm biến 1 là input
  pinMode(S2, INPUT);//Set chân cảm biến 2 là input
  pinMode(S3, INPUT);//Set chân cảm biến 3 là input
  pinMode(S4, INPUT);//Set chân cảm biến 4 là input
  pinMode(S5, INPUT);//Set chân cảm biến 4 là input
}


void loop() {
  doline();
}

void doline()
{
  if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[4]==0)&&(sensor[4]==1))
  error=4;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[4]==1)&&(sensor[4]==1))
  error=3;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[4]==1)&&(sensor[4]==0))
  error=2;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[4]==1)&&(sensor[4]==0))
  error=1;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==1)&&(sensor[4]==0)&&(sensor[4]==0))
  error=0;
  else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==1)&&(sensor[4]==0)&&(sensor[4]==0))
  error=-1;
  else if((sensor[0]==0)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[4]==0)&&(sensor[4]==0))
  error=-2;
  else if((sensor[0]==1)&&(sensor[1]==1)&&(sensor[2]==0)&&(sensor[4]==0)&&(sensor[4]==0))
  error=-3;
  else if((sensor[0]==1)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[4]==0)&&(sensor[4]==0))
  error=-4;
  else if((sensor[0]==0)&&(sensor[1]==0)&&(sensor[2]==0)&&(sensor[4]==0)&&(sensor[4]==0))
    if(error==-4) error=-5;
    else error=5;
}

void Tien( byte speedL, byte speedR)
{
  digitalWrite(MOTO1_L, 1);
  digitalWrite(MOTO1_R, 0);
  digitalWrite(MOTO2_L, 1);
  digitalWrite(MOTO2_R, 0);
}
void Retrai()
{
  digitalWrite(MOTO1_L, 0);
  digitalWrite(MOTO1_R, 0);
  digitalWrite(MOTO2_L, 1);
  digitalWrite(MOTO2_R, 0);
}
void Rephai()
{
  digitalWrite(MOTO1_L, 1);
  digitalWrite(MOTO1_R, 0);
  digitalWrite(MOTO2_L, 0);
  digitalWrite(MOTO2_R, 0);
}
void Lui(byte SpeedL, byte SpeedR)
{
  digitalWrite(MOTO1_L, 0);
  digitalWrite(MOTO1_R, 1);
  digitalWrite(MOTO2_L, 0);
  digitalWrite(MOTO2_R, 1);
}
