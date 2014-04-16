var fs = require('fs');

var stream = null;


exports.init = function (settings) {
	var name = settings.log.file + (settings.log.appendDate ? " " + new Date() : "") + (settings.log.extension ? settings.log.extension : "");
	if (!fs.existsSync(name))
		stream = fs.createWriteStream(name);
	else
		console.log("could not open file: " + name);
};

//Test logger... comment out for release
exports.init({log: {file: "logs/test", appendDate: 1, extension: null}});

if (stream)
	stream.once('open', function(fd) {
		stream.write("My first row\n");
		stream.write("My second row\n");
		//stream.end();
	});

exports.write = function (str) {
	if (stream) {
		setTimeout(function() {
			stream.write(str.toString() + "\n");
			//stream.end();
		},100);
	}
};

//more test code
for (var i = 0; i < 100000; i++)
	exports.write(i);