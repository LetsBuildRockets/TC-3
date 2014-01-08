var burnState = "stop";
var sequence = { };

exports.burn = function burn(settings) {
	if(burnState == "stop"){
		burntime = settings.burn.time;

		/*sequence commands go here */
		
		var num = "0";
		var command = JSON.parse("settings.burn.sequence.command"+num);
		if(command){
			setTimeout(function () {
				sequence[command.run](settings);
			}, (burntime+command.time)*1000);
		}
		
	}
};


sequence.init = function sequenceInit(settings, params){
	burnState = "initialized";
};

sequence.ignitor = function sequenceIgnitor(settings, state){
	burnState = "ignitor " + state;
};

sequence.stop = function sequenceStop(settings, params){
	burnState = "stop";
};


exports.getBurnState = function(){
	return burnState;
};