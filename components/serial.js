var yaml = require('js-yaml');
var fs = require('fs');
var SerialPort = require("serialport").SerialPort;
var settings = yaml.safeLoad(fs.readFileSync('./config/settings.yaml', 'ascii'));

var serialPort = new SerialPort(settings.serial.port, { // /dev/tty-usbserial1
	baudrate: settings.serial.baudrate
});