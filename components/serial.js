var yaml = require('js-yaml');
var fs = require('fs');
var serialPort = require("serialport");
var settings = yaml.safeLoad(fs.readFileSync('./config/settings.yaml', 'ascii'));

//list ports for rpi
serialPort.list(function (err, ports) {
	ports.forEach(function(port) {
		console.log(port.comName);
		console.log(port.pnpId);
		console.log(port.manufacturer);
	});
});


/*var serialPort = new SerialPort(settings.serial.port, { // /dev/tty-usbserial1
	baudrate: settings.serial.baudrate
}, false);

serialPort.open(function () {
	console.log('open');
	serialPort.on('data', function(data) {
		console.log('data received: ' + data);
	});
});*/
