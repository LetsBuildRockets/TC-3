var burnState = false;

exports.burn = function burn(settings) {
	if(!burnState){
		burnState = true;
		console.log("running");
		
		
		/*burn commands go here */
		
		
		
		setTimeout(function () {
			burnState = false;
			console.log('stop');
		}, settings.burn.time*1000);
	}
};

exports.getBurnState = function(){
	return burnState;
};