var SerialPort = require("serialport").SerialPort;

var serialPort = new SerialPort("COM3", { // /dev/tty-usbserial1
	baudrate: 57600
});