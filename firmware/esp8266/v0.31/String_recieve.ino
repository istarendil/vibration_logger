void recieve_string(char *punt){

  char buffa;
do{while (!Serial.available());}while(Serial.read()!='-');

  
  while (1){      
        while (!Serial.available());
        buffa=Serial.read();  
        if (buffa == '-') {*punt=0x00;return;}
        *punt=buffa;
        punt++; 
    } 
  return;
}
