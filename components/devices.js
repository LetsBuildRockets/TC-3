var burnState = false;
var sequence = { };

exports.burn = function burn(settings) {
	if(burnState == false){
		burnState = true;
		burntime = settings.burn.time;

		/*sequence commands go here */
		var command = settings.burn.sequence.command0;

		if(command){
			setTimeout(function () {
				sequence[command.run](settings, [command.params]);
			}, (burntime+command.time)*1000);
		}
		var command2 = settings.burn.sequence.command1;
		console.log(command2.time*1000);
		if(command2){
			setTimeout(function () {
				sequence[command2.run](settings, [command2.params]);
			}, (burntime+command2.time)*1000);
		}

	}
};


sequence.init = function sequenceInit(settings){
	burnState = "initialized";
};

sequence.ignitor = function sequenceIgnitor(settings, state){
	burnState = "ignitor " + state;
};


exports.getBurnState = function(){
	return burnState;
};