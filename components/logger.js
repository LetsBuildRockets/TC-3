var fs = require('fs');
var stream = null;

//var logs = [];
//logs[0] = new logger({log: {appendDate: 0, extension: null}}, "logs", "test");

function Logger(settings, logsFolder, fileName) {
	var date = new Date();
	var name = logsFolder + "/" + fileName + (settings.log.appendDate ? " " + date.getFullYear() + " " + date.getMonth() + " " + date.getDay() + "  " + date.getHours() + " " + date.getMinutes() + " " + date.getSeconds() : "") + (settings.log.extension ? settings.log.extension : "");
	console.log(name);
	this.fs = require('fs');
	if (!fs.existsSync(name)) 
		this.stream = this.fs.createWriteStream(name);
	else
		console.log("could not open file: " + name);
};

Logger.prototype.write = function (str) {
	if (this.stream)
		this.stream.write(str.toString() + "\n");
	//stream.write(new Date().toUTCString() + "," + str.toString() + "\n");
};

Logger.prototype.logArray = function (time, dataArray, convert10){
	var str = "";
	for(var i = 0; i < dataArray.length; i++)
		str += (convert10 ? (dataArray[i] ? "1" : "0") : dataArray[i]) + ",";
	this.write(time + "," + str);
};

Logger.prototype.close = function() {
	if (stream)
		this.stream.end();
	this.stream = null;
};


//test code via arg -test
if (process.argv.slice(2)[0] == '-test') {
	new logger({log: {file: "logs/test", appendDate: 1, extension: null}});
	if (this.stream)
		this.stream.once('open', function(fd) {
			this.stream.write("foo");
			this.stream.write("bar");
		});
	for (var i = 0; i < 10; i++)
		Logger.prototype.write(i);
};

/*
 * clear logs via arg
 * to clear one log: -clear [file path]
 * to clear all logs: -clear [folder path] -a
 */
if (process.argv.slice(2)[0] == '-clear') {
	if (path = process.argv.slice(2)[1]) {
		if (process.argv.slice(2)[2] == "-a") {
			this.fs.readdirSync(path).forEach(function(file, index){
				var curPath = path + "/" + file;
				this.fs.unlinkSync(curPath);
			});
			console.log('successfully deleted ' + path + "/*");
		} else {
			this.fs.unlinkSync(path);
			console.log('successfully deleted ' + path);
		}
	} else
		console.log("no path specified!");
};
module.exports = Logger;