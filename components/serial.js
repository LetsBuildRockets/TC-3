var serialPortImport = require("serialport");
var SerialPort = serialPortImport.SerialPort;
var serialPortExists = false;
var serialPort;
var settings;

exports.init = function(newSettings) {
	settings = newSettings;

	serialPortImport.list(function (err, ports) {
		ports.forEach(function(port) {
			if (serialPortExists == port.comName)
				serialPortExists = true;
			if (settings.debug)
				console.log(port.comName);
		});
	});
	serialPort = new SerialPort(settings.serial.port, {
		baudrate: settings.serial.baudrate
	}, false, function(data){console.log(data); serialPortExists = false;});
};


if (serialPortExists)
	serialPort.open(function () {
		if (settings.debug)
			console.log(serialPort.comName + ' opened');
		serialPort.on('data', function(data) {
			if (settings.debug)
				console.log('data received: ' + data);
		});
	});

exports.write = function (address, state) {
	while(true)
		console.log(serialPortExists);
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

//test code via arg -test
if (process.argv.slice(2)[0] == '-test') {
	var last = 0;
	setInterval(function() {
		if (last)
			serialPort.write("0:0\n");
		else
			serialPort.write("0:1\n");
		last = !last;
	}, 500);
}