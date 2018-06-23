#ifndef COMMANDLIB_H
#define COMMANDLIB_H

#define STM32_CHECK                                         0x80
//call for data class  
#define STM32toTX1_IMU_DATA                                 0x91
#define STM32toTX1_PWM_DATA                                 0x92
#define STM32toTX1_WATER_DATA                               0x93


//send data class
#define TX1toSTM32_PWM_DATA                                 0xB0
#define TX1toSTM32_Yaw_Rate_PID_KpKiKd_DATA                 0xB1
#define TX1toSTM32_Stabilize_Yaw_PID_KpKiKd_DATA            0xB2
#define TX1toSTM32_Depth_PID_KpKiKd_DATA                    0xB3
#define TX1toSTM32_Depth_Acclerate_Rate_PID_KpKiKd_DATA     0xB4
#define TX1toSTM32_Taeget_Positioin_DATA                    0xB5
#define TX2toSTM32_stop_PID_Control                         0xB6
#define TX2toSTM32_start_PID_Control                        0xB7
#define TX1toSTM32_Current_Positioin_DATA                   0xB8
#define TX1toSTM32_STM32_Reset                              0xB9

#define NO_Data                                              0xFF
#define Data_Send_Start                                      0xFE
#define Data_Receive_Start                                   0xFE
#define Data_Send_Stop                                       0xFD
#define Data_Receive_Stop                                    0xFD
#define INVALID_COMMAND                                      0xF0


#endif // COMMANDLIB_H
