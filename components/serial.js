var yaml = require('js-yaml');
var fs = require('fs');
var serialPort = require("serialport");
var SerialPort = serialPort.SerialPort;
var settings = yaml.safeLoad(fs.readFileSync('./config/settings.yaml', 'ascii'));
var serialPortExists = false;

serialPort.list(function (err, ports) {
	ports.forEach(function(port) {
		if (serialPortExists == port.comName)
			serialPortExists = true;
		console.log(port.comName);
	});
});


serialPort = new SerialPort(settings.serial.port, {
	baudrate: settings.serial.baudrate
}, true, function(data){console.log(data); serialPortExists = false;});

if (serialPortExists)
	serialPort.open(function () {
		if (settings.debug)
			console.log(serialPort.comName + ' opened');
		serialPort.on('data', function(data) {
			if (settings.debug)
				console.log('data received: ' + data);
		});

		//serialTest(serialPort);
	});

function serialTest(port){
	var last = 0;
	setInterval(function() {
		if (last)
			port.write("0:0\n");
		else
			port.write("0:1\n");
		last = !last;
	}, 500);
}

exports.write = function (address, state) {
	if (serialPortExists)
		serialPort.write(address + ":" + (state ? 1 : 0) + "\n");
	if (settings.debug)
		console.log("serial write: " + address + ":" + state);
};

var lastPulse = false;
exports.pulse = function(address, wavelength){
	var interval = setInterval(function(){
		exports.write(address, !lastPulse);
		lastPulse = !lastPulse;
	}, wavelength);
	return interval;
};