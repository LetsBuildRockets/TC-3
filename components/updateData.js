var sendUpdate;
var settings;
var devices;

exports.init = function init(newSendUpdate, newDevices, newSettings){
	sendUpdate = newSendUpdate;
	devices = newDevices;
	settings = newSettings;

	setInterval(function() {
		update();
	}, 500);
};

function update(){
	for(var s = 0; s <= devices.sensors.length; s++){
		sendUpdate('sensor', s + ":" + devices.sensors[s]);
	}
}