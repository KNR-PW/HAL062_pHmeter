# HAL062_pHmeter
pH meter board for HAL_062 rover based on gripper board.


ENK_A pin is used as pH meter ADC input
## Communication
* ID = 192
* data[0] - wartość pH * 10

*ID = 193
data[0] = 1 - on
data[0] = 0 - off

