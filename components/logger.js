var fs = require('fs');

var stream = null;


exports.init = function (settings) {
	var name = settings.log.file + (settings.log.appendDate ? " " + new Date() : "") + (settings.log.extension ? settings.log.extension : "");
	if (!fs.existsSync(name))
		stream = fs.createWriteStream(name);
	else
		console.log("could not open file: " + name);
};

exports.write = function (str) {
	if (stream)
		stream.write(str.toString() + "\n");
};

exports.close = function() {
	if (stream)
		stream.end();
};


//test code via arg '-test'
if (process.argv.slice(2)[0] == '-test') {
	exports.init({log: {file: "logs/test", appendDate: 1, extension: null}});
	if (stream)
		stream.once('open', function(fd) {
			stream.write("foo");
			stream.write("bar");
		});
	for (var i = 0; i < 10; i++)
		exports.write(i);
};

if (process.argv.slice(2)[0] == '-clear') {
	if (path = process.argv.slice(2)[1]) {
		if (process.argv.slice(2)[2] == "-a") {
			fs.readdirSync(path).forEach(function(file, index){
				var curPath = path + "/" + file;
				fs.unlinkSync(curPath);
			});
			console.log('successfully deleted ' + path + "/*");
		} else {
			fs.unlinkSync(path);
			console.log('successfully deleted ' + path);
		}
	} else
		console.log("no path specified!");
};