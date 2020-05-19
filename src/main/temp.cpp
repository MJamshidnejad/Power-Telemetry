enum MB_FC
{
    MB_FC_NONE                     = 0,   /*!< null operator */
    MB_FC_READ_COILS               = 1,	/*!< FCT=1 -> read coils or digital outputs */
    MB_FC_READ_DISCRETE_INPUT      = 2,	/*!< FCT=2 -> read digital inputs */
    MB_FC_READ_REGISTERS           = 3,	/*!< FCT=3 -> read registers or analog outputs */
    MB_FC_READ_INPUT_REGISTER      = 4,	/*!< FCT=4 -> read analog inputs */
    MB_FC_WRITE_COIL               = 5,	/*!< FCT=5 -> write single coil or output */
    MB_FC_WRITE_REGISTER           = 6,	/*!< FCT=6 -> write single register */
    MB_FC_WRITE_MULTIPLE_COILS     = 15,	/*!< FCT=15 -> write multiple coils or outputs */
    MB_FC_WRITE_MULTIPLE_REGISTERS = 16	/*!< FCT=16 -> write multiple registers */
};


    /*
  	packet.u8id = TDL104_ID;
  	packet.u8fct = MB_FC_READ_REGISTERS;
  	packet.u16RegAdd = F3_2_TIME_MIN;
  	packet.u16CoilsNo = 1;
  	packet.au16reg = modbus_buffer;
*/
  /* packet = {.u8id = TDL104_ID,
             .u8fct = MB_FC_READ_INPUT_REGISTER,
             .u16RegAdd = F4_4_V31,
             .u16CoilsNo = 4,
             .au16reg = modbus_buffer
   };
*/
    //Serial.println(modbus_buffer[0]);
  	//Serial.print(master.getState());
    //Serial.print(master.getLastError());
    //rtuSerial.begin(115200);
    //rtuSerial.println("HELLO! IAM HERE !\r\n");

  master.query(packet);

  do{
    master.poll();
  }
  while(master.getState() == COM_WAITING);

  

  /*pumper(&data);

  Serial<<'\n'<<endl;
  Serial<<"V1: "<<data.v1<<", V2: "<<data.v2<<", V3: "<<data.v3<<endl;
  Serial<<"P1: "<<data.p1<<", P2: "<<data.p2<<", P3: "<<data.p3<<endl;
  Serial<<"Tempeture: "<<data.temp<<", Frequncy: "<<data.freq<<endl;
  Serial<<"Relay status code: "<<data.relay_status<<endl;

  //Serial.print(modbus_buffer[0]);

  delay(1000);
  */

    //modem.setBaud(38400);
  //TinyGsmAutoBaud(SerialAT);
  //delay(500);
  //modem.restart();

  get_f4(F4_2_TEMP);

  Serial<<'\n'<<endl;
  Serial<<modbus_buffer[0]<<modbus_buffer[1]<<modbus_buffer[2]<<modbus_buffer[3]<<endl;
  Serial<<modbus_buffer[4]<<modbus_buffer[5]<<modbus_buffer[6]<<modbus_buffer[7]<<endl;

  void get_voltages(data_buffer *data)
{
    get_f4(F4_4_V12);
    data->v1 = modbus_buffer[1];
    
    get_f4(F4_4_V23);
    data->v2 = modbus_buffer[1];
    
    get_f4(F4_4_V31);
    data->v3 = modbus_buffer[1];
}

void get_powers(data_buffer *data)
{
    get_f4(F4_4_P1);
    data->p1 = modbus_buffer[1];
    
    get_f4(F4_4_P2);
    data->p2 = modbus_buffer[1];
    
    get_f4(F4_4_P3);
    data->p3 = modbus_buffer[1];
}

void get_temp_freq(data_buffer *data)
{
    get_f4(F4_2_TEMP);
    data->temp = modbus_buffer[0];
    
    get_f4(F4_2_FREQ);
    data->freq = modbus_buffer[0];
}

void get_relay_status(data_buffer *data)
{
    get_f3(F3_2_RELAY_STATUS);
    data->relay_status = modbus_buffer[0];
}
