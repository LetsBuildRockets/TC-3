var isPi = require('os').arch()  == "arm";
if(isPi) {
  var i2c = require('i2c');
  var wire = new i2c(0x18, {device: '/dev/i2c-1'});
}
var deviceAddr = [0x48, 0x49, 0x50, 0x51];
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

function readSensorData () {
  if(isPi) {
    wire.setAddress(deviceAddr[1]);
    
  } else {
    console.log("Cannot Read Sensor Data. This is not a Raspberry Pi-.");
    return 0;
  }
}



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
  readSensorData();
}