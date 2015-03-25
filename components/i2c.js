var i2c = require('i2c');
var address = 0x18;
var wire = new i2c(address, {device: '/dev/i2c-1'});
var updateDevice;
var settings;

exports.init = function(newSettings, newUpdate) {
	settings = newSettings;
	updateDevice = newUpdate;

};

exports.scan  = function () {
  wire.scan(function(err, data) {
    if(err) console.log(data);
    console.log(data);  
  });
};

exports.write = function (address, state) {
  // TODO: plain write
};

var lastPulse = false;
exports.pulse = function(address, wavelength){
	var interval = setInterval(function(){
		exports.write(address, !lastPulse);
		lastPulse = !lastPulse;
	}, wavelength);
	return interval;
};

// test code via arg -test
if (process.argv.slice(2)[0] == '-test') {
	exports.init({serial: {port: process.argv.slice(2)[1], baudrate: 9600}});

	serialPort.on('data', function(data) {
		console.log('data received: ' + data);
	});

	var last = 0;
	setInterval(function() {
		if (serialPortExists) {
			if (last)
				serialPort.write("0:0\n");
			else
				serialPort.write("0:1\n");
			last = !last;
		} else
			console.log("serial port not open!!!");
	}, 500);
}