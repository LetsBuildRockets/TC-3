var sendUpdate;
var settings;


exports.init = function init(newSendUpdate, newSettings){
	sendUpdate = newSendUpdate;
	settings = newSettings;

	setInterval(function() {
		update();
	}, 500);
};

function update(){
	sendUpdate('sensor', "0:" + Math.round((Math.random()*60-30)));
	sendUpdate('sensor', "1:" + Math.round((Math.random()*60-30)));
	sendUpdate('sensor', "2:" + Math.round((Math.random()*60-30)));
	sendUpdate('sensor', "3:" + Math.round((Math.random()*60-30)));
	sendUpdate('sensor', "4:" + Math.round((Math.random()*60-30)));
}