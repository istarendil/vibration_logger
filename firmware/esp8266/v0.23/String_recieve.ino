void recieve_string(char *punt){

  char buffer;
do{while (!Serial.available());}while(Serial.read()!='"');

  while (1){      
        while (!Serial.available());
        buffer=Serial.read();  
        if (buffer == '"') {return ;}
        *punt=buffer;
        punt++; 
    } 
  return;
}
