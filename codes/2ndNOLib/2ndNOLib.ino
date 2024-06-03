#define dirPin1 2
#define stepPin1 3
#define ena1 6

#define dirPin2 4
#define stepPin2 5
#define ena2 7

int p = 0;
int count = 0;
int x = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(stepPin1, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(ena1,OUTPUT);

  digitalWrite(ena1,LOW);

  Serial.begin(9600);
  pinMode(stepPin2, OUTPUT);
  pinMode(dirPin2, OUTPUT);
  pinMode(ena2,OUTPUT);

  digitalWrite(ena2,LOW);
  //startZ();
}

void loop() {
  startZ(x);
  
}

void startZ(int a){
  while(a < 10){
    digitalWrite(dirPin1, HIGH);   //go upword - high
    digitalWrite(dirPin2, HIGH);

    digitalWrite(stepPin1, HIGH);
    digitalWrite(stepPin2, HIGH);
    delayMicroseconds(1000);

    digitalWrite(stepPin1, LOW);
    digitalWrite(stepPin2, LOW);
    delayMicroseconds(1000);
    a++;
    //Serial.println(x);

       //go upword - high
    //digitalWrite(stepPin2, HIGH);
    //delayMicroseconds(500);
    
    //delayMicroseconds(500);
  }
  
  //return x++;

}

// void startTable(){
//   int x = 0
//   while(x<2000){
    
//     x++;
//   }
// }
